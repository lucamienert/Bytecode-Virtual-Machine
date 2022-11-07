#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#pragma once

#include <stdint.h>

#include "error.h"

#define MAX_CODE_LENGHT  1000
#define MAX_LINE_LENGTH  80
#define LABEL_LENGTH     10
#define INSTR_LENGHT     5
#define N_LABELS         10

typedef unsigned char bytecode_t;

/**
 * List of Instructions read by the Interpreter
*/
#define BYTECODE_DEF(list_macro) list_macro(REAH),        \
        list_macro(READ),                                 \
        list_macro(REAC),                                 \
        list_macro(WRTH),                                 \
        list_macro(WRTD),                                 \
        list_macro(WRTC),                                 \
        list_macro(ADD),                                  \
        list_macro(SUB),                                  \
        list_macro(MUL),                                  \
        list_macro(DIV),                                  \
        list_macro(POP),                                  \
        list_macro(EQU),                                  \
        list_macro(GRT),                                  \
        list_macro(LST),                                  \
        list_macro(GOTO),                                 \
        list_macro(GOIF),                                 \
        list_macro(GOUN),                                 \
        list_macro(END),                                  \
        list_macro(DUP),                                  \
        list_macro(FLIP),                                 \
        list_macro(PUSH),                                 \
        list_macro(ERR),                                  \
        list_macro(NOP),                                  \
        list_macro(LAB),                                  \
        list_macro(IND),                                  \
        list_macro(GET),                                  \
        list_macro(PUT),

#define get_symbol_macro(symbol) symbol
#define get_ins_tuple_macro(symbol) {#symbol, symbol}

typedef enum {
    BYTECODE_DEF(get_symbol_macro)
    N_INST
} symbol_t;

typedef struct Instruction {
    char name[5];
    bytecode_t bytecode;
} instruction_t;

typedef enum {
    FALSE, // 0
    TRUE   // 1
} bool_flag_t;

const instruction_t INST_SET[N_INST];

/**
 * Reads the next Instruction
 * 
 * @returns symbol_t
*/
symbol_t get_instruction(const bytecode_t bc);

/**
 * Reads the next Bytecode from the instruction
 * 
 * @returns bytecode_t [unsigned char]
*/
bytecode_t get_bytecode (const char *instruction);

/**
 * Convert Int to Bytecode
 * 
 * @returns status_t {0, 1}
*/
status_t vm_get_integer_from_bytecode(const bytecode_t *compiled_code_ptr, int32_t *int_val);

/**
 * Convert Bytecode to Int
 * 
 * @returns status_t {0, 1}
*/
status_t vm_put_integer_to_bytecode(bytecode_t *compiled_code_ptr, const int32_t int_val);

#endif