#ifndef header_h
#define header_h
#define MAX_STATION 2

char *date;

typedef struct Car {
	char plate[10];
	char type;
	int processTime;
	struct Car *next;
}Car;

typedef struct WashingStation {
	int id;
	Car *processing;
}WashingStation;

typedef struct DryingStation {
	int id;
	Car *processing;
}DryingStation;

typedef struct WaitingList {
	Car *queue;
}WaitingList;

WashingStation washingStations[MAX_STATION];
DryingStation dryingStations[MAX_STATION];

extern struct WaitingList *WL;

// Prosedur untuk membuat list station kosong.
void createStation();

// Prosedur untuk menampilkan jenis mobil.
void tampilkanJenisMobil();

// Prosedur untuk menambah mobil kedalam list.
void tambahAntrian();


#endif