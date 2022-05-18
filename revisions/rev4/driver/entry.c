int main() {
    int a[] = {1,2,3,4,5};
    int ret = 0;
    int i;
    for(i=0; i<sizeof(a); i++)
    {
        ret = ret + a[i];
    }
    return ret;
}
