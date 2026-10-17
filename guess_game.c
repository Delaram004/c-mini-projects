#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int number = rand() % 100 + 1;
    int guess, attempts = 0;
    int best = -1;

    FILE *file = fopen("record.txt", "r");
    if (file != NULL)
    {
        if (fscanf(file, "%d", &best) != 1 || best < 1)
            best = -1;
        fclose(file);
    }

    printf("=== Number Guessing Game ===\n");
    printf("Guess a number between 1 and 100.\n");
    if (best != -1)
        printf("Current record: %d attempts\n", best);

    while (1)
    {
        printf("Your guess: ");
        if (scanf("%d", &guess) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (guess < 1 || guess > 100)
        {
            printf("Please enter a number between 1 and 100.\n");
            continue;
        }

        attempts++;

        if (guess < number)
            printf("Too low!\n");
        else if (guess > number)
            printf("Too high!\n");
        else
        {
            printf("Correct! You guessed it in %d attempts.\n", attempts);
            break;
        }
    }

    if (best == -1 || attempts < best)
    {
        printf("New record!\n");
        file = fopen("record.txt", "w");
        if (file != NULL)
        {
            fprintf(file, "%d", attempts);
            fclose(file);
        }
    }

    return 0;
}
