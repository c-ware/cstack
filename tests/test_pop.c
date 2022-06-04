/*
 * Tests popping values from a stack
*/

#include "common.h"

int main(void) {
    char *storage = NULL;
    char *buffer[4] = {0};
    struct StringStack *strings = NULL;
    struct StringStack strings_2 = {0};

    strings = cstack_init(strings, STRING_STACK);
    strings_2 = cstack_init_stack(&strings_2, buffer, 4, STRING_STACK_S);

    /* Push to heap stack */
    cstack_push(strings, "foo", STRING_STACK);
    cstack_push(strings, "bar", STRING_STACK);
    cstack_push(strings, "baz", STRING_STACK);
    cstack_push(strings, "tuna", STRING_STACK);

    /* Push to stack stack */
    cstack_push(&strings_2, "foo", STRING_STACK_S);
    cstack_push(&strings_2, "bar", STRING_STACK_S);
    cstack_push(&strings_2, "baz", STRING_STACK_S);
    cstack_push(&strings_2, "tuna", STRING_STACK_S);

    assert(strings->length == 4);

    /* Test heap operations */
    storage = cstack_pop(strings, STRING_STACK);
    assert(strcmp(storage, "tuna") == 0);
    assert(strings->length == 3);
    assert(strings->capacity == CSTACK_INITIAL_SIZE);

    storage = cstack_pop(strings, STRING_STACK);
    assert(strcmp(storage, "baz") == 0);
    assert(strings->length == 2);
    assert(strings->capacity == CSTACK_INITIAL_SIZE);

    storage = cstack_pop(strings, STRING_STACK);
    assert(strcmp(storage, "bar") == 0);
    assert(strings->length == 1);
    assert(strings->capacity == CSTACK_INITIAL_SIZE);

    storage = cstack_pop(strings, STRING_STACK);
    assert(strcmp(storage, "foo") == 0);
    assert(strings->length == 0);
    assert(strings->capacity == CSTACK_INITIAL_SIZE);

    /* Test stack operations */
    storage = cstack_pop(&strings_2, STRING_STACK_S);
    assert(strcmp(storage, "tuna") == 0);
    assert(strings_2.length == 3);
    assert(strings_2.capacity == 4);

    storage = cstack_pop(&strings_2, STRING_STACK_S);
    assert(strcmp(storage, "baz") == 0);
    assert(strings_2.length == 2);
    assert(strings_2.capacity == 4);

    storage = cstack_pop(&strings_2, STRING_STACK_S);
    assert(strcmp(storage, "bar") == 0);
    assert(strings_2.length == 1);
    assert(strings_2.capacity == 4);

    storage = cstack_pop(&strings_2, STRING_STACK_S);
    assert(strcmp(storage, "foo") == 0);
    assert(strings_2.length == 0);
    assert(strings_2.capacity == 4);

    cstack_free(strings, STRING_STACK);
    cstack_free(&strings_2, STRING_STACK_S);

    return EXIT_SUCCESS;
}
