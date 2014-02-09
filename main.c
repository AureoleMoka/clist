#include <stdio.h>
#include <string.h>
#include "clist.h"

char str[2048];
clist a;
int c;

clist f (char* str) {
    clist a = stocl (str);
    return reverse (a);
}    

int main (int argc, char* argv[]) {
    if (argc > 0) {
        for (c=1; c<argc; c++) {
            strcat (str, " ");
            strcat (str, argv[c]);
        } return pl (f (str));
    }

    else {
        fprintf (stderr, "Usage: clist <arg 1> .. <arg n>");
        return 1;
    }
}
