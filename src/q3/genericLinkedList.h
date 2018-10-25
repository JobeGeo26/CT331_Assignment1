#ifndef CT331_ASSIGNMENT_GENERIC_LINKED_LIST
#define CT331_ASSIGNMENT_GENERIC_LINKED_LIST

typedef void(*printFn)(void* data);

typedef struct genericlistElementStruct {
	void* data;
	size_t size;
	printFn printFunction;
	struct genericlistElementStruct* next;
} genericlistElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
genericlistElement* createEl(void* data, size_t size, printFn print);

//Prints out each element in the list
void traverse(genericlistElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
genericlistElement* insertAfter(genericlistElement* after, void* data, size_t size, printFn print);

//Delete the element after the given el
void deleteAfter(genericlistElement* after);

//returns the number of elements in the linked list
int length(genericlistElement* list);

//push a new element onto the head of a list.
void push(genericlistElement** list, void* data, size_t size, printFn print);

//pop an element from the head of a list.
genericlistElement* pop(genericlistElement** head);

//enqueue a new element onto the head of the list.
void enqueue(genericlistElement** list, void* data, size_t size, printFn print);

//dequeue an element from the tail of the list.
genericlistElement* dequeue(genericlistElement* list);

//prints out an integer element
void printInt(void* data);
void printChar(void* data);

//prints out a string element
void printStr(void* data);

//prints out a float element
void printFloat(void* data);






#endif
