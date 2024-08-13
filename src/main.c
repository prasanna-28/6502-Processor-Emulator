#include <stdint.h>
#include <stdio.h>


typedef uint8_t ubyte;
typedef int8_t byte;
typedef uint16_t dbyte;


typedef struct {
    ubyte AR;    // accumulator
    ubyte XR;    // x register
    ubyte YR;    // y register
    dbyte PC;    // program counter
    ubyte SP;    // stack pointer
    ubyte SR;    // status register
} CPU;


// region Stack
void push(CPU *cpu, ubyte value)
{
    return;
}

ubyte pop(CPU* cpu)
{
    return;
}
// end Stack


int main()
{
    CPU* cpu;
    initialize(cpu);
    emulate(cpu);

    return 0;
}
