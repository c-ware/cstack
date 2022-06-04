/*
 * Test the is_empty macro
*/

#include "common.h"

int main(void) {
    char *storage = NULL;
    char *buffer[4] = {0};
    struct StringStack *strings = NULL;
    struct StringStack strings_2 = {0};

    strings = cstack_init(strings, STRING_STACK);
    strings_2 = cstack_init_stack(&strings_2, buffer, 4, STRING_STACK_S);

    assert(cstack_is_empty(strings, STRING_STACK) == 1);
    assert(cstack_is_empty(&strings_2, STRING_STACK_S) == 1);

    cstack_push(strings, "foo", STRING_STACK);
    cstack_push(&strings_2, "foo", STRING_STACK_S);
    assert(cstack_is_empty(strings, STRING_STACK) == 0);
    assert(cstack_is_empty(&strings_2, STRING_STACK_S) == 0);

    cstack_push(strings, "bar", STRING_STACK);
    cstack_push(&strings_2, "bar", STRING_STACK_S);
    assert(cstack_is_empty(strings, STRING_STACK) == 0);
    assert(cstack_is_empty(&strings_2, STRING_STACK_S) == 0);

    cstack_push(strings, "baz", STRING_STACK);
    cstack_push(&strings_2, "baz", STRING_STACK_S);
    assert(cstack_is_empty(strings, STRING_STACK) == 0);
    assert(cstack_is_empty(&strings_2, STRING_STACK_S) == 0);

    storage = cstack_pop(strings, STRING_STACK);
    storage = cstack_pop(&strings_2, STRING_STACK_S);
    assert(cstack_is_empty(strings, STRING_STACK) == 0);
    assert(cstack_is_empty(&strings_2, STRING_STACK_S) == 0);

    storage = cstack_pop(strings, STRING_STACK);
    storage = cstack_pop(&strings_2, STRING_STACK_S);
    assert(cstack_is_empty(strings, STRING_STACK) == 0);
    assert(cstack_is_empty(&strings_2, STRING_STACK_S) == 0);

    storage = cstack_pop(strings, STRING_STACK);
    storage = cstack_pop(&strings_2, STRING_STACK_S);
    assert(cstack_is_empty(strings, STRING_STACK) == 1);
    assert(cstack_is_empty(&strings_2, STRING_STACK_S) == 1);

    (void) storage;

    cstack_free(strings, STRING_STACK);
    cstack_free(&strings_2, STRING_STACK_S);

    return EXIT_SUCCESS;
}
