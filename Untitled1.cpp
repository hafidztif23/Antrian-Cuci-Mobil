if (index == 1)
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
				if (washingStations[0].processing->washingTime < washingStations[1].processing->washingTime)
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