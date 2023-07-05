int foo() {
    int a;
    int b;
    return a + b;
}

int bar() {
    int a[] = {1,2,3,4,5};
    int ret = 0;
    int i;
    for(i=0; i<sizeof(a); i++)
    {
        ret = ret + a[i];
    }
    return ret;
}

int main() {
    return 0;
}
