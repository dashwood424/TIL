#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LinkedListNodeType {
	int data;
	struct LinkedListNodeType *pLink; //���� ����� ���� ������ �����ϴ� ��� ����
}LinkedListNode;

//�� ������ ��� pLink�� ���� NULL 

typedef struct LinkedListType {
	int currentCount;
	LinkedListNode headerNode;
}LinkedList;

LinkedList *createLinkedList() { //�Է��Ķ���� ����, ���� �ڷḦ �߰��� ������ �������� �Ҵ�
	LinkedList *pReturn = (LinkedList *)malloc(sizeof(LinkedList)); //���Ḯ��Ʈ�� ����ü LinkedList�� ���� �޸𸮸� �Ҵ�
	memset(pReturn, 0, sizeof(LinkedList)); //�Ҵ�� �޸𸮸� 0���� �ʱ�ȭ
	return pReturn;
}

//�������� ��ũ�� ����Ű�� ���:�ε����� 0�� �ڷ�
//1��° ����� ��ũ�� ����Ű�� ���:�ε����� 1�� �ڷ�

//�Է� �Ķ���� position���� 0�� ���޵Ǹ� ��� ����� ���� ��ũ�� �ѹ� �̵�

int getLinkedListData(LinkedList *pList, int position) {
	int i = 0;

	LinkedListNode *pCurrentNode = &(pList->headerNode);
	for (i = 0; i <= position; i++) {
		pCurrentNode = pCurrentNode->pLink; //�ε��� position+1 Ƚ����ŭ ����Ǹ�ũ�� �̿��Ͽ� ���� ���� �̵�
											//pCurrentNode�� ���� ��带 ��� pCurrentNode�� ����
	}

	return pCurrentNode->data;
}


//���ο� ����� ����-> �߰��Ϸ��� �ڷḦ �����ϴ� ��带 ���� ����
//���� ����� ó��-> ���� �߰��� ����� ���� ���� ���� position ��ġ�� ��带 ����
//���� ����� ó��-> ��ġ�� (position-1)�� ����� ���� ���� ���� �߰��� ��带 ����

int addLinkedListData(LinkedList *pList, int position, int data) {
	int i = 0;
	LinkedListNode *pNewNode = NULL;
	LinkedListNode *pPreNode = NULL;

	pNewNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
	pNewNode->data = data; //���ο� ����� ����

	pPreNode = &(pList->headerNode);
	for (i = 0; i < position; i++) {
		pPreNode = pPreNode->pLink;
	} //���� �ڷḦ �߰��Ϸ��� ��ġ�� ���� ������ �̵�

	pNewNode->pLink = pPreNode->pLink; //���� ����� ó��
	pPreNode->pLink = pNewNode; //���� ����� ó��
	pList->currentCount++; //���� ��� ���� 1 ����
	return 0;

}

//���� ����� ó��-> �ε����� (position-1)�� ����� ���� ���� �ε����� (position+1)�� ��带 ����
//���� ����� �޸� ����-> �����Ϸ��� ����� �޸𸮸� �����Ѵ�
int removeLinkedListData(LinkedList *pList, int position) {
	int i = 0;
	LinkedListNode *pDelNode = NULL;
	LinkedListNode *pPreNode = NULL;

	pPreNode = &(pList->headerNode);
	for (i = 0; i < position; i++) {
		pPreNode = pPreNode->pLink;
	} //�����Ϸ��� ����� ���� ������ �̵�

	pDelNode = pPreNode->pLink; //�����Ϸ��� ��� ����
	pPreNode->pLink = pDelNode->pLink; //���� ����� ó��

	free(pDelNode); //���� ����� �޸� ����
	pList->currentCount--; //���� ��� ���� 1 ����
	return 0;
}


//���Ḯ��Ʈ��ü�Ǹ޸𸮸� �����ϴ��Լ�
void deleteLinkedList(LinkedList *pList) {
	LinkedListNode *pDelNode = NULL;
	LinkedListNode *pPreNode = pList->headerNode.pLink;
	while (pPreNode != NULL) {
		pDelNode = pPreNode;
		pPreNode = pPreNode->pLink;

		free(pDelNode);
	} //���Ḯ��Ʈ�� �� ��带 ó������ ������� �޸� ������Ŵ

	free(pList); //���Ḯ��Ʈ ��ü�� �޸� ������Ŵ

}

int getLinkedListLength(LinkedList *pList) {
	if (NULL != pList) {
		return pList->currentCount;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	LinkedList *pList = NULL;
	int value = 0;

	pList = createLinkedList(); //����Ʈ ����
	addLinkedListData(pList, 0, 10);
	addLinkedListData(pList, 1, 20);
	addLinkedListData(pList, 1, 30);

	value = getLinkedListData(pList, 1);
	printf("��ġ: %d, ��: %d\n", 1, value);

	removeLinkedListData(pList, 0);
	deleteLinkedList(pList);

	return 0;
}


/*
*�迭����Ʈ
Ư�� �ڷῡ ���� Ž��(����)�ӵ��� ����
�迭�� Ư�� ��ġ�� �ٷ� ������ �����ϱ� ������ �迭����Ʈ�� �ڷ� ���� ������ O(1)�̴�.
���������� �����Ͽ� ����
�������� �޸𸮰��� �ʿ�

*���Ḯ��Ʈ
���ϴ� �ڷḦ ã�� ������ �����ͷ� ��带 Ž���ؾ���(�ӵ�����)
�����ϴ� �ڷ��� ������ N����� ���Ḯ��Ʈ�� �ڷ� ���� ������ �ð����⵵�� O(n)
������ ��带 �������� �����ϰ� ����, ���� ���
*/
