#include <MLV/MLV_all.h>
#include "interactions.h"
#include "window.h"
#include <stdio.h>

MLV_Image* leftImage;
MLV_Image* rightImage;

void create_window(){
	MLV_create_window("Morphing", "Morphing",WIDTH_WINDOW,HEIGHT_WINDOW);
}

void free_window(){
	MLV_free_window();
}

void actualise_window(){
	MLV_actualise_window();
}

MLV_Image* load_image(const char* path){
	
	MLV_Image* image = MLV_load_image(path);
	
	MLV_resize_image(image,512,512);
	
	return image;
	
}

void draw_image(MLV_Image* image, int x, int y){
	
	MLV_draw_image(image,x,y);
	
}

void init_window(MLV_Image* firstImage, MLV_Image* secondImage){
	
	MLV_draw_filled_rectangle(0, 0, WIDTH_WINDOW, HEIGHT_WINDOW, MLV_COLOR_BLACK);
	
	leftImage = firstImage;
	rightImage = secondImage;
	
	draw_image(leftImage, 10, 10);
	draw_image(rightImage, 542, 10);

	MLV_draw_adapted_text_box(20, 550, "Add constraint point", 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER);
	MLV_draw_adapted_text_box(200, 550, "Show constraint point", 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER);
	MLV_draw_adapted_text_box(380, 550, "Start rendering", 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER);
	MLV_draw_adapted_text_box(520, 550, "<<<", 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER);
	update_frames_button();
	MLV_draw_adapted_text_box(700, 550, ">>>", 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER);
	MLV_draw_adapted_text_box(800, 550, "Quit", 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER);
	
	actualise_window();
}

void update_frames_button(){
	char strFrames[12];
	if(frames == 1){
		sprintf(strFrames, "%d Frame", frames);
	}else{
		sprintf(strFrames, "%d Frames", frames);
	}
	MLV_draw_text_box(586, 552, 98, 33, strFrames, 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER,MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
	actualise_window();
}

void hover_hide(int hover){
	if(hover){
		MLV_draw_adapted_text_box(197, 552, "Hide constraint point", 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_YELLOW, MLV_TEXT_CENTER);
	}else{
		MLV_draw_adapted_text_box(197, 552, "Show constraint point", 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER);
	}
	actualise_window();
}

void hover_add(int hover){
	if(hover){
		MLV_draw_adapted_text_box(20, 552, "Add constraint point", 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_YELLOW, MLV_TEXT_CENTER);
	}else{
		MLV_draw_adapted_text_box(20, 552, "Add constraint point", 9, MLV_COLOR_GREY, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER);
	}
	actualise_window();
}

void draw_new_constraint_point(int x, int y, MLV_Color color, int side){
	if(!side){
		draw_image(leftImage, 10, 10);
	}else{
		draw_image(rightImage, 542, 10);
	}
	MLV_draw_filled_circle(x,y,3,color);
	actualise_window();
}
