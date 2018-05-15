#include <stdio.h>
#include "interactions.h"
#include "window.h"
#include "delaunay.h"

int adding_points = 0;

int constraint_point_display = 0;

constraintPoint *leftCP;
constraintPoint *rightCP;

int frames = 1;

void process_click(int x, int y){
	if((20 < x && x < 182) && (552 < y && y < 585)){
		printf("Add constraint point\n");
		if(get_constraint_point_display() == 0){
			toggle_constraint_point_display();
		}
		if(adding_points){
			leftCP = NULL;
			rightCP = NULL;
			/* RETIRER LES POINTS VERTS */
		}
		toggle_adding_points();
	}
	else if((197 < x && x < 365) && (552 < y && y < 585)){
		if(!adding_points){
			toggle_constraint_point_display();
		}
		printf("Hide constraint point : %d\n", get_constraint_point_display());
	}
	else if((380 < x && x < 508) && (552 < y && y < 585)){
		printf("Start rendering\n");
	}
	else if((523 < x && x < 571) && (552 < y && y < 585)){
		printf("<<<\n");
		if(frames > 1){
			frames--;
			update_frames_button();
		}
	}
	else if((586 < x && x < 661) && (552 < y && y < 585)){
		printf("%d Frame\n", frames);
		
	}
	else if((676 < x && x < 724) && (552 < y && y < 585)){
		printf(">>>\n");
		frames++;
		update_frames_button();
	}
	else if((739 < x && x < 787) && (552 < y && y < 585)){
		/* IL FAUT TOUT FREEEEEEEEEE*/
		printf("Quit\n");
	}
	else if((10 < x && x < 522) && (10 < y && y < 522)){
		printf("Image de gauche\n");
		if(adding_points){
			if(leftCP){
				free(leftCP);
			}
			leftCP = create_constraintPoint(x,y);
			draw_new_constraint_point(x, y, MLV_COLOR_GREEN, 0);
		}
	}
	else if((542 < x && x < 1054) && (10 < y && y < 522)){
		printf("Image de droite\n");
		if(adding_points){
			if(rightCP){
				free(rightCP);
			}
			rightCP = create_constraintPoint(x,y);
			draw_new_constraint_point(x, y, MLV_COLOR_GREEN, 1);
		}		
	}
	if(leftCP != NULL && rightCP != NULL){
		/*Créer la pair/triangle et l'envoyer*/
		/*Dessiner les triangles*/
		toggle_adding_points();
		leftCP = NULL;
		rightCP = NULL;		
		
	}
}

void toggle_adding_points(){
		if(adding_points){
			adding_points = 0;
			hover_add(0);
		}else{
			adding_points = 1;
			hover_add(1);
		}
}

void toggle_constraint_point_display(){
		if(constraint_point_display){
			constraint_point_display = 0;
			hover_hide(0);
		}else{
			constraint_point_display = 1;
			hover_hide(1);
		}
}

int get_constraint_point_display(){
	return constraint_point_display;
}