
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

extern Station washingStations[MAX_STATION];
extern Station dryingStations[MAX_STATION];

extern struct WaitingList *WL;

// Prosedur untuk membuat list station kosong.
void createStation();

// Prosedur untuk menampilkan jenis mobil.
void showCarType();

// Prosedur untuk menambah mobil kedalam list.
void addQueue(char *modifiedDate);

// Prosedur untuk memasukkan mobil list pertama dalam waiting list kedalam stasiun kosong
void insertFromWaitingList(char *modifiedDate, int totalProcessingTime, struct tm *gmTime);

// Prosedur untuk menampilkan detail mobil yang telah selesai dicuci
void isDoneAlert(int i, char *modifiedDate, struct tm *gmTime);

// Prosedur untuk memasukkan mobil kedalam stasiun pengering setelah selesai dicuci di stasiun cuci basah
void insertToDryer(int j, int drying, char* modifiedDate, struct tm *gmTime);

// Prosedur untuk lompat waktu
void timeLeap(char *modifiedDate, struct tm *gmTime);

void status(char *modifiedDate, struct WaitingList *WL, Station washingStations[MAX_STATION], Station dryingStations[MAX_STATION]);

// Prosedur untuk mencari mobil berdasarkan plat nomor
void searchCar(char *plate);

void displayCarList();

#endif
