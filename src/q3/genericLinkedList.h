#ifndef CT331_ASSIGNMENT_GENERIC_LINKED_LIST
#define CT331_ASSIGNMENT_GENERIC_LINKED_LIST

typedef void(*printFn)(void* data);

typedef struct genericlistElementStruct {
	void* data;
	size_t size;
	printFn print;
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

//Returns the number of elements in a linked list
int length(genericlistElement* list);

//Push a new element onto the head of a list.
void push(genericlistElement** list, void* data, size_t size, printFn print);

//Pop an element from the head of a list.
genericlistElement* pop(genericlistElement** head);

//Enqueue a new element onto the head of the list.
void enqueue(genericlistElement** list, void* data, size_t size, printFn print);

//Dequeue an element from the tail of the list.
genericlistElement* dequeue(genericlistElement* list);

//Prints out an integer element
void printInt(void* data);

//Prints out a float element
void printFloat(void* data);

//Prints out a char element
void printChar(void* data);

//Prints out a string element
void printStr(void* data);



#endif
