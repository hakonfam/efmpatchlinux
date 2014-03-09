#include <linux/kernel.h>
#include <linux/of_platform.h>

#include <asm/v7m.h>

#include <asm/mach/arch.h>

#include "common.h"

static void __init efm32_init(void)
{
	of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);

	efm32_print_reset_cause();
	efm32_print_cpuinfo();
}

static const char *const efm32gg_compat[] __initconst = {
	"efm32,dk3750",
	NULL
};

DT_MACHINE_START(EFM32DT, "EFM32 (Device Tree Support)")
	.init_machine = efm32_init,
	.dt_compat = efm32gg_compat,
	.restart = armv7m_restart,
MACHINE_END
