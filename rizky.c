#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void cancel(WaitingList *WL) 
{
	char plate[10];
	printf("Masukan plat nomor kendaraan (A 123 B): ");
	scanf("%s", plate);
    Car *prev = NULL;
    Car *current = WL->queue;

    // Traverse the waiting list to find the car
    while (current != NULL) 
	{
        if (strcmp(current->plate, plate) == 0) 
		{
            // If the car is found, remove it from the list
            if (prev == NULL) 
			{
                WL->queue = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Car with plate %s has been canceled from the waiting list.\n", plate);
            return;
        }
        prev = current;
        current = current->next;
    }

    // If the car is not found in the waiting list, check the washing stations
    int i;
    for (i = 0; i < MAX_STATION; i++) 
	{
        if (washingStations[i].processing != NULL && strcmp(washingStations[i].processing->plate, plate) == 0) 
		{
            free(washingStations[i].processing);
            washingStations[i].processing = NULL;
            printf("Car with plate %s has been canceled from washing station %d.\n", plate, i);
            return;
        }
    }

    // If the car is not found in the waiting list or washing stations, check the drying stations
    for (i = 0; i < MAX_STATION; i++) 
	{
        if (dryingStations[i].processing != NULL && strcmp(dryingStations[i].processing->plate, plate) == 0) 
		{
            free(dryingStations[i].processing);
            dryingStations[i].processing = NULL;
            printf("Car with plate %s has been canceled from drying station %d.\n", plate, i);
            return;
        }
    }

    printf("Car with plate %s not found in the system.\n", plate);
}

	/* BELUM BERES*/
//void Estimate(int washingTime, int dryingTime) {
//    // Menghitung total waktu pengerjaan
//    int totalProcessingTime = washingTime + dryingTime;
//    
//    // Menampilkan estimasi waktu pengerjaan
//    printf("Estimasi waktu pengerjaan: %d menit\n", totalProcessingTime);
//}