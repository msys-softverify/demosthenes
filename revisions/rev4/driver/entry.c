int foo() {
    int a[] = {1,2,3,4,5};
    int ret = 0;
    int i;
    for(i=0; i<sizeof(a)/sizeof(int); i++)
    {
        ret = ret + a[i];
    }
    int x;
    int y;
    ret = ret + x * y;
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
