#include <stdio.h>

#define NUM_QUESTIONS 10
#define NUM_OPTIONS 4
#define NUM_LEVELS 5

int main(void)
{
    char *questions[NUM_QUESTIONS] = {
        "___ Hund ist braun. (Artikel)",
        "Was bedeutet 'Haus' auf Englisch? (Wortschatz)",
        "Ich fahre ___ Berlin. (Praeposition)",
        "Er ___ jeden Tag mit dem Bus. (fahren - Grammatik)",
        "Ich ___ gestern ins Kino gegangen. (Perfekt)",
        "Was ist das Gegenteil von 'freundlich'? (Wortbildung)",
        "Wenn ich reich ___, wuerde ich ein Haus kaufen. (Konjunktiv II)",
        "Das Buch liegt ___ dem Tisch. (Praeposition + Kasus)",
        "Nachdem er die Pruefung ___ hatte, ging er nach Hause. (Plusquamperfekt)",
        "Was bedeutet 'unumgaenglich'? (Wortschatz)"
    };

    char *options[NUM_QUESTIONS][NUM_OPTIONS] = {
        {"Der", "Die", "Das", "Den"},
        {"Car", "House", "Tree", "Dog"},
        {"nach", "zu", "in", "auf"},
        {"fahre", "faehrst", "faehrt", "fahrt"},
        {"habe", "bin", "hatte", "war"},
        {"unfreundlich", "freundlichlos", "freundlichunt", "freundlichig"},
        {"bin", "waere", "war", "sein"},
        {"auf den", "auf dem", "auf des", "auf der"},
        {"bestehen", "bestanden", "besteht", "bestand"},
        {"optional", "unvermeidlich", "verboten", "unmoeglich"}
    };

    // 0-indexed correct option for each question
    int correct_answers[NUM_QUESTIONS] = {0, 1, 0, 2, 1, 0, 1, 1, 1, 1};

    char *level_names[NUM_LEVELS] = {"A1", "A2", "B1", "B2", "C1"};

    int final_level_index = -1; // -1 means below A1

    printf("===== German Placement Quiz =====\n");
    printf("Covers vocabulary, grammar, articles, prepositions, and word formation.\n");

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

    printf("(Note: this quiz does not assess pronunciation or spoken fluency.)\n");

    return 0;
}
