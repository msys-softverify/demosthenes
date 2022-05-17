int main() {
    int a[] = {1, 2, 3};
    int b;
    int i;
    for(i=0; i < sizeof(a); i++) {
        b += a[i];
    }
    return 0;
}
