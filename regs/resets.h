#ifndef RESETS_REGS_H
#define RESETS_REGS_H

#include<stdint.h>

typedef struct RESETS_t RESETS_t;
struct RESETS_t
{
	uint32_t RESET;
	uint32_t WDSEL;
	uint32_t RESET_DONE;
};

#define RESETS ((volatile RESETS_t*)(0x4000c000))

#endif