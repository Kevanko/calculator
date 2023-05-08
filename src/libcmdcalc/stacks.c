#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <libcmdcalc/stacks.h>

StackDouble* init_stack_double(double value)
{
    StackDouble* stack = (StackDouble*)malloc(sizeof(StackDouble));
    if (!stack)
        return NULL;
    stack->value = value;
    stack->next = NULL;
    return stack;
}

StackDouble* push_double(StackDouble* stack, double value)
{
    StackDouble* new = init_stack_double(value);
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

double pop_double(StackDouble** stack)
{
    if (!(*stack))
        return -1;

    double value = (*stack)->value;
    StackDouble* tmp = *stack;

    if (!(*stack)->next) {
        *stack = NULL;
    } else {
        *stack = (*stack)->next;
    }

    free(tmp);
    return value;
}

int is_empty_double(StackDouble* st){
    if(!st)
        return 1;
    return 0;
}

double get_double(StackDouble* st){
    return st->value;
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

char pop_char(StackChar** stack)
{
    if (!(*stack))
        return '\0';

    char value = (*stack)->value;
    StackChar* tmp = *stack;

    if (!(*stack)->next) {
        *stack = NULL;
    } else {
        *stack = (*stack)->next;
    }

    free(tmp);
    return value;
}

int is_empty_char(StackChar* st){
    if(!st)
        return 1;
    return 0;
}

char get_char(StackChar* st){
    return st->value;
}
