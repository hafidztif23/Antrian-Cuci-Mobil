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

void tampilkanJenisMobil() {
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

void tambahAntrian() {
	
	int i, j, number, lower, upper = 0;
	char input, inputUp;
	char plate[10];
	bool valid = false;
	Car *car = (Car *) malloc (sizeof(Car));
	while(!valid){
		system("cls");
		fflush(stdin);
		printf("Silakan pilih jenis mobil anda: \n\n");
		tampilkanJenisMobil();
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

	
	if (washingStations[0].processing == NULL){
		washingStations[0].processing = car;
		printf("Triggered 1\n");
	} else if (washingStations[1].processing == NULL){
		washingStations[1].processing = car;
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

void lompatWaktu(char *modifiedDate, struct tm *gmTime) {
	system("cls");
	int inputHour, inputMinute, minute, remainingMinute;
	bool valid;
	struct Car *current = NULL;
	printf("Waktu sekarang: %s\n\n", modifiedDate);
	printf("Masukkan berapa jam untuk di lompati: ");
	fflush(stdin);
	scanf("%d", &inputHour);
	printf("Masukkan berapa menit untuk di lompati: ");
	fflush(stdin);
	scanf("%d", &inputMinute);
	gmTime->tm_hour = gmTime->tm_hour + inputHour;
	gmTime->tm_min = gmTime->tm_min + inputMinute;
	time_t modifiedTime = mktime(gmTime);
	modifiedDate = ctime(&modifiedTime);
	printf("Waktu menjadi: %s\n", modifiedDate);
	
	minute = (inputHour * 60) + inputMinute;
	
	for (int i = 0; i < MAX_STATION; i++) {
		valid = true;
		minute = (inputHour * 60) + inputMinute;
		if (washingStations[i].processing != NULL) {
			// Jika pengerjaan mobil selesai
			if (washingStations[i].processing->washingTime <= minute) {
				minute -= washingStations[i].processing->washingTime;
				remainingMinute = remainingMinute + minute;
				washingStations[i].processing = NULL;
			} else {
				washingStations[i].processing->washingTime = washingStations[i].processing->washingTime - minute;
				minute = 0;
			}
		}
	}

	
	if (remainingMinute > 0) {
        // Tambahkan sisa menit ke gmTime
        gmTime->tm_min += remainingMinute;
        time_t modifiedTime = mktime(gmTime);
        modifiedDate = ctime(&modifiedTime);
    }
    
    // Mengecek jika waiting list tidak kosong dan memasukkan node pertama pada waiting list kedalam stasiun kosong
    if (WL->queue != NULL) {
    	for (int i = 0; i < MAX_STATION; i++) {
    		if (washingStations[i].processing == NULL) {
    			washingStations[i].processing = WL->queue;
    			WL->queue = WL->queue->next;
			}
		}
	}
    
    printf("Waktu terakhir: %s\n", modifiedDate);
}


















