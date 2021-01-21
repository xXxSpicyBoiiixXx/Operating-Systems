# Declare constnat for the multiboot header.
.set ALIGN, 1<<0	# align loaded modules on page boundaries 
.set MEMINFO, 1<<1	# provide memory map 
.set FLAGS, ALGIN | MEMINFO # this is the multiboot 'flag' fieled 
.set MAGIC, 0x1BADB002 	# magic number letting hte bootloader find the header 
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above to prove we are multiboot 

# Declare a header as in the multiboot standard 
.section .multiboot 
.align 4 
.long MAGIC 
.long FLAGS
.long CHECKSUM

# Reserve a stack for hte intial thread 
.section .bss 
.align 16 
stack_bottom:
.skip 16384 
stack_top:

# The kernel entry point.
.section .text 
.global _start 
.type _start, @function 
_start:
	movl $stack_top, %esp 

	# Call the global consructors
	call _init 
	
	# Transfer control to the main kernel 
	call kernel_main 
	
	# Hang if kernel_main unexpectedly returns 
	cli
1:	hlt
	jmp 1b
.size _start, . - _start
