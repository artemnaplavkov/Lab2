#include <stdio.h>
#include <stdlib.h>
#include "store.h"


int main() {
	int stop = 0;
	struct notebook* arr = NULL;
	int n = 0;
	while (stop != 1) {
		printf("1-read 2-create 3-print 4-find\n");
		int key;
		scanf("%d", &key);
		switch (key) {
		case 1:
			printf("read\n");
			break;
		case 2:
			create(&arr, &n);
			printf("write\n");
			break;
		case 3:
			printf("print\n");
			break;
		case 4:
			printf("find\n");
			break;
		default:
			printf("bye");
			stop = 1;
			break;
		}
	}

}