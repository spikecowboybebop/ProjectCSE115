#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "patient_new_entry.h"
#include "patient_search_record.h"
#include "patient_modify_record.h"
#include "patient_delete_records.h"
#include "patient_all_records.h"
#include "staff_new_entry.h"
#include "staff_search_record.h"
#include "staff_modify_record.h"
#include "staff_delete_records.h"
#include "staff_all_records.h"
#define MAX_ITEMS 100
#define FILENAME "inventory.txt"
typedef struct
{
    //creating user structure

    char userName[30];//User name must be unique
    char firstName[30];
    char lastName[30];
    char userPassword[30];//user password needed to log in

}UserType;
typedef struct
{
    char name[30];
    int id;
    float price;
    int quantity;
    char user[30];

}inventory;

void patient_system() {
struct patient_data *ptr;
    ptr = (struct patient_data *)malloc(1 * sizeof(struct patient_data));
    int c;
    do {
        printf("[Enter a] Add New Patient Records\n");
        printf("[Enter b] Search Existing Patient Records\n");
        printf("[Enter c] Modify Existing Patient Records\n");
        printf("[Enter d] Delete Patient Records\n");
        printf("[Enter e] View all Records\n");
        printf("Choice - ");

        char b;
        scanf("%c", &b);
        fflush(stdin);

        switch (b) {
            case 'a':
                patient_new_entry(ptr);
                break;
            case 'b':
                patient_search_record(ptr);
                break;
            case 'c':
                patient_modify_record(ptr);
                break;
            case 'd':
                patient_delete_records();
                break;
            case 'e':
                patient_all_records();
                break;
            default:
                printf("Error\n");
                break;
        }
        printf("\nEnter 1 to do it again or 0 to exit - ");
        scanf("%d", &c);
        fflush(stdin);
        printf("\n");
        system("cls");
    } while (c != 0);

}
void staff_system() {
struct staff_data *ptr;
    ptr = (struct staff_data *)malloc(1 * sizeof(struct staff_data));
    int c;
    do {
        printf("[Enter a] Add New Employee Records\n");
        printf("[Enter b] Search Existing Employee Records\n");
        printf("[Enter c] Modify Existing Employee Records\n");
        printf("[Enter d] Delete Employee Records\n");
        printf("[Enter e] View all Records\n");
        printf("Choice - ");

        char b;
        scanf("%c", &b);
        fflush(stdin);

        switch (b) {
            case 'a':
                staff_new_entry(ptr);
                break;
            case 'b':
                staff_search_record(ptr);
                break;
            case 'c':
                staff_modify_record(ptr);
                break;
            case 'd':
                staff_delete_records();
                break;
            case 'e':
                staff_all_records();
                break;
            default:
                printf("Error\n");
                break;
        }
        printf("\nEnter 1 to do it again or 0 to exit - ");
        scanf("%d", &c);
        fflush(stdin);
        printf("\n");
        system("cls");
    } while (c != 0);

}

void showUserMenu()
{
    //this menu will show for registration , log in or deleting user
    // This menu will appear at the start of the project

    printf("1.New user register \n");
    printf("2.User log in \n");
    printf("3.Delete user\n");
    printf("4.Exit\n");
}
void newUser()
{

    UserType newUser;// this structure is used to create a new user
    UserType user;// this structure will read user from file

    FILE* fp;

    while(1)
    {
        //here we are taking user name from the user and determining the size of user name

        fflush(stdin);//this is to clear the input buffer from new lines
        printf("User Name : ");
        gets(newUser.userName);

        if(strlen(newUser.userName)>4&&strlen(newUser.userName)<30)  //strlen to determine the size of userName
        {

            break;
        }
        printf("Username size must be between 5 and 30 \n");
    }

    fp= fopen("userInfo.txt", "r");//opening user file in reading mode

    while(fscanf(fp, "%s %d", user.userName, &user.userPassword) == 2)
    {

        if(strcmp(user.userName,newUser.userName)==0)  //comparing strings of new user and existing user from file
        {

            printf("User name is already taken. Please enter another user name \n");
            fclose(fp);
            return;// this return will return the user to user menu
        }
    }

    fclose(fp);

    fflush(stdin);
    printf("First Name : ");
    gets(newUser.firstName);

    fflush(stdin);
    printf("Last Name : ");
    gets(newUser.lastName);

    while(1)
    {
        //taking password input and making sure that is has appropriate size

        fflush(stdin);
        printf("Password : ");
        gets(newUser.userPassword);

        if(strlen(newUser.userPassword)>3&&strlen(newUser.userPassword)<30)  //determining the size of password
        {

            break;
        }
        printf("Password size must be between 4 and 30 \n");
    }

    fp= fopen("userInfo.txt", "a");//opening file in append mode

    if(fp==NULL)  //if there is no file
    {

        printf("File could not be opened");
    }

    fprintf(fp,"%s %s\n", newUser.userName,newUser.userPassword); //writing about new user in the file

    fclose(fp);
}
UserType userLogIn()
{
    //this function tries to log in and returns the user

    char userName[30];//log in username
    char pass[30];//if the password is correct user will log in

    UserType user;// creating a structure

    fflush(stdin);
    printf("Enter user name : \n");
    gets(userName);// log in username

    printf("Enter password : \n");
    gets(pass);// log in user password

    FILE* fp;

    fp= fopen("userInfo.txt", "r");

    while(fscanf(fp, "%s %s", user.userName, user.userPassword) == 2)
    {

        if(strcmp(user.userName, userName)==0 && strcmp(user.userPassword, pass)==0)  //comparing string for user and password from user input and file
        {

            return user;
        }
    }

    strcpy(user.userName,"NULL");// here the user is null when log in is unsuccessful

    return user;// returning null user

}
int countUsers()
{
    // this function will count the number of users in the user file

    int count = 0; //variable used to count users
    char username[50], password[50]; //buffer to read each user's information from file

    FILE *fp;

    fp = fopen("userInfo.txt", "r");

    while (fscanf(fp, "%s %s", username, password) == 2)
    {
        //here we are reading the username and password (two strings) for each user and counting the number of users

        count++;
    }

    fclose(fp);

    return count;//here we return the number of users
}

void deleteUser()
{
    //here we will delete a user

    int index= -1;//if index does not change it means the user is not found
    int i=0;
    int count= countUsers();//counting the number of users
    char userName[30];
    char userPass[30];

    UserType *users=(UserType*) malloc(count * sizeof(UserType));
    //creating an array of dynamic size for UserType users[count];

    fflush(stdin);
    printf("Enter user name to delete : ");
    gets(userName);

    fflush(stdin);
    printf("Enter user pass : ");
    gets(userPass);

    FILE* fp;
    fp= fopen("userInfo.txt", "r");

    while(fscanf(fp, "%s %s", users[i].userName, users[i].userPassword) != EOF)
    {

        if(strcmp(users[i].userName,userName)==0&&strcmp(users[i].userPassword,userPass)==0 )
        {
            //if we find the user to delete from the string compare then we will get the index of the user to delete

            index =i;
        }

        i++;
    }

    fclose(fp);

    if(index== -1)
    {
        // if we do not get the user, the index will remain unchanged

        printf("The user was not found \n");
        return; //this will return the user to user menu
    }

    for(i=index; i<count-1; i++)
    {
        //this loop is used to delete the user by bringing all the users at the right 1 place left

        users[i]= users[i+1]; //here we are taking the user to the rightmost array
    }

    fp= fopen("userInfo.txt", "w");

    printf("\nUser deleted \n");

    for(i=0; i<count-1; i++)
    {
        fprintf(fp, "%s %s\n", users[i].userName, users[i].userPassword);
    }

    fclose(fp);
}
void showHospitalMenu()
{
    printf("1. Patient\n");
    printf("2. Staff\n");
    printf("3. Pharmacy\n");
    printf("4. Log Out\n");
}
int num_items = 0;
inventory items[MAX_ITEMS];
void pharmacy(UserType currentUser)
{
    FILE * fp = fopen(FILENAME, "r");
    if (fp != NULL)
    {
        inventory item;
        char user[30];
        while (fscanf(fp, "%s %d %f %d %s\n", item.name, &item.id, &item.price, &item.quantity, user) == 5)
        {
            if (strcmp(item.name, "") != 0 && strcmp(currentUser.userName, user) == 0)
            {
                items[num_items] = item;
                num_items++;
            }
        }
        fclose(fp);
    }
    int option;
    system("cls");

    do
    {
        printf("1. Add item\n");
        printf("2. Modify item\n");
        printf("3. Search item\n");
        printf("4. List items\n");
        printf("5. Delete item\n");
        printf("6. Purchase item\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            system("cls");
            if (num_items == MAX_ITEMS)
            {
                printf("Can't add more items, inventory is full!\n");
                break;
            }

            inventory item;

            printf("Enter name of item: ");
            scanf("%s", item.name);

            printf("Enter ID of item: ");
            scanf("%d", &item.id);

            printf("Enter price of item: ");
            scanf("%f", &item.price);

            printf("Enter quantity of item: ");
            scanf("%d", &item.quantity);

            strcpy(item.user, currentUser.userName); // Set user field to current user's username

            items[num_items] = item;
            num_items++;

            // Append item to file
            FILE * fp = fopen(FILENAME, "a");
            fprintf(fp, "%s %d %.2f %d %s\n", item.name, item.id, item.price, item.quantity, currentUser.userName);
            fclose(fp);

            printf("Item added successfully.\n");
            break;
        }
        case 2:
        {
            system("cls");
            if (num_items == 0)
            {
                printf("No items to modify, inventory is empty!\n");
                break;
            }

            int id_to_modify;
            printf("Enter ID of item to modify: ");
            scanf("%d", &id_to_modify);

            int found_index = -1;
            for (int i = 0; i < num_items; i++)
            {
                if (items[i].id == id_to_modify)
                {
                    found_index = i;
                    break;
                }
            }

            if (found_index == -1)
            {
                printf("Item with ID %d not found!\n", id_to_modify);
                break;
            }
            float new_price;
            printf("Enter new price for item %s (current price is %.2f): ", items[found_index].name, items[found_index].price);
            scanf("%f", &new_price);

            // Update price field of item in memory
            items[found_index].price = new_price;

            // Rewrite updated inventory to file
            FILE * fp = fopen(FILENAME, "w");
            for (int i = 0; i < num_items; i++)
            {
                fprintf(fp, "%s %d %.2f %d %s\n", items[i].name, items[i].id, items[i].price, items[i].quantity, currentUser.userName);
            }
            fclose(fp);
            printf("Price updated successfully.\n");
            break;
        }
        case 3:
        {
            system("cls");
            int id;
            printf("Enter ID of item to search: ");
            scanf("%d", &id);

            // Open file for read
            FILE *fp = fopen(FILENAME, "r");
            if (fp == NULL)
            {
                printf("Error opening file.\n");
                break;
            }

            inventory item;
            int found = 0;

            while (fscanf(fp, "%s %d %f %d %s\n", item.name, &item.id, &item.price, &item.quantity, item.user) != EOF)
            {
                if (item.id == id && strcmp(item.user, currentUser.userName) == 0)
                {
                    printf("\n%-20s %-10s %-10s %-10s\n", "Name", "ID", "Price", "Quantity");
                    printf("%-20s %-10d %-10.2f %-10d\n", item.name, item.id, item.price, item.quantity);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Item with entered ID not found or doesn't belong to current user.\n");
            }

            fclose(fp);
            getc(stdin);
            break;
        }
        case 4:
        {
            system("cls");
            FILE *fp = fopen(FILENAME, "r");
            if (fp != NULL)
            {
                inventory item;
                char user[30];
                printf("%-20s %-10s %-10s %-10s\n", "Name", "ID", "Price", "Quantity");
                while (fscanf(fp, "%s %d %f %d %s\n", item.name, &item.id, &item.price, &item.quantity, user) == 5)
                {
                    if (strcmp(item.name, "") != 0 && strcmp(currentUser.userName, user) == 0)
                {
                    printf("%-20s %-10d %-10.2f %-10d\n", item.name, item.id,item.price, item.quantity);
                }
            }
            fclose(fp);
            }
            else
            {
            printf("Error opening file.\n");
            }
            break;
        }
        case 5:
        {
            system("cls");

            if (num_items == 0)
            {
                printf("Inventory is empty!\n");
                break;
            }

            int id_to_delete;
            printf("Enter ID of item to delete: ");
            scanf("%d", &id_to_delete);

            // Search for item with matching ID
            int index_to_delete = -1;
            for (int i = 0; i < num_items; i++)
            {
                if (items[i].id == id_to_delete)
                {
                    index_to_delete = i;
                    break;
                }
            }

            if (index_to_delete == -1)
            {
                printf("Item not found in inventory!\n");
                break;
            }

            // Delete item from array
            for (int i = index_to_delete + 1; i < num_items; i++)
            {
                items[i - 1] = items[i];
            }
            num_items--;

            // Rewrite file without deleted item
            FILE * fp = fopen(FILENAME, "w");
            for (int i = 0; i < num_items; i++)
            {
                fprintf(fp, "%s %d %.2f %d %s\n", items[i].name, items[i].id, items[i].price, items[i].quantity, items[i].user);
            }
            fclose(fp);

            printf("Item deleted successfully.\n");
            break;
        }
        case 6:
        {
            // Open inventory file for reading
            system("cls");
            FILE *fp = fopen(FILENAME, "r");
            if (fp == NULL)
            {
                printf("Error opening inventory file.\n");
                break;
            }

            // Read items from file into array
            num_items = 0;
            while (fscanf(fp, "%s %d %f %d %s", items[num_items].name, &items[num_items].id, &items[num_items].price, &items[num_items].quantity, items[num_items].user) != EOF && num_items < MAX_ITEMS)
            {
                num_items++;
            }
            fclose(fp);

            int purchase_complete = 0;
            while (!purchase_complete)
            {
                // Prompt user to enter ID of item to purchase
                printf("Enter ID of item to purchase: ");
                int id;
                scanf("%d", &id);

                // Search for item with given ID in inventory
                int index = -1;
                for (int i = 0; i < num_items; i++)
                {
                    if (items[i].id == id && strcmp(items[i].user, currentUser.userName) == 0)
                    {
                        index = i;
                        break;
                    }
                }

                // If item not found or does not belong to current user, display error message and repeat loop
                if (index == -1)
                {
                    printf("Item with entered ID not found or doesn't belong to current user.\n");
                    break;
                }

                // Prompt user to enter quantity to purchase
                printf("Enter quantity to purchase: ");
                int quantity_to_purchase;
                scanf("%d", &quantity_to_purchase);

                // If not enough stock available, display error message and repeat loop
                if (quantity_to_purchase > items[index].quantity)
                {
                    printf("Not enough stock available.\n");
                    break;
                }

                // Calculate total price and display to user
                float total_price = items[index].price * quantity_to_purchase;
                printf("Total price for purchase: %.2f\n", total_price);

                // Update inventory and file
                items[index].quantity -= quantity_to_purchase;
                fp = fopen(FILENAME, "w");
                for (int i = 0; i < num_items; i++)
                {
                    fprintf(fp, "%s %d %.2f %d %s\n", items[i].name, items[i].id, items[i].price, items[i].quantity, items[i].user);
                }
                fclose(fp);

                // Display success message and prompt user to continue or exit
                printf("Purchase successful.\n");
                printf("Do you want to purchase another item? (y/n) ");
                char choice;
                scanf(" %c", &choice);
                if (choice == 'n' || choice == 'N')
                {
                    purchase_complete = 1;
                }
            }
            break;
        }
        case 7:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid option, please try again.\n");
        }
    }
    while (option != 7);
}
void mainMenu(UserType currentUser)
{
    UserType user;//structure for user
    int userChoice;//userChoice for switch case

    while(1)
    {

        showHospitalMenu(); // showing the book menu
        printf("User choice : ");
        scanf("%d", &userChoice);//user will choose what to do
        fflush(stdin);

        switch(userChoice)
        {

        case 1:
            patient_system();
            ;
            break;

        case 2:
            staff_system();
            ;
            break;

        case 3:
            pharmacy(currentUser);
            break;

        case 4:

            return;//returning to user menu after logging out
            break;

        default:

            printf("Please enter a valid option \n");//if user inputs an non valid option in the book menu

        }
        printf("Enter any button to continue...\n");
        getc(stdin); //character input
        system("cls"); //console clean
    }
}

int main()
{

    int userMenuChoice;//user input for user menu
    int count; //variable for counting
    int i;// variable to use loops
    int userInput;//variable to get user input
    int result;// variable to get a result
    UserType users;// structure for users
    UserType user;// structure for user

    FILE* fp;
    fp = fopen("userInfo.txt", "r");

    if(fp==NULL)
    {
        fp = fopen("userInfo.txt", "w");
    }
    fclose(fp);

    fp = fopen("inventory.txt", "r");

    if(fp==NULL)
    {
        fp = fopen("inventory.txt", "w");
    }
    fclose(fp);
    // Create the database files of they don't exist already

    while(1)
    {

        showUserMenu();// showing the user menu
        printf("User choice : ");
        scanf("%d", &userMenuChoice);

        switch(userMenuChoice)
        {

        case 1:

            newUser();// creating a new user using this function

            break;

        case 2 :

            user=userLogIn();

            if(strcmp(user.userName,"NULL") !=0)
            {
                //when user log in fails a null user is returned
                //when logged in successful we are sending to main menu with logged in user information
                system("cls");
                mainMenu(user);
            }
            else
            {
                printf("Log in failed, please try again\n");// for null user
            }

            break;
        case 3 :

            deleteUser();// deleting a user

            break;

        case 4 :

            return 0;// exit

            break;
        default:
            // if user enters a non valid option

            printf("Please enter a valid option \n");
        }

        printf("Enter any button to continue...\n");
        getc(stdin); //character input
        system("cls"); //console clean
    }
    return 0;
}
