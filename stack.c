#include <stdint.h>
#include <stdio.h>

#define SIZE 4

typedef struct Stack {
    uint32_t  MEM[SIZE];
    uint32_t *ESP;
} Stack;

void init_stack(Stack *sp)
{
    sp->ESP = &sp->MEM[SIZE];
}

void push(Stack *sp, uint32_t value)
{
    sp->ESP--;
    *sp->ESP = value;
    printf("[PUSH] ESP -> 0x%08X | VALUE = 0x%08X\n", (unsigned int) (uintptr_t) sp->ESP, value);
}

uint32_t pop(Stack *sp)
{
    uint32_t val = *sp->ESP;
    sp->ESP++;
    printf("[POP ] ESP -> 0x%08X | VALUE = 0x%08X\n", (unsigned int) (uintptr_t) (sp->ESP - 1), val);
    return val;
}

int main()
{
    Stack mystack;
    init_stack(&mystack);
    push(&mystack, 0xDEADBEEF);
    push(&mystack, 0x12345678);
    uint32_t v1 = pop(&mystack);
    uint32_t v2 = pop(&mystack);

    printf("\n[TEST] POP1 = 0x%08X (Expected: 0x12345678)\n", v1);
    printf("[TEST] POP2 = 0x%08X (Expected: 0xDEADBEEF)\n", v2);

    return 0;
}
