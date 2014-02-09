#include "lambda.h"

typedef struct clist *clist;
clist init (char, clist);
clist last (clist);
clist droplast (clist);
clist con (clist, clist);
clist single (char);
clist nth (char, clist);
size_t length (clist);
clist reverse (clist);
int pl (clist);
clist range (char, char);
clist map (char (*f) (char), clist);
clist filter (_Bool (*p) (char), clist);
clist stocl (char*);
int ind (clist, char);
char foldl (char (*f) (char, char), char, clist);
unsigned long fac (char);
char sum (clist);
