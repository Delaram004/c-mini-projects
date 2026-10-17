if (gender == 'm' || gender == 'M')
    {
        bmr = 10 * weight + 6.25 * height - 5 * age + 5;
    }
    else
    {
        bmr = 10 * weight + 6.25 * height - 5 * age - 161;
    }

    float activity_factor;

    switch (activity_choice)
    {
        case 1:
            activity_factor = 1.2;
            break;

        case 2:
            activity_factor = 1.375;
            break;

        case 3:
            activity_factor = 1.55;
            break;

        case 4:
            activity_factor = 1.725;
            break;

        case 5:
            activity_factor = 1.9;
            break;
    }

    float tdee = bmr * activity_factor;
    float target_calories;

    switch (goal_choice)
    {
        case 1:
            target_calories = tdee - 500;
            break;

        case 2:
            target_calories = tdee + 300;
            break;

        case 3:
            target_calories = tdee;
            break;
    }

    // Protein target depends on goal and training experience
    float protein_per_kg;

    if (goal_choice == 1)
    {
        protein_per_kg = (training_years >= 2) ? 2.2 : 1.8;
    }
    else if (goal_choice == 2)
    {
        protein_per_kg = (training_years >= 2) ? 2.0 : 1.6;
    }
    else
    {
        protein_per_kg = 1.8;
    }

    float protein_grams = protein_per_kg * weight;
    float protein_calories = protein_grams * 4;
    float remaining_calories = target_calories - protein_calories;

    printf("\n===== Results =====\n");
    printf("BMR: %.0f kcal\n", bmr);
    printf("TDEE (maintenance): %.0f kcal\n", tdee);
    printf("Target daily calories: %.0f kcal\n", target_calories);
    printf("Target protein: %.0f g (%.0f kcal)\n",
           protein_grams, protein_calories);
    printf("Remaining calories for carbs/fat: %.0f kcal\n",
           remaining_calories);

    return 0;
}
