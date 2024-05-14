#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"header.h"

void createList()
{
    for (int i = 0; i < MAX_STATION; i++) {
        stations[i].id = i + 1;
        stations[i].queue = NULL;
    }	
}

// Fungsi untuk membatalkan antrian pada stasiun tertentu
void cancel(int stationID, char plate) {
    Station *station = &stations[stationID]; // Mendapatkan pointer ke stasiun dengan ID tertentu
    
    // Jika stasiun tidak ditemukan, keluar dari fungsi
    if (station == NULL) {
        printf("Stasiun tidak ditemukan.\n");
        return;
    }
    
    // Cek apakah antrian kosong
    if (station->queue == NULL) {
        printf("Antrian pada stasiun %d kosong.\n", stationID);
        return;
    }
    
    // Jika mobil pertama di antrian memiliki plat yang sesuai, hapus mobil tersebut
    if (station->queue->plate == plate) {
        Car *temp = station->queue; // Simpan alamat mobil yang akan dihapus
        station->queue = station->queue->next; // Geser pointer antrian ke mobil berikutnya
        free(temp); // Bebaskan memori mobil yang dihapus
        printf("Antrian untuk mobil dengan plat %c pada stasiun %d dibatalkan.\n", plate, stationID);
        return;
    }
    
    // Traverse antrian untuk mencari mobil dengan plat yang sesuai
    Car *prev = station->queue;
    Car *current = prev->next;
    while (current != NULL) {
        if (current->plate == plate) {
            prev->next = current->next; // Hapus mobil dari antrian
            free(current); // Bebaskan memori mobil yang dihapus
            printf("Antrian untuk mobil dengan plat %c pada stasiun %d dibatalkan.\n", plate, stationID);
            return;
        }
        prev = current;
        current = current->next;
    }
    
    // Jika mobil dengan plat yang sesuai tidak ditemukan
    printf("Mobil dengan plat %c tidak ditemukan dalam antrian pada stasiun %d.\n", plate, stationID);
}
