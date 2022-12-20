#ifndef GPIO_REGS_H
#define GPIO_REGS_H

#include<stdint.h>

typedef struct GPIO_status_ctrl_t GPIO_status_ctrl_t;
struct GPIO_status_ctrl_t
{
	uint32_t GPIO_STATUS;
	uint32_t GPIO_CTRL;
};

typedef struct GPIO_t GPIO_t;
struct GPIO_t
{
	GPIO_status_ctrl_t STATUS_CTRL[30];
	uint32_t INTR[4];
	uint32_t PROC0_INTE[4];
	uint32_t PROC0_INTF[4];
	uint32_t PROC0_INTS[4];
	uint32_t PROC1_INTE[4];
	uint32_t PROC1_INTF[4];
	uint32_t PROC1_INTS[4];
	uint32_t DORMANT_WAKE_INTE[4];
	uint32_t DORMANT_WAKE_INTF[4];
	uint32_t DORMANT_WAKE_INTS[4];
};

typedef struct GPIO_pad_t GPIO_pad_t;
struct GPIO_pad_t
{
	uint32_t VOLTAGE_SELECT;
	uint32_t GPIO_PAD_CTRL[30];
	uint32_t SWCLK;
	uint32_t SWD;
};

#define GPIO      ((volatile GPIO_t*)(0x40014000))
#define GPIO_PADS ((volatile GPIO_pad_t*)(0x4001c000))

#endif