void staff_delete_records() {
	char del_user[2][70];
	printf("Enter Employee's ID - ");
	gets(del_user[0]);
	printf("Enter Name - ");
	gets(del_user[1]);

	char filedelete[70];
	strcpy(filedelete, "staff-");
	strcat(filedelete, del_user[0]);
	strcat(filedelete, del_user[1]);
	strcat(filedelete, ".txt");

	char count[10];
	FILE *rdptr;
	rdptr = fopen("staff_count.txt", "r");
	fgets(count, sizeof(count), rdptr);
	int c = atoi(count);
	fclose(rdptr);

	char userdata[c][70];
	FILE *getdata;
	getdata = fopen("staff_data.txt", "r");
	for(int i = 0; ( (fgets(userdata[i], sizeof(userdata), getdata)) != NULL && (i < c)); i++) {
		continue;
	}
	fclose(getdata);
	strcat(del_user[0], " ");
	strcat(del_user[0], del_user[1]);
	strcat(del_user[0], "\n");

	int cmpr[c];

	for(int i = 0; i < c; i++) {
		cmpr[i] = strcmp(del_user[0], userdata[i]);
	}
	FILE *writedata;
	writedata = fopen("staff_data.txt", "w");
	for(int i = 0; i < c; i++) {
		if(cmpr[i] == 0) {
			continue;
		}
		else {
			fprintf(writedata, "%s", userdata[i]);
		}
	}
	fclose(writedata);

	c--;
	FILE *changecounter;
	changecounter = fopen("staff_count.txt", "w");
	fprintf(changecounter, "%d", c);
	fclose(changecounter);

	if(remove(filedelete) == 0) {
		printf("DELETE: OPERATION SUCCESSFUL\n");
	}
	else {
		printf("DELETE: OPERATION FAILED\n");
	}
}