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

void process(StackDouble** stack_d, StackChar** stack_c)
{
    double a = pop_double(stack_d);
    double b = pop_double(stack_d);
    char symbol = pop_char(stack_c);
    *stack_d = push_double(*stack_d, match(b, a, symbol));
}

double main_program(char* str)
{
    StackDouble* stack_d = NULL;
    StackChar* stack_c = NULL;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            char* end;
            double num = strtod(&str[i], &end);
            i = end - str - 1;
            stack_d = push_double(stack_d, num);

        } else if (str[i] != ' ') {
            if (stack_c == NULL || priority(str[i]) > priority(stack_c->value)
                || str[i] == '(') {
                stack_c = push_char(stack_c, str[i]);
            } else if (str[i] == ')') {
                while (get_char(stack_c) != '(') {
                    process(&stack_d, &stack_c);
                }
                pop_char(&stack_c);
            } else {
                while (priority(str[i]) <= priority(get_char(stack_c))) {
                    process(&stack_d, &stack_c);
                    if (is_empty_char(stack_c))
                        break;
                }
                stack_c = push_char(stack_c, str[i]);
            }
        }
    }
    while (!is_empty_char(stack_c)) {
        process(&stack_d, &stack_c);
    }

    return pop_double(&stack_d);
}

void print_error(char* str, int id)
{
    printf("%s\n", str);
    for (int i = 0; i < id; i++) {
        printf(" ");
    }
    printf("^\nERROR\n");
}