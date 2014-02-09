#include "clist.h"

// head : tail : empty
typedef struct list {
	char head;
	struct list *tail;
} list;
// every list ends with empty list
list empty = {'\0', NULL};

// creates a list and return its pocharer.
// head is the value and the first element
// and tail is a pocharer to the rest of the list.
list* init (char h, list *t) {
	list *L = (list*) malloc (sizeof (list));
	L-> tail = t;
	L-> head = h;

	return L;
}

// last returns a pointer to the last list
list* last (list *L) {
	if (L-> tail == &empty) return L;
	else return last (L-> tail);
}

// droplast returns a pocharer to the list
// passed in argument without the last
// ex: droplast (range (1,3)) = [1, 2]
list* droplast (list *L) {
	if (L-> tail == &empty) return &empty;
	else return con (single (L-> head), droplast (L-> tail));
}

// con is a very important function.
// it's "++" haskell function. It takes
// two lists and returns a concatened
// list with the two
list* con (list *La, list *Lb) {
	list *L = init (La-> head, La-> tail);
	last(L)-> tail = Lb;
	return L;
}

// single takes a char and returns a list
// with that char. single (5) = [5]
// this is mostly used with con
list* single (char h) {return init (h, &empty);}

// length returns the length of a list
// length (range (1,10)) = 11
size_t length (list *L) {
	if (L != &empty) return 1 + length (L-> tail);
	else return 0;
}

// reverse reverses a list
list* reverse (list *L) {
	list* rec (list *L, list *acc) {
		if (L != &empty) return rec (L-> tail, con (single (L-> head), acc));
		else return acc;
	} return rec (L, &empty);
}

// pl is used to prchar a list using haskell style
void pl (list *L) {
	if (L != &empty) {
		printf ("[");
		while (L-> tail != &empty) {
			printf ("%c, ", L-> head);
			L = L-> tail;
		} printf ("%c]", L-> head);
	} else printf ("[]");
}

// range returns a list with every char
// between a and b, including a and b
list* range (char a, char b) {
	if (a<=b) return init (a, range (a+1, b));
	else return &empty;
}

// map is a functor with applies the function f
// passed in argument on every element of the list.
// map (lambda (char, (char a), {return a*a;}, range (1, 5))
// = [1, 4, 9, 16, 25], all the squares from 1 to 5
list* map (char (*f) (char), list* L) {
	if (L != &empty) return con (
		single (f (L-> head))
		, map (f, L-> tail)
	); else return L;
}

// filter takes a list and a predicate and returns
// another list with elements that made the predicate true.
// filter (lambda (_Bool, (char a), {return a > 5;}, range (4, 7))
// = [6, 7], (6 and 7 are higher that 5) 
list* filter (_Bool (*p) (char), list *L) {
	if (L != &empty && p (L-> head)) return con (single (L-> head), filter (p, L-> tail));
	else if (L != &empty && !p (L-> head)) return filter (p, L-> tail);
	else return L;
}

list* stocl (char* S) {
    if (*S != '\0') return init (*S, stocl (S+1));
    else return &empty;
}

// foldl folds a list from the left and applies f on every element, 
// accumulating the result on acc. This is useleful for instance
// on factorial or sum, written above.
char foldl (char (*f) (char, char), char acc, list *L) {
	if (L != &empty) return foldl (f, f (acc, L-> head), L-> tail);
	else return acc;
}
