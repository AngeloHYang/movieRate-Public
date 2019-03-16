/*
Things about 1) 2) 3) and quit
You can add bar items and compare input string with existing items with these functions below.
*/
#include <string.h>
int length(char* inputString)
{
	int result = 0;
	while (result < 1000 && inputString[result] != '\0')
	{
		result++;
	}
	return result;
}

int howManyItemsAlready(char bars[][1000], int limits)
{
	int howMany = 0;
	while (bars[howMany][0] != '\0' && howMany < limits)
	{
		howMany++;
	}
	return howMany;
}

void add(char bars[][1000], char* inputString, int limits)
{
	int AddTo = howManyItemsAlready(bars, limits);
	//printf("AddTo = %d, inputString = %s\n", AddTo, inputString);
	//system("pause");
	strcpy_s(bars[AddTo], 1000, inputString);
}

void deleteSpaceInTheEnd(char* inputString)
{
	int start = length(inputString);
	//printf("length(inputString): %d\n", length(inputString));
	while (start > 1)
	{
		if (inputString[start - 1] == 32)
		{
			inputString[start - 1] = '\0';
			start--;
		}
		else
		{
			break;
		}
		//printf("start: %d\n", start);
		//system("pause");
	}
}

int barExist(char *inputString, char twoDimensionalArray[][1000], int limits)
{
	int result = 0;
	deleteSpaceInTheEnd(inputString);
	for (int whichOne = 0; whichOne < howManyItemsAlready(twoDimensionalArray, limits); whichOne++)
	{
		if (strcmp(twoDimensionalArray[whichOne], inputString) == 0)
		{
			return whichOne;
		}	
	}
	return -1;
}