#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#include"header.h"
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
