#define _CRT_SECURE_NO_WARNINGS
#include "myfunc.h"

void consoleInput(SList** ppH)
{
	SBooks newBook = { 0 };
	SList bookshelf = { 0 };
	int counter = 0, pagesNum;
	char c = 0;

	printf("\nEnter an author of a book, you want to add: ");
	getchar();
	while ((c = getchar()) != '\n')
	{
		newBook.author[counter] = c;
		counter++;
	}
	newBook.author[counter] = '\0';
	counter = 0;

	printf("\nEnter a title of a book, you want to add: ");
	while ((c = getchar()) != '\n')
	{
		newBook.title[counter] = c;
		counter++;
	}
	newBook.title[counter] = '\0';
	counter = 0;

	printf("\nEnter a date when a book was written: ");
	while ((c = getchar()) != '\n')
	{
		newBook.year[counter] = c;
		counter++;
	}
	newBook.year[counter] = ' ';
	strcat(newBook.year, "year");  //ÕÎÒÜ ÁÈ ÏÎÌÈËÊÀ ÍÅ ÂÈÑÊÎ×ÈËÀ
	counter = 0;

	printf("\nEnter number of pages of a book, you want to add: ");

	while ((c = getchar()) != '\n')
	{
		newBook.pages[counter] = c;
		counter++;
	}
	newBook.pages[counter] = ' ';
	strcat(newBook.pages, "pages");
	counter = 0;

	printf("\nEnter price of a book, you want to add: ");
	getchar();
	scanf("%d", &newBook.price);
	add_sortElem(bookshelf, ppH, newBook);
}

void add_sortElem(SList bookshelf, SList** ppH, struct SBooks books)
{
	SList* prevEl = *ppH;
	SList* curEl = *ppH;
	SList* pTmp = (SList*)malloc(sizeof(SList));
	pTmp->mBooks = books;
	
	if (!*ppH)                 //ßêùî â ñïèñêó íåìàº åëåìåíò³â, òî ïåðøèì ïðèçíà÷àºìî pTmp
	{
		*ppH = pTmp;
		pTmp->mNext = NULL;
	}
	else                      //Â ³íøîìó âèïàäêó äîäàºìî éîãî â ñïèñîê ³ ñîðòóºìî
	{
		for (curEl; curEl != NULL; curEl = curEl->mNext)
		{
			if (strcmp(pTmp->mBooks.title, curEl->mBooks.title) < 0)             
			{
				if (curEl != *ppH)            
				{
					prevEl->mNext = pTmp;
					pTmp->mNext = curEl;
				}
				else
				{
					pTmp->mNext = curEl;
					*ppH = pTmp;
				}
				break;
			}
			if (curEl != *ppH)
			   prevEl = prevEl->mNext;	
			
			if (!curEl->mNext)             //ßêùî åëåìåíò íå º ìåíøèì çà âæå íàÿâí³, òî äîäàºìî éîãî â ê³íåöü ñïèñêó
			{
				curEl->mNext = pTmp;
				pTmp->mNext = NULL;
				break;
			}
		}
	}
}

void dealloc(SList** ppHead)
{
	SList* cur = *ppHead;
	if (cur == NULL) return;
	cur = cur->mNext;
	dealloc(&cur);
	free(cur);
	*ppHead = NULL;
}

int isEmpty(SList* pFirst)
{
	return !pFirst;
}

void swap(struct SList, SList* pos1, SList* pos2)
{
	SBooks tmp;
    tmp = pos1->mBooks;
    pos1->mBooks = pos2->mBooks;
	pos2->mBooks = tmp;
}

void sel_sort(SList bookshelf, SList* phead)
{
	SList* pmin = phead;
	SList* pk = phead;
	SList* pj = phead;

	for (pk; pk != NULL; pk = pk->mNext)
	{
		for (pj; pj != NULL; pj = pj->mNext)
		{
				if (strcmp(pj->mBooks.title, pmin->mBooks.title) < 0)
				{
					pmin = pj;
				}
		}
		swap(bookshelf, pk, pmin);
		pmin = pk->mNext;
		pj = pk->mNext;
	}
}

void deleteMid(SList** ppH)
{
	SList* pCur1 = *ppH;
	while (1)
	{
		SList* pCur2 = pCur1;
		pCur1 = pCur1->mNext;

		if (!pCur1)
			break;
		if (pCur1->mBooks.title[0] == 'D') {
			if (!pCur1->mNext)
			{
				pCur2->mNext = NULL;
				break;
			}
			pCur2->mNext = pCur1->mNext;
			free(pCur1);
			pCur1 = pCur2;
		}
	}
	pCur1 = *ppH;
	if (pCur1->mBooks.title[0] == 'D')
		if (pCur1->mNext)
			* ppH = pCur1->mNext;
		else
			*ppH = NULL;
}

int getSize(SList* pFirst)
{
	SList* pTmp = pFirst;
	int counter = 0;
	while (pTmp)
	{
		++counter;
		pTmp = pTmp->mNext;
	}
	return counter;
}