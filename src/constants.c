#include "../include/constants.h"

#include <string.h>

const instruction_t INST_SET[] = {
    BYTECODE_DEF(get_ins_tuple_macro)
};

symbol_t get_instruction(const bytecode_t bytecode) 
{
    for (int32_t i = 0; i < N_INST; ++i) 
    {
        if (INST_SET[i].bytecode == bytecode)
            return (symbol_t)i;
    }

    return ERR;
}

bytecode_t get_bytecode(const char *instruction) 
{
    for (int32_t i = 0; i < N_INST; ++i) 
    {
        if (strcmp(INST_SET[i].name, instruction) == 0)
            return INST_SET[i].bytecode;
    }

    return INST_SET[ERR].bytecode;
}

status_t vm_get_integer_from_bytecode(const bytecode_t *compiled_code_ptr, int32_t *int_val)
{
    int32_t value = 0;

    value = compiled_code_ptr[0];
    value |= compiled_code_ptr[1] << 8;
    value |= compiled_code_ptr[2] << 16;
    value |= compiled_code_ptr[3] << 24;

    *int_val = value;

    return SUCCESS;
}

status_t vm_put_integer_to_bytecode(bytecode_t *compiled_code_ptr, const int32_t int_val)
{
    int32_t value = 0;

    compiled_code_ptr[0] = (bytecode_t)int_val;
    compiled_code_ptr[1] = (bytecode_t)(int_val >> 8);
    compiled_code_ptr[2] = (bytecode_t)(int_val >> 16);
    compiled_code_ptr[3] = (bytecode_t)(int_val >> 24);

    return SUCCESS;
}