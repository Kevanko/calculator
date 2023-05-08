#pragma once

typedef struct StackDouble {
    double value;
    struct StackDouble* next;
} StackDouble;

typedef struct StackChar {
    char value;
    struct StackChar* next;
} StackChar;

StackDouble* init_stack_double(double value);
StackDouble* push_double(StackDouble* stack, double value);
double pop_double(StackDouble** stack);
int is_empty_double(StackDouble* st);
double get_double(StackDouble* st);

StackChar* init_stack_char(char value);
StackChar* push_char(StackChar* stack, char value);
char pop_char(StackChar** stack);
int is_empty_char(StackChar* st);
char get_char(StackChar* st);
