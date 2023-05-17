#pragma once

#include <libcmdcalc/stacks.h>

int check(char* str);
int priority(char symbol);
double match(double a, double b, char s);
void process(StackDouble** stack_d, StackChar** stack_c);
double main_program(char* str);
void print_error(char* str, int id);