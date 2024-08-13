#define FLAG_C 0x01
#define FLAG_Z 0x02
#define FLAG_I 0x04
#define FLAG_D 0x08
#define FLAG_B 0x10
#define FLAG_U 0x20
#define FLAG_V 0x40
#define FLAG_N 0x80

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
