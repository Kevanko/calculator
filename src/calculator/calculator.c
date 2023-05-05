#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <libcalculator/header.h>

int main()
{
    char str[MAX_LENGTH];
    fgets(str, MAX_LENGTH, stdin);
    str[strlen(str) - 1] = '\0';

    double num;

    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            char* end;
            num = strtod(&str[i], &end);
            printf("%f ", num);
            i = end - str;
        } else
            printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
