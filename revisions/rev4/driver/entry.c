#import <stdlib.h>

int *foo(int n) {
    int *ptr = malloc(sizeof(int));
    if(!ptr) {
        return NULL;
    }
    *ptr = n;
    
    return ptr;
}

int bar() {
    int *p = foo(10);
    if (p != NULL) {}
    p[0] = 0;
}

int main() {
    int a;
    int b;
    a *=b;
    return 0;
}
