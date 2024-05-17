#ifndef header_h
#define header_h
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

extern struct WaitingList *WL;

// Prosedur untuk membuat list station kosong.
void createStation();

// Prosedur untuk menampilkan jenis mobil.
void tampilkanJenisMobil();

// Prosedur untuk menambah mobil kedalam list.
void tambahAntrian();

// Prosedur untuk inisialisasi awal program
void initialization(char *modifiedDate);

// Prosedur untuk lompat waktu
void lompatWaktu(char *modifiedDate, struct tm *gmTime);

#endif