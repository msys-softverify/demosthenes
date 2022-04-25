/**
  * Demonstration of taintedness tracking capabilities
  */
#include <stdio.h>
#include <stdlib.h>

int fprintf_wrapper(const char* str) {
    return fprintf(stderr, str);
}

void wrapup() {
    char buf[256];
    
    /* no user input -> no error */
    fprintf_wrapper("Constant string!"); 
    fgets(buf, sizeof(buf), stdin);
    /* Format string is taken from user input -> format string vulnerability */
    fprintf_wrapper(buf); 
}

void dumb_hexify() {
    char buf[2];
    int d;
    
    char hex_digits[16] = { 
        '0', '1', '2', '3', 
        '4', '5', '6', '7', 
        '8', '9', 'A', 'B',
        'C', 'D', 'E', 'F'
    };

    fgets(buf, sizeof(buf), stdin);
    d = atol(buf);
    printf("%c\n", hex_digits[d]);
    
}

struct simple_point {
    float x,y;
};

struct simple_point* trust_thy_user_not() {
    /* suppose we get binary data from stdin and assume there is 
     a certain protocol. Typical scenario: we read a number of elements
     from the stream which should be followed by reading these elements to
     memory. If memory is allocated without checking for sane limits, 
     Denial of Service attack or even arbitrary code execution may 
     be caused by malicious input */

    unsigned int n_points;
    struct simple_point* points;
    
    fread(&n_points, sizeof(n_points), 1, stdin);
    points = (struct simple_point*) calloc(n_points, sizeof(struct simple_point));
    fread(points, sizeof(struct simple_point), n_points, stdin);

    return points;
}
