
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#include"header.h"


void searchCar(char *plate, char *modifiedDate, struct tm *gmTime) {
	system("cls");
	Car *current;
	int found = 0;

	// Cari di washing stations
	int i;
	for (i = 0; i < MAX_STATION; i++) {
		if (washingStations[i].processing != NULL && strcmp(washingStations[i].processing->plate, plate) == 0) {
			found = 1;
			printf("Mobil ditemukan. Berikut adalah rincian Mobil:\n");
			printf("Plat nomor : %s\n", washingStations[i].processing->plate);
			printf("Jenis mobil : %c\n", washingStations[i].processing->type);
			printf("Posisi mobil : Stasiun Basah %d\n", i + 1);
			printf("Waktu pengerjaan : %d menit\n", washingStations[i].processing->washingTime + washingStations[i].processing->dryingTime);
			printf("Waktu kedatangan : %s", washingStations[i].processing->arrivalTime);
			printf("Waktu mulai pencucian : %s", washingStations[i].processing->processedTime);
			// Kalkulasi waktu selesai pencucian berdasarkan waktu mulai dan waktu pengerjaan
			time_t modifiedTime = mktime(gmTime) + (washingStations[i].processing->washingTime + washingStations[i].processing->dryingTime) * 60;
			printf("Waktu selesai pencucian : %s\n", ctime(&modifiedTime));
		}
	}

	// Cari di drying stations
	if (!found) {
		for (i = 0; i < MAX_STATION; i++) {
			if (dryingStations[i].processing != NULL && strcmp(dryingStations[i].processing->plate, plate) == 0) {
				found = 1;
				printf("Mobil ditemukan. Berikut adalah rincian Mobil:\n");
				printf("Plat nomor : %s\n", dryingStations[i].processing->plate);
				printf("Jenis mobil : %c\n", dryingStations[i].processing->type);
				printf("Posisi mobil : Stasiun Pengering %d\n", i + 1);
				printf("Waktu pengerjaan : %d menit\n", dryingStations[i].processing->washingTime + dryingStations[i].processing->dryingTime);
				printf("Waktu kedatangan : %s", dryingStations[i].processing->arrivalTime);
				printf("Waktu mulai pencucian : %s", dryingStations[i].processing->processedTime);
				// Kalkulasi waktu selesai pencucian berdasarkan waktu mulai dan waktu pengerjaan
				time_t modifiedTime = mktime(gmTime) + (dryingStations[i].processing->washingTime + dryingStations[i].processing->dryingTime) * 60;
				printf("Waktu selesai pencucian : %s\n", ctime(&modifiedTime));
			}
		}
	}

	// Cari di waiting list
	if (!found) {
		i = 0;
		current = WLBasah->queue;
		while (current != NULL) {
			if (strcmp(current->plate, plate) == 0) {
				found = 1;
				printf("Mobil ditemukan. Berikut adalah rincian Mobil:\n");
				printf("Plat nomor : %s\n", current->plate);
				printf("Jenis mobil : %c\n", current->type);
				printf("Posisi mobil : Waiting List antrian ke-%d\n", i + 1);
				printf("Waktu pengerjaan : %d menit\n", current->washingTime + current->dryingTime);
				printf("Waktu kedatangan : %s", current->arrivalTime);
				printf("Waktu mulai pencucian : Belum diproses\n");
				printf("Waktu selesai pencucian : Belum diproses\n");
			}
			i++;
			current = current->next;
		}
	}

	if (!found) {
		printf("Mobil yang anda inputkan tidak ditemukan.\n");
	}
}

void displayCarList(char *modifiedDate, struct tm *gmTime) {
	system("cls");
	Car *current;
	int i;

	// Tampilkan mobil di washing stations
	for (i = 0; i < MAX_STATION; i++) {
		if (washingStations[i].processing != NULL) {
			printf("Mobil di Stasiun Cuci %d:\n", i + 1);
			printf("Plat nomor : %s\n", washingStations[i].processing->plate);
			printf("Jenis mobil : %c\n", washingStations[i].processing->type);
			printf("Posisi mobil : Stasiun Cuci %d\n", i + 1);
			printf("Waktu pengerjaan : %d menit\n", washingStations[i].processing->washingTime + washingStations[i].processing->dryingTime);
			printf("Waktu kedatangan : %s", washingStations[i].processing->arrivalTime);
			printf("Waktu mulai pencucian : %s", washingStations[i].processing->processedTime);
			// Kalkulasi waktu selesai pencucian berdasarkan waktu mulai dan waktu pengerjaan
			time_t modifiedTime = mktime(gmTime) + (washingStations[i].processing->washingTime + washingStations[i].processing->dryingTime) * 60;
			printf("Waktu selesai pencucian : %s\n", ctime(&modifiedTime));
		}
	}

	// Tampilkan mobil di drying stations
	for (i = 0; i < MAX_STATION; i++) {
		if (dryingStations[i].processing != NULL) {
			printf("Mobil di Stasiun Pengering %d:\n", i + 1);
			printf("Plat nomor : %s\n", dryingStations[i].processing->plate);
			printf("Jenis mobil : %c\n", dryingStations[i].processing->type);
			printf("Posisi mobil : Stasiun Pengering %d\n", i + 1);
			printf("Waktu pengerjaan : %d menit\n", dryingStations[i].processing->washingTime + dryingStations[i].processing->dryingTime);
			printf("Waktu kedatangan : %s", dryingStations[i].processing->arrivalTime);
			printf("Waktu mulai pencucian : %s", dryingStations[i].processing->processedTime);
			// Kalkulasi waktu selesai pencucian berdasarkan waktu mulai dan waktu pengerjaan
			time_t modifiedTime = mktime(gmTime) + (dryingStations[i].processing->washingTime + dryingStations[i].processing->dryingTime) * 60;
			printf("Waktu selesai pencucian : %s\n", ctime(&modifiedTime));
		}
	}

	// Tampilkan mobil di waiting list
	i = 0;
	current = WLBasah->queue;
	printf("Mobil di Waiting List:\n\n");
	while (current != NULL) {
		printf("Antrian ke-%d\n", i + 1);
		printf("Plat nomor : %s\n", current->plate);
		printf("Jenis mobil : %c\n", current->type);
		printf("Waktu pengerjaan : %d menit\n", current->washingTime + current->dryingTime);
		printf("Waktu kedatangan : %s", current->arrivalTime);
		printf("Waktu mulai pencucian : Belum diproses\n");
		printf("Waktu selesai pencucian : Belum diproses\n\n");
		i++;
		current = current->next;
	}
}

void spaceToContinue(){
	printf("\n\nTekan spasi untuk melanjutkan");
    while(getch() != ' '); // menunggu user menekan spasi untuk melanjutkan
    system("cls");
}
