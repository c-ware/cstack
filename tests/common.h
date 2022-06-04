#ifndef CWARE_LIBCSTACK_COMMON_H
#define CWARE_LIBCSTACK_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../src/cstack.h"

/* String stack settings */
#define STRING_STACK_TYPE char*
#define STRING_STACK_FREE(value)
#define STRING_STACK_HEAP 1

/* Stack string stack settings */
#define STRING_STACK_S_TYPE char*
#define STRING_STACK_S_FREE(value)
#define STRING_STACK_S_HEAP 0

struct StringStack {
    char **contents;
    int length;
    int capacity;
};

#endif
