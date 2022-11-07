#ifndef STACK_H_
#define STACK_H_

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "error.h"

#define MAX_STACK_SIZE 100

typedef struct Stack
{
    void *elements[MAX_STACK_SIZE];
    int32_t top_element;
} stack_t;

/**
 * Creates new Stack
 * 
 * @returns new Stack
*/
stack_t *init_stack(void);

/**
 * 
*/
bool is_empty(stack_t *stack);

/**
 * 
*/
bool is_full(stack_t *stack);

/**
 * 
*/
status_t *push(stack_t *stack, void *key);

/**
 * 
*/
void *pop(stack_t *stack);

/**
 * 
*/
void *top(stack_t *stack);

/**
 * 
*/
void stack_free(stack_t *stack);


#endif