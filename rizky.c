#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "rizky.h"

void createList()
{
    // Inisialisasi waiting list
    WaitingList *WL = (WaitingList*) malloc(sizeof(struct WaitingList));
    WL->queue = NULL;

    // Inisialisasi stasiun cuci dan kering
    int i;
    for (i = 0; i < MAX_STATION; i++) 
	{
        washingStations[i].processing = NULL;
        dryingStations[i].processing = NULL;
    }
}

// Untuk cancel antrian
void cancel(WaitingList *WL) 
{
	// Jika list kosong
    if (WL->queue == NULL) 
	{
        printf("Antrian kosong.\n");
        return;
    }

    char plate[20];
    char confirmation;
    printf("Masukan plat nomor kendaraan (A 123 B): ");
    scanf(" %[^\n]", plate);

    Car *prev = NULL;
    Car *current = WL->queue;

    // Untuk mencari kendaraang dengan plat nomor yang sama
    while (current != NULL) 
	{
		// Untuk memeriksa apakah plat nomor saat ini sama dengan yang di input user
        if (strcmp(current->plate, plate) == 0) 
		{
            // Tampilkan informasi lengkap tentang mobil
            printf("Informasi mobil:\n");
            printf("Plat Nomor: %s\n", current->plate);
            printf("Tipe: %c\n", current->type);
            printf("Waktu Cuci: %d\n", current->washingTime);
            printf("Waktu Kering: %d\n", current->dryingTime);
            printf("Waktu Digunakan: %d\n", current->usedTime);
            printf("Waktu Kedatangan: %s\n", current->arrivalTime);
            printf("Waktu Diproses: %s\n", current->processedTime);

            // Konfirmasi pembatalan
            printf("Apakah yakin ingin membatalkan antrian? (y/t): ");
            scanf(" %c", &confirmation);

            if (confirmation == 'y' || confirmation == 'Y') {
                // Jika kendaraan berada pada node pertama
                if (prev == NULL) {
                    WL->queue = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                printf("Antrian untuk mobil dengan plat %s telah dibatalkan.\n", plate);
            } else {
                printf("Pembatalan antrian dibatalkan.\n");
            }
            return;
        }
        prev = current;
        current = current->next;
    }
	// Jika tidak ada didalam list
    printf("Mobil dengan plat %s tidak ditemukan dalam antrian.\n", plate);
}

// Untuk estimate
void Estimate(WaitingList *WL) 
{
	// Jika list koksong
    if (WL == NULL || WL->queue == NULL) 
	{
        printf("Antrian kosong.\n");
        return;
    }
    
    char plate[20];
    printf("Masukan plat nomor kendaraan (A 123 B): ");
    scanf(" %[^\n]", plate);

    Car *current = WL->queue;
    // Untuk mencari kendaraang dengan plat nomor yang sama
    while (current != NULL) 
	{
		// Untuk memeriksa apakah plat nomor saat ini sama dengan yang di input user
        if (strcmp(current->plate, plate) == 0) 
		{
            // Tampilkan informasi lengkap tentang mobil
            printf("Informasi mobil:\n");
            printf("Plat Nomor: %s\n", current->plate);
            printf("Tipe: %c\n", current->type);
            printf("Waktu Cuci: %d menit\n", current->washingTime);
            printf("Waktu Kering: %d menit\n", current->dryingTime);
            printf("Waktu Digunakan: %d menit\n", current->usedTime);
            printf("Waktu Kedatangan: %s\n", current->arrivalTime);
            printf("Waktu Diproses: %s\n", current->processedTime);

            // Menghitung total waktu pengerjaan
            int totalProcessingTime = current->washingTime + current->dryingTime;
            printf("Estimasi waktu pengerjaan: %d menit\n", totalProcessingTime);
            return;
        }
        current = current->next;
    }

    printf("Mobil dengan plat %s tidak ditemukan dalam antrian.\n", plate);
}
