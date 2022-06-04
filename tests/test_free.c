/*
 * Test the free macro.
*/

#include "common.h"

int main(void) {
    char *buffer[4] = {0};
    struct StringStack *stack = NULL;
    struct StringStack stack_2 = {0};

    stack = cstack_init(stack, STRING_STACK);
    stack_2 = cstack_init_stack(&stack_2, buffer, 4, STRING_STACK_S);

    /* Push some values to the heap stack */
    cstack_push(stack, "foo", STRING_STACK);
    cstack_push(stack, "bar", STRING_STACK);
    cstack_push(stack, "baz", STRING_STACK);
    cstack_push(stack, "tuna", STRING_STACK);
    cstack_push(stack, "spam", STRING_STACK);
    cstack_push(stack, "thud", STRING_STACK);

    /* Push some values to the stack stack */
    cstack_push(&stack_2, "foo", STRING_STACK_S);
    cstack_push(&stack_2, "bar", STRING_STACK_S);
    cstack_push(&stack_2, "baz", STRING_STACK_S);
    cstack_push(&stack_2, "tuna", STRING_STACK_S);

    assert(stack->length == 6);
    assert(stack_2.length == 4);

    cstack_free(stack, STRING_STACK);
    cstack_free(&stack_2, STRING_STACK_S);

    /* Since the heap stack will be freed, we can only check the stack stack */
    assert(stack_2.length == 0);

    return EXIT_SUCCESS;
}
