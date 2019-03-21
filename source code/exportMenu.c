#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
extern int locale;

void exportMenu(struct eachData* start)
{
	if (locale == 1)
	{
		system("cls");
		printf("数据将会导出到名为 movies.md 的文件中...");
		errno_t err;  //判断此文件流是否存在 存在返回1
		FILE* new;
		err = fopen_s(&new, "movies.md", "w+");
		//new = fopen("movies.md", "w+");
		fprintf(new, "# 电影\n\n");
		fprintf(new, "序号 | 名称 | 评分 | 评论\n");
		fprintf(new, "--- | --- | --- | ---\n");
		int howManyMoviesInTotal = howManyMovies(start);

		char namePlace[1000], commentPlace[10000];
		long long int* IDPlace = (long long int*) malloc(sizeof(long long int));
		int* starPlace = (int*)malloc(sizeof(int));

		for (int whichMovie = 1; whichMovie <= howManyMoviesInTotal; whichMovie++)
		{
			if (searchByWhichOneMovie(whichMovie, start, namePlace, IDPlace, starPlace, commentPlace) == 1)
			{
				//printf("\n\nThis is the %d movie!\n", whichMovie);
				fprintf(new, "%d | ", whichMovie);

				fprintf(new, "%s | ", namePlace);

				//printf("Name: %s\n", namePlace);
				//printf("ID: %d\n", *IDPlace);
				//printf("Star: ");
				for (int whichStar = 1; whichStar <= *starPlace; whichStar++)
				{
					fprintf(new, "★");
				}
				fprintf(new, " | ");
				//printf("Comment: %s\n", commentPlace);

				fprintf(new, "%s", commentPlace);

				fprintf(new, "\n");
			}
		}
		fprintf(new, "\n慢走不送!");

		free(IDPlace);
		free(starPlace);
		fclose(new);
		printf("文件创建成功!\n");
	}
	if (locale == 2)
	{
		system("cls");
		printf("We are going to export the data into a md file named \"movies.md\"...");
		errno_t err;  //判断此文件流是否存在 存在返回1
		FILE* new;
		err = fopen_s(&new, "movies.md", "w+");
		//new = fopen("movies.md", "w+");
		fprintf(new, "# Movies\n\n");
		fprintf(new, "Number | Name | Stars | Comment\n");
		fprintf(new, "--- | --- | --- | ---\n");
		int howManyMoviesInTotal = howManyMovies(start);

		char namePlace[1000], commentPlace[10000];
		long long int* IDPlace = (long long int*) malloc(sizeof(long long int));
		int* starPlace = (int*)malloc(sizeof(int));

		for (int whichMovie = 1; whichMovie <= howManyMoviesInTotal; whichMovie++)
		{
			if (searchByWhichOneMovie(whichMovie, start, namePlace, IDPlace, starPlace, commentPlace) == 1)
			{
				//printf("\n\nThis is the %d movie!\n", whichMovie);
				fprintf(new, "%d | ", whichMovie);

				fprintf(new, "%s | ", namePlace);

				//printf("Name: %s\n", namePlace);
				//printf("ID: %d\n", *IDPlace);
				//printf("Star: ");
				for (int whichStar = 1; whichStar <= *starPlace; whichStar++)
				{
					fprintf(new, "★");
				}
				fprintf(new, " | ");
				//printf("Comment: %s\n", commentPlace);

				fprintf(new, "%s", commentPlace);

				fprintf(new, "\n");
			}
		}
		fprintf(new, "\nHave a nice day!");

		free(IDPlace);
		free(starPlace);
		fclose(new);
		printf("File created!\n");
	}
	system("pause");
}