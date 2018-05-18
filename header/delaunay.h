#ifndef _DELAUNAY
#define _DELAUNAY

typedef struct _constraintPoint constraintPoint;

typedef struct _pair pair;

typedef struct _triangle triangle;

constraintPoint *create_constraintPoint(int x, int y);

pair *create_pair(constraintPoint *source, constraintPoint *destination);

void free_pair(pair *p);

triangle *create_triangle(constraintPoint *cpA, constraintPoint *cpB, constraintPoint *cpC);

void free_triangle(triangle *t);

triangle *remove_list(triangle *lst, triangle *t) ;

int is_in_triangle(constraintPoint *cp, triangle *t) ;

#endif
