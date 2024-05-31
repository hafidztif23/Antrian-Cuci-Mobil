
#ifndef header_h
#define header_h
#define MAX_STATION 2

char *date;

typedef struct Car {
	char plate[10];
	char type;
	int washingTime;
	int dryingTime;
	int totalTime;
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

extern struct WaitingList *WLBasah;
extern struct WaitingList *WLKering;



// Prosedur untuk membuat list station kosong.
void createStation();

// Prosedur untuk menampilkan jenis mobil.
void showCarType();

// Prosedur untuk menambah mobil kedalam list.
void addQueue(char *modifiedDate);

// Prosedur untuk menampilkan detail mobil yang telah selesai dicuci dan menyimpan ke file Log_Selesai_Pencucian.txt
void isDoneAlert(int i, char *modifiedDate, struct tm *gmTime, int totalTime);

// Menampilkan isi file Log_Selesai_Pencucian.txt
void displayLog();

// Menampilkan status antrian dan waiting list saat ini
void status(char *modifiedDate, struct WaitingList *WL, Station washingStations[MAX_STATION], Station dryingStations[MAX_STATION]);

// Menyelesaikan satu task dalam satu stasiun
void selesaiPengerjaan(char *modifiedDate, struct tm *gmTime);

// Menyelesaikan satu task dalam stasiun cuci kering
void selesaiCuciKering(int index, char *modifiedDate, struct tm *gmTime);

// Menyelesaikan satu task dalam stasiun cuci basah
void selesaiCuciBasah(int index, char *modifiedDate, struct tm *gmTime);

// Prosedur untuk mencari mobil berdasarkan plat nomor
void searchCar(char *plate, struct tm *gmTime);

// Menampilkan detail semua mobil
void displayCarList(struct tm *gmTime);

void spaceToContinue();

// Untuk membatalkan antrian
void cancel(WaitingList *WL, char *modifiedDate);

// Untuk estimasi kapan mobil yang dicari akan dikerjakan
void Estimate(WaitingList *WL);

// Pembayaran ketika mobil akan dimasukkan kedalam antrian
void payment(WaitingList *WL);
void pay(int cost);

#endif
