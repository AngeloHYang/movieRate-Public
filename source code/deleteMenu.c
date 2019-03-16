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
		printf("为了删除电影，你需要知道它的ID\n");
		printf("- 你想回去查看一下吗?(y/n)\n- ");
		gets_s(inputString, 1000);
		deleteSpaceInTheEnd(inputString);
		//printf("inputString: %s\n", inputString);
		if (strcmp(inputString, "y") == 0)
		{
			printf("\n好吧，如你所愿\n");
			system("pause");
		}
		else
		{
			if (strcmp(inputString, "n") != 0)
			{
				printf("\n我就当你知道ID。\n");
			}
			if (howManyMovies(start) == 0)
			{
				printf("没有电影的说。\nさようなら!\n");
				system("pause");
			}
			else
			{
				printf("请输入ID: ");
				scanf_s("%lld", &inputID);
				getchar();
				whichOneIsIt = byIDTellWhichOneMovie(inputID, start);
				if (whichOneIsIt == -1)
				{
					printf("这个ID %lld 并不存在的说!\n", inputID);
					system("pause");
				}
				else
				{
					searchByWhichOneMovie(whichOneIsIt, start, namePlace, IDPlace, starPlace, commentPlace);
					printf("\n电影:\n名称: %s\n", namePlace);
					printf("评分: ");
					for (int whichOne = 1; whichOne <= *starPlace; whichOne++)
					{
						printf("★");
					}
					printf("\n");
					printf("评论: %s\n", commentPlace);
					printf("\n\n你确认要删除吗?(y/n)\n");
					memset(inputString, '\0', sizeof(inputString));
					gets_s(inputString, 1000);
					deleteSpaceInTheEnd(inputString);
					//printf("This is NO. %d\n!", whichOneIsIt);
					if (strcmp(inputString, "y") == 0)
					{
						start = deleteMovie(whichOneIsIt, start);
						printf("\n电影已删除!\n");
						system("pause");
					}
					else
					{
						printf("电影未删除!\n");
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
						printf("★");
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