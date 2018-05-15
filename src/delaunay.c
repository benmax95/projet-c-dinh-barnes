#include <stdio.h>
#include <stdlib.h>
#include "delaunay.h"

struct _constraintPoint{
	int x;
	int y;
};

struct _pair{
		constraintPoint*       source;
		constraintPoint*       destination;
};

struct _setOfPair {
		pair*   pair;
		struct _setOfPair* next;
};

struct _triangle{
	constraintPoint* cp_A;
	constraintPoint* cp_B;
	constraintPoint* cp_C;
};

struct _setOfTriangle {
		triangle*   triangle;
		struct _setOfTriangle* next;
};


/* constraintPoint Part */

constraintPoint *create_constraintPoint(int x, int y) {
	
	constraintPoint *cp = (constraintPoint*)malloc(sizeof(constraintPoint));

	cp->x = x;
	cp->y = y;
	
	return cp;
}

/* Pair Part => contains the a constraintPoint source (1st picture) and a constraintPoint desctination (2nd picture)*/

pair *create_pair(constraintPoint *constraintPointSource, constraintPoint *constraintPointDestination) {
	
	pair *p = (pair*)malloc(sizeof(pair));

	p->source = constraintPointSource;
	p->destination = constraintPointDestination;
	
	return p;
}

void free_pair(pair *p) {
	
	free(p->source);
	
	free(p->destination);
	
	free(p);
	
}

/* setOfPair Part */

setOfPair *create_setOfPair() {
	
	setOfPair *s = (setOfPair*)malloc(sizeof(setOfPair));
	
	s->next=NULL;
	
	return s;
}

void add_setOfPair(constraintPoint *constraintPointSource, constraintPoint *constraintPointDestination, setOfPair *s){
	
	pair *pair = create_pair(constraintPointSource,constraintPointDestination);
	
	setOfPair *new_s = create_setOfPair();
	
	new_s->pair = pair;
	s->next = new_s;
	
}

pair *remove_setOfPair(setOfPair *s) {
	
	if(s == NULL){
		return NULL;
	}
	
	pair *pair = s->pair;
	
	return pair;
	
}

void free_setOfPair(setOfPair *s) {
	
	while(s){
		pair *pair = s->pair ;
		free_pair(pair) ;
		s=s->next ;
	}
	
	free(s);
	
}

/* Triangle Part */

triangle *create_triangle(constraintPoint *cp_A, constraintPoint *cp_B, constraintPoint *cp_C) {
	
	triangle *t = (triangle*)malloc(sizeof(triangle));

	t->cp_A = cp_A;
	t->cp_B = cp_B;
	t->cp_C = cp_C;
	
	return t;
	
}

/* setOfTriangle Part */

setOfTriangle *create_setOfTriangle() {
	
	setOfTriangle *s = (setOfTriangle*)malloc(sizeof(setOfTriangle));

	s->next=NULL;
	
	return s;
}


void add_setOfTriangle(constraintPoint *cp_A, constraintPoint *cp_B, constraintPoint *cp_C, setOfTriangle *s){
	
	triangle *t = create_triangle(cp_A, cp_B, cp_C);
	
	setOfTriangle *new_s = create_setOfTriangle();
	
	new_s->triangle = t;
	
	s->next = new_s;
	
}

triangle* remove_setOfTriangle(setOfTriangle *s) {

	if(s==NULL){
		return NULL;
	}
	
	triangle *t = s->triangle;
	
	return t;
	
}

void free_triangle(triangle *t) {
	
	free(t);
	
}

void free_setOfTriangle(setOfTriangle *s) {
	
	while(s){
		triangle *t = s->triangle;
		free_triangle(t);
		s=s->next;
	}
	
	free(s);
	
}