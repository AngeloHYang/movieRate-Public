#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bar.h"
struct eachData
{
	long long int ID;
	char name[1000];
	int stars;
	char comment[10000];
	struct eachData* next;
};

int howManyMovies(struct eachData* start)
{
	int howMany = 0;
	if (start == NULL)
	{
		//printf("Start is NULL\n");
		return 0;
	}
	//printf("Start isn't NULL!\n");
	while (start->next != NULL)
	{
		howMany++;
		start = start->next;
	}
	howMany++;
	return howMany;
}

int byNameTellWhichOneMovie(char inputName[1000], struct eachData* start)
{
	int result = -1;
	deleteSpaceInTheEnd(inputName);
	for (int counter = 1; counter <= howManyMovies(start); counter++)
	{
		if (memcmp(inputName, start->name, 1000) == 0)
		{
			result = counter;
			break;
		}
		start = start->next;
	}
	return result;
}

struct eachData* addMovie(char inputName[1000], int inputStar, char inputComment[10000], struct eachData* start, long long int* IDCounter)
{
	//printf("**This is the process of adding movie!**\n");
	if (byNameTellWhichOneMovie(inputName, start) == -1)
	{
		//printf("The movie %s doesn't exist yet!\n", inputName);
		if (howManyMovies(start) == 0)
		{
			start = (struct eachData*) malloc(sizeof(struct eachData));
			memset(start->comment, '\0', sizeof(start->comment));
			memset(start->name, '\0', sizeof(start->name));
			start->next = NULL;
			memcpy(start->name, inputName, 1000);
			memcpy(start->comment, inputComment, 10000);
			start->stars = inputStar;
			(*IDCounter) = (*IDCounter) +1;
			start->ID = (*IDCounter);
			//printf("We just added something to start, that being\nname: %s\nstar: %d\nID:%lld\n\n", inputName, inputStar, start->ID);
			return start;
		}
		else
		{
			struct eachData* old = start;
			while (start->next != NULL)
			{
				start = start->next;
			}
			struct eachData*  new = (struct eachData*) malloc(sizeof(struct eachData));
			start->next = new;
			new->next = NULL;
			memset(new->name, '\0', sizeof(new->name));
			memset(new->comment, '\0', sizeof(new->comment));
			memcpy(new->name, inputName, 1000);
			memcpy(new->comment, inputComment, 10000);
			new->stars = inputStar;
			(*IDCounter) = (*IDCounter) + 1;
			new->ID = (*IDCounter);

			//printf("We just added something, that being\nname: %s\nstarts: %d\n\n", inputName, inputStar);
			return old;
		}
	}
}

struct eachData* deleteMovie(int whichOneMovie, struct eachData* start)
{
	struct eachData* new;
	if (whichOneMovie == 1)
	{
		new = start->next;
		free(start);
		return new;
	}
	else if (whichOneMovie == howManyMovies(start))
	{
		struct eachData* begin = start;
		for (int whichOne = 1; whichOne < whichOneMovie - 1; whichOne++)
		{
			start = start->next;
		}
		new = start->next;
		free(new);
		start->next = NULL;
		return begin;
	}
	else
	{
		struct eachData* begin = start;
		for (int whichOne = 1; whichOne < whichOneMovie - 1; whichOne++)
		{
			start = start->next;
		}
		new = start->next;
		start->next = start->next->next;
		free(new);
		return begin;
	}
}

int searchByWhichOneMovie(int whichOne, struct eachData* start, char namePlace[1000], long long int* IDPlace, int* starPlace, char commentPlace[10000])
{
	//printf("The adress of starPlace: %d\n", starPlace);
	//printf("The value of starPlace before anything: %d\n", *starPlace);
	//printf("\nStart searchByWhichOneMovie!\n");
	int result = 0;
	if (howManyMovies(start) >= whichOne)
	{
		result = 1;
		//printf("The movie number is within range!\n");
	}
	if (result == 1)
	{
		int counter = 1;
		while (counter < whichOne)
		{
			start = start->next;
			counter++;
		}
		memset(namePlace, '\0', sizeof(namePlace));
		strcpy_s(namePlace, sizeof(char) * 1000, start->name);
		*IDPlace = start->ID;
		memset(commentPlace, '\0', sizeof(commentPlace));
		strcpy_s(commentPlace, sizeof(char) * 10000, start->comment);
		//printf("There should be %d starts.\n", start->stars);
		*starPlace = start->stars;

		//printf("There should be %d starts. Once again, %d stars!\n", start->stars, *starPlace);

	}
	return result;
}

int byIDTellWhichOneMovie(long long int inputID, struct eachData* start)
{
	int whichOneIsIt = -1;
	char namePlace[1000];
	char commentPlace[10000];
	long long int* IDPlace = (long long int*) malloc(sizeof(long long int));
	int* starPlace = (int*) malloc(sizeof(int));

	for (int whichOne = 1; whichOne <= howManyMovies(start); whichOne++)
	{
		if (searchByWhichOneMovie(whichOne, start, namePlace, IDPlace, starPlace, commentPlace) == 1)
		{
			if (*IDPlace == inputID)
			{
				whichOneIsIt = whichOne;
				break;
			}
		}
	}
	free(IDPlace);
	free(starPlace);
	return whichOneIsIt;
}

int searchByNameMovie()
{
	return 0;
}



