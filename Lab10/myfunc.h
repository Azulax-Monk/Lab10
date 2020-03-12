#pragma once
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct SBooks {
	char author[100];
	char title[100];
	char year[50];
	char pages[50];
	int price;
}SBooks;
typedef struct SList
{
	SBooks mBooks;
	struct SList* mNext;
}SList;

int isEmpty(SList* pFirst);

void consoleInput(SList** ppH);

void add_sortElem(SList bookshelf, SList** ppH, struct SBooks books);

void sel_sort(SList bookshelf, SList* phead);

void deleteMid(SList** ppH);

void dealloc(SList** ppHead);
