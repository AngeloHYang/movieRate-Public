#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "bar.h"

extern locale;

struct eachData* deleteMenu(struct eachData* start)
{
	char inputString[1000];
	long long int inputID;
	int whichOneIsIt;
	char namePlace[1000];
	char commentPlace[10000];
	long long int* IDPlace = (long long int*) malloc(sizeof(long long int));
	int* starPlace = (int*)malloc(sizeof(int));
	memset(inputString, '\0', sizeof(inputString));
	if (locale == 1)
	{
		system("cls");
		printf("Ϊ��ɾ����Ӱ������Ҫ֪������ID\n");
		printf("- �����ȥ�鿴һ����?(y/n)\n- ");
		gets_s(inputString, 1000);
		deleteSpaceInTheEnd(inputString);
		//printf("inputString: %s\n", inputString);
		if (strcmp(inputString, "y") == 0)
		{
			printf("\n�ðɣ�������Ը\n");
			system("pause");
		}
		else
		{
			if (strcmp(inputString, "n") != 0)
			{
				printf("\n�Ҿ͵���֪��ID��\n");
			}
			if (howManyMovies(start) == 0)
			{
				printf("û�е�Ӱ��˵��\n���褦�ʤ�!\n");
				system("pause");
			}
			else
			{
				printf("������ID: ");
				scanf_s("%lld", &inputID);
				getchar();
				whichOneIsIt = byIDTellWhichOneMovie(inputID, start);
				if (whichOneIsIt == -1)
				{
					printf("���ID %lld �������ڵ�˵!\n", inputID);
					system("pause");
				}
				else
				{
					searchByWhichOneMovie(whichOneIsIt, start, namePlace, IDPlace, starPlace, commentPlace);
					printf("\n��Ӱ:\n����: %s\n", namePlace);
					printf("����: ");
					for (int whichOne = 1; whichOne <= *starPlace; whichOne++)
					{
						printf("��");
					}
					printf("\n");
					printf("����: %s\n", commentPlace);
					printf("\n\n��ȷ��Ҫɾ����?(y/n)\n");
					memset(inputString, '\0', sizeof(inputString));
					gets_s(inputString, 1000);
					deleteSpaceInTheEnd(inputString);
					//printf("This is NO. %d\n!", whichOneIsIt);
					if (strcmp(inputString, "y") == 0)
					{
						start = deleteMovie(whichOneIsIt, start);
						printf("\n��Ӱ��ɾ��!\n");
						system("pause");
					}
					else
					{
						printf("��Ӱδɾ��!\n");
						system("pause");
					}
				}
			}
		}
	}
	else if (locale == 2)
	{
		system("cls");
		printf("In order to delete a movie you must remember it's ID\n");
		printf("- Do you want to go back and check it out?(y/n)\n- ");
		gets_s(inputString, 1000);
		deleteSpaceInTheEnd(inputString);
		//printf("inputString: %s\n", inputString);
		if (strcmp(inputString, "y") == 0)
		{
			printf("\nAlright, as you wish\n");
			system("pause");
		}
		else
		{
			if (strcmp(inputString, "n") != 0)
			{
				printf("\nI'll suppose you know the ID.\n");
			}
			if (howManyMovies(start) == 0)
			{
				printf("There're no movies to delete.\nSayounara!\n");
				system("pause");
			}
			else
			{
				printf("Please input the ID: ");
				scanf_s("%lld", &inputID);
				getchar();
				whichOneIsIt = byIDTellWhichOneMovie(inputID, start);
				if (whichOneIsIt == -1)
				{
					printf("The ID %lld does not exist!\n", inputID);
					system("pause");
				}
				else
				{
					searchByWhichOneMovie(whichOneIsIt, start, namePlace, IDPlace, starPlace, commentPlace);
					printf("\nThe movie:\nName: %s\n", namePlace);
					printf("Stars: ");
					for (int whichOne = 1; whichOne <= *starPlace; whichOne++)
					{
						printf("��");
					}
					printf("\n");
					printf("Comment: %s\n", commentPlace);
					printf("\n\nAre you SURE to delete it?(y/n)\n");
					memset(inputString, '\0', sizeof(inputString));
					gets_s(inputString, 1000);
					deleteSpaceInTheEnd(inputString);
					if (strcmp(inputString, "y") == 0)
					{
						start = deleteMovie(whichOneIsIt, start);
						printf("\nMovie deleted!\n");
						system("pause");
					}
					else
					{
						printf("Movie not deleted!\n");
						system("pause");
					}
				}
			}
		}
	}
	free(IDPlace);
	free(starPlace);
	return start;
}