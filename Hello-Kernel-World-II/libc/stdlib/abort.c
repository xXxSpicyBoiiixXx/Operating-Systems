#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void abort(void) {
#if defined(__is_libk)
	// Add a proper kernel panic 
	printf("kernel: panic: abort()\n");

#else 
	// Terminate the process as if by SIGABRT 
	printf("abort()\n");

#endif 
	while(1) { } 
	__bulitin_unreachable();
}

