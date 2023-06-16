void staff_modify_record(struct staff_data *ptr) {
	printf("Enter ID - ");
	gets((ptr + 0)->id);
	printf("Enter Employee's Name - ");
	gets((ptr + 0)->staff_name);
	char fname[100] = "staff-";
	strcat(fname, (ptr+0)->id);
	strcat(fname, (ptr+0)->staff_name);
	strcat(fname, ".txt");

	FILE *fptr;
	fptr = fopen(fname, "r");

	if(fptr == NULL) {
		printf("No record found for %s(%s)\n", (ptr+0)->staff_name, (ptr+0)->id);
	}
	else {
		printf("Record Found for %s(%s)\n", (ptr+0)->staff_name, (ptr+0)->id);

		char data[12][200];
		for(int i = 0; (fgets(data[i], sizeof(data), fptr) && (i < 12) ); i++) {
			continue;
		}
		strcpy((ptr + 0)->id, data[0]);
    	strcpy((ptr + 0)->staff_name, data[1]);
      	strcpy((ptr + 0)->gen, data[2]);
        strcpy((ptr + 0)->bgrp, data[3]);
        strcpy((ptr + 0)->age, data[4]);
        strcpy((ptr + 0)->address[0], data[5]);
        strcpy((ptr + 0)->address[1], data[6]);
        strcpy((ptr + 0)->address[2], data[7]);
        strcpy((ptr + 0)->address[3], data[8]);
        strcpy((ptr + 0)->phn, data[9]);
        strcpy((ptr + 0)->salary, data[10]);
        strcpy((ptr + 0)->designation, data[11]);

    fclose(fptr);

    printf("[Enter 1] - Modify Employee's Gender\n");
    printf("[Enter 2] - Modify Employee's Blood Group\n");
    printf("[Enter 3] - Modify Employee's Age\n");
    printf("[Enter 4] - Modify Employee's House No\n");
    printf("[Enter 5] - Modify Employee's Address Street\n");
    printf("[Enter 6] - Modify Employee's Address City\n");
    printf("[Enter 7] - Modify Employee's Address Country\n");
    printf("[Enter 8] - Modify Employee's Phone\n");
    printf("[Enter 9] - Modify Employee's Salary\n");
    printf("[Enter 10] - Modify Employee's Designation\n");
    
    FILE *dfptr;
    dfptr = fopen(fname, "w+");

    int a;
    printf("Choice: ");
    scanf("%d", &a);
    fflush(stdin);

    switch(a) {

        case 1:
            printf("Enter Employee's Gender - ");
            gets((ptr + 0)->gen);

            fprintf(dfptr, "%s", (ptr + 0)->id);
            fprintf(dfptr, "%s", (ptr + 0)->staff_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "\n%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->salary);
            fprintf(dfptr, "%s", (ptr + 0)->designation);

            break;
        case 2:
            printf("Enter Employee's Blood Group - ");
            gets((ptr + 0)->bgrp);

            fprintf(dfptr, "%s", (ptr + 0)->id);
            fprintf(dfptr, "%s", (ptr + 0)->staff_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "\n%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->salary);
            fprintf(dfptr, "%s", (ptr + 0)->designation);

            break;
        case 3:
            printf("Enter Employee's Age - ");
            gets((ptr + 0)->age);

            fprintf(dfptr, "%s", (ptr + 0)->id);
            fprintf(dfptr, "%s", (ptr + 0)->staff_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "\n%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->salary);
            fprintf(dfptr, "%s", (ptr + 0)->designation);

            break;
        case 4:
            printf("Enter Employee's House No - ");
            gets((ptr + 0)->address[0]);

            fprintf(dfptr, "%s", (ptr + 0)->id);
            fprintf(dfptr, "%s", (ptr + 0)->staff_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "\n%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->salary);
            fprintf(dfptr, "%s", (ptr + 0)->designation);

            break;
        case 5:
            printf("Enter Employee's Street - ");
            gets((ptr + 0)->address[1]);

            fprintf(dfptr, "%s", (ptr + 0)->id);
            fprintf(dfptr, "%s", (ptr + 0)->staff_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "\n%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->salary);
            fprintf(dfptr, "%s", (ptr + 0)->designation);

            break;
        case 6:
            printf("Enter Employee's City - ");
            gets((ptr + 0)->address[2]);

            fprintf(dfptr, "%s", (ptr + 0)->id);
            fprintf(dfptr, "%s", (ptr + 0)->staff_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "\n%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->salary);
            fprintf(dfptr, "%s", (ptr + 0)->designation);

            break;
        case 7:
            printf("Enter Employee's Country - ");
            gets((ptr + 0)->address[3]);

            fprintf(dfptr, "%s", (ptr + 0)->id);
            fprintf(dfptr, "%s", (ptr + 0)->staff_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "\n%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->salary);
            fprintf(dfptr, "%s", (ptr + 0)->designation);

            break;
        case 8:
            printf("Enter Patient's Phone - ");
            gets((ptr + 0)->phn);

            fprintf(dfptr, "%s", (ptr + 0)->id);
            fprintf(dfptr, "%s", (ptr + 0)->staff_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "\n%s", (ptr + 0)->salary);
            fprintf(dfptr, "%s", (ptr + 0)->designation);

            break;
        case 9:
            printf("Enter Employee's Salary - ");
            gets((ptr + 0)->salary);

            fprintf(dfptr, "%s", (ptr + 0)->id);
            fprintf(dfptr, "%s", (ptr + 0)->staff_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->salary);
            fprintf(dfptr, "\n%s", (ptr + 0)->designation);

            break;
        case 10:
            printf("Enter Employee's designation - ");
            gets((ptr + 0)->designation);

            fprintf(dfptr, "%s", (ptr + 0)->id);
            fprintf(dfptr, "%s", (ptr + 0)->staff_name);
            fprintf(dfptr, "%s", (ptr + 0)->gen);
            fprintf(dfptr, "%s", (ptr + 0)->bgrp);
            fprintf(dfptr, "%s", (ptr + 0)->age);
            fprintf(dfptr, "%s", (ptr + 0)->address[0]);
            fprintf(dfptr, "%s", (ptr + 0)->address[1]);
            fprintf(dfptr, "%s", (ptr + 0)->address[2]);
            fprintf(dfptr, "%s", (ptr + 0)->address[3]);
            fprintf(dfptr, "%s", (ptr + 0)->phn);
            fprintf(dfptr, "%s", (ptr + 0)->salary);
            fprintf(dfptr, "%s", (ptr + 0)->designation);

            break;
        default:
            printf("Error!\n");
            break;
    }
    fclose(dfptr);
	}
}
