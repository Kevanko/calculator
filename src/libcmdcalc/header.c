#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libcmdcalc/header.h>
#include <libcmdcalc/stacks.h>

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
                return (int)i;
            bracket += 1;
        } else if (str[i] == ')') {
            if (count == 0)
                return (int)i;
            bracket -= 1;
        } else
            return (int)i;

        if (count < 0 || count > 1 || bracket < 0) {
            return i;
        }
    }
    if (bracket == 0 && count == 1)
        return 0;
    else
        return (int)strlen(str);
}

int priority(char symbol)
{
    switch (symbol) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;

    default:
        return 0;
    }
}

double match(double a, double b, char s)
{
    switch (s) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

void process(StackDouble** st_double, StackChar** st_char)
{
    double a = pop_double(st_double);
    double b = pop_double(st_double);
    char symbol = pop_char(st_char);
    *st_double = push_double(*st_double, match(b, a, symbol));
}

double main_program(char* str)
{
    StackDouble* st_double = NULL;
    StackChar* st_char = NULL;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            char* end;
            double num = strtod(&str[i], &end);
            i = end - str - 1;
            st_double = push_double(st_double, num);

        } else if (str[i] != ' ') {
            if (st_char == NULL || priority(str[i]) > priority(st_char->value)
                || str[i] == '(') {
                st_char = push_char(st_char, str[i]);
            } else if (str[i] == ')') {
                while (get_char(st_char) != '(') {
                    process(&st_double, &st_char);
                }
                pop_char(&st_char);
            } else {
                while (priority(str[i]) <= priority(get_char(st_char))) {
                    process(&st_double, &st_char);
                    if (is_empty_char(st_char))
                        break;
                }
                st_char = push_char(st_char, str[i]);
            }
        }
    }
    while (!is_empty_char(st_char)) {
        process(&st_double, &st_char);
    }

    return pop_double(&st_double);
}

void print_error(char* str, int id)
{
    printf("%s\n", str);
    for (int i = 0; i < id; i++) {
        printf(" ");
    }
    printf("^\nERROR\n");
}