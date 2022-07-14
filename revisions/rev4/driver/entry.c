#include <stddef.h>

char* foo()
{
    char *c;
    return c;
}
void bar()
{
    char *p = foo();
    if(p == NULL) { return; }
    if(p != NULL) { p[0] = 0; }
}

int main() {
    int a[] = {1,2,3,4,5};
    int ret = 0;
    int i;
    for(i=0; i<sizeof(a)/sizeof(int); i++)
    {
        ret = ret + a[i];
    }
    return ret;
}
