#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include"header.h"

int main(){
	
	char input;
	char plate[10];
//	WaitingList *WLBasah = malloc(sizeof(struct WaitingList));
//	WaitingList *WLKering = malloc(sizeof(struct WaitingList));
//	WLBasah->queue = NULL;
//	WLKering->queue = NULL;
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
		system("cls");
		status(modifiedDate, WLBasah, washingStations, dryingStations);
		printf("\n======================================================\n");
		printf("||          Program Antrian Dago Car Wash           ||\n");
		printf("======================================================\n");
		printf("|| [1] Tambah Mobil                                 ||\n");
		printf("|| [2] Selesaikan Pengerjaan                        ||\n");
		printf("|| [3] Tampilkan Daftar Mobil                       ||\n");
		printf("|| [4] Cari Mobil                                   ||\n");
		printf("|| [5] Tampilkan Log                                ||\n");
		printf("|| [6] Batalkan Antrian                             ||\n");
		printf("|| [7] Pembayaran                                   ||\n");
		printf("|| [8] Estimasi Dikerjakan                          ||\n");
		printf("|| [0] Keluar                                       ||\n");
		printf("======================================================\n");
		printf("Pilih Opsi: ");
		fflush(stdin);
		scanf(" %c", &input);
		switch(input){
		case '1':	
			// Tambah Antrian
			addQueue(modifiedDate);
			break;

		case '2':
			// Selesaikan pengerjaan
			selesaiPengerjaan(modifiedDate, gmTime);
			break;
		case '3':
			displayCarList(modifiedDate, gmTime);
			spaceToContinue();
			break;
		case '4':
			fflush(stdin);
			printf("Masukkan Plat Nomor: ");
			fgets(plate, sizeof(plate), stdin);
			plate[strcspn(plate, "\n")] = '\0'; // Menghapus karakter newline dari input
			searchCar(plate, modifiedDate, gmTime);
			spaceToContinue();
			break;

		case '5':
			// Log Selesai Pencucian
			displayLog();
			spaceToContinue();
			break;
		case '6':
			//Batalkan Antrian
			cancel(WLBasah, modifiedDate);
			break;
		case '7':
			// Pembayaran
			payment(WLBasah);
			break;
		case '8':
			// Estimasi Dikerjakan
			Estimate(WLBasah);
			break;
			
		default:
			printf("Masukkan input yang valid!\n");
			Sleep(1000);
			break;
		}
			
	} while (input != '0');
	
	return 0;
}