#include <stdio.h>
#include <string.h>

#define MAX_HISTORY 50

int main(void)
{
    char history[MAX_HISTORY][100];
    int count = 0;
    int choice;
    double a, b, result;

    while (1)
    {
        printf("\n===== Menu-Based Calculator =====\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. View History\n6. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 6)
        {
            printf("Goodbye!\n");
            break;
        }

        if (choice == 5)
        {
            printf("\n--- Calculation History ---\n");
            if (count == 0)
                printf("No calculations yet.\n");
            for (int i = 0; i < count; i++)
                printf("%s\n", history[i]);
            continue;
        }

        if (choice < 1 || choice > 6)
        {
            printf("Invalid option.\n");
            continue;
        }

        printf("First number: ");
        if (scanf("%lf", &a) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Second number: ");
        if (scanf("%lf", &b) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        char op;
        switch (choice)
        {
            case 1: result = a + b; op = '+'; break;
            case 2: result = a - b; op = '-'; break;
            case 3: result = a * b; op = '*'; break;
            case 4:
                if (b == 0)
                {
                    printf("Error: cannot divide by zero!\n");
                    continue;
                }
                result = a / b; op = '/'; break;
        }

        printf("Result: %.2f\n", result);

        if (count < MAX_HISTORY)
        {
            snprintf(history[count], sizeof(history[count]), "%.2f %c %.2f = %.2f", a, op, b, result);
            count++;
        }
    }
    return 0;
}
