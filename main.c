#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"header.h"

// Kamus lokal
	stations stasiun;
	Car mobil;
	char plate;
	

int main(){
	int input;
	
	// Create list
	
	switch(input){
		case 1:
			// Tambah Antrian
			
			break;
		case 2:
			// Tampilkan Antrian saat ini
			break;
		case 3:
			// Fast forward time
			break;
		case 4:
			// Search mobil (Estimasi waktu dikerjakan, plat nomor, tipe mobil) 
			printf("Masukkan plat nomor: ");
			fgets(plate, sizeof(plate), stdin);
			Search();
			break;
	}
	return 0;
}
