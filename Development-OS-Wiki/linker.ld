/* 
 * The bootloader will look at this image and start 
 * execution at the symbol designated as the entry 
 * point
 *
 * In addition, the compiler may produce other sections,
 * by default it will put them in a segment with the 
 * same name. Just add stuff to the end of the linker
 * as needed.
 */

ENTRY(_start)

/* 
 * This section tells where the various sections of 
 * the object files will be put in the final 
 * kernal image 
 */
SECTIONS
{
	/* 
	 * Begins putting section at 1MiB 
	 * a conventional place for kernels 
	 * to be loaded at by the bootloader
	 */
	. = 1M;

	/* 
	 * First put the multiboot header, it is 
	 * required to be put very early in the image
	 * or the bootloader won't recoggnize
	 * the file forma. 
	 */
	
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

	/* 
	 * Read-only data 
	 */

	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	/*
	 * Read-Write data
	 */
	
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}
	
	/*
	 * Read-Write data (uninitialized) and stack
	 */
	
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}
}

