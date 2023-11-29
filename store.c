#include "store.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void create(struct notebook **arr, int *n) {
	if (*n>0)
		free(*arr);
	printf("notebooks number = ");
	scanf("%d", n);
	if (n < 1)
		return;
	*arr = (struct notebook*)calloc(*n, sizeof(struct notebook));
	for (int i = 0; i < *n; i++) {
		printf("notebook %d\n", (i + 1));

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

void write(struct notebook* arr, int n) {
	if (n == 0)
		return;
	FILE* f = fopen("notebooks.txt", "w");
	if (!f)
		return;
	fprintf(f,"%d\n", n);
	for (int i = 0; i < n; i++)
		fprintf(f, "%s %d %d %d %f\n", arr[i].name, arr[i].year, arr[i].ram, arr[i].ssd, arr[i].price);
	fclose(f);
}
