#include <stdio.h>
#include "MLV/MLV_all.h"
#include "interactions.h"
#include "delaunay.h"
#include "window.h"

int main(int argc, char* argv[]){
    
	constraintPoint *cp1 = create_constraintPoint(0,0);
	constraintPoint *cp2 = create_constraintPoint(0,20);
	constraintPoint *cp3 = create_constraintPoint(20,0);
	
	constraintPoint *cp4 = create_constraintPoint(2,2);
	constraintPoint *cp5 = create_constraintPoint(4,4);
	constraintPoint *cp6 = create_constraintPoint(0,0);
	
	triangle *t1 = create_triangle(cp1,cp2,cp3);
	
	printf("%d",is_in_triangle(cp4, t1));
	printf("%d",is_in_triangle(cp5, t1));
	printf("%d",is_in_triangle(cp6, t1));
	printf("%d",is_in_triangle(cp7, t1));
	
	create_window();

    MLV_Image* firstImage = load_image(argv[1]);
    MLV_Image* secondImage = load_image(argv[2]);

    init_window(firstImage,secondImage);

	int x_click, y_click;
	
	int l = 0 ; 
	
    while (l == 0) {

         MLV_wait_mouse	(&x_click,&y_click);
		 
         process_click(x_click, y_click);

    }
	
    free_window();

    return 0;
}