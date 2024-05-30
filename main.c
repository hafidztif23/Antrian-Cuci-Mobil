//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<windows.h>
//#include<time.h>
//#include"header.h"
//
//int main(){
//	char input;
//	WL = malloc(sizeof(struct WaitingList));
//	WL->queue = NULL;
//	// Mengambil nilai waktu saat ini berupa detik
//	time_t now = time(NULL);
//	// Modifikasi value jam agar berada di jam 7 pagi
//	struct tm *gmTime = gmtime(&now);
//	gmTime->tm_hour = 7;
//	gmTime->tm_min = 0;
//	gmTime->tm_sec = 0;
//	// Mengubah kembali value gmTime ke detik
//	time_t modifiedTime = mktime(gmTime);
//	// Konversi detik menjadi sebuah date utuh
//	char *modifiedDate = ctime(&modifiedTime);
//	printf("%s\n", modifiedDate);
//	
//	// Create list
//	createStation();
//	
//	do{
//		printf("1. Tambah Antrian.\n");
//		printf("2. Lompat Waktu\n");
//		fflush(stdin);
//		input = getchar();
//		switch(input){
//		case '1':	
//			// Tambah Antrian
//			addQueue(modifiedDate);
//			break;
//
//		case '2':
//			// Tampilkan Antrian saat ini
//			timeLeap(modifiedDate, gmTime);
//			break;
////			
////		case 3:
////			
////		case 4:
////			// Search mobil (Estimasi waktu dikerjakan, plat nomor, tipe mobil) 
////
////		case 5:
////			// Cancel antrian
//		}
//	} while (input != 0);
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include"header.h"

int main(){
	
	char input;
	char plate[10];
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
		fflush(stdin);
		system("cls");
		status(modifiedDate, WL, washingStations, dryingStations);
		printf("\n======================================================\n");
		printf("||          Program Antrian Dago Car Wash           ||\n");
		printf("======================================================\n");
		printf("|| [1] Tambah Mobil                                 ||\n");
		printf("|| [2] Lompati Waktu                                ||\n");
		printf("|| [3] Tampilkan Informasi Lengkap Mobil            ||\n");
		printf("|| [4] Cari Mobil                                   ||\n");
		printf("|| [5] Batalkan Antrian                             ||\n");
		printf("|| [6] Keluar                                       ||\n");
		printf("======================================================\n");
		printf("Pilih Opsi: ");
		input = getchar();
		switch(input){
		case '1':	
			// Tambah Antrian
			addQueue(modifiedDate);
			break;

		case '2':
			// Tampilkan Antrian saat ini
			timeLeap(modifiedDate, gmTime);
			break;
		case '3':
			displayCarList();
			spaceToContinue();
			break;
		case '4':
			fflush(stdin);
			printf("Masukkan Plat Nomor: ");
			fgets(plate, sizeof(plate), stdin);
			plate[strcspn(plate, "\n")] = '\0'; // Menghapus karakter newline dari input
			searchCar(plate);
			spaceToContinue();
			break;

//		case 5:
//			// Cancel antrian
//		case 6:
			// Quit
		}
	} while (input != 0);
	return 0;
}
