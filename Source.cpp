#define _CRT_SECURE_NO_WARNINGS
#include "myfunc.h"         

int main()
{
	FILE* fp;
	SList bookshelf = { 0 };
	SList* phead = NULL;
	SBooks SBElem;
	int i = 0, option = 0;
	char sym_c;
	
	if ((fp = fopen("Books.txt", "rt")) == NULL)
	{
		printf("File was not opened.");
		return 1;
	}

	do
	{
		getc(fp);
		while ((sym_c = getc(fp)) != ',')
		{
			SBElem.author[i] = sym_c;
			i++;
		}
		SBElem.author[i] = '\0';
		i = 0;

		while ((sym_c = getc(fp)) != ',')
		{
			SBElem.title[i] = sym_c;
			i++;
		}
		SBElem.title[i] = sym_c = '\0';
		i = 0;

		while ((sym_c = getc(fp)) != ',')
		{
			SBElem.year[i] = sym_c;
			i++;
		}
		SBElem.year[i] = '\0';
		i = 0;

		while ((sym_c = getc(fp)) != ',')
		{
			SBElem.pages[i] = sym_c;
			i++;
		}
		SBElem.pages[i] = '\0';
		i = 0;

		fscanf(fp, "%d", &SBElem.price);
		add_sortElem(bookshelf, &phead, SBElem);
		sym_c = getc(fp);
		fseek(fp, -1, 1);
	} while (sym_c != '.');      //Запис елементів в список

	if(isEmpty(phead))  return 3;
	//
	// Меню
	//
	while (1)
	{
		printf("\n1) Show books.\n2) Delete books with the title 'D...'.\n3) Add a new book.\n4) Exit.\n");
		
		printf("\nChoose youre option: ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			for (SList* i = phead; i != NULL; i = i->mNext)
				printf("%-18s || %-27s || %6s || %-10s || %-4d grn. ||\n", i->mBooks.author, i->mBooks.title, i->mBooks.year, i->mBooks.pages, i->mBooks.price);
			break;

		case 2:
			deleteMid(&phead);
			printf("\n\n\nAfter:\n");
			for (SList* i = phead; i != NULL; i = i->mNext)
				printf("%-18s || %-27s || %6s || %-10s || %-4d grn. ||\n", i->mBooks.author, i->mBooks.title, i->mBooks.year, i->mBooks.pages, i->mBooks.price);
			break;
		case 3:
			consoleInput(&phead);
			break;
		case 4:
			fclose(fp);
			dealloc(&phead);
			return 0;
		}
	}
}