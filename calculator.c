#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* ================= BASIC OPERATIONS ================= */

void basicOperations()
{
    int choice;

    while (1)
    {
        clearScreen();
        printf(CYAN "\n--- BASIC OPERATIONS ---\n" RESET);
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("0. Back to Main Menu\n");

        printf("\nChoose: ");
        scanf("%d", &choice);

        if (choice == 0)
            return;

        double result = 0;
        char input[50];
        int isFloatUsed = 0;

        printf(YELLOW "\nEnter first number: " RESET);
        scanf("%s", input);

        if (strchr(input, '.'))
            isFloatUsed = 1;
        result = atof(input);

        while (1)
        {
            printf(YELLOW "Enter next number (or = to finish): " RESET);
            scanf("%s", input);

            if (strcmp(input, "=") == 0)
                break;

            if (strchr(input, '.'))
                isFloatUsed = 1;

            double num = atof(input);

            switch (choice)
            {
            case 1:
                result += num;
                break;
            case 2:
                result -= num;
                break;
            case 3:
                result *= num;
                break;
            case 4:
                if (num == 0)
                {
                    printf(RED "Math Error: Division by zero!\n" RESET);
                    printf("\nPress Enter to continue...");
                    getchar();
                    getchar();
                    return;
                }
                result /= num;
                isFloatUsed = 1;
                break;
            default:
                printf(RED "Invalid Choice\n" RESET);
                return;
            }
        }

        printf(GREEN "\nFinal Result: " RESET);

        if (!isFloatUsed && floor(result) == result)
            printf(GREEN "%lld\n" RESET, (long long)result);
        else
            printf(GREEN "%.6lf\n" RESET, result);

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
}

/* ================= SCIENTIFIC OPERATIONS ================= */

void scientificOperations()
{
    int choice;

    while (1)
    {
        clearScreen();
        printf(CYAN "\n--- SCIENTIFIC OPERATIONS ---\n" RESET);
        printf("1. Power (x^y)\n");
        printf("2. Square Root\n");
        printf("3. Log10\n");
        printf("4. sin(x)  [Degrees]\n");
        printf("5. cos(x)  [Degrees]\n");
        printf("6. tan(x)  [Degrees]\n");
        printf("0. Back to Main Menu\n");

        printf("\nChoose: ");
        scanf("%d", &choice);

        if (choice == 0)
            return;

        double x, y, result;
        int isFloatUsed = 0; // Track if output should be float

        switch (choice)
        {

        case 1:
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &x, &y);
            result = pow(x, y);
            if (floor(result) != result)
                isFloatUsed = 1;
            break;

        case 2:
            printf("Enter number: ");
            scanf("%lf", &x);
            if (x < 0)
            {
                printf(RED "Math Error: Square root of negative number!\n" RESET);
                printf("\nPress Enter to continue...");
                getchar();
                getchar();
                continue;
            }
            else
            {
                result = sqrt(x);
                if (floor(result) != result)
                    isFloatUsed = 1;
            }
            break;

        case 3:
            printf("Enter number: ");
            scanf("%lf", &x);
            if (x <= 0)
            {
                printf(RED "Math Error: Log undefined for zero or negative!\n" RESET);
                printf("\nPress Enter to continue...");
                getchar();
                getchar();
                continue;
            }
            else
            {
                result = log10(x);
                if (floor(result) != result)
                    isFloatUsed = 1;
            }
            break;

        case 4:
            printf("Enter angle in degrees: ");
            scanf("%lf", &x);
            result = sin(x * M_PI / 180.0);
            if (floor(result) != result)
                isFloatUsed = 1;
            break;

        case 5:
            printf("Enter angle in degrees: ");
            scanf("%lf", &x);
            result = cos(x * M_PI / 180.0);
            if (floor(result) != result)
                isFloatUsed = 1;
            break;

        case 6:
            printf("Enter angle in degrees: ");
            scanf("%lf", &x);
            if (fmod(x, 180.0) == 90.0)
            {
                printf(RED "Math Error: tan undefined at 90 + k*180 degrees!\n" RESET);
                printf("\nPress Enter to continue...");
                getchar();
                getchar();
                continue;
            }
            else
            {
                result = tan(x * M_PI / 180.0);
                if (floor(result) != result)
                    isFloatUsed = 1;
            }
            break;

        default:
            printf(RED "Invalid Choice\n" RESET);
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            continue;
        }

        // Display the result according to type
        printf(GREEN "\nResult: " RESET);
        if (!isFloatUsed && floor(result) == result)
            printf(GREEN "%lld\n" RESET, (long long)result);
        else
            printf(GREEN "%.6lf\n" RESET, result);

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
}

/* ================= FACTORIAL ================= */

long long factorial(int n)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void factorialMenu()
{
    while (1)
    {
        clearScreen();
        printf(CYAN "\n--- FACTORIAL ---\n" RESET);
        printf("Enter number (-1 to go back): ");

        int n;
        scanf("%d", &n);

        if (n == -1)
            return;

        long long res = factorial(n);

        if (res < 0)
            printf(RED "Invalid Input!\n" RESET);
        else
            printf(GREEN "Factorial: %lld\n" RESET, res);

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
}

/* ================= MATRIX ADDITION ================= */

void matrixAddition()
{
    while (1)
    {
        clearScreen();
        printf(CYAN "\n--- MATRIX ADDITION (2x2) ---\n" RESET);
        printf("Enter 0 to go back or 1 to continue: ");

        int option;
        scanf("%d", &option);

        if (option == 0)
            return;

        int A[2][2], B[2][2], C[2][2];

        printf("Enter Matrix A (2x2):\n");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                scanf("%d", &A[i][j]);

        printf("Enter Matrix B (2x2):\n");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                scanf("%d", &B[i][j]);

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                C[i][j] = A[i][j] + B[i][j];

        printf(GREEN "\nResult Matrix:\n" RESET);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
}

/* ================= MAIN ================= */

int main()
{
    int choice;

    while (1)
    {
        clearScreen();

        printf(BLUE "=====================================\n");
        printf("        ADVANCED C CALCULATOR\n");
        printf("=====================================\n" RESET);

        printf(YELLOW "1. Basic Operations\n");
        printf("2. Scientific Operations\n");
        printf("3. Factorial\n");
        printf("4. Matrix Addition\n");
        printf("0. Exit\n" RESET);

        printf("\nChoose Option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            basicOperations();
            break;
        case 2:
            scientificOperations();
            break;
        case 3:
            factorialMenu();
            break;
        case 4:
            matrixAddition();
            break;
        case 0:
            printf(GREEN "\nThank You for Using the Calculator!\n" RESET);
            exit(0);
        default:
            printf(RED "Invalid Choice!\n" RESET);
            getchar();
            getchar();
        }
    }

    return 0;
}
