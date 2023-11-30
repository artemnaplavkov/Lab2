#pragma once

struct notebook {
	char name[50];
	int year;
	int ram;
	int ssd;
	float price;
};

void create(struct notebook** arr, int* n);
void write(struct notebook* arr, int n);
void read(struct notebook** arr, int* n);
void print(struct notebook* arr, int n);
void find(struct notebook* arr, int n);
