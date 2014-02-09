#include "lambda.h"

typedef struct list list;
list empty;
list* init (char, list*);
list* last (list*);
list* droplast (list*);
list* con (list*, list*);
list* single (char);
list* nth (char, list*);
size_t length (list*);
void pl (list*);
list* range (char, char);
list* map (char (*f) (char), list*);
list* filter (_Bool (*p) (char), list*);
char foldl (char (*f) (char, char), char, list*);
unsigned long fac (char);
char sum (list*);
