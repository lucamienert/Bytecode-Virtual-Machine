#ifndef ERROR_H_
#define ERROR_H_

#pragma once

typedef enum
{
    FAILURE, // 0
    SUCCESS  // 1
} status_t;

typedef enum
{
    ERROR,   // 0
    NO_ERROR // 1
} error_flags_t;

#endif