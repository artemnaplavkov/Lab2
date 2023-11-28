#pragma once

struct notebook {
	char name[50];
	int year;
	int ram;
	int ssd;
	float price;
};

void create(struct notebook** arr, int* n);