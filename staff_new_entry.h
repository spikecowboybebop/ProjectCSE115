struct staff_data {
    char id[50];
    char staff_name[50];
    char gen[8];
    char bgrp[5];
    char age[10];
    char address[4][30];
    char phn[15];
    char salary[100];
    char designation[100];
};
void staff_new_entry(struct staff_data *ptr) {
    FILE *staffCountCheck;
    staffCountCheck = fopen("staff_count.txt", "r");
    if(staffCountCheck == NULL) {
        FILE *staffCountCreate;
        staffCountCreate = fopen("staff_count.txt", "w");
        fprintf(staffCountCreate, "0");
        fclose(staffCountCreate);
    }

    printf("Enter ID of Employee - ");
    gets((ptr + 0)->id);

    printf("Enter Employee's Name - ");
    gets((ptr + 0)->staff_name);

    printf("Enter Employee's Gender - ");
    gets((ptr + 0)->gen);

    printf("Enter Employee's Blood Group - ");
    gets((ptr + 0)->bgrp);

    printf("Enter Employee's's Age - ");
    gets((ptr + 0)->age);

    printf("Enter Employee's Address -\n");
    printf("\tHouse No - ");
    gets((ptr + 0)->address[0]);

    printf("\tStreet - ");
    gets((ptr + 0)->address[1]);

    printf("\tCity - ");
    gets((ptr + 0)->address[2]);

    printf("\tCountry - ");
    gets((ptr + 0)->address[3]);

    printf("Enter Phone Number - ");
    gets((ptr + 0)->phn);

    printf("Enter Salary - ");
    gets((ptr + 0)->salary);

    printf("Enter Designation - ");
    gets((ptr + 0)->designation);

    FILE *cfptr;
    char cname[100] = "staff-";
    strcat(cname, (ptr + 0)->id);
    strcat(cname, (ptr + 0)->staff_name);
    strcat(cname, ".txt");

    cfptr = fopen(cname, "r");

    if(cfptr == NULL) {
        FILE *fptr;
        char fname[100] = "staff-";
        strcat(fname, (ptr + 0)->id);
        strcat(fname, (ptr + 0)->staff_name);
        strcat(fname, ".txt");

        fptr = fopen(fname, "w");

        fprintf(fptr, "%s\n", (ptr + 0)->id);

        fprintf(fptr, "%s\n", (ptr + 0)->staff_name);

        fprintf(fptr, "%s\n", (ptr + 0)->gen);

        fprintf(fptr, "%s\n", (ptr + 0)->bgrp);

        fprintf(fptr, "%s\n", (ptr + 0)->age);

        fprintf(fptr, "%s\n", (ptr + 0)->address[0]);

        fprintf(fptr, "%s\n", (ptr + 0)->address[1]);

        fprintf(fptr, "%s\n", (ptr + 0)->address[2]);

        fprintf(fptr, "%s\n", (ptr + 0)->address[3]);

        fprintf(fptr, "%s\n", (ptr + 0)->phn);

        fprintf(fptr, "%s\n", (ptr + 0)->salary);

        fprintf(fptr, "%s\n", (ptr + 0)->designation);

        fclose(fptr);

        FILE *cptr;
        cptr = fopen("staff_count.txt", "r");
        char count[100];
        fscanf(cptr, "%s", count);
        fclose(cptr);
        int c = atoi(count);
        c++;
        FILE *captr;
        captr = fopen("staff_count.txt", "w");
        fprintf(captr, "%d", c);
        fclose(captr);

        fflush(stdin);

        char writedata[100];
        strcpy(writedata, (ptr+0)->id);
        strcat(writedata, " ");
        strcat(writedata, (ptr+0)->staff_name);
        FILE *staffdata;
        staffdata = fopen("staff_data.txt", "a");
        fprintf(staffdata, "%s\n", writedata);
        fclose(staffdata);
    } 
    else {
        printf("Record already exists for %s(%s)\n", (ptr+0)->staff_name, (ptr+0)->id);
    }
}
