#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libcmdcalc/header.h>

int main(int argc, char** argv)
{
    for (int arg = 1; arg < argc; arg++) {
        char* str = argv[arg];
        int status = check(str);
        if (status) {
            print_error(str, status);
            continue;
        } else {
            double result = main_program(str);
            printf("%s = %.2f\n", str, result);
        }
    }
    return 0;
}
