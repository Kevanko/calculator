#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <libcalculator/header.h>

StackInt* init_stack_int(int value)
{
    StackInt* stack = (StackInt*)malloc(sizeof(StackInt));
    if (!stack)
        return NULL;
    stack->value = value;
    stack->next = NULL;
    return stack;
}

StackInt* push_int(StackInt* stack, int value)
{
    StackInt* new = init_stack_int(value);
    if (!new)
        return NULL;
    if (!stack) {
        stack = new;
        return stack;
    }
    new->next = stack;
    stack = new;
    return stack;
}

StackInt* pop_int(StackInt* stack)
{
    if (!stack)
        return NULL;
    if (!stack->next) {
        free(stack);
        return NULL;
    }
    StackInt * free_stack = stack;
    stack = stack->next;
    free(free_stack);
    return stack;
}

StackChar* init_stack_char(char value)
{
    StackChar* stack = (StackChar*)malloc(sizeof(StackChar));
    if (!stack)
        return NULL;
    stack->value = value;
    stack->next = NULL;
    return stack;
}

StackChar* push_char(StackChar* stack, char value)
{
    StackChar* new = init_stack_char(value);
    if (!new)
        return NULL;
    if (!stack) {
        stack = new;
        return stack;
    }
    new->next = stack;
    stack = new;
    return stack;
}

StackChar* pop_char(StackChar* stack)
{
    if (!stack)
        return NULL;
    if (!stack->next) {
        free(stack);
        return NULL;
    }
    StackChar * free_stack = stack;
    stack = stack->next;
    free(free_stack);
    return stack;
}

