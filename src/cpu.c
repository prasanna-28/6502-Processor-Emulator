#include "../include/cpu.h"
#include "../include/memory.h"
#include "../include/opcodes.h"

void initialize(CPU* cpu) {
    cpu->AR = 0x00;
    cpu->XR = 0x00;
    cpu->YR = 0x00;
    cpu->PC = 0xFFFC;
    cpu->SP = 0xFF;
    cpu->SR = 0x34;
}

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

