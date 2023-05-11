#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libcmdcalc/header.h>
#include <libcmdcalc/stacks.h>

int main(int argc, char** argv)
{
    for (int arg = 1; arg < argc; arg++) {
        char* str = argv[arg];
        int status = check(str);
        if (status) {
            print_error(str, status);
            continue;
        }
        StackDouble* st_double = NULL;
        StackChar* st_char = NULL;
        for (size_t i = 0; i < strlen(str); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                char* end;
                double num = strtod(&str[i], &end);
                i = end - str - 1;
                st_double = push_double(st_double, num);

            } else if (str[i] != ' ') {
                if (st_char == NULL
                    || priority(str[i]) > priority(st_char->value)
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
        while (!is_empty_double(st_double)) {
            double a = pop_double(&st_double);
            printf("%.2f\n", a);
        }
    }
    return 0;
}
