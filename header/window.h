#ifndef _WINDOW
#define _WINDOW

#include "MLV/MLV_all.h"

#define WIDTH_WINDOW 1070
#define HEIGHT_WINDOW 600

void create_window();

void free_window();

void actualise_window();

MLV_Image* load_image(const char* path);

void draw_image(MLV_Image* image, int x, int y);

void init_window(MLV_Image* firstImage, MLV_Image* secondImage);

void update_frames_button();

void draw_new_constraint_point(int x, int y, MLV_Color color, int side);

void draw_all_constraint_points();

void hover_hide();

void hover_add();

#endif /* GRAPHIC_H */