#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct {
    uint8_t AR, XR, YR, SP, SR;
    uint16_t PC;
} CPU;

void initialize_cpu(CPU* cpu);
void emulate(CPU* cpu);

#endif // CPU_H
