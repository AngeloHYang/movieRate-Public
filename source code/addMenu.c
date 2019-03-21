#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "bar.h"
//setlocale(LC_CTYPE, "utf-8"); 

extern locale;
extern long long int* IDCounter;

struct eachData* addMenu(struct eachData* start)
{
	char inputSelection[1000];
	memset(inputSelection, '\0', sizeof(inputSelection));
	char moreBase[1000];
	memset(moreBase, '\0', sizeof(moreBase));
	strcat_s(moreBase, 1000, "yes");

	int movieNumber = howManyMovies(start);
	char namePlace[1000], commentPlace[10000];
	int IDPlace = 0;
	int starPlace = 0;
	memset(namePlace, '\0', sizeof(namePlace));
	memset(commentPlace, '\0', sizeof(commentPlace));

	while (memcmp(inputSelection, moreBase, 1000) != 0)
	{
		system("cls");
		//printf("Before we start, the ID counter was %lld, btw\n", *IDCounter);
		if (locale == 1)
		{
			printf("���Ǽ���Ҫ�����ݿ������һ����Ӱ!\n");
			printf("- ��Ӱ��������ʲô?\n- ");
			gets_s(namePlace, sizeof(namePlace));
			printf("- ��׼���򼸷�?(1-10)\n- ");
			scanf_s("%d", &starPlace);
			getchar();
			printf("- ����һ��\n- ");
			gets_s(commentPlace, sizeof(commentPlace));
			printf("\n*ȷ����*\n");
			printf("����: %s\n", namePlace);
			printf("����: ");
			for (int whichStar = 1; whichStar <= starPlace; whichStar++)
			{
				printf("��");
			}
			printf("\n����: %s\n", commentPlace);
			printf("\n*(y/n)*\n");
			memset(inputSelection, '\0', sizeof(inputSelection));
			gets_s(inputSelection, sizeof(inputSelection));
			deleteSpaceInTheEnd(inputSelection);
			if (strcmp(inputSelection, "n") == 0)
			{
				memcpy(inputSelection, moreBase, 1000);
			}
			else if (strcmp(inputSelection, "y") == 0)
			{
				(*IDCounter) = (*IDCounter) + 1;
				start = addMovie(namePlace, starPlace, commentPlace, start, IDCounter);
				printf("�ɹ����!\n");
				memcpy(inputSelection, moreBase, 1000);
			}
			else if (strcmp(inputSelection, "n") != 0)
			{
				printf("�Ҿ͵�����\"��\"�ˡ�\n");
				(*IDCounter) = (*IDCounter) + 1;
				start = addMovie(namePlace, starPlace, commentPlace, start, IDCounter);
				printf("�ɹ����!\n");
				memcpy(inputSelection, moreBase, 1000);
				//printf("\nAs far as I'm concerned, something has been added!");
				//printf("\nName: %s\nstar: %d\nComment: %s\nsee?\n\n", start->name, start->stars, start->comment);
			}
		}
		else if (locale == 2)
		{
			printf("We are going to add a movie to the data base!\n");
			printf("- What is the name of the movie?\n- ");
			gets_s(namePlace, sizeof(namePlace));
			printf("- How many stars are you going to give it?(1-10)\n- ");
			scanf_s("%d", &starPlace);
			getchar();
			printf("- Leave a comment\n- ");
			gets_s(commentPlace, sizeof(commentPlace));
			printf("\n*Is this alright?*\n");
			printf("Name: %s\n", namePlace);
			printf("Stars: ");
			for (int whichStar = 1; whichStar <= starPlace; whichStar++)
			{
				printf("��");
			}
			printf("\nComment: %s\n", commentPlace);
			printf("\n*(y/n)*\n");
			memset(inputSelection, '\0', sizeof(inputSelection));
			gets_s(inputSelection, sizeof(inputSelection));
			deleteSpaceInTheEnd(inputSelection);
			if (strcmp(inputSelection, "n") == 0)
			{
				memcpy(inputSelection, moreBase, 1000);
			}
			else if (strcmp(inputSelection, "y") == 0)
			{
				(*IDCounter) = (*IDCounter) + 1;
				start = addMovie(namePlace, starPlace, commentPlace, start, IDCounter);
				printf("Added successfully!\n");
				memcpy(inputSelection, moreBase, 1000);
			}
			else if(strcmp(inputSelection, "n") != 0)
			{
				printf("I'll  take it as a \"yes\".\n");
				(*IDCounter) = (*IDCounter) + 1;
				start =  addMovie(namePlace, starPlace, commentPlace, start, IDCounter);
				printf("Added successfully!\n");
				memcpy(inputSelection, moreBase, 1000);
				//printf("\nAs far as I'm concerned, something has been added!");
				//printf("\nName: %s\nstar: %d\nComment: %s\nsee?\n\n", start->name, start->stars, start->comment);
			}
		}
	}
	system("pause");
	return start;
}