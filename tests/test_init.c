/*
 * Test the initialisation function
*/

#include "common.h"

int main(void) {
    char *buffer[4] = {0};
    struct StringStack *new_stack = NULL;
    struct StringStack another_stack = {0};

    /* Test a heap stack */
    new_stack = cstack_init(new_stack, STRING_STACK);

    assert(new_stack->length == 0);
    assert(new_stack->capacity == CSTACK_INITIAL_SIZE);
    assert(new_stack->contents != NULL);

    /* Test a stack stack */
    another_stack = cstack_init_stack(&another_stack, buffer, 4,
                                      STRING_STACK_S);

    assert(another_stack.length == 0);
    assert(another_stack.capacity == 4);
    assert(another_stack.contents == buffer);

    cstack_free(new_stack, STRING_STACK);
    cstack_free(&another_stack, STRING_STACK_S);

    return EXIT_SUCCESS;
}
