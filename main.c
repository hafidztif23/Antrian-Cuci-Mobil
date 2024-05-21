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
		printf("==================================================\n");
		printf("|                 Program CarWash                |\n");
		printf("==================================================\n");
		printf("| [1] Mobil Datang                               |\n");
		printf("| [2] Next 10 Menit                              |\n");
		printf("| [3] Tampilkan Daftar Mobil                     |\n");
		printf("| [4] Cari Mobil                                 |\n");
		printf("| [5] Cancel Antrian                             |\n");
		printf("| [6] Keluar                                     |\n");
		printf("==================================================\n");
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
//			
//		case 3:
			displayCarList();
			printf("Tekan sembarang tombol untuk melanjutkan...");
			getchar();
			break;
		case 4:
			fflush(stdin);
			printf("Masukkan Plat Nomor: ");
			fgets(plate, sizeof(plate), stdin);
			plate[strcspn(plate, "\n")] = '\0'; // Menghapus karakter newline dari input
			searchCar(plate);
			printf("Tekan sembarang tombol untuk melanjutkan...");
			getchar();
			break;

//		case 5:
//			// Cancel antrian
//		case 6:
			// Quit
		}
	} while (input != 0);
	return 0;
}
