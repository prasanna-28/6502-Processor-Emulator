#include <stdint.h>
#include <stdio.h>


typedef uint8_t ubyte;
typedef int8_t byte;
typedef uint16_t dbyte;

#define FLAG_C 0x01
#define FLAG_Z 0x02
#define FLAG_I 0x04
#define FLAG_D 0x08
#define FLAG_B 0x10
#define FLAG_U 0x20
#define FLAG_V 0x40
#define FLAG_N 0x80

typedef struct {
    ubyte AC;    // Accumulator
    ubyte XR;    // X register
    ubyte YR;    // Y register
    dbyte PC;    // Program Counter
    ubyte SP;    // Stack Pointer
    ubyte SR;    // Status Register
} CPU;

// region Memory
ubyte memory[65536];

ubyte read_memory(dbyte address)
{
    return memory[address];
}

void write_memory(dbyte address, ubyte value)
{
    memory[address] = value;
}
// end Memory


// region Flags
void update_zero_flag(CPU* cpu, byte value)
{
    if(value){
        cpu->SR &= ~FLAG_Z;
        return;
    }
    if(!value){
        cpu->SR |= FLAG_Z;
        return;
    }
}

void update_carry_flag(CPU* cpu, byte carry)
{
    if(!carry){
        cpu->SR &= ~FLAG_C;
        return;
    }
    if(carry){
        cpu->SR |= FLAG_C;
        return;
    }
}

void update_overflow_flag(CPU* cpu, byte overflow)
{
    if(!overflow){
        cpu->SR &= ~FLAG_V;
        return;
    }
    if(overflow){
        cpu->SR |= FLAG_V;
        return;
    }
}

void update_negative_flag(CPU* cpu, byte value)
{
    if(value < 0){
        cpu->SR |= FLAG_N;
        return;
    }
    if(value >= 0){
        cpu->SR &= ~FLAG_N;
        return;
    }
}

void update_dynamic_flags(CPU* cpu, byte value, byte carry, byte overflow)
{
    update_zero_flag(cpu, value);
    update_carry_flag(cpu, carry);
    update_overflow_flag(cpu, overflow);
    update_negative_flag(cpu, value);
}
// end Flags

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

// region LDA
void lda_immediate(CPU* cpu, ubyte immediate)
{
    cpu->AR = immediate;
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void lda_zero_page(CPU* cpu, ubyte address)
{
    cpu->AR = read_memory(address);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void lda_absolute(CPU* cpu, dbyte adr1, dbyte adr2)
{
    cpu->AR = read_memory((adr1 << 8) | adr2);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void lda_indirect(CPU* cpu, ubyte address)
{
    dbyte low_byte = (dbyte)read_memory(address);
    dbyte high_byte = (dbyte)read_memory(++address);
    cpu->AR = read_memory((high_byte << 8) | low_byte);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}
// end LDA

// region AND
void and_immediate(CPU* cpu, ubyte immediate)
{
    cpu->AR &= immediate;
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void and_zero_page(CPU* cpu, ubyte address)
{
    cpu->AR &= read_memory(address);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void and_absolute(CPU* cpu, ubyte adr1, ubyte adr2)
{
    cpu->A &= read_memory((adr1 << 8) | adr2);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void and_indirect(CPU* cpu, ubyte address)
{
    dbyte low_byte = (dbyte)read_memory(address);
    dbyte high_byte = (dbyte)read_memory(++address);
    cpu->AR &= read_memory((high_byte << 8) | low_byte);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}
// end AND

// region EOR
void eor_immediate(CPU* cpu, ubyte immediate)
{
    cpu->AR ^= immediate;
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void eor_zero_page(CPU* cpu, ubyte address)
{
    cpu->AR ^= read_memory(address);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void eor_absolute(CPU* cpu, ubyte adr1, ubyte adr2)
{
    cpu->AR ^= read_memory((adr1 << 8) | adr2);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void eor_indirect(CPU* cpu, ubyte address)
{
    dbyte low_byte = (dbyte)read_memory(address);
    dbyte high_byte = (dbyte)read_memory(++address);
    cpu->AR ^= read_memory((high_byte << 8) | low_byte);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}
// end EOR

// region ORA
void ora_immediate(CPU* cpu, ubyte immediate)
{
    cpu->AR |= immediate;
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void ora_zero_page(CPU* cpu, ubyte address)
{
    cpu->AR |= read_memory(address);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void ora_absolute(CPU* cpu, ubyte adr1, ubyte adr2)
{
    cpu->AR |= read_memory((adr1 << 8) | adr2);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}

void ora_indirect(CPU* cpu, ubyte address)
{
    dbyte low_byte = (dbyte)read_memory(address);
    dbyte high_byte = (dbyte)read_memory(++address);
    cpu->AR |= read_memory((high_byte << 8) | low_byte);
    update_dynamic_flags(cpu, (byte)cpu->AR, 0, 0);
}
// end ORA

void emulate(CPU* cpu)
{
    switch(memory[cpu->PC])
    {
    }
}


int main()
{
    CPU *cpu;
    emulate(cpu);
    return 0;
}
