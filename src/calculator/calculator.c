#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libcalculator/header.h>

int check(char* str)
{
    int count = 0, bracket = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == ' ')
            continue;

        if ((str[i] >= '0' && str[i] <= '9')) {
            char* end;
            strtod(&str[i], &end);
            i = end - str - 1;
            count += 1;
        } else if (
                str[i] == '/' || str[i] == '*' || str[i] == '+'
                || str[i] == '-') {
            count -= 1;
        } else if (str[i] == '(') {
            if (count == 1)
                return 1;
            bracket += 1;
        } else if (str[i] == ')') {
            if (count == 0)
                return 1;
            bracket -= 1;
        } else
            return 1;

        if (count < 0 || count > 1 || bracket < 0) {
            return 1;
        }
    }
    if (bracket == 0 && count == 1)
        return 0;
    else
        return 1;
}
int main()
{
    char str[MAX_LENGTH];
    fgets(str, MAX_LENGTH, stdin);
    str[strlen(str) - 1] = '\0';

    double num;

    printf("%d\n", check(str));

    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            char* end;
            num = strtod(&str[i], &end);
            printf("%.0f", num);
            i = end - str - 1;
        } else if (str[i] != ' ')
            printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
