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
		washingStations[i].id = i + 1;
		washingStations[i].processing = NULL;
	}
	
	for (int i = 0; i < MAX_STATION; i++){
		dryingStations[i].id = i + 1;
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
			lower = 48;
			upper = 53;
			srand(time(NULL));
			number = (rand() % (upper - lower + 1) + lower);
			car->processTime = number;
			car->type = 'A';
			valid = true;
		} else if (input == 'b' || input == 'B'){
			// Memilih tipe B
			// Lakukan randomisasi sesuai estimasi pengerjaan mobil tipe tertentu untuk waktu pengerjaan
			lower = 58;
			upper = 63;
			srand(time(NULL));
			number = (rand() % (upper - lower + 1) + lower);
			car->processTime = number;
			car->type = 'B';
			valid = true;
		} else if (input == 'c' || input == 'C' ){
			// Memilih tipe C
			// Lakukan randomisasi sesuai estimasi pengerjaan mobil tipe tertentu untuk waktu pengerjaan
			lower = 78;
			upper = 83;
			srand(time(NULL));
			number = (rand() % (upper - lower + 1) + lower);
			car->processTime = number;
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
	
	// Lakukan proses konfirmasi pembayaran disini sebelum menambahkan ke stasiun atau waiting list
	// konfirmasiPembayaran {
	
	
//	   }

	
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

void lompatWaktu {
	
}


















