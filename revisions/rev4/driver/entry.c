int foo() {
    int a;
    int b;
    return a + b;
}
int bar() {
    int c[] = {1, 2, 3};
    int i;
    int ret;
    for(i<0; i<sizeof(c); i++)
    {
        ret = ret + c[i];
    }
    return ret;
}
int hoge() {
    int d[] = {1, 2, 3};
    int i;
    int ret;
    for(i<0; i<sizeof(d); i++)
    {
        ret = ret + d[i];
    }
    return ret;
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
