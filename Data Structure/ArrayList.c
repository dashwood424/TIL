#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ArrayListNodeType {
	int data;
}ArrayListNode; //int 형의 자료를 1개 저장, 배열 리스트의 자료 저장 단위인 노드를 정의

typedef struct ArrayListType {
	int maxCount; //최대 자료 개수:배열의 크기
	int currentCount; //현재 자료 개수
	ArrayListNode *pData; //자료 저장을 위한 1차원 배열, maxCount만큼 할당된 배열을 가리키는 포인터
}ArrayList;

ArrayList *createList(int count) {
	ArrayList *pReturn = (ArrayList *)malloc(sizeof(ArrayList));
	pReturn->maxCount = count;
	pReturn->currentCount = 0;
	pReturn->pData = (ArrayListNode *)malloc(sizeof(ArrayListNode)*count);
	memset(pReturn->pData, 0, sizeof(ArrayListNode)*count);
} //리스트 생성

int addListData(ArrayList *pList, int position, int data) {
	int i = 0;
	for (i = pList->currentCount - 1; i >= position; i--) {
		pList->pData[i + 1] = pList->pData[i];
	} //추가되는 위치와 그 오른쪽에 있는 기존 자료를 모두 오른쪽으로 한 칸씩 이동

	pList->pData[position].data = data; //실제 자료 추가
	pList->currentCount++; //현재 저장된 자료 개수를 1증가
	return 0;
}

int removeListData(ArrayList *pList, int position) {
	int i = 0;
	for (i = position; i < pList->currentCount - 1; i++) {
		pList->pData[i] = pList->pData[i + 1]; //제거되는 원소의 위치와 그 오른쪽으로 있는 원소를 왼쪽으로 한칸씩 이동
	}
	pList->currentCount--;
	return 0; //값 제거 성공
}

int getListData(ArrayList *pList, int position) {
	return pList->pData[position].data; //position에 위치한 데이터 리턴
}

void deleteList(ArrayList* pList) {
	free(pList->pData); //배열 리스트의 멤버 변수인 pData가 배열을 가리키는 포인터이므로 먼저 할당된 배열의 메모리를 해제시킴
	free(pList); //리스트 자체에 대한 메모리 해제
}

int main(int argc, char *argv[]) {
	ArrayList *pList = NULL;
	int value = 0;

	pList = createList(5);
	addListData(pList, 0, 10);
	addListData(pList, 1, 20);
	addListData(pList, 0, 30);

	value = getListData(pList, 1);
	printf("위치: %d, 값: %d\n", 1, value);

	removeListData(pList, 0);
	deleteList(pList);

	return 0;
}