#include <stdio.h>
#include <stdlib.h>
#include "delaunay.h"

struct _constraintPoint{
	int x;
	int y;
};

struct _pair{
	constraintPoint* source;
	constraintPoint* destination;
	struct _pair* next;
};

struct _triangle{
	constraintPoint* cp_A;
	constraintPoint* cp_B;
	constraintPoint* cp_C;
	struct _triangle* next;
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

/* Triangle Part */

triangle *create_triangle(constraintPoint *cp_A, constraintPoint *cp_B, constraintPoint *cp_C) {
	
	triangle *t = (triangle*)malloc(sizeof(triangle));

	t->cp_A = cp_A ;
	t->cp_B = cp_B ;
	t->cp_C = cp_C ;
	
	t->next = NULL ;
	
	return t;
	
}

triangle *remove_list(triangle *lst, triangle *t) {
	
	if (lst == NULL)
		return NULL;
	
	if (lst == t) {
		
		triangle *tmp = lst;
		lst = lst->next;
		
		free(tmp);
		
		return lst;
	}

	triangle *ptr = lst->next;
	triangle *pred = lst;
	
	while (ptr != NULL && ptr != t) {
		pred = ptr;
		
		ptr = ptr->next;
	}
	
	if (ptr != NULL) {
		
		triangle *tmp = ptr;
		pred->next = ptr->next;
		
		free(tmp);
	}
	
	return lst;
}

int is_in_triangle(constraintPoint *cp, triangle *t){
	
	int x_cp = cp->x ;
	int y_cp = cp->y ;
	
	int vector_cp_a_x = t->cp_A->x - x_cp ;
	int vector_cp_a_y = t->cp_A->y - y_cp ;
	
	int vector_cp_b_x = t->cp_B->x - x_cp ;
	int vector_cp_b_y = t->cp_B->y - y_cp ;
	
	int vector_cp_c_x = t->cp_C->x - x_cp ;
	int vector_cp_c_y = t->cp_C->y - y_cp ;
	
	int res_a = (vector_cp_b_x * vector_cp_c_y) - (vector_cp_b_y * vector_cp_c_x) ;
	
	int res_b = (vector_cp_c_x * vector_cp_a_y) - (vector_cp_c_y * vector_cp_a_x) ;
	
	int res_c = (vector_cp_a_x * vector_cp_b_y) - (vector_cp_a_y * vector_cp_b_x) ;
	
	if( (res_a <= 0) && (res_b <= 0) && (res_c <= 0)){
		res_a *= -1 ;
		res_b *= -1 ;
		res_c *= -1 ;
	}
	
	if(res_a >= 0 && res_b >= 0 && res_c >= 0)
		return 1;
	
	return 0 ;
	
}