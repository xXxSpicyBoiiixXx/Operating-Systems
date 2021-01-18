#include <stdio.h>
#include <kernel/tty.h>

voide kernel_main(void) {
	terminal_initialize();
	printf("Hello, Kernel World!\n");
}

