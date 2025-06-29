#include <stdint.h>
#include <stdio.h>

#define ISA_X86 uint32_t
#define ISA_X64 uint64_t

#define ISA ISA_X86


typedef enum Registers
{
    EAX,
    EBX,
    ECX,
    EDX,
    REG_COUNT
} Register;

ISA registers[REG_COUNT];

void mov(Register dst, ISA src)
{
    registers[dst] = src;
}
void add(Register dst, ISA src)
{
    registers[dst] += src;
}
void sub(Register dst, ISA src)
{
    registers[dst] -= src;
}
int main()
{
    mov(EAX, 0x120);
    printf("[MOV]--[EAX] --> 0x%08X (Expected : 0x120)\n", registers[EAX]);
    add(EAX, 0x1);
    printf("[ADD]--[EAX] --> 0x%08X (Expected : 0x121)\n", registers[EAX]);
    sub(EAX, 0x1);
    printf("[SUB]--[EAX] --> 0x%08X (Expected : 0x120)\n", registers[EAX]);
    return 0;
}