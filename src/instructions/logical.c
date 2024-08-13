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
