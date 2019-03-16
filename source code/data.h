struct eachData
{
	long long int ID;
	char name[1000];
	int stars;
	char comment[10000];
	struct eachData* next;
};

extern int howManyMovies(struct eachData* start);

extern int byNameTellWhichOneMovie(char inputName[1000], struct eachData* start);

extern struct eachData* addMovie(char inputName[1000], int inputStar, char inputComment[10000], struct eachData* start, long long int IDCounter);

extern int searchByWhichOneMovie(int whichOne, struct eachData* start, char namePlace[1000], long long int* IDPlace, int* starPlace, char commentPlace[10000]);

extern int byIDTellWhichOneMovie(long long int inputID, struct eachData* start);

extern struct eachData* deleteMovie(int whichOneMovie, struct eachData* start);