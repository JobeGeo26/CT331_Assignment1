#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericlistElement* createEl(void* data, size_t size, printFn print) {
	genericlistElement* e = malloc(sizeof(genericlistElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	void* dataPointer = malloc(size);
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	memmove(dataPointer, data, size);
	e->data = dataPointer;
	e->size = size;
	e->printFunction = print;
	e->next = NULL;
	return e;
}

//Prints out each element in the list

void traverse(genericlistElement* head) {
	genericlistElement* current = head;
	while (current != NULL) {
		current->printFunction(current->data);
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element


genericlistElement* insertAfter(genericlistElement* el, void* data,
	size_t size, printFn printFunc) {
	genericlistElement* newEl = createEl(data, size, printFunc);
	genericlistElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}

//Delete the element after the given element
void deleteAfter(genericlistElement* after) {
	genericlistElement* delete = after->next;
	genericlistElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}

// returns the number of elements in a linked list.
int length(genericlistElement* list) {
	int lengthCount = 0;
	genericlistElement* temp = list;
	while (temp != NULL) {
		temp = temp->next;
		lengthCount++;
	}
	return lengthCount;
}

// push a new element onto the head of a list.
void push(genericlistElement** list, void* data, size_t size, printFn print) {
	genericlistElement* newElement = createEl(data, size, print);
	newElement->next = *list;
	*list = newElement;
}

// pop an element from the head of a list.
genericlistElement* pop(genericlistElement** list) {
	if (*list != NULL) {
		genericlistElement* element = (*list)->next;

		
		*list = (*list)->next;

		return element;
	}
	return *list;
}

//enqueue a new element onto the head of the list.
void enqueue(genericlistElement** list, void* data, size_t size, printFn print) {
	push(list, data, size, print);
}

//dequeue an element from the tail of the list.
genericlistElement* dequeue(genericlistElement* list) {
	
	genericlistElement* temp = list;

	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	genericlistElement* tail = temp->next;
	temp->next = NULL;
	return tail;
}

void printChar(void* data) {
	printf("%c\n", *(char*)data);
}

	void printFloat(void* data) {
		printf("%f\n", *(float*)data);
	}

	
	void printStr(void* data) {
		printf("%s\n", data);
	}



void printInt(void* data) {
	printf("%d\n", *(int*)data);
}


