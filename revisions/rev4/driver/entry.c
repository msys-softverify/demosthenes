int foo() {
    int a;
    int b;
    return a + b;
}
int bar() {
    int c;
    int d;
    return a * d;
}
int hoge() {
    int e;
    int f;
    return e - f;
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
