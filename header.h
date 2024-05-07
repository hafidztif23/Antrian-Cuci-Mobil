#ifndef header_h
#define header_h
#define MAX_STATION 2


typedef struct Car {
	char plate;
	char type;
	struct Car *next;
}Car;

typedef struct Station {
	int id;
	Car *queue;
}Station;

Station stations[MAX_STATION];


#endif