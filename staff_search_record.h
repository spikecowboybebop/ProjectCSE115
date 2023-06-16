void staff_search_record(struct staff_data *ptr) {
    printf("Enter ID - ");
    gets((ptr + 0)->id);

    printf("Enter Employee's Name - ");
    gets((ptr + 0)->staff_name);

    char fname[100] = "staff-";
    strcat(fname, (ptr + 0)->id);
    strcat(fname, (ptr + 0)->staff_name);
    strcat(fname, ".txt");

    FILE *fptr;
    fptr = fopen(fname, "r");

    if(fptr == NULL) {
        printf("There is no record for %s(%s)", (ptr + 0)->staff_name, (ptr + 0)->id);
        fclose(fptr);
    }
    else {
        printf("\nRecord found for %s(%s)\n\n", (ptr + 0)->staff_name, (ptr + 0)->id);

        char data[12][200];
        for(int i =0; (fgets(data[i], sizeof(data), fptr) != NULL) && (i < 12); i++) {
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

        printf("Registration Number - ");
        puts((ptr + 0)->id);

        printf("Employee's Name - ");
        puts((ptr + 0)->staff_name);

        printf("Employee's Gender - ");
        puts((ptr + 0)->gen);

        printf("Employees Blood Group - ");
        puts((ptr + 0)->bgrp);

        printf("Employee's Age - ");
        puts((ptr + 0)->age);

        printf("Employee's Address -\n");
        printf("\tHouse No - ");
        puts((ptr + 0)->address[0]);

        printf("\tStreet - ");
        puts((ptr + 0)->address[1]);

        printf("\tCity - ");
        puts((ptr + 0)->address[2]);

        printf("\tCountry - ");
        puts((ptr + 0)->address[3]);

        printf("Phone Number - ");
        puts((ptr + 0)->phn);

        printf("Salary - ");
        puts((ptr + 0)->salary);

        printf("Designation - ");
        puts((ptr + 0)->designation);

        fclose(fptr);
    }

}
