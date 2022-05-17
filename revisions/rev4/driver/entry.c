int main() {
    int a[] = {1, 2, 3};
    int b;
    int i;
    for(i=0; i < sizeof(a); i++) {
        b += a[i];
    }
    int c[] = {1, 2, 3};
    int d;
    for(i=0; i < sizeof(a); i++) {
        d += c[i];
    }
    return 0;
}
