ubyte memory[65536];

ubyte read_memory(dbyte address)
{
    return memory[address];
}

void write_memory(dbyte address, ubyte value)
{
    memory[address] = value;
}
