#include <stdlib.h>


void match_or_mismatch()
{
    char buf[10];
    double* flt_ptr = new double;
    int* numarray = new int[20];

    /* Oops. Forgot that buf is actually allocated on stack ... */
    free(buf);
    /* free'ing a pointer allocated by 'new' certainly is not right */
    free(flt_ptr);
    /* Now we use right deallocation operation. Not. Should have used 'delete[]' instead! */
    delete numarray;
}
