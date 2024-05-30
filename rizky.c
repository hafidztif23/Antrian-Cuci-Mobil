#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#include "header.h"

// Untuk cancel antrian
void cancel(WaitingList *WL, char* modifiedDate) 
{
	// Jika list kosong
    if (WL->queue == NULL) 
	{
        printf("Antrian kosong.\n");
        Sleep(2000);
        return;
    }

    char plate[20];
    char confirmation;
    printf("Masukan plat nomor kendaraan (A 123 B): ");
    scanf(" %[^\n]", plate);

    Car *prev = NULL;
    Car *current = WL->queue;
	system("cls");
    // Untuk mencari kendaraang dengan plat nomor yang sama
    while (current != NULL) 
	{
		// Untuk memeriksa apakah plat nomor saat ini sama dengan yang di input user
        if (strcmp(current->plate, plate) == 0) 
		{
            // Tampilkan informasi lengkap tentang mobil
            printf("Mobil terdapat dalam antrian\nInformasi mobil:\n");
            printf("Plat Nomor: %s\n", current->plate);
            printf("Jenis Mobil: %c\n", current->type);
            printf("Waktu Pengerjaan: %d menit\n", current->washingTime + current->dryingTime);
            printf("Waktu Kedatangan: %s", current->arrivalTime);
            printf("Waktu Mulai Pencucian: Belum Diproses\n");
            printf("Waktu Selesai Pencucian: Belum Diproses\n\n");

            // Konfirmasi pembatalan
            printf("Apakah yakin ingin membatalkan antrian? (y/t): ");
            scanf(" %c", &confirmation);

            if (confirmation == 'y' || confirmation == 'Y') 
			{
                // Jika kendaraan berada pada node pertama
                if (prev == NULL) 
				{
                    WL->queue = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                printf("Antrian untuk mobil dengan plat %s telah dibatalkan.\n", plate);
                Sleep(2000);
            } else {
                printf("Pembatalan antrian dibatalkan.\n");
                Sleep(2000);
            }
            return;
        }
        prev = current;
        current = current->next;
    }
	// Jika tidak ada didalam list
    printf("Mobil dengan plat %s tidak ditemukan dalam antrian.\n", plate);
    Sleep(2000);
}

// Untuk estimate
void Estimate(WaitingList *WL) 
{
    // Jika list kosong
    if (WL == NULL || WL->queue == NULL) 
	{
        printf("Antrian kosong.\n");
        Sleep(2000);
        return;
    }
    
    char plate[20];
    printf("Masukan plat nomor kendaraan (A 123 B): ");
    scanf(" %[^\n]", plate);

    Car *current = WL->queue;
    int position = 0; // Posisi mobil dalam antrian
    int totalWaitingTime = 0; // Total waktu tunggu hingga mobil tersebut diproses
	system("cls");
    // Untuk mencari kendaraan dengan plat nomor yang sama
    while (current != NULL) 
	{
        if (strcmp(current->plate, plate) == 0) 
		{
            // Tampilkan informasi lengkap tentang mobil
            printf("Mobil terdapat dalam antrian\nInformasi mobil:\n");
            printf("Plat Nomor: %s\n", current->plate);
            printf("Jenis Mobil: %c\n", current->type);
            printf("Waktu Pengerjaan: %d menit\n", current->washingTime + current->dryingTime);
            printf("Waktu Kedatangan: %s", current->arrivalTime);
            printf("Waktu Mulai Pencucian: Belum Diproses\n");
            printf("Waktu Selesai Pencucian: Belum Diproses\n\n");

            // Menghitung total waktu pengerjaan
            int totalProcessingTime = current->washingTime + current->dryingTime;
            printf("Estimasi waktu pengerjaan: %d menit\n", totalProcessingTime);

            // Menghitung estimasi waktu hingga mobil tersebut diproses
            printf("Estimasi waktu hingga mobil diproses: %d menit\n", totalWaitingTime);
            spaceToContinue();
            return;
        }
        // Tambahkan waktu pengerjaan dari mobil sebelumnya dalam antrian
        totalWaitingTime += current->washingTime + current->dryingTime;
        current = current->next;
        position++;
    }

    printf("Mobil dengan plat %s tidak ditemukan dalam antrian.\n", plate);
    spaceToContinue();
}

// bayar-bayar
void pay(int cost) 
{
    int amountPaid;
    printf("Total biaya(Rp): %d\n", cost);
    printf("Masukkan jumlah yang dibayar(Rp): ");
    scanf("%d", &amountPaid);
    
    if (amountPaid < cost) 
	{
        printf("Jumlah yang dibayar tidak cukup. Pembayaran gagal.\n");
        spaceToContinue();
        return;
    }

    int change = amountPaid - cost;
    printf("Pembayaran berhasil.\n");
    if (change > 0) 
	{
        printf("Kembalian: %d\n", change);
    }
    spaceToContinue();
}

void payment(WaitingList *WL) 
{
    if (WL->queue == NULL) 
    {
        printf("Antrian kosong.\n");
        Sleep(2000);
        return;
    }

    char plate[20];
    printf("Masukkan plat nomor kendaraan (A 123 B): ");
    scanf(" %[^\n]", plate);

    Car *current = WL->queue;
    system("cls");
    while (current != NULL)
    {
        if (strcmp(current->plate, plate) == 0) 
        {
            // Tampilkan informasi lengkap tentang mobil
            printf("Mobil terdapat dalam antrian\nInformasi mobil:\n");
            printf("Plat Nomor: %s\n", current->plate);
            printf("Jenis Mobil: %c\n", current->type);
            printf("Waktu Kedatangan: %s", current->arrivalTime);
            printf("Waktu Mulai Pencucian: Belum Diproses\n");
            printf("Waktu Selesai Pencucian: Belum Diproses\n\n");

            int cost = 0; // Inisialisasi biaya menjadi 0
            switch(current->type) // Tentukan biaya berdasarkan jenis mobil
            {
                case 'A':
                    cost = 50000; // Biaya untuk jenis mobil A
                    break;
                case 'B':
                    cost = 60000; // Biaya untuk jenis mobil B
                    break;
                case 'C':
                    cost = 80000; // Biaya untuk jenis mobil C
                    break;
                default:
                    printf("Jenis mobil tidak valid.\n");
                    Sleep(2000);
                    return;
            }

            printf("Biaya Cuci: %d\n", cost);
            pay(cost);
            
            // Setelah pembayaran, hapus mobil dari antrian
//            Car *temp = current;
//            WL->queue = current->next;
//            free(temp);

            return;
        }
        current = current->next;
    }

    printf("Mobil dengan plat %s tidak ditemukan dalam antrian.\n", plate);
    Sleep(2000);
}