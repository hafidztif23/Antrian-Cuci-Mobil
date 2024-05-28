#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#include"header.h"

WaitingList *WL = NULL;
Station washingStations[MAX_STATION];
Station dryingStations[MAX_STATION];

void createStation() {
	for (int i = 0; i < MAX_STATION; i++){
		washingStations[i].processing = NULL;
	}
	
	for (int i = 0; i < MAX_STATION; i++){
		dryingStations[i].processing = NULL;
	}
}

void showCarType() {
	printf("======================================================\n");
	printf("||                  JENIS MOBIL A                   ||\n");
	printf("||      (Waktu pencucian kurang lebih 50 menit)     ||\n");
	printf("======================================================\n");
	printf("|| - KIA Picanto                                    ||\n");
	printf("|| - Daihatsu Ceria                                 ||\n");
	printf("|| - Suzuki Karimun                                 ||\n");
	printf("|| - Toyota Yaris                                   ||\n");
	printf("||                                                  ||\n");
	printf("||   Dan Sejenisnya...                              ||\n");
	printf("||                                                  ||\n");
	printf("======================================================\n\n");
	
	printf("======================================================\n");
	printf("||                  JENIS MOBIL B                   ||\n");
	printf("||      (Waktu pencucian kurang lebih 60 menit)     ||\n");
	printf("======================================================\n");
	printf("|| - Toyota Avanza                                  ||\n");
	printf("|| - Honda Freed                                    ||\n");
	printf("|| - Suzuki Ertiga                                  ||\n");
	printf("||                                                  ||\n");
	printf("||   Dan Sejenisnya...                              ||\n");
	printf("||                                                  ||\n");
	printf("======================================================\n\n");
	
	printf("======================================================\n");
	printf("||                  JENIS MOBIL C                   ||\n");
	printf("||      (Waktu pencucian kurang lebih 80 menit)     ||\n");
	printf("======================================================\n");
	printf("|| - Metromini                                      ||\n");
	printf("|| - Truk                                           ||\n");
	printf("||                                                  ||\n");
	printf("||   Dan Sejenisnya...                              ||\n");
	printf("||                                                  ||\n");
	printf("======================================================\n\n");
}

void status(char *modifiedDate, struct WaitingList *WL, Station washingStations[MAX_STATION], Station dryingStations[MAX_STATION]){
	char car1[50];
	char car2[50];
	if (washingStations[0].processing == NULL && washingStations[1].processing == NULL){
		printf("======================================================\n");
		printf("||                 STASIUN BASAH                    ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("||        Kosong         ||         Kosong          ||\n");
		printf("======================================================\n\n");
	} else if (washingStations[0].processing != NULL && washingStations[1].processing == NULL){
		printf("======================================================\n");
		printf("||                 STASIUN BASAH                    ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("|| Plat Nomor: %s  ||         Kosong          ||\n", washingStations[0].processing->plate);
		printf("|| Tipe Mobil: %c         ||=========================||\n", washingStations[0].processing->type);
		printf("|| Sisa waktu: %d menit  ||                           \n", washingStations[0].processing->washingTime);
		printf("===========================\n\n");
	} else if (washingStations[0].processing == NULL && washingStations[1].processing != NULL){
		printf("======================================================\n");
		printf("||                 STASIUN BASAH                    ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("||        Kosong         || Plat Nomor: %s    ||\n", washingStations[1].processing->plate);
		printf("=========================|| Tipe Mobil: %c           ||\n", washingStations[1].processing->type);
		printf("                         || Sisa waktu: %d menit    ||\n", washingStations[1].processing->washingTime);
		printf("                         =============================\n\n");
	} else {
		printf("======================================================\n");
		printf("||                 STASIUN BASAH                    ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("|| Plat Nomor: %s  || Plat Nomor: %s    ||\n", washingStations[0].processing->plate, washingStations[1].processing->plate);
		printf("|| Tipe Mobil: %c         || Tipe Mobil: %c           ||\n", washingStations[0].processing->type, washingStations[1].processing->type);
		printf("|| Sisa waktu: %d menit  || Sisa waktu: %d menit    ||\n", washingStations[0].processing->washingTime, washingStations[1].processing->washingTime);
		printf("======================================================\n\n");
	}
	
	if (dryingStations[0].processing == NULL && dryingStations[1].processing == NULL){
		printf("======================================================\n");
		printf("||               STASIUN PENGERING                  ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("||        Kosong         ||         Kosong          ||\n");
		printf("======================================================\n\n");
	} else if (dryingStations[0].processing != NULL && dryingStations[1].processing == NULL){
		printf("======================================================\n");
		printf("||               STASIUN PENGERING                  ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("|| Plat Nomor: %s  ||         Kosong          ||\n", dryingStations[0].processing->plate);
		printf("|| Tipe Mobil: %c         ||=========================||\n", dryingStations[0].processing->type);
		printf("|| Sisa waktu: %d menit  ||                           \n", dryingStations[0].processing->dryingTime);
		printf("===========================\n\n");
	} else if (dryingStations[0].processing == NULL && dryingStations[1].processing != NULL){
		printf("======================================================\n");
		printf("||               STASIUN PENGERING                  ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("||        Kosong         || Plat Nomor: %s    ||\n", dryingStations[1].processing->plate);
		printf("=========================|| Tipe Mobil: %c           ||\n", dryingStations[1].processing->type);
		printf("                         || Sisa waktu: %d menit    ||\n", dryingStations[1].processing->dryingTime);
		printf("                         =============================\n\n");
	} else {
		printf("======================================================\n");
		printf("||               STASIUN PENGERING                  ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("|| Plat Nomor: %s  || Plat Nomor: %s    ||\n", dryingStations[0].processing->plate, dryingStations[1].processing->plate);
		printf("|| Tipe Mobil: %c         || Tipe Mobil: %c           ||\n", dryingStations[0].processing->type, dryingStations[1].processing->type);
		printf("|| Sisa waktu: %d menit  || Sisa waktu: %d menit    ||\n", dryingStations[0].processing->dryingTime, dryingStations[1].processing->dryingTime);
		printf("======================================================\n\n");
	}
	
	if (WL->queue == NULL){
		printf("============================\n");
		printf("||      WAITING LIST      ||\n");
		printf("============================\n");
		printf("||  1  ||     Kosong      ||\n");
		printf("============================\n\n");
	} else {
		printf("======================================================\n");
		printf("||                   WAITING LIST                   ||\n");
		printf("======================================================\n");
		
		int i = 1;
		char str[50];
		struct Car *current = WL->queue;
		while (current != NULL){
			strcpy(str, current->arrivalTime);
			size_t len = strlen(str);
    		if (len > 0 && str[len - 1] == '\n'){
        			str[len - 1] = '\0';
    		}
			printf("||      || Plat Nomor   : %s                  ||\n", current->plate);
			printf("||   %d  || Tipe Mobil   : %c                         ||\n", i, current->type);
			printf("||      || Waktu Datang : %s  ||\n", str);
			printf("======================================================\n");
			i++;
			current = current->next;
		}
//		printf("||  1  ||     Kosong      ||\n");
//		printf("============================\n");
	}
}
void addQueue(char *modifiedDate) {
	
	int i, j, number, lower, upper = 0;
	char input, inputUp;
	char plate[10];
	char *time1;
	bool valid = false;
	Car *car = (Car *) malloc (sizeof(Car));
	while(!valid){
		system("cls");
		fflush(stdin);
		printf("Silakan pilih jenis mobil anda: \n\n");
		showCarType();
		printf("\n Pilihan (A, B, atau C): ");
		input = getchar();
		if (input == 'a' || input == 'A'){
			// Memilih tipe A
			// Lakukan randomisasi sesuai estimasi pengerjaan mobil tipe tertentu untuk waktu pengerjaan
			lower = 34;
			upper = 37;
			srand(time(NULL));
			number = (rand() % (upper - lower + 1) + lower);
			car->washingTime = number;
			lower = 13;
			upper = 17;
			number = (rand() % (upper - lower + 1) + lower);
			car->dryingTime = number;
			car->type = 'A';
			time1 = strdup(modifiedDate);
			car->arrivalTime = time1;
			valid = true;
		} else if (input == 'b' || input == 'B'){
			// Memilih tipe B
			// Lakukan randomisasi sesuai estimasi pengerjaan mobil tipe tertentu untuk waktu pengerjaan
			lower = 43;
			upper = 47;
			srand(time(NULL));
			number = (rand() % (upper - lower + 1) + lower);
			car->washingTime = number;
			lower = 13;
			upper = 17;
			number = (rand() % (upper - lower + 1) + lower);
			car->dryingTime = number;
			car->type = 'B';
			time1 = strdup(modifiedDate);
			car->arrivalTime = time1;
			valid = true;
		} else if (input == 'c' || input == 'C' ){
			// Memilih tipe C
			// Lakukan randomisasi sesuai estimasi pengerjaan mobil tipe tertentu untuk waktu pengerjaan
			lower = 63;
			upper = 67;
			srand(time(NULL));
			number = (rand() % (upper - lower + 1) + lower);
			car->washingTime = number;
			lower = 13;
			upper = 17;
			number = (rand() % (upper - lower + 1) + lower);
			car->dryingTime = number;
			car->type = 'C';
			time1 = strdup(modifiedDate);
			car->arrivalTime = time1;
			valid = true;
		} else {
			// Tidak valid
			printf("Mohon masukkan opsi yang valid.");
			Sleep(2000);
			valid = false;
		}
	}
	valid = false;
	while (!valid){
		inputUp = toupper(input);
		printf(" Tipe mobil yang dipilih: %c\n\n", inputUp);
		fflush(stdin);
		printf(" Masukkan Plat Nomor (Maksimal 7 Karakter): ");
		fgets(plate, sizeof(plate), stdin);

    	// Menghapus karakter newline dari input
    	plate[strcspn(plate, "\n")] = '\0';
    
    	// Hapus spasi untuk validasi
    	char *newStr = (char *)malloc(strlen(plate) + 1);
    	for (i = 0; plate[i]; i++) {
        	if (plate[i] != ' ') {
            	newStr[j++] = plate[i];
        	}
    	}
    	newStr[j] = '\0';
		if (strlen(newStr) > 7){
			printf("Plat nomor melebihi 7 karakter!\n");
			valid = false;
		} else {
			valid = true;
		}
	}
	strcpy(car->plate, plate);
	car->next = NULL;

	
//	Lakukan proses konfirmasi pembayaran disini sebelum menambahkan ke stasiun atau waiting list
//	konfirmasiPembayaran() {
//	
//	
//	}



	int l;
	for (l = 0; l < MAX_STATION; l++) {
    	if (washingStations[l].processing == NULL) {
        	washingStations[l].processing = car;
        	time1 = strdup(modifiedDate);
			washingStations[l].processing->processedTime = time1;
        	printf("Mobil diproses di stasiun pencucian %d\n", l + 1);
        	break;
    	}
	}
	
	if (l == MAX_STATION) {
    	if (WL->queue == NULL) {
        	WL->queue = car;
    	} else {
        	struct Car *current = WL->queue;
        	while (current->next != NULL) {
            	current = current->next;
        	}
        	current->next = car;
    	}
	}
}

void insertFromWaitingList(char *modifiedDate, int totalProcessingTime, struct tm *gmTime) {
	struct tm *temp = gmTime;
	char *time1;
	temp->tm_min += totalProcessingTime;
	time_t tempTime1 = mktime(temp);
	time1 = ctime(&tempTime1);
	
    if (WL->queue != NULL) {
    	for (int i = 0; i < MAX_STATION; i++) {
    		if (washingStations[i].processing == NULL) {
    			washingStations[i].processing = WL->queue;
    			time1 = strdup(modifiedDate);
				washingStations[i].processing->processedTime = time1;
    			WL->queue = WL->queue->next;
			}
		}
	}
}

void isDoneAlert(int i, char *modifiedDate, struct tm *gmTime) {
	char *finishTime;
	int totalProcessingTime = dryingStations[i].processing->washingTime + dryingStations[i].processing->dryingTime;
	gmTime->tm_min += totalProcessingTime;
	time_t modifiedTime = mktime(gmTime);
    modifiedDate = ctime(&modifiedTime);
    finishTime = modifiedDate;
    
	printf("\nMobil dengan plat nomor %s bertipe %c telah selesai dicuci.\n", dryingStations[i].processing->plate, dryingStations[i].processing->type);
	printf("Waktu kedatangan   :   %s", dryingStations[i].processing->arrivalTime);
	printf("Waktu diproses     :   %s", dryingStations[i].processing->processedTime);
	printf("Waktu selesai      :   %s\n\n", finishTime);
	
	gmTime->tm_min -= totalProcessingTime;
	time_t modifiedTime1 = mktime(gmTime);
    modifiedDate = ctime(&modifiedTime1);
	
}

void insertToDryer(int j, int drying, char* modifiedDate, struct tm *gmTime) {
	for (int i = 0; i < MAX_STATION; i++) {
		if (dryingStations[i].processing == NULL) {
			dryingStations[i].processing = washingStations[j].processing;
			printf("Mobil memasuki drying station.\n");
			if (dryingStations[i].processing->dryingTime <= drying) {
				dryingStations[i].processing->usedTime += dryingStations[i].processing->dryingTime;
				isDoneAlert(i, modifiedDate, gmTime);
				dryingStations[i].processing->dryingTime = 0;
				dryingStations[i].processing = NULL;
				break;
			} else {
				dryingStations[i].processing->washingTime -= drying;
				dryingStations[i].processing->usedTime += drying;
				break;
			}
		} else {
			if (dryingStations[i].processing->dryingTime <= drying) {
				dryingStations[i].processing->usedTime += dryingStations[i].processing->dryingTime;
				isDoneAlert(i, modifiedDate, gmTime);
				drying -= dryingStations[i].processing->dryingTime;
				dryingStations[i].processing->dryingTime = 0;
				dryingStations[i].processing = NULL;
			} else {
				dryingStations[i].processing->washingTime -= drying;
				dryingStations[i].processing->usedTime += drying;
			}
		}
	}
}

void timeLeap(char *modifiedDate, struct tm *gmTime) {
    int inputHour, inputMinute, minute, remainingMinute, totalMinute, totalProcessingTime, temp, temp1;
    bool valid = true;
    struct Car *current = NULL;

    printf("Waktu sekarang: %s\n\n", modifiedDate);
    printf("Masukkan berapa jam untuk di lompati: ");
    fflush(stdin);
    scanf("%d", &inputHour);
    printf("Masukkan berapa menit untuk di lompati: ");
    fflush(stdin);
    scanf("%d", &inputMinute);
    minute = (inputHour * 60) + inputMinute;
    remainingMinute = minute;
    totalMinute = 0;

    while (remainingMinute > 0 && valid) {
        int usedMinute = 0; // Menyimpan menit yang digunakan dalam iterasi ini
        valid = false; // Reset valid flag

        // Process washing stations first
        for (int i = 0; i < MAX_STATION; i++) {
            if (washingStations[i].processing != NULL) {
                valid = true;
                totalProcessingTime = washingStations[i].processing->washingTime + washingStations[i].processing->dryingTime;
                if (washingStations[i].processing->washingTime <= remainingMinute) {
                    temp = washingStations[i].processing->washingTime;
                    washingStations[i].processing->usedTime += washingStations[i].processing->washingTime;
                    insertToDryer(i, remainingMinute - washingStations[i].processing->washingTime, modifiedDate, gmTime);
                    washingStations[i].processing->washingTime = 0;
                    washingStations[i].processing = NULL;
                    if (WL->queue != NULL) {
                        insertFromWaitingList(modifiedDate, totalProcessingTime, gmTime);
                    }
                } else {
                    washingStations[i].processing->washingTime -= remainingMinute;
                    washingStations[i].processing->usedTime += remainingMinute;
                    temp = remainingMinute;
                }
                usedMinute = temp > usedMinute ? temp : usedMinute;
            }
        }

        remainingMinute -= usedMinute;
        totalMinute += usedMinute;
    }

    remainingMinute = minute - totalMinute; // Calculate remaining minutes for drying stations

    // Process drying stations with remaining minutes
    for (int i = 0; i < MAX_STATION; i++) {
        if (dryingStations[i].processing != NULL) {
            if (dryingStations[i].processing->dryingTime <= remainingMinute) {
                dryingStations[i].processing->usedTime += dryingStations[i].processing->dryingTime;
                isDoneAlert(i, modifiedDate, gmTime);
                dryingStations[i].processing->dryingTime = 0;
                dryingStations[i].processing = NULL;
            } else {
                dryingStations[i].processing->dryingTime -= remainingMinute;
                dryingStations[i].processing->usedTime += remainingMinute;
            }
        }
    }

    if (remainingMinute > 0) {
        gmTime->tm_min -= remainingMinute;
        time_t modifiedTime = mktime(gmTime);
        modifiedDate = ctime(&modifiedTime);
    }

    printf("Total minute: %d\n", totalMinute);
    gmTime->tm_min += minute;
    time_t modifiedTime = mktime(gmTime);
    modifiedDate = ctime(&modifiedTime);
    
    printf("Waktu terakhir: %s\n", modifiedDate);
}