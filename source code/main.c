#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "bar.h"
int locale;



int main()
{
	locale = 0;
	char inputString[1000];
	while (locale != 2 && locale != 1)
	{
		system("cls");
		printf("Please choose your language:\n");
		printf("1) ÖÐÎÄ\n");
		printf("2) English\n");
		printf("\nInput quit to quit\n");
		printf("\nYour input: ");
		scanf_s("%d", &locale);
		memset(inputString, '\0', sizeof(inputString));
		gets_s(inputString, 1000);
		deleteSpaceInTheEnd(inputString);
		//strcat_s(inputString, 1000, "2");
		if (strcmp(inputString, "1") == 0)
		{
			locale = 1;
		}
		else if (strcmp(inputString, "2") == 0)
		{
			locale = 2;
		}
		if (locale >= 1 && locale <= 2)
		{
			menu();
		}
		if (strcmp(inputString, "quit") == 0)
		{
			break;
		}
	}
	return 0;
}