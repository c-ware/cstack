/*
 * An implementation of an array-based stack using macros.
 *
 * #define INT_STACK_TYPE   int
 * #define INT_STACK_FREE(value) \
 *     free((value))
 * #define STACK_NAME_HEAP  1
*/

#ifndef CWARE_LIBCSTACK_H
#define CWARE_LIBCSTACK_H

#define CSTACK_VERSION "1.0.2"

#ifndef CSTACK_INITIAL_SIZE
#define CSTACK_INITIAL_SIZE 5
#elif CSTACK_INITIAL_SIZE <= 0 
        "cstack_init: default length must be greater than 0"
#endif

#define _cstack_assert_positive(name, value, n)                             \
do {                                                                        \
    if((value) < 0) {                                                       \
        fprintf(stderr, "%s: argument %i expected positive number, got %i " \
                        "(%s:%i)\n", (name), (n), (value), __FILE__,        \
                                                          __LINE__);        \
        abort();                                                            \
    }                                                                       \
} while(0)

#define _cstack_assert_nonnull(name, value, n)                           \
do {                                                                     \
    if((value) == NULL) {                                                \
        fprintf(stderr, "%s: %s (%i) expected to be non-NULL (%s:%i)\n", \
                        (name), #value, (n), __FILE__, __LINE__);        \
        abort();                                                         \
    }                                                                    \
} while(0)

#define cstack_init(stack, namespace)                        \
    (stack);                                                 \
                                                             \
    (stack) = calloc(1, sizeof(*(stack)));                   \
    (stack)->capacity = CSTACK_INITIAL_SIZE;        \
    (stack)->contents = calloc(CSTACK_INITIAL_SIZE, \
                               sizeof(namespace ## _TYPE))

#define cstack_init_stack(stack, buffer, _capacity, namespace)  \
    *(stack);                                                   \
                                                                \
    _cstack_assert_positive("cstack_init_stack", _capacity, 3); \
    _cstack_assert_nonnull("cstack_init_stack", buffer, 2);     \
                                                                \
    (stack)->contents = buffer;                                 \
    (stack)->capacity = _capacity

#define cstack_push(stack, value, namespace)                                  \
    if((stack)->length == (stack)->capacity) {                                \
        if((namespace ## _HEAP) == 0) {                                       \
            fprintf(stderr, "cstack_push: stack is full. maximum capacity of" \
                            " %i (%s:%i)\n", (stack)->capacity, __FILE__,     \
                                                                __LINE__);    \
            abort();                                                          \
        }                                                                     \
                                                                              \
        (stack)->capacity = (stack)->capacity * 2;                            \
        (stack)->contents = realloc((stack)->contents, (stack)->capacity *    \
                                                sizeof(namespace ## _TYPE));  \
    }                                                                         \
                                                                              \
    (stack)->contents[(stack)->length] = (value);                             \
    (stack)->length++

#define cstack_pop(stack, namespace)                                          \
    (stack)->contents[(stack)->length - 1];                                   \
                                                                              \
    if((stack)->length == 0) {                                                \
        fprintf(stderr, "cstack_pop: attempt to pop from empty stack."        \
                        " (%s:%i)\n", __FILE__, __LINE__);                    \
        abort();                                                              \
    }                                                                         \
                                                                              \
    (stack)->length--

#define cstack_free(stack, namespace)                               \
do {                                                                \
    _cstack_assert_nonnull("cstack_free", (stack), 1);              \
    _cstack_assert_nonnull("cstack_free", (stack)->contents, 1);    \
                                                                    \
    while((stack)->length > 0) {                                    \
        namespace ## _FREE((stack)->contents[(stack)->length - 1]); \
        (stack)->length--;                                          \
    }                                                               \
                                                                    \
    if(namespace ## _HEAP) {                                        \
        free((stack)->contents);                                    \
        free((stack));                                              \
    }                                                               \
} while(0)

#define cstack_length(stack, namespace) \
    ((stack)->length)

#define cstack_is_empty(stack, namespace) \
    ((stack)->length == 0)

#define cstack_peek(stack, namespace) \
    ((stack)->contents[(stack)->length - 1])

#endif
