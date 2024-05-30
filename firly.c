#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include "header.h"

Station washingStations[MAX_STATION];
Station dryingStations[MAX_STATION];
WaitingList *WLBasah;
WaitingList *WLKering;

void createStation()
{
	for (int i = 0; i < MAX_STATION; i++)
	{
		washingStations[i].processing = NULL;
	}

	for (int i = 0; i < MAX_STATION; i++)
	{
		dryingStations[i].processing = NULL;
	}
	WLBasah = malloc(sizeof(struct WaitingList));
	WLKering = malloc(sizeof(struct WaitingList));
	WLBasah->queue = NULL;
	WLKering->queue = NULL;
}

void showCarType()
{
	printf("======================================================\n");
	printf("||                  JENIS MOBIL A                   ||\n");
	printf("||      (Waktu pencucian kurang lebih 50 menit)     ||\n");
	printf("======================================================\n");
	printf("|| - KIA Picanto                                    ||\n");
	printf("|| - Daihatsu Ceria                                 ||\n");
	printf("|| - Suzuki Karimun                                 ||\n");
	printf("|| - Toyota Yaris                                   ||\n");
	printf("||                                                  ||\n");
	printf("||   Dan Sejenisnya...                              ||\n");
	printf("||                                                  ||\n");
	printf("======================================================\n\n");

	printf("======================================================\n");
	printf("||                  JENIS MOBIL B                   ||\n");
	printf("||      (Waktu pencucian kurang lebih 60 menit)     ||\n");
	printf("======================================================\n");
	printf("|| - Toyota Avanza                                  ||\n");
	printf("|| - Honda Freed                                    ||\n");
	printf("|| - Suzuki Ertiga                                  ||\n");
	printf("||                                                  ||\n");
	printf("||   Dan Sejenisnya...                              ||\n");
	printf("||                                                  ||\n");
	printf("======================================================\n\n");

	printf("======================================================\n");
	printf("||                  JENIS MOBIL C                   ||\n");
	printf("||      (Waktu pencucian kurang lebih 80 menit)     ||\n");
	printf("======================================================\n");
	printf("|| - Metromini                                      ||\n");
	printf("|| - Truk                                           ||\n");
	printf("||                                                  ||\n");
	printf("||   Dan Sejenisnya...                              ||\n");
	printf("||                                                  ||\n");
	printf("======================================================\n\n");
}

void status(char *modifiedDate, struct WaitingList *WL, Station washingStations[MAX_STATION], Station dryingStations[MAX_STATION])
{
	char car1[50];
	char car2[50];
	char str[50];
	strcpy(str, modifiedDate);
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
	printf("======================================================\n");
	printf("||          PROGRAM ANTRIAN DAGO CAR WASH           ||\n");
	printf("||                                                  ||\n");
	printf("||    WAKTU SAAT INI : %s     ||\n", str);
	printf("======================================================\n");
	if (washingStations[0].processing == NULL && washingStations[1].processing == NULL)
	{
		printf("======================================================\n");
		printf("||                 STASIUN BASAH                    ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("||        Kosong         ||         Kosong          ||\n");
		printf("======================================================\n\n");
	}
	else if (washingStations[0].processing != NULL && washingStations[1].processing == NULL)
	{
		printf("======================================================\n");
		printf("||                 STASIUN BASAH                    ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("|| Plat Nomor: %s  ||         Kosong          ||\n", washingStations[0].processing->plate);
		printf("|| Tipe Mobil: %c         ||=========================||\n", washingStations[0].processing->type);
		printf("|| Sisa waktu: %d menit  ||                           \n", washingStations[0].processing->washingTime);
		printf("===========================\n\n");
	}
	else if (washingStations[0].processing == NULL && washingStations[1].processing != NULL)
	{
		printf("======================================================\n");
		printf("||                 STASIUN BASAH                    ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("||        Kosong         || Plat Nomor: %s    ||\n", washingStations[1].processing->plate);
		printf("=========================|| Tipe Mobil: %c           ||\n", washingStations[1].processing->type);
		printf("                         || Sisa waktu: %d menit    ||\n", washingStations[1].processing->washingTime);
		printf("                         =============================\n\n");
	}
	else
	{
		printf("======================================================\n");
		printf("||                 STASIUN BASAH                    ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("|| Plat Nomor: %s  || Plat Nomor: %s    ||\n", washingStations[0].processing->plate, washingStations[1].processing->plate);
		printf("|| Tipe Mobil: %c         || Tipe Mobil: %c           ||\n", washingStations[0].processing->type, washingStations[1].processing->type);
		printf("|| Sisa waktu: %d menit  || Sisa waktu: %d menit    ||\n", washingStations[0].processing->washingTime, washingStations[1].processing->washingTime);
		printf("======================================================\n\n");
	}

	if (dryingStations[0].processing == NULL && dryingStations[1].processing == NULL)
	{
		printf("======================================================\n");
		printf("||               STASIUN PENGERING                  ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("||        Kosong         ||         Kosong          ||\n");
		printf("======================================================\n\n");
	}
	else if (dryingStations[0].processing != NULL && dryingStations[1].processing == NULL)
	{
		printf("======================================================\n");
		printf("||               STASIUN PENGERING                  ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("|| Plat Nomor: %s  ||         Kosong          ||\n", dryingStations[0].processing->plate);
		printf("|| Tipe Mobil: %c         ||=========================||\n", dryingStations[0].processing->type);
		printf("|| Sisa waktu: %d menit  ||                           \n", dryingStations[0].processing->dryingTime);
		printf("===========================\n\n");
	}
	else if (dryingStations[0].processing == NULL && dryingStations[1].processing != NULL)
	{
		printf("======================================================\n");
		printf("||               STASIUN PENGERING                  ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("||        Kosong         || Plat Nomor: %s    ||\n", dryingStations[1].processing->plate);
		printf("=========================|| Tipe Mobil: %c           ||\n", dryingStations[1].processing->type);
		printf("                         || Sisa waktu: %d menit    ||\n", dryingStations[1].processing->dryingTime);
		printf("                         =============================\n\n");
	}
	else
	{
		printf("======================================================\n");
		printf("||               STASIUN PENGERING                  ||\n");
		printf("======================================================\n");
		printf("||       Stasiun 1       ||        Stasiun 2        ||\n");
		printf("||=======================||=========================||\n");
		printf("|| Plat Nomor: %s  || Plat Nomor: %s    ||\n", dryingStations[0].processing->plate, dryingStations[1].processing->plate);
		printf("|| Tipe Mobil: %c         || Tipe Mobil: %c           ||\n", dryingStations[0].processing->type, dryingStations[1].processing->type);
		printf("|| Sisa waktu: %d menit  || Sisa waktu: %d menit    ||\n", dryingStations[0].processing->dryingTime, dryingStations[1].processing->dryingTime);
		printf("======================================================\n\n");
	}

	if (WLBasah->queue == NULL)
	{
		printf("====================================\n");
		printf("||    WAITING LIST CUCI BASAH     ||\n");
		printf("====================================\n");
		printf("||  1  ||         Kosong          ||\n");
		printf("====================================\n\n");
	}
	else
	{
		printf("======================================================\n");
		printf("||              WAITING LIST CUCI BASAH             ||\n");
		printf("======================================================\n");

		int i = 1;
		char str[50];
		struct Car *current = WL->queue;
		while (current != NULL)
		{
			strcpy(str, current->arrivalTime);
			size_t len = strlen(str);
			if (len > 0 && str[len - 1] == '\n')
			{
				str[len - 1] = '\0';
			}
			printf("||      || Plat Nomor   : %s                  ||\n", current->plate);
			printf("||   %d  || Tipe Mobil   : %c                         ||\n", i, current->type);
			printf("||      || Waktu Datang : %s  ||\n", str);
			printf("======================================================\n");
			i++;
			current = current->next;
		}
	}
	
	if (WLKering->queue == NULL)
	{
		printf("====================================\n");
		printf("||    WAITING LIST CUCI KERING    ||\n");
		printf("====================================\n");
		printf("||  1  ||         Kosong          ||\n");
		printf("====================================\n\n");
	}
	else
	{
		printf("======================================================\n");
		printf("||             WAITING LIST CUCI KERING             ||\n");
		printf("======================================================\n");

		int i = 1;
		char str[50];
		struct Car *current = WL->queue;
		while (current != NULL)
		{
			strcpy(str, current->arrivalTime);
			size_t len = strlen(str);
			if (len > 0 && str[len - 1] == '\n')
			{
				str[len - 1] = '\0';
			}
			printf("||      || Plat Nomor   : %s                  ||\n", current->plate);
			printf("||   %d  || Tipe Mobil   : %c                         ||\n", i, current->type);
			printf("||      || Waktu Datang : %s  ||\n", str);
			printf("======================================================\n");
			i++;
			current = current->next;
		}
	}
}
void addQueue(char *modifiedDate)
{

	int i, j, number, lower, upper = 0;
	char input, inputUp;
	char plate[10];
	char *time1;
	bool valid = false;
	Car *car = (Car *)malloc(sizeof(Car));
	while (!valid)
	{
		system("cls");
		fflush(stdin);
		printf("Silakan pilih jenis mobil anda: \n\n");
		showCarType();
		printf("\n Pilihan (A, B, atau C): ");
		input = getchar();
		if (input == 'a' || input == 'A')
		{
			// Memilih tipe A
			// Lakukan randomisasi sesuai estimasi pengerjaan mobil tipe tertentu untuk waktu pengerjaan
			lower = 34;
			upper = 37;
			srand(time(NULL));
			number = (rand() % (upper - lower + 1) + lower);
			car->washingTime = number;
			lower = 13;
			upper = 17;
			number = (rand() % (upper - lower + 1) + lower);
			car->dryingTime = number;
			car->type = 'A';
			car->totalTime = car->washingTime + car->dryingTime;
			time1 = strdup(modifiedDate);
			car->arrivalTime = time1;
			valid = true;
		}
		else if (input == 'b' || input == 'B')
		{
			// Memilih tipe B
			// Lakukan randomisasi sesuai estimasi pengerjaan mobil tipe tertentu untuk waktu pengerjaan
			lower = 43;
			upper = 47;
			srand(time(NULL));
			number = (rand() % (upper - lower + 1) + lower);
			car->washingTime = number;
			lower = 13;
			upper = 17;
			number = (rand() % (upper - lower + 1) + lower);
			car->dryingTime = number;
			car->type = 'B';
			car->totalTime = car->washingTime + car->dryingTime;
			time1 = strdup(modifiedDate);
			car->arrivalTime = time1;
			valid = true;
		}
		else if (input == 'c' || input == 'C')
		{
			// Memilih tipe C
			// Lakukan randomisasi sesuai estimasi pengerjaan mobil tipe tertentu untuk waktu pengerjaan
			lower = 63;
			upper = 67;
			srand(time(NULL));
			number = (rand() % (upper - lower + 1) + lower);
			car->washingTime = number;
			lower = 13;
			upper = 17;
			number = (rand() % (upper - lower + 1) + lower);
			car->dryingTime = number;
			car->type = 'C';
			car->totalTime = car->washingTime + car->dryingTime;
			time1 = strdup(modifiedDate);
			car->arrivalTime = time1;
			valid = true;
		}
		else
		{
			// Tidak valid
			printf("Mohon masukkan opsi yang valid.");
			Sleep(2000);
			valid = false;
		}
	}
	valid = false;
	while (!valid)
	{
		inputUp = toupper(input);
		printf(" Tipe mobil yang dipilih: %c\n\n", inputUp);
		fflush(stdin);
		printf(" Masukkan Plat Nomor (Maksimal 7 Karakter): ");
		fgets(plate, sizeof(plate), stdin);

		// Menghapus karakter newline dari input
		plate[strcspn(plate, "\n")] = '\0';

		// Hapus spasi untuk validasi
		char *newStr = (char *)malloc(strlen(plate) + 1);
		for (i = 0; plate[i]; i++)
		{
			if (plate[i] != ' ')
			{
				newStr[j++] = plate[i];
			}
		}
		newStr[j] = '\0';
		if (strlen(newStr) > 7)
		{
			printf("Plat nomor melebihi 7 karakter!\n");
			valid = false;
		}
		else
		{
			valid = true;
		}
	}
	strcpy(car->plate, plate);
	car->next = NULL;

	//	Lakukan proses konfirmasi pembayaran disini sebelum menambahkan ke stasiun atau waiting list

	int l;
	for (l = 0; l < MAX_STATION; l++)
	{
		if (washingStations[l].processing == NULL)
		{
			washingStations[l].processing = car;
			time1 = strdup(modifiedDate);
			washingStations[l].processing->processedTime = time1;
			break;
		}
	}

	if (l == MAX_STATION)
	{
		if (WLBasah->queue == NULL)
		{
			WLBasah->queue = car;
		}
		else
		{
			struct Car *current = WLBasah->queue;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = car;
		}
	}
}

void displayLog()
{
	system("cls");
	FILE *log;
	log = fopen("Log_Selesai_Pencucian.txt", "r");
	if (log == NULL)
	{
		printf("Gagal membuka file!\n");
		exit(1);
	}
	char line[100];
	while (fgets(line, sizeof(line), log) != NULL)
	{
		printf("%s", line);
	}
	fclose(log);
}

void isDoneAlert(int i, char *modifiedDate, struct tm *gmTime, int totalTime)
{
	FILE *log;
	log = fopen("Log_Selesai_Pencucian.txt", "a");
	if (log == NULL)
	{
		printf("File gagal dibuat/dibuka!\n");
		exit(1);
	}
	
	char *finishTime;
	
	char *ctimeStr = strdup(dryingStations[i].processing->processedTime);
    struct tm tm;
    
    sscanf(ctimeStr, "%*s %*s %d %d:%d:%d %d", &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec, &tm.tm_year);
    tm.tm_year -= 1900;
    tm.tm_mon = 4;
    tm.tm_isdst = -1;
    
    tm.tm_min += dryingStations[i].processing->totalTime;
    time_t modifiedTime = mktime(&tm);
    finishTime = ctime(&modifiedTime);
    

	fprintf(log, "%s", finishTime);
	fprintf(log, "Mobil dengan plat nomor %s bertipe %c telah selesai dicuci.\n", dryingStations[i].processing->plate, dryingStations[i].processing->type);
	fprintf(log, "Waktu kedatangan   :   %s", dryingStations[i].processing->arrivalTime);
	fprintf(log, "Waktu diproses     :   %s", dryingStations[i].processing->processedTime);
	fprintf(log, "Waktu selesai      :   %s\n\n", finishTime);

	fclose(log);
}

void selesaiCuciBasah(int index, char *modifiedDate, struct tm *gmTime)
{
	Car *car;
	bool valid = false;
	bool valid1 = false;
	if (index == 0)
	{
		if (washingStations[0].processing == NULL)
		{
			printf("Stasiun tersebut kosong\n");
			Sleep(2000);
			return;
		}
		else
		{

			// Jika stasiun cuci basah kedua kosong
			if (washingStations[1].processing == NULL)
			{
				// Jika kedua stasiun pengering kosong
				if (dryingStations[0].processing == NULL && dryingStations[1].processing == NULL)
				{
					// Cek waiting list
					if (WLKering->queue != NULL && WLKering->queue->next != NULL)
					{
						if (WLKering->queue == NULL)
						{
							WLKering->queue = washingStations[0].processing;
						}
						else
						{
							struct Car *current = WLKering->queue;
							while (current->next != NULL)
							{
								current = current->next;
							}
							current->next = washingStations[0].processing;
						}
					}

					valid = true;
					if (WLKering->queue != NULL)
					{
						dryingStations[0].processing = WLKering->queue;
						WLKering->queue = WLKering->queue->next;
					}
					else
					{
						dryingStations[0].processing = washingStations[0].processing;
						valid = false;
					}

					if (valid)
					{
						if (WLKering->queue != NULL)
						{
							dryingStations[1].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[1].processing = washingStations[0].processing;
						}
					}

					gmTime->tm_min += washingStations[0].processing->washingTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					washingStations[0].processing = NULL;

					// Jika stasiun pengering kedua kosong namun stasiun pengering pertama tidak kosong
				}
				else if (dryingStations[1].processing == NULL)
				{
					dryingStations[0].processing->dryingTime -= washingStations[0].processing->washingTime;
					if (dryingStations[0].processing->dryingTime <= 0)
					{
						// Cuci selesai
						isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
						gmTime->tm_min += dryingStations[0].processing->dryingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						dryingStations[0].processing = NULL;

						// Cek waiting list
						if (WLKering->queue != NULL && WLKering->queue->next != NULL)
						{
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[0].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
							}
						}

						valid = true;
						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[0].processing;
							valid = false;
						}

						if (valid)
						{
							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[0].processing;
							}
						}
					}
					else
					{
						// Cek waiting list
						if (WLKering->queue != NULL)
						{
							struct Car *current = WLKering->queue;
							while (current->next != NULL)
							{
								current = current->next;
							}
							current->next = washingStations[0].processing;
							dryingStations[1].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[1].processing = washingStations[0].processing;
						}
					}

					gmTime->tm_min += washingStations[0].processing->washingTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					washingStations[0].processing = NULL;

					// Jika stasiun pengering pertama kosong namun stasiun pengering kedua tidak kosong
				}
				else if (dryingStations[0].processing == NULL)
				{
					dryingStations[1].processing->dryingTime -= washingStations[0].processing->washingTime;
					if (dryingStations[1].processing->dryingTime <= 0)
					{
						// Cuci selesai
						isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
						dryingStations[1].processing = NULL;

						// Cek waiting list
						if (WLKering->queue != NULL && WLKering->queue->next != NULL)
						{
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[0].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
							}
						}

						valid = true;
						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[0].processing;
							valid = false;
						}

						if (valid)
						{
							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[0].processing;
							}
						}
					}
					else
					{
						// Cek waiting list
						valid = true;
						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[0].processing;
							valid = false;
						}

						if (valid)
						{
							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[0].processing;
							}
						}
					}

					gmTime->tm_min += washingStations[0].processing->totalTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					washingStations[0].processing = NULL;

					// Jika tidak ada stasiun pengering yang kosong
				}
				else
				{
					dryingStations[0].processing->dryingTime -= washingStations[0].processing->washingTime;
						dryingStations[1].processing->dryingTime -= washingStations[0].processing->washingTime;
						if (dryingStations[0].processing->dryingTime >= 0 && dryingStations[1].processing->dryingTime >= 0)
						{

							// Pindah ke waiting list cuci kering
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[0].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
							}
						}
						
						else if (dryingStations[0].processing->dryingTime <= 0 && dryingStations[1].processing->dryingTime <= 0)
						{
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[0].processing = NULL;
							dryingStations[1].processing = NULL;

							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[0].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[0].processing;
								}
							}

							valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[0].processing;
								}
							}
							valid = true;
						}
						
						else if (dryingStations[0].processing->dryingTime <= 0)
						{
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							dryingStations[0].processing = NULL;

							// Cek jika ada waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
								valid = false;
							}
						}
						
						else if (dryingStations[1].processing->dryingTime <= 0 && valid)
						{
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[1].processing = NULL;

							// Cek jika ada waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[0].processing;
							}
						}
					gmTime->tm_min += washingStations[0].processing->washingTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					washingStations[0].processing = NULL;
				}

				// Jika stasiun cuci basah tidak ada yang kosong
			}
			else
			{
				// Jika washing station 1 waktunya lebih kecil daripada washing station 2
				if (washingStations[0].processing->washingTime <= washingStations[1].processing->washingTime)
				{
					
					washingStations[1].processing->washingTime -= washingStations[0].processing->washingTime;

					// Jika kedua stasiun pengering kosong
					if (dryingStations[0].processing == NULL && dryingStations[1].processing == NULL)
					{

						// Cek waiting list
						if (WLKering->queue != NULL && WLKering->queue->next != NULL)
						{
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[0].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
							}
						}

						valid = true;
						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[0].processing;
							valid = false;
						}

						if (valid)
						{
							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[0].processing;
							}
						}

						gmTime->tm_min += washingStations[0].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[0].processing = NULL;

						// Jika stasiun pengering pertama kosong namun stasiun pengering kedua tidak kosong
					}
					else if (dryingStations[0].processing == NULL)
					{
						dryingStations[1].processing->dryingTime -= washingStations[0].processing->washingTime;
						if (dryingStations[1].processing->dryingTime <= 0)
						{
							// Cuci selesai
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[1].processing = NULL;

							// Cek waiting list
							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[0].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[0].processing;
								}
							}

							valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[0].processing;
								}
							}
						}
						else
						{
							// Cek waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
							}
						}

						gmTime->tm_min += washingStations[0].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[0].processing = NULL;

						// Jika stasiun pengering kedua kosong namun stasiun pengering pertama tidak kosong
					}
					else if (dryingStations[1].processing == NULL)
					{
						dryingStations[0].processing->dryingTime -= washingStations[0].processing->washingTime;
						if (dryingStations[0].processing->dryingTime <= 0)
						{
							// Cuci selesai
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							dryingStations[0].processing = NULL;

							// Cek waiting list
							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[0].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[0].processing;
								}
							}

							valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[0].processing;
								}
							}
						}
						else
						{
							// Cek waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[0].processing;
							}
						}

						gmTime->tm_min += washingStations[0].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[0].processing = NULL;

						// Jika tidak ada stasiun pengering yang kosong
					}
					else
					{
						dryingStations[0].processing->dryingTime -= washingStations[0].processing->washingTime;
						dryingStations[1].processing->dryingTime -= washingStations[0].processing->washingTime;
						if (dryingStations[0].processing->dryingTime >= 0 && dryingStations[1].processing->dryingTime >= 0)
						{

							// Pindah ke waiting list cuci kering
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[0].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
							}
						}
						
						else if (dryingStations[0].processing->dryingTime <= 0 && dryingStations[1].processing->dryingTime <= 0)
						{
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[0].processing = NULL;
							dryingStations[1].processing = NULL;

							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[0].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[0].processing;
								}
							}

							valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[0].processing;
								}
							}
							valid = true;
						}
						
						else if (dryingStations[0].processing->dryingTime <= 0)
						{
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							dryingStations[0].processing = NULL;

							// Cek jika ada waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
								valid = false;
							}
						}
						
						else if (dryingStations[1].processing->dryingTime <= 0 && valid)
						{
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[1].processing = NULL;

							// Cek jika ada waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[0].processing;
							}
						}

						gmTime->tm_min += washingStations[0].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[0].processing = NULL;
					}

					// Jika waktu stasiun 1 lebih besar daripada stasiun 2
				}
				else
				{
					valid1 = true;
					washingStations[0].processing->washingTime -= washingStations[1].processing->washingTime;

					// Jika kedua stasiun pengering kosong
					if (dryingStations[0].processing == NULL && dryingStations[1].processing == NULL)
					{

						// Cek waiting list
						if (WLKering->queue != NULL && WLKering->queue->next != NULL)
						{
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[1].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
							}
						}

						valid = true;
						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[1].processing;
							valid = false;
						}

						if (valid)
						{
							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[1].processing;
							}
						}
						
						gmTime->tm_min += washingStations[1].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[1].processing = NULL;

						// Jika stasiun pengering pertama kosong namun stasiun pengering kedua tidak kosong
					}
					else if (dryingStations[0].processing == NULL)
					{
						dryingStations[1].processing->dryingTime -= washingStations[1].processing->washingTime;
						if (dryingStations[1].processing->dryingTime <= 0)
						{
							// Cuci selesai
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[1].processing = NULL;

							// Cek waiting list
							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[1].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[1].processing;
								}
							}

							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[1].processing;
							}

							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[1].processing;
							}
						}
						else
						{
							// Cek waiting list
							bool valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[1].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[1].processing;
								}
							}
						}

						gmTime->tm_min += washingStations[1].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[1].processing = NULL;

						// Cek waiting list
						if (WLKering->queue != NULL && WLKering->queue->next != NULL)
						{
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[1].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
							}
						}

						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[1].processing;
						}

						if (WLKering->queue != NULL)
						{
							dryingStations[1].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[1].processing = washingStations[1].processing;
						}
					}
					else if (dryingStations[1].processing == NULL)
					{
						dryingStations[0].processing->dryingTime -= washingStations[1].processing->washingTime;
						if (dryingStations[0].processing->dryingTime <= 0)
						{
							// Cuci selesai
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							dryingStations[0].processing = NULL;
						}

						// Cek waiting list
						if (WLKering->queue != NULL)
						{
							struct Car *current = WLKering->queue;
							while (current->next != NULL)
							{
								current = current->next;
							}
							current->next = washingStations[1].processing;
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[1].processing;
						}

						gmTime->tm_min += washingStations[1].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[1].processing = NULL;

						// Jika kedua stasiun pengering tidak kosong
					}
					else
					{
						dryingStations[0].processing->dryingTime -= washingStations[1].processing->washingTime;
						dryingStations[1].processing->dryingTime -= washingStations[1].processing->washingTime;
						if (dryingStations[0].processing->dryingTime >= 0 && dryingStations[1].processing->dryingTime >= 0)
						{

							// Pindah ke waiting list cuci kering
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[1].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
							}
						}
						
						else if (dryingStations[0].processing->dryingTime <= 0 && dryingStations[1].processing->dryingTime <= 0)
						{
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[0].processing = NULL;
							dryingStations[1].processing = NULL;

							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[1].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[1].processing;
								}
							}

							valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[1].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[1].processing;
								}
							}
							valid = true;
						}
						
						else if (dryingStations[0].processing->dryingTime <= 0)
						{
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							dryingStations[0].processing = NULL;

							// Cek jika ada waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[1].processing;
								valid = false;
							}
						}
						
						else if (dryingStations[1].processing->dryingTime <= 0 && valid)
						{
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[1].processing = NULL;

							// Cek jika ada waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[1].processing;
							}
						}

						gmTime->tm_min += washingStations[1].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[1].processing = NULL;
					}
				}
			}

			if (valid1)
			{
				if (WLBasah->queue != NULL)
				{
					washingStations[1].processing = WLBasah->queue;
					washingStations[1].processing->processedTime = modifiedDate;
					WLBasah->queue = WLBasah->queue->next;
				}
			}
			else
			{
				if (WLBasah->queue != NULL)
				{
					washingStations[0].processing = WLBasah->queue;
					washingStations[0].processing->processedTime = modifiedDate;
					WLBasah->queue = WLBasah->queue->next;
				}
			}
		}
	}
	else if (index == 1)
	{
		if (washingStations[1].processing == NULL)
		{
			printf("Stasiun tersebut kosong\n");
			Sleep(2000);
			return;
		}
		else
		{

			// Jika stasiun cuci basah pertama kosong
			if (washingStations[0].processing == NULL)
			{
				// Jika kedua stasiun pengering kosong
				if (dryingStations[0].processing == NULL && dryingStations[1].processing == NULL)
				{
					// Cek waiting list
					if (WLKering->queue != NULL && WLKering->queue->next != NULL)
					{
						if (WLKering->queue == NULL)
						{
							WLKering->queue = washingStations[1].processing;
						}
						else
						{
							struct Car *current = WLKering->queue;
							while (current->next != NULL)
							{
								current = current->next;
							}
							current->next = washingStations[1].processing;
						}
					}

					valid = true;
					if (WLKering->queue != NULL)
					{
						dryingStations[0].processing = WLKering->queue;
						WLKering->queue = WLKering->queue->next;
					}
					else
					{
						dryingStations[0].processing = washingStations[1].processing;
						valid = false;
					}

					if (valid)
					{
						if (WLKering->queue != NULL)
						{
							dryingStations[1].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[1].processing = washingStations[1].processing;
						}
					}

					gmTime->tm_min += washingStations[1].processing->washingTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					washingStations[1].processing = NULL;

					// Jika stasiun pengering kedua kosong namun stasiun pengering pertama tidak kosong
				}
				else if (dryingStations[1].processing == NULL)
				{
					dryingStations[0].processing->dryingTime -= washingStations[1].processing->washingTime;
					if (dryingStations[0].processing->dryingTime <= 0)
					{
						// Cuci selesai
						isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
						gmTime->tm_min += dryingStations[0].processing->dryingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						dryingStations[0].processing = NULL;

						// Cek waiting list
						if (WLKering->queue != NULL && WLKering->queue->next != NULL)
						{
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[1].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
							}
						}

						valid = true;
						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[1].processing;
							valid = false;
						}

						if (valid)
						{
							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[1].processing;
							}
						}
					}
					else
					{
						// Cek waiting list
						if (WLKering->queue != NULL)
						{
							struct Car *current = WLKering->queue;
							while (current->next != NULL)
							{
								current = current->next;
							}
							current->next = washingStations[1].processing;
							dryingStations[1].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[1].processing = washingStations[1].processing;
						}
					}

					gmTime->tm_min += washingStations[1].processing->washingTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					washingStations[1].processing = NULL;

					// Jika stasiun pengering pertama kosong namun stasiun pengering kedua tidak kosong
				}
				else if (dryingStations[0].processing == NULL)
				{
					dryingStations[1].processing->dryingTime -= washingStations[1].processing->washingTime;
					if (dryingStations[1].processing->dryingTime <= 0)
					{
						// Cuci selesai
						isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
						dryingStations[1].processing = NULL;

						// Cek waiting list
						if (WLKering->queue != NULL && WLKering->queue->next != NULL)
						{
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[1].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
							}
						}

						valid = true;
						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[1].processing;
							valid = false;
						}

						if (valid)
						{
							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[1].processing;
							}
						}
					}
					else
					{
						// Cek waiting list
						valid = true;
						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[1].processing;
							valid = false;
						}

						if (valid)
						{
							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[1].processing;
							}
						}
					}

					gmTime->tm_min += washingStations[1].processing->totalTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					washingStations[1].processing = NULL;

					// Jika tidak ada stasiun pengering yang kosong
				}
				else
				{
					dryingStations[0].processing->dryingTime -= washingStations[1].processing->washingTime;
					dryingStations[1].processing->dryingTime -= washingStations[1].processing->washingTime;
					if (dryingStations[0].processing->dryingTime <= 0)
					{
						// Cuci selesai
						isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
						dryingStations[0].processing = NULL;
						dryingStations[0].processing = washingStations[1].processing;
					}
					if (dryingStations[1].processing->dryingTime <= 0)
					{
						// Cuci selesai
						isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
						dryingStations[1].processing = NULL;
					}
					gmTime->tm_min += washingStations[1].processing->washingTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					washingStations[1].processing = NULL;
				}

				// Jika stasiun cuci basah tidak ada yang kosong
			}
			else
			{
				// Jika washing station 1 waktunya lebih kecil daripada washing station 2
				if (washingStations[0].processing->washingTime <= washingStations[1].processing->washingTime)
				{
					valid1 = true;
					washingStations[1].processing->washingTime -= washingStations[0].processing->washingTime;

					// Jika kedua stasiun pengering kosong
					if (dryingStations[0].processing == NULL && dryingStations[1].processing == NULL)
					{

						// Cek waiting list
						if (WLKering->queue != NULL && WLKering->queue->next != NULL)
						{
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[0].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
							}
						}

						valid = true;
						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[0].processing;
							valid = false;
						}

						if (valid)
						{
							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[0].processing;
							}
						}

						gmTime->tm_min += washingStations[0].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[0].processing = NULL;

						// Jika stasiun pengering pertama kosong namun stasiun pengering kedua tidak kosong
					}
					else if (dryingStations[0].processing == NULL)
					{
						dryingStations[1].processing->dryingTime -= washingStations[0].processing->washingTime;
						if (dryingStations[1].processing->dryingTime <= 0)
						{
							// Cuci selesai
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[1].processing = NULL;

							// Cek waiting list
							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[0].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[0].processing;
								}
							}

							valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[0].processing;
								}
							}
						}
						else
						{
							// Cek waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
							}
						}

						gmTime->tm_min += washingStations[0].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[0].processing = NULL;

						// Jika stasiun pengering kedua kosong namun stasiun pengering pertama tidak kosong
					}
					else if (dryingStations[1].processing == NULL)
					{
						dryingStations[0].processing->dryingTime -= washingStations[0].processing->washingTime;
						if (dryingStations[0].processing->dryingTime <= 0)
						{
							// Cuci selesai
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							dryingStations[0].processing = NULL;

							// Cek waiting list
							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[0].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[0].processing;
								}
							}

							valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[0].processing;
								}
							}
						}
						else
						{
							// Cek waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[0].processing;
							}
						}

						gmTime->tm_min += washingStations[0].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[0].processing = NULL;

						// Jika tidak ada stasiun pengering yang kosong
					}
					else
					{
						dryingStations[0].processing->dryingTime -= washingStations[0].processing->washingTime;
						dryingStations[1].processing->dryingTime -= washingStations[0].processing->washingTime;
						if (dryingStations[0].processing->dryingTime >= 0 && dryingStations[1].processing->dryingTime >= 0)
						{

							// Pindah ke waiting list cuci kering
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[0].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
							}
						}
						
						else if (dryingStations[0].processing->dryingTime <= 0 && dryingStations[1].processing->dryingTime <= 0)
						{
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[0].processing = NULL;
							dryingStations[1].processing = NULL;

							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[0].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[0].processing;
								}
							}

							valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[0].processing;
								}
							}
							valid = true;
						}
						
						else if (dryingStations[0].processing->dryingTime <= 0)
						{
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							dryingStations[0].processing = NULL;

							// Cek jika ada waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[0].processing;
								valid = false;
							}
						}
						
						else if (dryingStations[1].processing->dryingTime <= 0 && valid)
						{
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[1].processing = NULL;

							// Cek jika ada waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[0].processing;
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[0].processing;
							}
						}

						gmTime->tm_min += washingStations[0].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[0].processing = NULL;
					}

					// Jika waktu stasiun 1 lebih besar daripada stasiun 2
				}
				else
				{
					washingStations[0].processing->washingTime -= washingStations[1].processing->washingTime;

					// Jika kedua stasiun pengering kosong
					if (dryingStations[0].processing == NULL && dryingStations[1].processing == NULL)
					{

						// Cek waiting list
						if (WLKering->queue != NULL && WLKering->queue->next != NULL)
						{
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[1].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
							}
						}

						valid = true;
						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[1].processing;
							valid = false;
						}

						if (valid)
						{
							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[1].processing;
							}
						}
						
						gmTime->tm_min += washingStations[1].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[1].processing = NULL;

						// Jika stasiun pengering pertama kosong namun stasiun pengering kedua tidak kosong
					}
					else if (dryingStations[0].processing == NULL)
					{
						dryingStations[1].processing->dryingTime -= washingStations[1].processing->washingTime;
						if (dryingStations[1].processing->dryingTime <= 0)
						{
							// Cuci selesai
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[1].processing = NULL;

							// Cek waiting list
							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[1].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[1].processing;
								}
							}

							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[1].processing;
							}

							if (WLKering->queue != NULL)
							{
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[1].processing;
							}
						}
						else
						{
							// Cek waiting list
							bool valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[1].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[1].processing;
								}
							}
						}

						gmTime->tm_min += washingStations[1].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[1].processing = NULL;

						// Cek waiting list
						if (WLKering->queue != NULL && WLKering->queue->next != NULL)
						{
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[1].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
							}
						}

						if (WLKering->queue != NULL)
						{
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[1].processing;
						}

						if (WLKering->queue != NULL)
						{
							dryingStations[1].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[1].processing = washingStations[1].processing;
						}
					}
					else if (dryingStations[1].processing == NULL)
					{
						dryingStations[0].processing->dryingTime -= washingStations[1].processing->washingTime;
						if (dryingStations[0].processing->dryingTime <= 0)
						{
							// Cuci selesai
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							dryingStations[0].processing = NULL;
						}

						// Cek waiting list
						if (WLKering->queue != NULL)
						{
							struct Car *current = WLKering->queue;
							while (current->next != NULL)
							{
								current = current->next;
							}
							current->next = washingStations[1].processing;
							dryingStations[0].processing = WLKering->queue;
							WLKering->queue = WLKering->queue->next;
						}
						else
						{
							dryingStations[0].processing = washingStations[1].processing;
						}

						gmTime->tm_min += washingStations[1].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[1].processing = NULL;

						// Jika kedua stasiun pengering tidak kosong
					}
					else
					{
						dryingStations[0].processing->dryingTime -= washingStations[1].processing->washingTime;
						dryingStations[1].processing->dryingTime -= washingStations[1].processing->washingTime;
						if (dryingStations[0].processing->dryingTime >= 0 && dryingStations[1].processing->dryingTime >= 0)
						{

							// Pindah ke waiting list cuci kering
							if (WLKering->queue == NULL)
							{
								WLKering->queue = washingStations[1].processing;
							}
							else
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
							}
						}
						
						else if (dryingStations[0].processing->dryingTime <= 0 && dryingStations[1].processing->dryingTime <= 0)
						{
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[0].processing = NULL;
							dryingStations[1].processing = NULL;

							if (WLKering->queue != NULL && WLKering->queue->next != NULL)
							{
								if (WLKering->queue == NULL)
								{
									WLKering->queue = washingStations[1].processing;
								}
								else
								{
									struct Car *current = WLKering->queue;
									while (current->next != NULL)
									{
										current = current->next;
									}
									current->next = washingStations[1].processing;
								}
							}

							valid = true;
							if (WLKering->queue != NULL)
							{
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[1].processing;
								valid = false;
							}

							if (valid)
							{
								if (WLKering->queue != NULL)
								{
									dryingStations[1].processing = WLKering->queue;
									WLKering->queue = WLKering->queue->next;
								}
								else
								{
									dryingStations[1].processing = washingStations[1].processing;
								}
							}
							valid = true;
						}
						
						else if (dryingStations[0].processing->dryingTime <= 0)
						{
							isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
							dryingStations[0].processing = NULL;

							// Cek jika ada waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
								dryingStations[0].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[0].processing = washingStations[1].processing;
								valid = false;
							}
						}
						
						else if (dryingStations[1].processing->dryingTime <= 0 && valid)
						{
							isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
							dryingStations[1].processing = NULL;

							// Cek jika ada waiting list
							if (WLKering->queue != NULL)
							{
								struct Car *current = WLKering->queue;
								while (current->next != NULL)
								{
									current = current->next;
								}
								current->next = washingStations[1].processing;
								dryingStations[1].processing = WLKering->queue;
								WLKering->queue = WLKering->queue->next;
							}
							else
							{
								dryingStations[1].processing = washingStations[1].processing;
							}
						}

						gmTime->tm_min += washingStations[1].processing->washingTime;
						time_t modifiedTime = mktime(gmTime);
						modifiedDate = ctime(&modifiedTime);
						washingStations[1].processing = NULL;
					}
				}
			}

			if (valid1)
			{
				if (WLBasah->queue != NULL)
				{
					washingStations[0].processing = WLBasah->queue;
					washingStations[0].processing->processedTime = modifiedDate;
					WLBasah->queue = WLBasah->queue->next;
				}
			}
			else
			{
				if (WLBasah->queue != NULL)
				{
					washingStations[1].processing = WLBasah->queue;
					washingStations[1].processing->processedTime = modifiedDate;
					WLBasah->queue = WLBasah->queue->next;
				}
			}
		}
	}
}

 void selesaiCuciKering(int index, char *modifiedDate, struct tm *gmTime)
 {
	if (index == 0)
	{
		if (dryingStations[0].processing == NULL)
		{
			printf("Stasiun tersebut kosong\n");
			Sleep(2000);
			return;
		} 
		else 
		{
			if (washingStations[0].processing != NULL || washingStations[1].processing != NULL){
				printf("Stasiun cuci basah harus kosong\n");
				Sleep(2000);
				return;
			}
			else
			{
				if (dryingStations[1].processing == NULL)
				{
					isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
					gmTime->tm_min += dryingStations[0].processing->dryingTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					dryingStations[0].processing = NULL;
					if (WLKering->queue != NULL)
					{
						dryingStations[0].processing = WLKering->queue;
						WLKering->queue = WLKering->queue->next;
					}
				}
				else
				{
					if (dryingStations[0].processing->dryingTime <= dryingStations[1].processing->dryingTime);
					dryingStations[1].processing->dryingTime -= dryingStations[0].processing->dryingTime;
					isDoneAlert(0, modifiedDate, gmTime, dryingStations[0].processing->totalTime);
					gmTime->tm_min += dryingStations[0].processing->dryingTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					dryingStations[0].processing = NULL;
					if (WLKering->queue != NULL)
					{
						dryingStations[0].processing = WLKering->queue;
						WLKering->queue = WLKering->queue->next;
					}
				}
			}
		}
	}
	else if (index == 1)
	{
		if (dryingStations[1].processing == NULL)
		{
			printf("Stasiun tersebut kosong\n");
			Sleep(2000);
			return;
		} 
		else 
		{
			if (washingStations[0].processing != NULL || washingStations[1].processing != NULL){
				printf("Stasiun cuci basah harus kosong\n");
				Sleep(2000);
				return;
			}
			else
			{
				if (dryingStations[0].processing == NULL)
				{
					isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
					gmTime->tm_min += dryingStations[1].processing->dryingTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					dryingStations[1].processing = NULL;
					if (WLKering->queue != NULL)
					{
						dryingStations[1].processing = WLKering->queue;
						WLKering->queue = WLKering->queue->next;
					}
				}
				else
				{
					if (dryingStations[1].processing->dryingTime <= dryingStations[0].processing->dryingTime);
					dryingStations[0].processing->dryingTime -= dryingStations[1].processing->dryingTime;
					isDoneAlert(1, modifiedDate, gmTime, dryingStations[1].processing->totalTime);
					gmTime->tm_min += dryingStations[1].processing->dryingTime;
					time_t modifiedTime = mktime(gmTime);
					modifiedDate = ctime(&modifiedTime);
					dryingStations[1].processing = NULL;
					if (WLKering->queue != NULL)
					{
						dryingStations[1].processing = WLKering->queue;
						WLKering->queue = WLKering->queue->next;
					}
				}
			}
		}
	}
}

void selesaiPengerjaan(char *modifiedDate, struct tm *gmTime)
{
	int index;
	char input;
	system("cls");
	do
	{
		system("cls");
		status(modifiedDate, WLBasah, washingStations, dryingStations);
		printf("Pilih selesaikan pengerjaan di stasiun mana\n");
		printf("1. Stasiun Cuci Basah 1\n");
		printf("2. Stasiun Cuci Basah 2\n");
		printf("3. Stasiun Cuci Kering 1 (Stasiun cuci basah 1 & 2 harus kosong)\n");
		printf("4. Stasiun Cuci Kering 2 (Stasiun cuci basah 1 & 2 harus kosong)\n");
		printf("0. Keluar\n");
		scanf(" %c", &input);
		switch (input)
		{
		case '1':
			index = 0;
			selesaiCuciBasah(index, modifiedDate, gmTime);
			break;

		case '2':
			index = 1;
			selesaiCuciBasah(index, modifiedDate, gmTime);
			break;
			
		case '3':
			index = 0;
			selesaiCuciKering(index, modifiedDate, gmTime);
			break;
			
		case '4':
			index = 1;
			selesaiCuciKering(index, modifiedDate, gmTime);
			break;
		}	
	} while (input != '0');
}