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

// region Opcode
#define LDA_IMMEDIATE 0xA9
#define LDA_ZERO_PAGE 0xA5
#define LDA_ZERO_PAGE_X 0xB5
#define LDA_ABSOLUTE 0xAD
#define LDA_ABSOLUTE_X 0xBD
#define LDA_ABSOLUTE_Y 0xB9
#define LDA_INDIRECT_X 0xA1
#define LDA_INDIRECT_Y 0xB1

#define LDX_IMMEDIATE 0xA2
#define LDX_ZERO_PAGE 0xA6
#define LDX_ZERO_PAGE_Y 0xB6
#define LDX_ABSOLUTE 0xAE
#define LDX_ABSOLUTE_Y 0xBE

#define LDY_IMMEDIATE 0xA0
#define LDY_ZERO_PAGE 0xA4
#define LDY_ZERO_PAGE_X 0xB4
#define LDY_ABSOLUTE 0xAC
#define LDY_ABSOLUTE_X 0xBC

#define STA_ZERO_PAGE 0x85
#define STA_ZERO_PAGE_X 0x95
#define STA_ABSOLUTE 0x8D
#define STA_ABSOLUTE_X 0x9D
#define STA_ABSOLUTE_Y 0x99
#define STA_INDIRECT_X 0x81
#define STA_INDIRECT_Y 0x91

#define STX_ZERO_PAGE 0x86
#define STX_ZERO_PAGE_Y 0x96
#define STX_ABSOLUTE 0x8E

#define STY_ZERO_PAGE 0x84
#define STY_ZERO_PAGE_X 0x94
#define STY_ABSOLUTE 0x8C

#define ADC_IMMEDIATE 0x69
#define ADC_ZERO_PAGE 0x65
#define ADC_ZERO_PAGE_X 0x75
#define ADC_ABSOLUTE 0x6D
#define ADC_ABSOLUTE_X 0x7D
#define ADC_ABSOLUTE_Y 0x79
#define ADC_INDIRECT_X 0x61
#define ADC_INDIRECT_Y 0x71

#define SBC_IMMEDIATE 0xE9
#define SBC_ZERO_PAGE 0xE5
#define SBC_ZERO_PAGE_X 0xF5
#define SBC_ABSOLUTE 0xED
#define SBC_ABSOLUTE_X 0xFD
#define SBC_ABSOLUTE_Y 0xF9
#define SBC_INDIRECT_X 0xE1
#define SBC_INDIRECT_Y 0xF1

#define AND_IMMEDIATE 0x29
#define AND_ZERO_PAGE 0x25
#define AND_ZERO_PAGE_X 0x35
#define AND_ABSOLUTE 0x2D
#define AND_ABSOLUTE_X 0x3D
#define AND_ABSOLUTE_Y 0x39
#define AND_INDIRECT_X 0x21
#define AND_INDIRECT_Y 0x31

#define ORA_IMMEDIATE 0x09
#define ORA_ZERO_PAGE 0x05
#define ORA_ZERO_PAGE_X 0x15
#define ORA_ABSOLUTE 0x0D
#define ORA_ABSOLUTE_X 0x1D
#define ORA_ABSOLUTE_Y 0x19
#define ORA_INDIRECT_X 0x01
#define ORA_INDIRECT_Y 0x11

#define EOR_IMMEDIATE 0x49
#define EOR_ZERO_PAGE 0x45
#define EOR_ZERO_PAGE_X 0x55
#define EOR_ABSOLUTE 0x4D
#define EOR_ABSOLUTE_X 0x5D
#define EOR_ABSOLUTE_Y 0x59
#define EOR_INDIRECT_X 0x41
#define EOR_INDIRECT_Y 0x51

#define CMP_IMMEDIATE 0xC9
#define CMP_ZERO_PAGE 0xC5
#define CMP_ZERO_PAGE_X 0xD5
#define CMP_ABSOLUTE 0xCD
#define CMP_ABSOLUTE_X 0xDD
#define CMP_ABSOLUTE_Y 0xD9
#define CMP_INDIRECT_X 0xC1
#define CMP_INDIRECT_Y 0xD1

#define CPX_IMMEDIATE 0xE0
#define CPX_ZERO_PAGE 0xE4
#define CPX_ABSOLUTE 0xEC

#define CPY_IMMEDIATE 0xC0
#define CPY_ZERO_PAGE 0xC4
#define CPY_ABSOLUTE 0xCC

#define INC_ZERO_PAGE 0xE6
#define INC_ZERO_PAGE_X 0xF6
#define INC_ABSOLUTE 0xEE
#define INC_ABSOLUTE_X 0xFE

#define INX 0xE8
#define INY 0xC8

#define DEC_ZERO_PAGE 0xC6
#define DEC_ZERO_PAGE_X 0xD6
#define DEC_ABSOLUTE 0xCE
#define DEC_ABSOLUTE_X 0xDE

#define DEX 0xCA
#define DEY 0x88

#define ASL_ACCUMULATOR 0x0A
#define ASL_ZERO_PAGE 0x06
#define ASL_ZERO_PAGE_X 0x16
#define ASL_ABSOLUTE 0x0E
#define ASL_ABSOLUTE_X 0x1E

#define LSR_ACCUMULATOR 0x4A
#define LSR_ZERO_PAGE 0x46
#define LSR_ZERO_PAGE_X 0x56
#define LSR_ABSOLUTE 0x4E
#define LSR_ABSOLUTE_X 0x5E

#define ROL_ACCUMULATOR 0x2A
#define ROL_ZERO_PAGE 0x26
#define ROL_ZERO_PAGE_X 0x36
#define ROL_ABSOLUTE 0x2E
#define ROL_ABSOLUTE_X 0x3E

#define ROR_ACCUMULATOR 0x6A
#define ROR_ZERO_PAGE 0x66
#define ROR_ZERO_PAGE_X 0x76
#define ROR_ABSOLUTE 0x6E
#define ROR_ABSOLUTE_X 0x7E

#define JMP_ABSOLUTE 0x4C
#define JMP_INDIRECT 0x6C
#define JSR_ABSOLUTE 0x20
#define RTS 0x60

#define BEQ 0xF0
#define BNE 0xD0
#define BCS 0xB0
#define BCC 0x90
#define BMI 0x30
#define BPL 0x10
#define BVS 0x70
#define BVC 0x50

#define PHA 0x48
#define PHP 0x08
#define PLA 0x68
#define PLP 0x28

#define TAX 0xAA
#define TXA 0x8A
#define TAY 0xA8
#define TYA 0x98
#define TSX 0xBA
#define TXS 0x9A

#define BRK 0x00
#define RTI 0x40
#define NOP 0xEA

#define CLC 0x18
#define SEC 0x38
#define CLI 0x58
#define SEI 0x78
#define CLV 0xB8
#define CLD 0xD8
#define SED 0xF8

#define BIT_ZERO_PAGE 0x24
#define BIT_ABSOLUTE 0x2C
// end Opcode

typedef struct {
    ubyte AR;    // accumulator
    ubyte XR;    // x register
    ubyte YR;    // y register
    dbyte PC;    // program counter
    ubyte SP;    // stack pointer
    ubyte SR;    // status register
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

// region LDX
void ldx_immediate(CPU* cpu, ubyte immediate)
{
    cpu->XR = immediate;
    update_dynamic_flags(cpu, (byte)cpu->XR, 0, 0);
}

void ldx_zero_page(CPU* cpu, ubyte address)
{
    cpu->XR = read_memory(address);
    update_dynamic_flags(cpu, (byte)cpu->XR, 0, 0);
}

void ldx_absolute(CPU* cpu, dbyte adr1, dbyte adr2)
{
    cpu->XR = read_memory((adr1 << 8) | adr2);
    update_dynamic_flags(cpu, (byte)cpu->XR, 0, 0);
}

void ldx_indirect(CPU* cpu, ubyte address)
{
    dbyte low_byte = (dbyte)read_memory(address);
    dbyte high_byte = (dbyte)read_memory(++address);
    cpu->XR = read_memory((high_byte << 8) | low_byte);
    update_dynamic_flags(cpu, (byte)cpu->XR, 0, 0);
}
// end LDX

// region LDY
void ldy_immediate(CPU* cpu, ubyte immediate)
{
    cpu->YR = immediate;
    update_dynamic_flags(cpu, (byte)cpu->YR, 0, 0);
}

void ldy_zero_page(CPU* cpu, ubyte address)
{
    cpu->YR = read_memory(address);
    update_dynamic_flags(cpu, (byte)cpu->YR, 0, 0);
}

void ldy_absolute(CPU* cpu, dbyte adr1, dbyte adr2)
{
    cpu->YR = read_memory((adr1 << 8) | adr2);
    update_dynamic_flags(cpu, (byte)cpu->YR, 0, 0);
}

void ldy_indirect(CPU* cpu, ubyte address)
{
    dbyte low_byte = (dbyte)read_memory(address);
    dbyte high_byte = (dbyte)read_memory(++address);
    cpu->YR = read_memory((high_byte << 8) | low_byte);
    update_dynamic_flags(cpu, (byte)cpu->YR, 0, 0);
}
// end LDY

// region STA

void sta_zero_page(CPU* cpu, ubyte address)
{
    write_memory((dbyte)address, cpu->AR);
}

void sta_absolute(CPU* cpu, ubyte adr1, ubyte adr2)
{
    write_memory(((dbyte)adr1 << 8) | adr2, cpu->AR);
}

void sta_indirect(CPU* cpu, ubyte address)
{

}

// end STA

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
    cpu->AR &= read_memory((adr1 << 8) | adr2);
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

// region CMP




// end CMP

void emulate(CPU* cpu)
{
    uint8_t opcode = memory[cpu->PC++];
    switch(opcode)
    {
        // LDA
        case LDA_IMMEDIATE:
        case LDA_ZERO_PAGE:
        case LDA_ZERO_PAGE_X:
        case LDA_ABSOLUTE:
        case LDA_ABSOLUTE_X:
        case LDA_ABSOLUTE_Y:
        case LDA_INDIRECT_X:
        case LDA_INDIRECT_Y:
            break;

        // LDX
        case LDX_IMMEDIATE:
        case LDX_ZERO_PAGE:
        case LDX_ZERO_PAGE_Y:
        case LDX_ABSOLUTE:
        case LDX_ABSOLUTE_Y:
            break;

        // LDY
        case LDY_IMMEDIATE:
        case LDY_ZERO_PAGE:
        case LDY_ZERO_PAGE_X:
        case LDY_ABSOLUTE:
        case LDY_ABSOLUTE_X:
            break;

        // STA
        case STA_ZERO_PAGE:
        case STA_ZERO_PAGE_X:
        case STA_ABSOLUTE:
        case STA_ABSOLUTE_X:
        case STA_ABSOLUTE_Y:
        case STA_INDIRECT_X:
        case STA_INDIRECT_Y:
            break;

        // STX
        case STX_ZERO_PAGE:
        case STX_ZERO_PAGE_Y:
        case STX_ABSOLUTE:
            break;

        // STY
        case STY_ZERO_PAGE:
        case STY_ZERO_PAGE_X:
        case STY_ABSOLUTE:
            break;

        // ADC
        case ADC_IMMEDIATE:
        case ADC_ZERO_PAGE:
        case ADC_ZERO_PAGE_X:
        case ADC_ABSOLUTE:
        case ADC_ABSOLUTE_X:
        case ADC_ABSOLUTE_Y:
        case ADC_INDIRECT_X:
        case ADC_INDIRECT_Y:
            break;

        // SBC
        case SBC_IMMEDIATE:
        case SBC_ZERO_PAGE:
        case SBC_ZERO_PAGE_X:
        case SBC_ABSOLUTE:
        case SBC_ABSOLUTE_X:
        case SBC_ABSOLUTE_Y:
        case SBC_INDIRECT_X:
        case SBC_INDIRECT_Y:
            break;

        // AND
        case AND_IMMEDIATE:
        case AND_ZERO_PAGE:
        case AND_ZERO_PAGE_X:
        case AND_ABSOLUTE:
        case AND_ABSOLUTE_X:
        case AND_ABSOLUTE_Y:
        case AND_INDIRECT_X:
        case AND_INDIRECT_Y:
            break;

        // ORA
        case ORA_IMMEDIATE:
        case ORA_ZERO_PAGE:
        case ORA_ZERO_PAGE_X:
        case ORA_ABSOLUTE:
        case ORA_ABSOLUTE_X:
        case ORA_ABSOLUTE_Y:
        case ORA_INDIRECT_X:
        case ORA_INDIRECT_Y:
            break;

        // EOR
        case EOR_IMMEDIATE:
        case EOR_ZERO_PAGE:
        case EOR_ZERO_PAGE_X:
        case EOR_ABSOLUTE:
        case EOR_ABSOLUTE_X:
        case EOR_ABSOLUTE_Y:
        case EOR_INDIRECT_X:
        case EOR_INDIRECT_Y:
            break;

        // CMP
        case CMP_IMMEDIATE:
        case CMP_ZERO_PAGE:
        case CMP_ZERO_PAGE_X:
        case CMP_ABSOLUTE:
        case CMP_ABSOLUTE_X:
        case CMP_ABSOLUTE_Y:
        case CMP_INDIRECT_X:
        case CMP_INDIRECT_Y:
            break;

        // CPX
        case CPX_IMMEDIATE:
        case CPX_ZERO_PAGE:
        case CPX_ABSOLUTE:
            break;

        // CPY
        case CPY_IMMEDIATE:
        case CPY_ZERO_PAGE:
        case CPY_ABSOLUTE:
            break;

        // INC
        case INC_ZERO_PAGE:
        case INC_ZERO_PAGE_X:
        case INC_ABSOLUTE:
        case INC_ABSOLUTE_X:
            break;

        // DEC
        case DEC_ZERO_PAGE:
        case DEC_ZERO_PAGE_X:
        case DEC_ABSOLUTE:
        case DEC_ABSOLUTE_X:
            break;

        // ASL
        case ASL_ACCUMULATOR:
        case ASL_ZERO_PAGE:
        case ASL_ZERO_PAGE_X:
        case ASL_ABSOLUTE:
        case ASL_ABSOLUTE_X:
            break;

        // LSR
        case LSR_ACCUMULATOR:
        case LSR_ZERO_PAGE:
        case LSR_ZERO_PAGE_X:
        case LSR_ABSOLUTE:
        case LSR_ABSOLUTE_X:
            break;

        // ROL
        case ROL_ACCUMULATOR:
        case ROL_ZERO_PAGE:
        case ROL_ZERO_PAGE_X:
        case ROL_ABSOLUTE:
        case ROL_ABSOLUTE_X:
            break;

        // ROR
        case ROR_ACCUMULATOR:
        case ROR_ZERO_PAGE:
        case ROR_ZERO_PAGE_X:
        case ROR_ABSOLUTE:
        case ROR_ABSOLUTE_X:
            break;

        // JMP
        case JMP_ABSOLUTE:
        case JMP_INDIRECT:
            break;

        // JSR
        case JSR_ABSOLUTE:
            break;

        // Branch instructions
        case BEQ:
        case BNE:
        case BCS:
        case BCC:
        case BMI:
        case BPL:
        case BVS:
        case BVC:
            break;

        // Stack operations
        case PHA:
        case PHP:
        case PLA:
        case PLP:
            break;

        // Register transfers
        case TAX:
        case TXA:
        case TAY:
        case TYA:
        case TSX:
        case TXS:
            break;

        // System functions
        case BRK:
        case RTI:
        case NOP:
            break;

        // Flag operations
        case CLC:
        case SEC:
        case CLI:
        case SEI:
        case CLV:
        case CLD:
        case SED:
            break;

        // Bit test
        case BIT_ZERO_PAGE:
        case BIT_ABSOLUTE:
            break;

        // Single byte instructions
        case INX:
        case INY:
        case DEX:
        case DEY:
            break;

        // Return from subroutine
        case RTS:
            break;

        default:
            printf("Unknown Opcode at address <%h>.", cpu->PC);
            exit(1);

    }
}


int main()
{
    CPU *cpu;

    cpu->AR = 0x00;
    cpu->XR = 0x00;
    cpu->YR = 0x00;
    cpu->PC = 0xFFFC;
    cpu->SP = 0xFF;
    cpu->SR = 0x34;

    emulate(cpu);

    return 0;
}
