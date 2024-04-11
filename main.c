#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int data;
} org;
typedef struct
{
    int amount;

} expense;
void welcome();     // For Welcome page -- Line 24
void signup();      // For Sign Up -- Line 56
int authenticate(); // To Check if username and password match -- Line 108
int login();        // For Log In -- Line 99
void after_login();
void Attendance();
void expenditure();
// ********** MAIN FUNCTION ********** //
int main()
{
    welcome();
}

// First Appearence
void welcome()
{

    int option;

    do
    {
        printf("WELCOME\n");

        printf("Press the serial number to proceed\n");
        printf("1. Sign Up\n");
        printf("2. Log in\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            signup();
            break;
        case 2:
            int a = login();
            if (a)
            {
                after_login();
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid input!!\n");
            printf("Please choose 1, 2 or 3\n");
        }
    } while (option < 1 || option > 3);
}

void signup()
{
    int option;
    char username[30];
    char pass[5];
    char Roll_no[5];
    do
    {
        printf("**Sign up page**\n");
        printf("Choose according to your preference\n");
        printf("1.Student\n");
        printf("2.organiser\n");
        printf("3.Back\n");

        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter Username: ");
            scanf("%s", username);
            printf("Enter Roll no: ");
            scanf("%s", Roll_no);
            printf("Enter Password: ");
            scanf("%s", pass);
            FILE *a;
            a = fopen("studentcredential.csv", "a+");

            fprintf(a, "%s %s %s\n", username, pass, Roll_no);
            fclose(a);
            welcome();
            break;
        case 2:
            printf("Enter Username: ");
            scanf("%s", username);
            printf("Enter Password: ");
            scanf("%s", pass);
            FILE *b;
            b = fopen("facaltycredential.csv", "a+");
            fprintf(b, "%s %s\n", username, pass);
            fclose(b);
            welcome();
            break;

        case 3:
            welcome();
            return;
        default:
            printf("Invalid input!!\n");
            printf("Please choose 1, 2 or 3\n");
        }
    } while (option < 1 || option > 3);

    welcome();
}

// Function to check if the username and password match
int authenticate(char username[], char password[], FILE *file)
{
    char line[40];
    char stored_username[30];
    char stored_password[5];

    // Open the file in read mode
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    // Read each line from the file
    while (fgets(line, sizeof(line), file))
    {
        // Extract username and password from the line
        sscanf(line, "%s %s", stored_username, stored_password);

        // Compare the provided username and password with the stored ones
        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0)
        {
            fclose(file);
            return 1; // Return 1 if the credentials match
        }
    }

    fclose(file);
    return 0; // Return 0 if credential do not match
}

int login()
{
    system("cls");
    char username[30];
    char password[5];
    int option;
    do
    {
        printf("Menu\n1.Student\n2.Organiser\n3.Back\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            // Prompt the user to enter their username
            printf("Enter username: ");
            scanf("%s", username);

            // Prompt the user to enter their password
            printf("Enter password: ");
            scanf("%s", password);

            FILE *a = fopen("studentcredential.csv", "r");
            // Authenticate the user
            if (authenticate(username, password, a))
            {
                printf("Login successful!\n");
                return 1;
            }
            else
            {
                printf("Invalid username or password. Please try again.\n");
                welcome();
                return 0;
            }
            break;
        case 2:
            // Prompt the user to enter their username
            printf("Enter username: ");
            scanf("%s", username);

            // Prompt the user to enter their password
            printf("Enter password: ");
            scanf("%s", password);

            FILE *b = fopen("facaltycredential.csv", "r");
            // Authenticate the user
            if (authenticate(username, password, b))
            {
                printf("Login successful!\n");
                return 1;
            }
            else
            {
                printf("Invalid username or password. Please try again.\n");
                welcome();
                return 0;
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid input!!\n");
            printf("Please choose 1, 2 or 3\n");
        }
    } while (option < 1 || option > 3);
}

void after_login()
{
    system("cls");
    int option;
    do
    {
        prinf("Menu\n\n1.Attendence\n2.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            Attendance();
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("Invalid input!!\n");
            printf("Please choose 1 or 2\n");
        }
    } while (option < 1 || option > 2);
}

void Attendence()
{
}

void expenditure()
{
}