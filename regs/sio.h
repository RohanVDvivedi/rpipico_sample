#ifndef SIO_REGS_H
#define SIO_REGS_H

#include<stdint.h>

typedef struct SIO_t SIO_t;
struct SIO_t
{
    uint32_t CPUID;
    uint32_t GPIO_IN;
    uint32_t GPIO_HI_IN;

    uint32_t RESERVED_0;

    uint32_t GPIO_OUT;
    uint32_t GPIO_OUT_SET;
    uint32_t GPIO_OUT_CLR;
    uint32_t GPIO_OUT_XOR;
    uint32_t GPIO_OE;
    uint32_t GPIO_OE_SET;
    uint32_t GPIO_OE_CLR;
    uint32_t GPIO_OE_XOR;
    uint32_t GPIO_HI_OUT;
    uint32_t GPIO_HI_OUT_SET;
    uint32_t GPIO_HI_OUT_CLR;
    uint32_t GPIO_HI_OUT_XOR;
    uint32_t GPIO_HI_OE;
    uint32_t GPIO_HI_OE_SET;
    uint32_t GPIO_HI_OE_CLR;
    uint32_t GPIO_HI_OE_XOR;

    // ...
};

#define SIO ((volatile SIO_t*)(0xd0000000))

#endif