#include <stdio.h>



int main(int arg, char* argc[]) {
	printf("Jobe George- 16323856\n");
	int a = 2;
	printf("Size of int is %d", sizeof(a));

	int b = 2;
	int *c = &b;
	printf("\nSize of int* is %d", sizeof(c));

	long d = 200;
	printf("\nSize of long is %d", sizeof(d));

	double e = 20.1;
	double *f = &e;
	printf("\nSize of double* is %d", sizeof(f));

	char g = 'a';
	char *h = &g;
	char **i = &h;
	printf("\nSize of char** is %d\n", sizeof(i));


	return 0;
}

