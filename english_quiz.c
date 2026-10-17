#include <stdio.h>

#define NUM_QUESTIONS 10
#define NUM_OPTIONS 4
#define NUM_LEVELS 5

int main(void)
{
    char *questions[NUM_QUESTIONS] = {
        "She ___ a teacher.",
        "What is the plural of 'child'?",
        "I have lived here ___ 2015.",
        "He is very ___ ; he never gets angry.",
        "If I ___ more time, I would learn Spanish.",
        "Choose the correct synonym for 'reluctant'.",
        "By the time we arrived, the meeting ___.",
        "Which sentence uses the passive voice correctly?",
        "Despite ___ tired, she finished the project.",
        "Select the closest meaning of 'ubiquitous'."
    };

    char *options[NUM_QUESTIONS][NUM_OPTIONS] = {
        {"am", "is", "are", "be"},
        {"childs", "childes", "children", "child's"},
        {"for", "since", "at", "in"},
        {"patient", "patience", "patiently", "patients"},
        {"have", "had", "would have", "has"},
        {"eager", "unwilling", "confident", "curious"},
        {"already started", "has already started",
         "had already started", "already starts"},
        {"The cake was eaten by the children.",
         "The children was eaten the cake.",
         "The cake ate by the children.",
         "The children eating the cake."},
        {"being", "be", "to be", "been"},
        {"rare", "omnipresent", "ancient", "fragile"}
    };

    // 0-indexed correct option for each question:
    // B, C, B, A, B, B, C, A, A, B
    int correct_answers[NUM_QUESTIONS] = {
        1, 2, 1, 0, 1, 1, 2, 0, 0, 1
    };

    char *level_names[NUM_LEVELS] = {
        "A1", "A2", "B1", "B2", "C1"
    };

    int final_level_index = -1; // -1 means below A1

    printf("===== English Placement Quiz =====\n");
    printf("This quiz measures grammar and vocabulary only.\n");

    for (int level = 0; level < NUM_LEVELS; level++)
    {
        int correct_this_level = 0;

        for (int q = level * 2; q < level * 2 + 2; q++)
        {
            printf("\n[%s] %s\n", level_names[level], questions[q]);

            for (int o = 0; o < NUM_OPTIONS; o++)
            {
                printf("  %d. %s\n", o + 1, options[q][o]);
            }

            int answer;

            do
            {
                printf("Your answer (1-4): ");

                if (scanf("%d", &answer) != 1)
                {
                    printf("Invalid input. Please enter a number from 1 to 4.\n");

                    while (getchar() != '\n');

                    answer = 0;
                }
                else if (answer < 1 || answer > 4)
                {
                    printf("Invalid choice. Please enter a number from 1 to 4.\n");
                }

            } while (answer < 1 || answer > 4);

            if (answer - 1 == correct_answers[q])
            {
                printf("Correct!\n");
                correct_this_level++;
            }
            else
            {
                printf("Incorrect.\n");
            }
        }

        if (correct_this_level == 0)
        {
            printf("\nStopping here - this level was too difficult.\n");
            break;
        }

        final_level_index = level;
    }

    printf("\n===== Result =====\n");

    if (final_level_index == -1)
    {
        printf("Estimated level: Below A1\n");
    }
    else
    {
        printf("Estimated level: %s\n", level_names[final_level_index]);
    }

    printf("(Note: this quiz does not assess pronunciation, accent, or spoken fluency.)\n");

    return 0;
}
