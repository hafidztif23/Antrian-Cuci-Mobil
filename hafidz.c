#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#include"header.h"

struct WaitingList *WL = NULL;

void createStation() {
	for (int i = 0; i < MAX_STATION; i++){
		washingStations[i].processing = NULL;
	}
	
	for (int i = 0; i < MAX_STATION; i++){
		dryingStations[i].processing = NULL;
	}
}

void showCarType() {
	printf("Jenis Mobil A (Waktu Pencucian kurang lebih 50 Menit)\n");
	printf("- KIA Picanto\n");
	printf("- Daihatsu Ceria\n");
	printf("- Suzuki Karimun\n");
	printf("- Toyota Yaris\n");
	printf("  Dan Sejenisnya...\n");
	
	printf("\nJenis Mobil B (Waktu Pencucian kurang lebih 60 Menit)\n");
	printf("- Toyota Avanza\n");
	printf("- Honda Freed\n");
	printf("- Suzuki Ertiga\n");
	printf("  Dan Sejenisnya...\n");
	
	printf("\nJenis Mobil C (Waktu Pencucian kurang lebih 80 Menit)\n");
	printf("- Metromini\n");
	printf("- Truk\n");
	printf("  Dan Sejenisnya...\n");
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
		printf("Tipe mobil yang dipilih: %c\n\n", inputUp);
		fflush(stdin);
		printf("Masukkan Plat Nomor (Maksimal 7 Karakter): ");
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



// To fix

//	for (int i = 0; i < MAX_STATION; i++) {
//		if (washingStations[i].processing == NULL){
//			washingStations[i].processing = car;
//			washingStations[i].processing->processedTime = modifiedDate;
//			printf("Triggered %d\n", i+1);
//			break;
//		} else {
//			printf("Triggered 3\n");
//			if (WL->queue == NULL){
//				printf("Triggered 4\n");
//				WL->queue = car;
//			} else {
//				printf("Triggered 5\n");
//				struct Car *current = WL->queue;
//        		while (current->next != NULL) {
//        			printf("%s\n", current->plate);
//            		current = current->next;
//        		}
//        		current->next = car;
//        	}
//		}
//	}
	
	if (washingStations[0].processing == NULL){
		washingStations[0].processing = car;
		time1 = strdup(modifiedDate);
		washingStations[0].processing->processedTime = time1;
		printf("Triggered 1\n");
	} else if (washingStations[1].processing == NULL){
		washingStations[1].processing = car;
		time1 = strdup(modifiedDate);
		washingStations[0].processing->processedTime = time1;
		printf("Triggered 2\n");
	} else {
		printf("Triggered 3\n");
		if (WL->queue == NULL){
			printf("Triggered 4\n");
			WL->queue = car;
		} else {
			printf("Triggered 5\n");
			struct Car *current = WL->queue;
        	while (current->next != NULL) {
        		printf("%s\n", current->plate);
            	current = current->next;
        	}
        	current->next = car;
		}
	}
}

void insertFromWaitingList(char *modifiedDate) {
	char *time1;
    if (WL->queue != NULL) {
    	for (int i = 0; i < MAX_STATION; i++) {
    		if (washingStations[i].processing == NULL) {
    			washingStations[i].processing = WL->queue;
    			time1 = strdup(modifiedDate);
				washingStations[0].processing->processedTime = time1;
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
	int inputHour, inputMinute, minute, remainingMinute, totalMinute, exceedTime, totalProcessingTime, temp, temp1;
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
	exceedTime = 0;
	
    remainingMinute = minute;

    do {
        int usedMinute = 0; // Menyimpan menit yang digunakan dalam iterasi ini
        for (int i = 0; i < MAX_STATION; i++) {
            if (washingStations[i].processing != NULL) {
            	printf("washingStation[%d].processing tidak NULL\n", i);
            	totalProcessingTime = washingStations[i].processing->washingTime + washingStations[i].processing->dryingTime;
            	if (minute > totalProcessingTime) {
            		exceedTime = minute - totalProcessingTime;
				}
				printf("Total Processing Time: %d\n", totalProcessingTime);
				printf("Minute: %d\n", minute);
				printf("Exceed Time: %d\n", exceedTime);
            	
            	// Jika waktu cuci mobil lebih sedikit dari menit tersisa, mobil selesai dicuci basah
                if (washingStations[i].processing->washingTime <= remainingMinute) {
                	printf("washingStation[%d].processing->washingTime = %d, remainingMinute = %d\n", i, washingStations[i].processing->washingTime, remainingMinute);
                    temp = washingStations[i].processing->washingTime;
                    temp1 = remainingMinute - washingStations[i].processing->washingTime;
                    // Jika temp lebih besar dari usedMinute, usedMinute diisi temp
                    // Jika temp tidak lebih besar dari usedMinute, usedMinute diisi usedMinute
                    usedMinute = temp > usedMinute ? temp : usedMinute;
                    
                    // Memasukkan ke stasiun pengering dengan parameter i = index washing station, temp1 = waktu tersedia untuk pengering, dan waktu saat ini.
                    washingStations[i].processing->usedTime += washingStations[i].processing->washingTime;
                    insertToDryer(i, temp1, modifiedDate, gmTime);
                    washingStations[i].processing->washingTime = 0;
                    washingStations[i].processing = NULL;
                    
                    // Jika waiting list tidak kosong, masukkan node pertama pada waiting list kedalam stasiun kosong
                    if (WL->queue == NULL) {
                    	printf("Waiting list kosong\n");
					} else {
						insertFromWaitingList(modifiedDate);
						printf("Mengambil mobil dari waiting list\n");
					}
                    
                // Jika waktu cuci mobil lebih besar dari menit tersisa, waktu cuci tersebut di kurangi menit tersisa    
                } else {
                	printf("washingStation[%d].processing->washingTime lebih besar dari remainingMinute\n");
                    washingStations[i].processing->washingTime -= remainingMinute;
                    washingStations[i].processing->usedTime += remainingMinute;
                    usedMinute = remainingMinute;
                    totalMinute += usedMinute;
                }
            } else {
            	printf("Semua stasiun kosong\n");
            	valid = false;
            	break;
			}
        }
        remainingMinute -= usedMinute;
    } while (remainingMinute > 0 && valid == true);
    
    // Cek jika stasiun kosong, namun drying station terisi
    if (!valid) {
    	for (int i = 0; i < MAX_STATION; i++) {
    		if (dryingStations[i].processing != NULL) {
    			if (dryingStations[i].processing->dryingTime <= remainingMinute) {
					dryingStations[i].processing->usedTime += dryingStations[i].processing->dryingTime;
					isDoneAlert(i, modifiedDate, gmTime);
					dryingStations[i].processing->dryingTime = 0;
					dryingStations[i].processing = NULL;
				} else {
					dryingStations[i].processing->washingTime -= remainingMinute;
					dryingStations[i].processing->usedTime += remainingMinute;
				}
			}
		}
	}
    
    if (exceedTime > 0) {
    	gmTime->tm_min -= exceedTime;
    	time_t modifiedTime = mktime(gmTime);
    	modifiedDate = ctime(&modifiedTime);
	}

	printf("Total minute: %d\n", totalMinute);
    gmTime->tm_min += minute;
    time_t modifiedTime = mktime(gmTime);
    modifiedDate = ctime(&modifiedTime);
	
    printf("Waktu terakhir: %s\n", modifiedDate);
}

void searchCar(char *plate) {
	Car *current;
	int found = 0;

	// Cari di washing stations
	for (int i = 0; i < MAX_STATION; i++) {
		if (washingStations[i].processing != NULL && strcmp(washingStations[i].processing->plate, plate) == 0) {
			found = 1;
			printf("Mobil ditemukan.\n");
			printf("Plat nomor : %s\n", washingStations[i].processing->plate);
			printf("Jenis mobil : %c\n", washingStations[i].processing->type);
			printf("Posisi mobil : Stasiun Cuci %d\n", i + 1);
			printf("Waktu pengerjaan : %d menit\n", washingStations[i].processing->washingTime + washingStations[i].processing->dryingTime);
			printf("Waktu kedatangan : %s", washingStations[i].processing->arrivalTime);
			printf("Waktu mulai pencucian : %s\n", washingStations[i].processing->processedTime);
			break;
		}
	}

	// Cari di drying stations
	if (!found) {
		for (int i = 0; i < MAX_STATION; i++) {
			if (dryingStations[i].processing != NULL && strcmp(dryingStations[i].processing->plate, plate) == 0) {
				found = 1;
				printf("Mobil ditemukan.\n");
				printf("Plat nomor : %s\n", dryingStations[i].processing->plate);
				printf("Jenis mobil : %c\n", dryingStations[i].processing->type);
				printf("Posisi mobil : Stasiun Pengering %d\n", i + 1);
				printf("Waktu pengerjaan : %d menit\n", dryingStations[i].processing->washingTime + dryingStations[i].processing->dryingTime);
				printf("Waktu kedatangan : %s", dryingStations[i].processing->arrivalTime);
				printf("Waktu mulai pencucian : %s\n", dryingStations[i].processing->processedTime);
				break;
			}
		}
	}

	// Cari di waiting list
	if (!found) {
		current = WL->queue;
		while (current != NULL) {
			if (strcmp(current->plate, plate) == 0) {
				found = 1;
				printf("Mobil ditemukan.\n");
				printf("Plat nomor : %s\n", current->plate);
				printf("Jenis mobil : %c\n", current->type);
				printf("Posisi mobil : Waiting List\n");
				printf("Waktu pengerjaan : %d menit\n", current->washingTime + current->dryingTime);
				printf("Waktu kedatangan : %s", current->arrivalTime);
				printf("Waktu mulai pencucian : Belum diproses\n");
				printf("Waktu selesai pencucian : Belum diproses\n");
				break;
			}
			current = current->next;
		}
	}

	if (!found) {
		printf("Mobil yang anda inputkan tidak ditemukan.\n");
	}
}

void displayCarList() {
	Car *current;
	time_t now;
	struct tm *gmTime;
	now = time(NULL);
	gmTime = gmtime(&now);

	// Tampilkan mobil di washing stations
	for (int i = 0; i < MAX_STATION; i++) {
		if (washingStations[i].processing != NULL) {
			printf("Mobil di Stasiun Cuci %d:\n", i + 1);
			printf("Plat nomor : %s\n", washingStations[i].processing->plate);
			printf("Jenis mobil : %c\n", washingStations[i].processing->type);
			printf("Posisi mobil : Stasiun Cuci %d\n", i + 1);
			printf("Waktu pengerjaan : %d menit\n", washingStations[i].processing->washingTime + washingStations[i].processing->dryingTime);
			printf("Waktu kedatangan : %s", washingStations[i].processing->arrivalTime);
			printf("Waktu mulai pencucian : %s\n", washingStations[i].processing->processedTime);
			// Kalkulasi waktu selesai pencucian berdasarkan waktu mulai dan waktu pengerjaan
			time_t processedTime = mktime(gmTime) + (washingStations[i].processing->washingTime + washingStations[i].processing->dryingTime) * 60;
			printf("Waktu selesai pencucian : %s\n", ctime(&processedTime));
		}
	}

	// Tampilkan mobil di drying stations
	for (int i = 0; i < MAX_STATION; i++) {
		if (dryingStations[i].processing != NULL) {
			printf("Mobil di Stasiun Pengering %d:\n", i + 1);
			printf("Plat nomor : %s\n", dryingStations[i].processing->plate);
			printf("Jenis mobil : %c\n", dryingStations[i].processing->type);
			printf("Posisi mobil : Stasiun Pengering %d\n", i + 1);
			printf("Waktu pengerjaan : %d menit\n", dryingStations[i].processing->washingTime + dryingStations[i].processing->dryingTime);
			printf("Waktu kedatangan : %s", dryingStations[i].processing->arrivalTime);
			printf("Waktu mulai pencucian : %s\n", dryingStations[i].processing->processedTime);
			// Kalkulasi waktu selesai pencucian berdasarkan waktu mulai dan waktu pengerjaan
			time_t processedTime = mktime(gmTime) + (dryingStations[i].processing->washingTime + dryingStations[i].processing->dryingTime) * 60;
			printf("Waktu selesai pencucian : %s\n", ctime(&processedTime));
		}
	}

	// Tampilkan mobil di waiting list
	current = WL->queue;
	while (current != NULL) {
		printf("Mobil di Waiting List:\n");
		printf("Plat nomor : %s\n", current->plate);
		printf("Jenis mobil : %c\n", current->type);
		printf("Posisi mobil : Waiting List\n");
		printf("Waktu pengerjaan : %d menit\n", current->washingTime + current->dryingTime);
		printf("Waktu kedatangan : %s", current->arrivalTime);
		printf("Waktu mulai pencucian : Belum diproses\n");
		printf("Waktu selesai pencucian : Belum diproses\n");
		current = current->next;
	}
}
