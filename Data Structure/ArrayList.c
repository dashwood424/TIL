#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ArrayListNodeType {
	int data;
}ArrayListNode; //int ���� �ڷḦ 1�� ����, �迭 ����Ʈ�� �ڷ� ���� ������ ��带 ����

typedef struct ArrayListType {
	int maxCount; //�ִ� �ڷ� ����:�迭�� ũ��
	int currentCount; //���� �ڷ� ����
	ArrayListNode *pData; //�ڷ� ������ ���� 1���� �迭, maxCount��ŭ �Ҵ�� �迭�� ����Ű�� ������
}ArrayList;

ArrayList *createList(int count) {
	ArrayList *pReturn = (ArrayList *)malloc(sizeof(ArrayList));
	pReturn->maxCount = count;
	pReturn->currentCount = 0;
	pReturn->pData = (ArrayListNode *)malloc(sizeof(ArrayListNode)*count);
	memset(pReturn->pData, 0, sizeof(ArrayListNode)*count);
} //����Ʈ ����

int addListData(ArrayList *pList, int position, int data) {
	int i = 0;
	for (i = pList->currentCount - 1; i >= position; i--) {
		pList->pData[i + 1] = pList->pData[i];
	} //�߰��Ǵ� ��ġ�� �� �����ʿ� �ִ� ���� �ڷḦ ��� ���������� �� ĭ�� �̵�

	pList->pData[position].data = data; //���� �ڷ� �߰�
	pList->currentCount++; //���� ����� �ڷ� ������ 1����
	return 0;
}

int removeListData(ArrayList *pList, int position) {
	int i = 0;
	for (i = position; i < pList->currentCount - 1; i++) {
		pList->pData[i] = pList->pData[i + 1]; //���ŵǴ� ������ ��ġ�� �� ���������� �ִ� ���Ҹ� �������� ��ĭ�� �̵�
	}
	pList->currentCount--;
	return 0; //�� ���� ����
}

int getListData(ArrayList *pList, int position) {
	return pList->pData[position].data; //position�� ��ġ�� ������ ����
}

void deleteList(ArrayList* pList) {
	free(pList->pData); //�迭 ����Ʈ�� ��� ������ pData�� �迭�� ����Ű�� �������̹Ƿ� ���� �Ҵ�� �迭�� �޸𸮸� ������Ŵ
	free(pList); //����Ʈ ��ü�� ���� �޸� ����
}

int main(int argc, char *argv[]) {
	ArrayList *pList = NULL;
	int value = 0;

	pList = createList(5);
	addListData(pList, 0, 10);
	addListData(pList, 1, 20);
	addListData(pList, 0, 30);

	value = getListData(pList, 1);
	printf("��ġ: %d, ��: %d\n", 1, value);

	removeListData(pList, 0);
	deleteList(pList);

	return 0;
}