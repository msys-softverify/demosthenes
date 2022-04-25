#include <stdio.h>
#include <string.h>


/* This is a simple buffer overflow caused by an unbounded '%s' in sprintf */
void buffer_overflow_via_sprintf(char *dest)
{
	if (dest != NULL) {
		/* An overflow condition */
		sprintf(dest, "%s", "A string that will not fit into a 32 byte buffer");
		/* Overflows can be prevented with the proper format specifier
		 sprintf(dest, "%.31s", "A string that will not fit into a 32 byte buffer");
		 Unless we forget about the NULL terminator... */
		sprintf(dest, "%.32s", "A string that will not fit into a 32 byte buffer");
	}
}


/* This example shows the mistake in assuming that the user will input
 the expected value - there is no check to make sure only unsigned 8-bit 
 values are passed in, and so large numbers can cause a buffer overflow */
void buffer_overflow_dotted_quad(void) 
{
	char buf[50];
	unsigned int a1,a2,a3,a4, bigaddr;

	printf("Enter IP address as xx.xx.xx.xx: ");
	scanf("%u.%u.%u.%u", &a1, &a2, &a3, &a4);

	bigaddr = (a1<<24) + (a2<<16) + (a3<<8) + a4; 

	sprintf(buf, "%u.%u.%u.%u = %u", a1,a2,a3,a4, bigaddr);
	printf("Results: %s\n", buf);
}

/* An off-by-one error commonly occurs when the terminating NULL is forgotten */
void off_by_one_error(void)
{
	char *source = "This string is exactly 36 bytes long";
	char dest[36];

	strcpy(dest, source);
}

/* Klocwork compiler has built-in C preprocessor which allows it to
   handle preprocessor code correctly */

/* This macro shows an unsafe expansion */
#define BADSTRCPY(x) strcpy(x, "this is a long, long buffer that is quite a bit longer than 8, but less than 128 characters");
/* This is a buffer overrun that occurs because of an unsafe macro (above) */
void buffer_overrun_via_macro_expansion(char *dest)
{
	if (dest != NULL) {
		BADSTRCPY(dest);
	}
}

/* now we actually invoke 'buffer_overrun_via_macro_expansion' and only now we get error */
void invoke_bad_copy() {
    char buf[8];

    buffer_overrun_via_macro_expansion(buf);
}
