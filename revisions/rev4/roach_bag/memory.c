#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FILETYPE_ERROR, FILETYPE_JPEG, FILETYPE_PNG, FILETYPE_NOTSUPPORTED } filetype_t;

filetype_t get_file_type(const char* filename, size_t header_size) {
    FILE* fp;
    void* buf = malloc(header_size);
    filetype_t res = FILETYPE_NOTSUPPORTED;
    size_t n_read;

    fp = fopen(filename, "r");
    if (fp == NULL || header_size<4) {
        /* trying to handle abnormal situation function does not
           deallocate grabbed memory */
        return FILETYPE_ERROR;
    }
    /* malloc may fail to allocate memory and return 0, in that case
       we gate null pointer dereference in fread */
    n_read = fread(buf, header_size, 1, fp);
    if (n_read < 4) {
        fclose(fp); 
        /* Here we fail to deallocate 'buf' once again */
        return FILETYPE_ERROR;
    }
    fclose(fp);

    if (memcmp(buf, "JFIF", 4) == 0) {
        res = FILETYPE_JPEG;
    } else if (memcmp(((char*)buf)+1, "PNG", 3)==0){
        res = FILETYPE_PNG;
    }
   
    free(buf); 
    return res; /* we may have a path on which 'res' may be uninitialized */
}

