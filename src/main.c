#include <stdio.h>
#include "MLV/MLV_all.h"
#include "interactions.h"
#include "window.h"

int main(int argc, char* argv[]){
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