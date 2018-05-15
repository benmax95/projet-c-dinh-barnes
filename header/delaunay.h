#ifndef _DELAUNAY
#define _DELAUNAY

typedef struct _constraintPoint constraintPoint;

typedef struct _pair pair;

typedef struct _setOfPair setOfPair;

typedef struct _triangle triangle;

typedef struct _setOfTriangle setOfTriangle;

constraintPoint *create_constraintPoint(int x, int y);

pair *create_pair(constraintPoint *source, constraintPoint *destination);

setOfPair *create_setOfPair();

void add_setOfPair(constraintPoint *constraintPointSource, constraintPoint *constraintPointDestination, setOfPair *s);

pair *remove_setOfPair(setOfPair *s);

void free_pair(pair *p);

void free_setOfPair(setOfPair *s);

triangle *create_triangle(constraintPoint *cpA, constraintPoint *cpB, constraintPoint *cpC);

setOfTriangle *create_setOfTriangle();

void add_setOfTriangle(constraintPoint *cp_A, constraintPoint *cp_B, constraintPoint *cp_C, setOfTriangle *s);

triangle* remove_setOfTriangle(setOfTriangle *s);

void free_triangle(triangle *t);

void free_setOfTriangle(setOfTriangle *s);

#endif
