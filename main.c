#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include"header.h"

int main(){
	char input;
	WL = malloc(sizeof(struct WaitingList));
	WL->queue = NULL;
	// Mengambil nilai waktu saat ini berupa detik
	time_t now = time(NULL);
	// Modifikasi value jam agar berada di jam 7 pagi
	struct tm *gmTime = gmtime(&now);
	gmTime->tm_hour = 7;
	gmTime->tm_min = 0;
	gmTime->tm_sec = 0;
	// Mengubah kembali value gmTime ke detik
	time_t modifiedTime = mktime(gmTime);
	// Konversi detik menjadi sebuah date utuh
	char *modifiedDate = ctime(&modifiedTime);
	printf("%s\n", modifiedDate);
	
	// Create list
	createStation();
	
	do{
		printf("1. Tambah Antrian.\n");
		printf("2. Lompat Waktu\n");
		fflush(stdin);
		input = getchar();
		switch(input){
		case '1':	
			// Tambah Antrian
			tambahAntrian(modifiedDate);
			break;

		case '2':
			// Tampilkan Antrian saat ini
			lompatWaktu(modifiedDate, gmTime);
			break;
//			
//		case 3:
//			// Fast forward time
//			
//		case 4:
//			// Search mobil (Estimasi waktu dikerjakan, plat nomor, tipe mobil) 
//
//		case 5:
//			// Cancel antrian
	}
	
			
		
	} while (input != 0);
	return 0;
}