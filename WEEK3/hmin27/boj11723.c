#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ADD 1
#define REMOVE 2
#define CHECK 4
#define TOGGLE 8
#define ALL 16
#define EMPTY 32

typedef struct _Elem {
	int data;
	struct _Elem *next;
} Elem;

Elem *head;


int _check(int val) {  //값이 linked list에 있는지 확인 후 있으면 1, 없으면 0 return
	Elem *ptr;

	if (head != NULL) {
		ptr = head;
		while (ptr != NULL) {
			if (val == ptr->data) return 1;
			ptr = ptr->next;
		}

	}

	return 0;
}

void _add(int val) {
	Elem *ptr;
	ptr = head;

	Elem *newNode = (Elem *)malloc(sizeof(Elem));
	newNode->data = val;
	newNode->next = NULL;


	if (head == NULL) head = newNode;
	else {
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}

}

void _remove(int val) {
	Elem *curPtr, *prePtr;

	curPtr = head->next;
	prePtr = head;

	while (curPtr != NULL) {
		if (val == curPtr->data) {
			prePtr->next = curPtr->next;
			free(curPtr);
			break;
		}
		prePtr = curPtr;
		curPtr = curPtr->next;

	}

//	free(prePtr);
}

int compare(char *opr) {

	if (!strcmp(opr, "add")) return ADD;
	else if (!strcmp(opr, "remove")) return REMOVE;
	else if (!strcmp(opr, "check")) return CHECK;
	else if (!strcmp(opr, "toggle")) return TOGGLE;
	else if (!strcmp(opr, "all")) return ALL;
	else if (!strcmp(opr, "empty")) return EMPTY;
}

void operation(int setOpr, int value) {

	if ( (setOpr & CHECK) || (setOpr & ADD) || (setOpr & REMOVE) || (setOpr & TOGGLE) ) {

		if (_check(value)) {
			if (setOpr & CHECK) printf("1\n");
			else if(setOpr & REMOVE | setOpr & TOGGLE) {
				_remove(value); //값이 이미 있다면 삭제하기
			}
		}
		else {
			if (setOpr & CHECK) printf("0\n");
			else if(setOpr & ADD | setOpr & TOGGLE) {
				_add(value); //값이 없다면 추가하기
			}
		}
	} 
	
	else if (setOpr & ALL) {
		Elem  *tail, *ptr;
		int i, lastIndex = 0;

		if (head != NULL) {
			ptr = head->next;
			for (i = 0; i<20; i++) {
				ptr->data = i + 1;
				if (ptr->next == NULL) {
					lastIndex = i+1;
					break;
				}

				ptr = ptr->next;
			}

		}

		tail = head;
		for (i = lastIndex; i < 20; i++) {
			Elem * temp = (Elem *)malloc(sizeof(Elem));
			temp->data = i+1;
			temp->next = NULL;


			tail->next = temp;
			tail = temp;
		}

		tail->next = NULL;
	}

	else if (setOpr & EMPTY) {
		Elem *curDel, *nextDel;

		if (head != NULL) {
			curDel = head;
			nextDel = head->next;

			free(curDel);

			while (nextDel != NULL) {
				curDel = nextDel;
				nextDel = nextDel->next;
				free(curDel);
			}

		}

		head = NULL;
	}
}


int main() {
	char opr[10];
	int repetition, value, setOpr;

	scanf("%d", &repetition);

	for (int i = 0; i < repetition; i++) {
		scanf("%s %d", opr, &value);
		setOpr = compare(opr);

		operation(setOpr, value);
	}
	
	return 0;
}