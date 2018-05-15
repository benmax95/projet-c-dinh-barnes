#ifndef INTERACTIONS_H
#define INTERACTIONS_H

extern int frames;

void process_click(int x, int y);

void toggle_adding_points();

void toggle_constraint_point_display();

int get_constraint_point_display();

#endif /* INTERACTIONS_H */