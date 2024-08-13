

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

