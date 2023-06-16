void staff_all_records() {
	FILE *fptr;
	fptr = fopen("staff_count.txt", "r");

	if(fptr == NULL) {
		printf("NO RECORD FOUND\n");
	}
	else {
		char count[10];
		fgets(count, sizeof(count), fptr);
		int c = atoi(count);

		if(c == 0) {
			printf("NO RECORD FOUND\n");
		}

		FILE *all_records;
		all_records = fopen("staff_data.txt", "r");
		if(all_records == NULL) {
			printf("NO RECORD FOUND\n");
			fclose(all_records);
		}
		else {
			char data[c][70];
			printf("ID   NAME\n");
			for (int i = 0; ((fgets(data[i], sizeof(data), all_records)) != NULL && (i < c)); i++)
			{
				printf("%s", data[i]);
			}
			fclose(all_records);
		}
	}
	fclose(fptr);
}