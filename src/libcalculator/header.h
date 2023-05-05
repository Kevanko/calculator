#pragma once
#define MAX_LENGTH 4096

typedef struct StackInt {
    int value;
    struct StackInt* next;
} StackInt;

typedef struct StackChar {
    char value;
    struct StackChar* next;
} StackChar;

StackInt* init_stack_int(int value);
StackInt* push_int(StackInt* stack, int value);
StackInt* pop_int(StackInt* stack);

StackChar* init_stack_char(char value);
StackChar* push_char(StackChar* stack, char value);
StackChar* pop_char(StackChar* stack);
