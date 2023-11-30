#include "store.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void create(struct notebook **arr, int *n) {
	if (*n > 0) {
		free(*arr);
		n = 0;
	}
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

void read(struct notebook** arr, int* n) {
	if (*n > 0) {
		free(*arr);
		n = 0;
	}
	FILE* f = fopen("notebooks.txt", "r");
	if (!f)
		return;
	fscanf(f, "%d", n);
	if (n < 1)
		return;
	*arr = (struct notebook*)calloc(*n, sizeof(struct notebook));
	for (int i = 0; i < *n; i++)
		fscanf(f, "%s %d %d %d %f\n", (*arr)[i].name, &(*arr)[i].year, &(*arr)[i].ram, &(*arr)[i].ssd, &(*arr)[i].price);
}

void print(struct notebook* arr, int n) {
	if (n == 0)
		return;
	printf("name\tyear\tram\tssd\tprice\n");
	for (int i = 0; i < n; i++)
		printf("%s\t%d\t%d\t%d\t%f\n", arr[i].name, arr[i].year, arr[i].ram, arr[i].ssd, arr[i].price);
}

void find(struct notebook* arr, int n) {
	if (n == 0)
		return;
	printf("name = ");
	char name[50];
	scanf("%s", name);
	printf("name\tyear\tram\tssd\tprice\n");
	for (int i = 0; i < n; i++)
		if (strcmp(name, arr[i].name) == 0)
			printf("%s\t%d\t%d\t%d\t%f\n", arr[i].name, arr[i].year, arr[i].ram, arr[i].ssd, arr[i].price);
}
