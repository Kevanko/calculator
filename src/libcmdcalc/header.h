#pragma once

#include <libcmdcalc/stacks.h>

int check(char* str);
int prioritet(char symbol);
double match(double a, double b, char s);
void process(StackDouble** st_double, StackChar** st_char);
void print_error(char* str, int id);