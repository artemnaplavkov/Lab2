#include "store.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void create(struct notebook **arr, int *n) {
	free(*arr);
	printf("notebooks number = ");
	scanf("%d", n);
	if (n < 1)
		return;
	*arr = (struct notebook*)calloc(*n, sizeof(struct notebook));
	for (int i = 0; i < *n; i++) {
		printf("name = ");
		scanf("%s", (*arr)[i].name);
		printf("year = ");
		scanf("%d", &(*arr)[i].year);
		printf("ram = ");
		scanf("%d", &(*arr)[i].ram);
		printf("ssd = ");
		scanf("%d", &(*arr)[i].ssd);
		printf("price = ");
		scanf("%f", &(*arr)[i].price);
	}
}
