#ifndef rizky_h
#define rizky_h
#define MAX_STATION 2

char *date;

typedef struct Car {
	char plate[10];
	char type;
	int washingTime;
	int dryingTime;
	int usedTime;
	char *arrivalTime;
	char *processedTime;
	struct Car *next;
}Car;

typedef struct Station {
	Car *processing;
}Station;

typedef struct WaitingList {
	Car *queue;
}WaitingList;

Station washingStations[MAX_STATION];
Station dryingStations[MAX_STATION];

//struct WaitingList *WL = NULL;

//WaitingList *WL = NULL; 
//extern struct WaitingList *WL;

void createList();
void cancel(WaitingList *WL, char *modifiedDate);
void Estimate(WaitingList *WL);
void payment(WaitingList *WL);
void pay(int cost);

#endif
