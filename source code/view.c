#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "bar.h"

extern locale;

void viewMenu(struct eachData* start)
{
	char inputSelection[1000];
	memset(inputSelection, '\0', sizeof(inputSelection));
	char quitBase[1000];
	memset(quitBase, '\0', sizeof(quitBase));
	strcat_s(quitBase, 1000, "quit");
	

	char namePlace[1000], commentPlace[10000];
	long long int* IDPlace = (long long int*) malloc(sizeof(long long int));
	int* starPlace = (int*) malloc(sizeof(int));
	//*starPlace = 3;
	//printf("starPlace at the beginning: %d\n", *starPlace);
	//printf("The adress of it: %d\n", starPlace);
	//system("pause");
	//int* starPlace = NULL;

	struct eachData* begin = start;
	int movieNumber = howManyMovies(start);
	

	

	
	//printf("You have just input *%s*\n", inputSelection);
	while (memcmp(inputSelection, quitBase, 1000) != 0)
	{
		system("cls");

		if (locale == 1)
		{
			printf("Ŀǰ��%d����Ӱ�����ݿ���\n", movieNumber);
			if (movieNumber >= 1)
			{
				printf("����:\n\n");
				for (int whichOne = 1; whichOne <= movieNumber; whichOne++)
				{
					if (searchByWhichOneMovie(whichOne, begin, namePlace, IDPlace, starPlace, commentPlace) == 1)
					{
						printf("����: %s\n", namePlace);
						printf("ID: %d\n", *IDPlace);
						printf("����: ");
						for (int whichStar = 1; whichStar <= *starPlace; whichStar++)
						{
							printf("��");
						}
						printf("\n");
						printf("����: %s\n", commentPlace);
						printf("\n");
					}
				}
			}


			printf("\n\n���� quit ���˳�\n");
		}
		else if (locale == 2)
		{
			if (movieNumber == 1)
			{
				printf("There is currently %d movie in the database.\n", movieNumber);
			}
			else
			{
				printf("There are currently %d movies in the database.\n", movieNumber);
			}
			if (movieNumber >= 1)
			{
				printf("As follows\n\n  ");
				for (int whichOne = 1; whichOne <= movieNumber; whichOne++)
				{
					if (searchByWhichOneMovie(whichOne, begin, namePlace, IDPlace, starPlace, commentPlace) == 1)
					{
						printf("\n\nThis is the %d movie!\n", whichOne);
						printf("Name: %s\n", namePlace);
						printf("ID: %d\n", *IDPlace);
						printf("Star: ");
						for (int whichStar = 1; whichStar <= *starPlace; whichStar++)
						{
							printf("��");
						}
						printf("\n");
						printf("Comment: %s\n", commentPlace);
						printf("\n");
					}
				}
			}
			printf("\n\nInput quit to quit\n");
		}
		gets_s(inputSelection, 1000);
		deleteSpaceInTheEnd(inputSelection);
		//printf("You have just input *%s*\n", inputSelection);
	}
	free(IDPlace);
	free(starPlace);
}