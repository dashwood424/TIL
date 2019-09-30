#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LinkedListNodeType {
	int data;
	struct LinkedListNodeType *pLink; //다음 노드의 연결 정보를 저장하는 멤버 변수
}LinkedListNode;

//맨 마지막 노드 pLink의 값이 NULL 

typedef struct LinkedListType {
	int currentCount;
	LinkedListNode headerNode;
}LinkedList;

LinkedList *createLinkedList() { //입력파라미터 없음, 새로 자료를 추가할 때마다 동적으로 할당
	LinkedList *pReturn = (LinkedList *)malloc(sizeof(LinkedList)); //연결리스트의 구조체 LinkedList에 대한 메모리를 할당
	memset(pReturn, 0, sizeof(LinkedList)); //할당된 메모리를 0으로 초기화
	return pReturn;
}

//헤더노드의 링크가 가리키는 노드:인덱스가 0인 자료
//1번째 노드의 링크가 가리키는 노드:인덱스가 1인 자료

//입력 파라미터 position으로 0이 전달되면 헤더 노드의 다음 링크로 한번 이동

int getLinkedListData(LinkedList *pList, int position) {
	int i = 0;

	LinkedListNode *pCurrentNode = &(pList->headerNode);
	for (i = 0; i <= position; i++) {
		pCurrentNode = pCurrentNode->pLink; //인덱스 position+1 횟수만큼 노드의링크를 이용하여 다음 노드로 이동
											//pCurrentNode의 다음 노드를 노드 pCurrentNode에 대입
	}

	return pCurrentNode->data;
}


//새로운 노드의 생성-> 추가하려는 자료를 저장하는 노드를 새로 생성
//다음 노드의 처리-> 새로 추가한 노드의 다음 노드로 기존 position 위치의 노드를 지정
//이전 노드의 처리-> 위치가 (position-1)인 노드의 다음 노드로 새로 추가한 노드를 지정

int addLinkedListData(LinkedList *pList, int position, int data) {
	int i = 0;
	LinkedListNode *pNewNode = NULL;
	LinkedListNode *pPreNode = NULL;

	pNewNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
	pNewNode->data = data; //새로운 노드의 생성

	pPreNode = &(pList->headerNode);
	for (i = 0; i < position; i++) {
		pPreNode = pPreNode->pLink;
	} //새로 자료를 추가하려는 위치의 이전 노드까지 이동

	pNewNode->pLink = pPreNode->pLink; //다음 노드의 처리
	pPreNode->pLink = pNewNode; //이전 노드의 처리
	pList->currentCount++; //현재 노드 개수 1 증가
	return 0;

}

//이전 노드의 처리-> 인덱스가 (position-1)인 노드의 다음 노드로 인덱스가 (position+1)인 노드를 지정
//제거 노드의 메모리 해제-> 제거하려는 노드의 메모리를 해제한다
int removeLinkedListData(LinkedList *pList, int position) {
	int i = 0;
	LinkedListNode *pDelNode = NULL;
	LinkedListNode *pPreNode = NULL;

	pPreNode = &(pList->headerNode);
	for (i = 0; i < position; i++) {
		pPreNode = pPreNode->pLink;
	} //제거하려는 노드의 이전 노드까지 이동

	pDelNode = pPreNode->pLink; //제거하려는 노드 지정
	pPreNode->pLink = pDelNode->pLink; //이전 노드의 처리

	free(pDelNode); //제거 노드의 메모리 해제
	pList->currentCount--; //현재 노드 개수 1 감소
	return 0;
}


//연결리스트자체의메모리를 해제하는함수
void deleteLinkedList(LinkedList *pList) {
	LinkedListNode *pDelNode = NULL;
	LinkedListNode *pPreNode = pList->headerNode.pLink;
	while (pPreNode != NULL) {
		pDelNode = pPreNode;
		pPreNode = pPreNode->pLink;

		free(pDelNode);
	} //연결리스트의 각 노드를 처음부터 순서대로 메모리 해제시킴

	free(pList); //연결리스트 자체를 메모리 해제시킴

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

	pList = createLinkedList(); //리스트 생성
	addLinkedListData(pList, 0, 10);
	addLinkedListData(pList, 1, 20);
	addLinkedListData(pList, 1, 30);

	value = getLinkedListData(pList, 1);
	printf("위치: %d, 값: %d\n", 1, value);

	removeLinkedListData(pList, 0);
	deleteLinkedList(pList);

	return 0;
}


/*
*배열리스트
특정 자료에 대한 탐색(접근)속도가 빠름
배열의 특정 위치로 바로 접근이 가능하기 때문에 배열리스트의 자료 접근 연산은 O(1)이다.
물리적으로 연속하여 저장
연속적인 메모리공간 필요

*연결리스트
원하는 자료를 찾을 때까지 포인터로 노드를 탐색해야함(속도느림)
저장하는 자료의 개수가 N개라면 연결리스트의 자료 접근 연산은 시간복잡도가 O(n)
각각의 노드를 동적으로 생성하고 해제, 구현 어렵
*/
