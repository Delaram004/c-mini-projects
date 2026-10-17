#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    int length;
    int use_upper, use_lower, use_digits, use_symbols;

    printf("Password length: ");
    if (scanf("%d", &length) != 1  length < 1  length > 100)
    {
        printf("Password length must be between 1 and 100.\n");
        return 1;
    }

    printf("Include uppercase letters? (1=yes 0=no): ");
    scanf("%d", &use_upper);
    printf("Include lowercase letters? (1=yes 0=no): ");
    scanf("%d", &use_lower);
    printf("Include digits? (1=yes 0=no): ");
    scanf("%d", &use_digits);
    printf("Include symbols? (1=yes 0=no): ");
    scanf("%d", &use_symbols);

    char pool[100] = "";
    if (use_upper)
        strcat(pool, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (use_lower)
        strcat(pool, "abcdefghijklmnopqrstuvwxyz");
    if (use_digits)
        strcat(pool, "0123456789");
    if (use_symbols)
        strcat(pool, "!@#$%^&*()-_=+");

    int pool_len = strlen(pool);
    if (pool_len == 0)
    {
        printf("You must select at least one character type!\n");
        return 1;
    }

    srand(time(NULL));
    char password[101];

    for (int i = 0; i < length; i++)
        password[i] = pool[rand() % pool_len];
    password[length] = '\0';

    printf("Generated password: %s\n", password);

    return 0;
}
