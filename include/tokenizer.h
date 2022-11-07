#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#pragma once

#include <stdio.h>
#include <stdint.h>

#include "constants.h"
#include "error.h"

typedef struct Token 
{
    char token[MAX_LINE_LENGTH];
    uint32_t line_num;
    struct Token *next_token;
} token_t;

/**
 * Fill the List with Tokens
 * 
 * @returns status_t {0, 1}
*/
status_t vm_get_token_list(FILE *file, token_t **tokenList);

/**
 * Memory handling
 * 
 * @returns status_t {0, 1}
*/
status_t vm_free_token_list(token_t *tokenList);

#endif