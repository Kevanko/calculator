#pragma once

typedef struct Stack {
  void *value;
  struct Stack *next;
} Stack;