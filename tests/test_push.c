/*
 * Tests pushing values onto a stack
 *
 * 3 2 1 _ _ _
 * |----6----|
 * |-3-|
 *
 * Push '4'
 *
 * 4 3 2 1 _ _
 * |----6----|
 * |--4--|
 *
 * Destination: stack[0] + 1
 * Source: stack[0]
 * Bytes to move: length * sizeof(t)
*/

#include "common.h"

int main(void) {
    char *buffer[5] = {0};
    struct StringStack strings_2 = {0};
    struct StringStack *strings = NULL;

    strings_2 = cstack_init_stack(&strings_2, buffer, 5, STRING_STACK_S);
    strings = cstack_init(strings, STRING_STACK);

    /* Test heap functions */
    cstack_push(strings, "foo", STRING_STACK);
    assert(strcmp(strings->contents[0], "foo") == 0);
    assert(strings->length == 1);
    assert(strings->capacity == CSTACK_INITIAL_SIZE);

    cstack_push(strings, "bar", STRING_STACK);
    assert(strcmp(strings->contents[1], "bar") == 0);
    assert(strcmp(strings->contents[0], "foo") == 0);
    assert(strings->length == 2);
    assert(strings->capacity == CSTACK_INITIAL_SIZE);

    cstack_push(strings, "baz", STRING_STACK);
    assert(strcmp(strings->contents[2], "baz") == 0);
    assert(strcmp(strings->contents[1], "bar") == 0);
    assert(strcmp(strings->contents[0], "foo") == 0);
    assert(strings->length == 3);
    assert(strings->capacity == CSTACK_INITIAL_SIZE);

    cstack_push(strings, "tuna", STRING_STACK);
    assert(strcmp(strings->contents[3], "tuna") == 0);
    assert(strcmp(strings->contents[2], "baz") == 0);
    assert(strcmp(strings->contents[1], "bar") == 0);
    assert(strcmp(strings->contents[0], "foo") == 0);
    assert(strings->length == 4);
    assert(strings->capacity == CSTACK_INITIAL_SIZE);

    cstack_push(strings, "spam", STRING_STACK);
    assert(strcmp(strings->contents[4], "spam") == 0);
    assert(strcmp(strings->contents[3], "tuna") == 0);
    assert(strcmp(strings->contents[2], "baz") == 0);
    assert(strcmp(strings->contents[1], "bar") == 0);
    assert(strcmp(strings->contents[0], "foo") == 0);
    assert(strings->length == 5);
    assert(strings->capacity == CSTACK_INITIAL_SIZE);

    cstack_push(strings, "thud", STRING_STACK);
    assert(strcmp(strings->contents[5], "thud") == 0);
    assert(strcmp(strings->contents[4], "spam") == 0);
    assert(strcmp(strings->contents[3], "tuna") == 0);
    assert(strcmp(strings->contents[2], "baz") == 0);
    assert(strcmp(strings->contents[1], "bar") == 0);
    assert(strcmp(strings->contents[0], "foo") == 0);
    assert(strings->length == 6);
    assert(strings->capacity == CSTACK_INITIAL_SIZE * 2);

    /* Test stack functions */
    cstack_push(&strings_2, "foo", STRING_STACK_S);
    assert(strcmp(strings_2.contents[0], "foo") == 0);
    assert(strings_2.length == 1);
    assert(strings_2.capacity == 5);

    cstack_push(&strings_2, "bar", STRING_STACK_S);
    assert(strcmp(strings_2.contents[1], "bar") == 0);
    assert(strcmp(strings_2.contents[0], "foo") == 0);
    assert(strings_2.length == 2);
    assert(strings_2.capacity == 5);

    cstack_push(&strings_2, "baz", STRING_STACK_S);
    assert(strcmp(strings_2.contents[2], "baz") == 0);
    assert(strcmp(strings_2.contents[1], "bar") == 0);
    assert(strcmp(strings_2.contents[0], "foo") == 0);
    assert(strings_2.length == 3);
    assert(strings_2.capacity == 5);

    cstack_push(&strings_2, "tuna", STRING_STACK_S);
    assert(strcmp(strings_2.contents[3], "tuna") == 0);
    assert(strcmp(strings_2.contents[2], "baz") == 0);
    assert(strcmp(strings_2.contents[1], "bar") == 0);
    assert(strcmp(strings_2.contents[0], "foo") == 0);
    assert(strings_2.length == 4);
    assert(strings_2.capacity == 5);

    cstack_push(&strings_2, "spam", STRING_STACK_S);
    assert(strcmp(strings_2.contents[4], "spam") == 0);
    assert(strcmp(strings_2.contents[3], "tuna") == 0);
    assert(strcmp(strings_2.contents[2], "baz") == 0);
    assert(strcmp(strings_2.contents[1], "bar") == 0);
    assert(strcmp(strings_2.contents[0], "foo") == 0);
    assert(strings_2.length == 5);
    assert(strings_2.capacity == 5);

    cstack_free(strings, STRING_STACK);
    cstack_free(&strings_2, STRING_STACK_S);

    return EXIT_SUCCESS;
}

