#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "bar.h"
#include "data.h"

long long int* IDCounter;
extern void viewMenu(struct eachData* start);
extern struct eachData* addMenu(struct eachData* start);
struct eachData* start;
extern void exportMenu(struct eachData* start);
extern struct eachData* deleteMenu(struct eachData* start);
extern void getID();
extern void saveID();
struct eachData* getMovieFile();
extern void saveMovieFile();

void menu()
{
	IDCounter = (long long int*) malloc(sizeof(long long int));
	//*IDCounter = 0;
	getID();
	//printf("We heard that the ID is: %lld\n", *IDCounter);
	//system("pause");

	start = getMovieFile();

	char selects[5][1000];
	memset(selects, '\0', sizeof(char)*5*1000);
	add(selects, "1", 5);
	add(selects, "2", 5);
	add(selects, "3", 5);
	add(selects, "4", 5);
	add(selects, "quit", 5);
	
	/*for (int whichOne = 0; whichOne < 5; whichOne++)
	{
		printf("%s\n", selects[whichOne]);
	}
	system("pause");*/
	
	char inputSelection[1000];
	memset(inputSelection, '\0', sizeof(inputSelection));
	while (barExist(inputSelection, selects, 5) == -1)
	{
		system("cls");
		if (locale == 1)
		{
			printf("��ã�\n");
			printf("����һ�����װ��IMDb��������ϰ������������һЩ��Ӱ�����ƺ��������(1-10)���鿴��ɾ����������Щ����\n");
			//printf("�����ݽ��������ڴ棩\n");
			printf("1) �鿴\n");
			printf("2) ���\n");
			printf("3) ɾ��\n");
			printf("4) ���Ϊmd�ļ�\n");
			printf("\n\nVersion: 1.1\n");
			printf("- By AngeloHYang, https://angelohyang.github.io/, 2019��3��21�� \n���� quit ���˳�\n");
		}
		else if (locale == 2)
		{
			printf("Hello!\n");
			printf("This is a basic version of IMDb (coding practice), you may add some movies, comment and rate(1 - 10) them. You can also view, delete, export them.\n");
			//printf("Data will only be stored in the RAM\n");
			printf("1) View\n");
			printf("2) Add\n");
			printf("3) Delete\n");
			printf("4) Export to a MD file\n");
			printf("\n\nVersion: 1.1\n");
			printf("- By AngeloHYang, https://angelohyang.github.io/, 3/21/2019 \nInput quit to quit\n");
		}
		/*printf("The Bar: ");
		for (int whichOne = 0; whichOne <= 4; whichOne++)
		{
			printf(" *%s* ", selects[whichOne]);
		}*/
		gets_s(inputSelection, 1000);
		//printf("You have just input *%s*, so it shall be!\n", inputSelection);
		
		//system("pause");
		if (barExist(inputSelection, selects, 5) != -1)
		{
			if (barExist(inputSelection, selects, 5) == 0)
			{
				viewMenu(start);
			}
			else if (barExist(inputSelection, selects, 5) == 1)
			{
				start = addMenu(start);
			}
			else if (barExist(inputSelection, selects, 5) == 2)
			{
				start = deleteMenu(start);
			}
			else if (barExist(inputSelection, selects, 5) == 3)
			{
				exportMenu(start);
			}
			else if (barExist(inputSelection, selects, 5) == 4)
			{
				saveID();
				saveMovieFile();
				break;
			}
			memset(inputSelection, '\0', sizeof(inputSelection));
		}
	}
	


}