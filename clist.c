#include "clist.h"

typedef struct clist {
	char head;
	struct clist* tail;
} *clist;
// every clist ends with empty
struct clist empty = {'\0', NULL};

// creates a clist and return its pocharer.
// head is the value and the first element
// and tail is a pocharer to the rest of the clist.
clist init (char h, clist t) {
	clist L = (clist) malloc (sizeof (clist));
	L-> tail = t;
	L-> head = h;

	return L;
}

// last returns a pointer to the last clist
clist last (clist L) {
	if (L-> tail == &empty) return L;
	else return last (L-> tail);
}

// droplast returns a pocharer to the clist
// passed in argument without the last
// ex: droplast (range (1,3)) = [1, 2]
clist droplast (clist L) {
	if (L-> tail == &empty) return &empty;
	else return con (single (L-> head), droplast (L-> tail));
}

// con is a very important function.
// it's "++" haskell function. It takes
// two clists and returns a concatened
// clist with the two
clist con (clist La, clist Lb) {
	clist L = init (La-> head, La-> tail);
	last(L)-> tail = Lb;
	return L;
}

// single takes a char and returns a clist
// with that char. single (5) = [5]
// this is mostly used with con
clist single (char h) {return init (h, &empty);}

// length returns the length of a clist
// length (range (1,10)) = 11
size_t length (clist L) {
	if (L != &empty) return 1 + length (L-> tail);
	else return 0;
}

// reverse reverses a clist
clist reverse (clist L) {
	clist rec (clist L, clist acc) {
		/*if (L != &empty) return rec (L-> tail, con (single (L-> head), acc));*/
		if (L != &empty) return rec (L-> tail, init (L-> head, acc));
		else return acc;
	} return rec (L, &empty);
}

// pl prints a clist
int pl (clist L) {
    if (L != &empty) {printf ("%c", L-> head); pl (L-> tail);}
    else return 0;
}

// range returns a clist with every char
// between a and b, including a and b
clist range (char a, char b) {
	if (a<=b) return init (a, range (a+1, b));
	else return &empty;
}

// map is a functor with applies the function f
// passed in argument on every element of the clist.
// map (lambda (char, (char a), {return aa;}, range (1, 5))
// = [1, 4, 9, 16, 25], all the squares from 1 to 5
clist map (char (*f) (char), clist L) {
	if (L != &empty) return con (
		single (f (L-> head))
		, map (f, L-> tail)
	); else return L;
}

// filter takes a clist and a predicate and returns
// another clist with elements that made the predicate true.
// filter (lambda (_Bool, (char a), {return a > 5;}, range (4, 7))
// = [6, 7], (6 and 7 are higher that 5) 
clist filter (_Bool (*p) (char), clist L) {
	if (L != &empty && p (L-> head)) return con (single (L-> head), filter (p, L-> tail));
	else if (L != &empty && !p (L-> head)) return filter (p, L-> tail);
	else return L;
}

// stocl converts char* to clist
clist stocl (char* S) {
    if (*S != '\0') return init (*S, stocl (S+1));
    else return &empty;
}

// ind returns the index of the first occurence of c in L
int ind (clist L, char c) {
    if (L != &empty && L-> head != c) return 1 + ind (L-> tail, c);
    else if (L != &empty && L-> head == c) return -1;
    else return 0;
}

// foldl folds a clist from the left and applies f on every element, 
// accumulating the result on acc. This is useleful for instance
// on factorial or sum, written above.
char foldl (char (*f) (char, char), char acc, clist L) {
	if (L != &empty) return foldl (f, f (acc, L-> head), L-> tail);
	else return acc;
}
