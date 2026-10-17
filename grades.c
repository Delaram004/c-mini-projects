#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

int main(void)
{
    char names[MAX_STUDENTS][50];
    int scores[MAX_STUDENTS];
    int n;

    printf("Number of students: ");
    if (scanf("%d", &n) != 1  n < 1  n > MAX_STUDENTS)
    {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Name of student %d: ", i + 1);
        scanf("%49s", names[i]);
        printf("Score for %s: ", names[i]);
        scanf("%d", &scores[i]);
    }

    int sum = 0, max = scores[0], min = scores[0];
    int max_index = 0, min_index = 0;

    for (int i = 0; i < n; i++)
    {
        sum += scores[i];
        if (scores[i] > max)
        {
            max = scores[i];
            max_index = i;
        }
        if (scores[i] < min)
        {
            min = scores[i];
            min_index = i;
        }
    }

    float average = (float) sum / n;

    printf("\n===== Grade Report =====\n");
    printf("Average: %.2f\n", average);
    printf("Highest score: %s with %d\n", names[max_index], max);
    printf("Lowest score: %s with %d\n", names[min_index], min);

    return 0;
}
