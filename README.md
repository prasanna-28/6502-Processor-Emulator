# MOS 6502 Processor

## Overview

Emulator for 6502 8-bit microprocessor with 16-bit address bus and 64KB of memory.

## Registers

- A: Accumulator (8-bit)
- X, Y: Index Registers (8-bit)
- PC: Program Counter (16-bit)
- SP: Stack Pointer (8-bit, offset from $0100)
- P: Processor Status (8-bit)

## Status Flags (P Register)

| Bit | Flag | Description |
|-----|------|-------------|
| 7 | N | Negative |
| 6 | V | Overflow |
| 5 | - | Unused (Always 1) |
| 4 | B | Break |
| 3 | D | Decimal |
| 2 | I | Interrupt Disable |
| 1 | Z | Zero |
| 0 | C | Carry |

## Addressing Modes

1. Implied
2. Accumulator
3. Immediate
4. Zero Page
5. Zero Page,X
6. Zero Page,Y
7. Relative
8. Absolute
9. Absolute,X
10. Absolute,Y
11. Indirect
12. (Indirect,X)
13. (Indirect),Y

## Instruction Set

### Load/Store Operations

| Mnemonic | Operation | N | Z | C | I | D | V |
|----------|-----------|---|---|---|---|---|---|
| LDA | Load Accumulator | ✓ | ✓ | - | - | - | - |
| LDX | Load X Register | ✓ | ✓ | - | - | - | - |
| LDY | Load Y Register | ✓ | ✓ | - | - | - | - |
| STA | Store Accumulator | - | - | - | - | - | - |
| STX | Store X Register | - | - | - | - | - | - |
| STY | Store Y Register | - | - | - | - | - | - |

### Arithmetic Operations

| Mnemonic | Operation | N | Z | C | I | D | V |
|----------|-----------|---|---|---|---|---|---|
| ADC | Add with Carry | ✓ | ✓ | ✓ | - | - | ✓ |
| SBC | Subtract with Carry | ✓ | ✓ | ✓ | - | - | ✓ |
| INC | Increment Memory | ✓ | ✓ | - | - | - | - |
| INX | Increment X | ✓ | ✓ | - | - | - | - |
| INY | Increment Y | ✓ | ✓ | - | - | - | - |
| DEC | Decrement Memory | ✓ | ✓ | - | - | - | - |
| DEX | Decrement X | ✓ | ✓ | - | - | - | - |
| DEY | Decrement Y | ✓ | ✓ | - | - | - | - |

### Logical Operations

| Mnemonic | Operation | N | Z | C | I | D | V |
|----------|-----------|---|---|---|---|---|---|
| AND | Logical AND | ✓ | ✓ | - | - | - | - |
| ORA | Logical Inclusive OR | ✓ | ✓ | - | - | - | - |
| EOR | Exclusive OR | ✓ | ✓ | - | - | - | - |

### Shift and Rotate Operations

| Mnemonic | Operation | N | Z | C | I | D | V |
|----------|-----------|---|---|---|---|---|---|
| ASL | Arithmetic Shift Left | ✓ | ✓ | ✓ | - | - | - |
| LSR | Logical Shift Right | 0 | ✓ | ✓ | - | - | - |
| ROL | Rotate Left | ✓ | ✓ | ✓ | - | - | - |
| ROR | Rotate Right | ✓ | ✓ | ✓ | - | - | - |

### Jump & Subroutine Operations

| Mnemonic | Operation | N | Z | C | I | D | V |
|----------|-----------|---|---|---|---|---|---|
| JMP | Jump | - | - | - | - | - | - |
| JSR | Jump to Subroutine | - | - | - | - | - | - |
| RTS | Return from Subroutine | - | - | - | - | - | - |

### Branch Operations

| Mnemonic | Operation | N | Z | C | I | D | V |
|----------|-----------|---|---|---|---|---|---|
| BCC | Branch if Carry Clear | - | - | - | - | - | - |
| BCS | Branch if Carry Set | - | - | - | - | - | - |
| BNE | Branch if Not Equal | - | - | - | - | - | - |
| BEQ | Branch if Equal | - | - | - | - | - | - |
| BPL | Branch if Plus | - | - | - | - | - | - |
| BMI | Branch if Minus | - | - | - | - | - | - |
| BVC | Branch if Overflow Clear | - | - | - | - | - | - |
| BVS | Branch if Overflow Set | - | - | - | - | - | - |

### Status Flag Operations

| Mnemonic | Operation | N | Z | C | I | D | V |
|----------|-----------|---|---|---|---|---|---|
| CLC | Clear Carry Flag | - | - | 0 | - | - | - |
| SEC | Set Carry Flag | - | - | 1 | - | - | - |
| CLI | Clear Interrupt Disable | - | - | - | 0 | - | - |
| SEI | Set Interrupt Disable | - | - | - | 1 | - | - |
| CLV | Clear Overflow Flag | - | - | - | - | - | 0 |
| CLD | Clear Decimal Mode | - | - | - | - | 0 | - |
| SED | Set Decimal Mode | - | - | - | - | 1 | - |

### System Operations

| Mnemonic | Operation | N | Z | C | I | D | V |
|----------|-----------|---|---|---|---|---|---|
| BRK | Force Interrupt | - | - | - | 1 | - | - |
| RTI | Return from Interrupt | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| NOP | No Operation | - | - | - | - | - | - |

### Opcode Matrix

|     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | A | B | C | D | E | F |
|-----|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 0   |BRK|ORA|...| * |* * |ORA|ASL| * |PHP|ORA|ASL| * | * |ORA|ASL| * |
| 1   |BPL|ORA|...| * | * |ORA|ASL| * |CLC|ORA| * | * | * |ORA|ASL| * |
| 2   |JSR|AND|...| * |BIT|AND|ROL| * |PLP|AND|ROL| * |BIT|AND|ROL| * |
| 3   |BMI|AND|...| * | * |AND|ROL| * |SEC|AND| * | * | * |AND|ROL| * |
| 4   |RTI|EOR|...| * | * |EOR|LSR| * |PHA|EOR|LSR| * |JMP|EOR|LSR| * |
| 5   |BVC|EOR|...| * | * |EOR|LSR| * |CLI|EOR| * | * | * |EOR|LSR| * |
| 6   |RTS|ADC|...| * | * |ADC|ROR| * |PLA|ADC|ROR| * |JMP|ADC|ROR| * |
| 7   |BVS|ADC|...| * | * |ADC|ROR| * |SEI|ADC| * | * | * |ADC|ROR| * |
| 8   | * |STA|...| * |STY|STA|STX| * |DEY| * |TXA| * |STY|STA|STX| * |
| 9   |BCC|STA|...| * |STY|STA|STX| * |TYA|STA|TXS| * | * |STA| * | * |
| A   |LDY|LDA|LDX| * |LDY|LDA|LDX| * |TAY|LDA|TAX| * |LDY|LDA|LDX| * |
| B   |BCS|LDA|...| * |LDY|LDA|LDX| * |CLV|LDA|TSX| * |LDY|LDA|LDX| * |
| C   |CPY|CMP|...| * |CPY|CMP|DEC| * |INY|CMP|DEX| * |CPY|CMP|DEC| * |
| D   |BNE|CMP|...| * | * |CMP|DEC| * |CLD|CMP| * | * | * |CMP|DEC| * |
| E   |CPX|SBC|...| * |CPX|SBC|INC| * |INX|SBC|NOP| * |CPX|SBC|INC| * |
| F   |BEQ|SBC|...| * | * |SBC|INC| * |SED|SBC| * | * | * |SBC|INC| * |

Note: * represents unofficial opcodes

## Memory Map

- $0000-$00FF: Zero Page
- $0100-$01FF: Stack
- $FFFA-$FFFB: NMI vector
- $FFFC-$FFFD: Reset vector
- $FFFE-$FFFF: IRQ/BRK vector

