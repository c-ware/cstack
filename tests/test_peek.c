/*
 * Test the peek function
*/

#include "common.h"

int main(void) {
    char *buffer[4] = {0};
    struct StringStack *new_stack = NULL;
    struct StringStack another_stack = {0};

    /* Test a heap stack */
    new_stack = cstack_init(new_stack, STRING_STACK);

    cstack_push(new_stack, "foo", STRING_STACK);
    assert(strcmp(cstack_peek(new_stack, STRING_STACK), "foo") == 0);

    cstack_push(new_stack, "bar", STRING_STACK);
    assert(strcmp(cstack_peek(new_stack, STRING_STACK), "bar") == 0);

    /* Test a stack stack */
    another_stack = cstack_init_stack(&another_stack, buffer, 4,
                                      STRING_STACK_S);

    cstack_push(&another_stack, "foo", STRING_STACK);
    assert(strcmp(cstack_peek(&another_stack, STRING_STACK_S), "foo") == 0);

    cstack_push(&another_stack, "bar", STRING_STACK);
    assert(strcmp(cstack_peek(&another_stack, STRING_STACK_S), "bar") == 0);

    cstack_free(new_stack, STRING_STACK);
    cstack_free(&another_stack, STRING_STACK_S);

    return EXIT_SUCCESS;
}
