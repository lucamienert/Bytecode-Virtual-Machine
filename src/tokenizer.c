#include "../include/tokenizer.h"

#include <stdlib.h>
#include <string.h>

static status_t vm_init_token_node (token_t **token_node, const char *token, const unsigned int line_num) 
{
    *token_node = (token_t*) malloc(sizeof(struct Token));
    token_t *node = *token_node;

    if (node == NULL)
        return FAILURE;
    
    strncpy(node->token, token, MAX_LINE_LENGTH - 1);
    node->line_num = line_num;
    node->next_token = NULL;

    return SUCCESS;
}

status_t vm_get_token_list(FILE *file, token_t **token_list)
{
    char line[MAX_LINE_LENGTH];
    char *line_ptr = NULL;
    char *checkpoint = NULL;
    char *token = NULL;
    const char delim[] = " \n";

    uint32_t line_num = 0;
    uint32_t token_length = 0;

    token_t *next_token = NULL;
    token_t *prev_token = NULL;

    vm_init_token_node(token_list, "Dummy", 0);
    prev_token = *token_list;
    
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL)
        return SUCCESS;

    do 
    {
        ++line_num;
        line_ptr = line;

        while ((token = strtok_r(line_ptr, delim, &checkpoint)) != NULL) 
        {
            line_ptr = NULL;
            token_length = strlen(token);

            if (token_length == 0)
                continue;

            if (token[0] == '#')
                break;
            
            vm_init_token_node(&next_token, token, line_num);
            prev_token->next_token = next_token;
            prev_token = next_token;
        }
    } 
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL);

    return SUCCESS;
}

status_t vm_free_token_list(token_t *token_list)
{
    token_t *previous_token = NULL;
    token_t *next_token = NULL;

    previous_token = token_list;
    next_token = NULL;

    while (previous_token) 
    {
        next_token = previous_token->next_token;
        free(previous_token);
        previous_token = next_token;
    }

    return SUCCESS;
}