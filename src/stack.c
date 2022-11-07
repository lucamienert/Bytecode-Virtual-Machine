#include "../include/stack.h"

stack_t *init_stack(void)
{
    stack_t *stack = malloc(sizeof(struct Stack));

    for (int32_t i = 0; i < MAX_STACK_SIZE; ++i)
        stack->elements[i] = NULL;

    stack->top_element = -1;

    return stack;
}

bool is_empty(stack_t *stack)
{
    return stack->top_element == -1;
}

bool is_full(stack_t *stack)
{
    return stack->top_element >= MAX_STACK_SIZE -1;
}

status_t *push(stack_t *stack, void *key)
{
    if (is_full(stack))
        return FAILURE;

    stack->elements[++stack->top_element] = key;
    return SUCCESS;
}

void *pop(stack_t *stack)
{
    if (is_empty(stack))
        return (void*) 0;

    return stack->elements[stack->top_element--];
}

void *top(stack_t *stack)
{
    if (is_empty(stack))
        return (void*) 0;

    return stack->elements[stack->top_element];
}

void stack_free(stack_t *stack)
{
    void *poped = pop(stack);
    while (poped) 
    {
        free(poped);
        poped = pop(stack);
    }
    
    free(stack);
}