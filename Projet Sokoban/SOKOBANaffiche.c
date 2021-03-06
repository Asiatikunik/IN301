
void dessine_mur(SOKOBAN S, int x, int y){
	draw_fill_rectangle(S.la_case[x][y].hd, S.la_case[x][y].bg, COUL_MUR);
}

void dessine_caisse_a_bouger(SOKOBAN S, int x, int y){
	draw_fill_rectangle(S.la_case[x][y].hd, S.la_case[x][y].bg, COUL_CAISSE_A_BOUGER);
}

void dessine_caisse_place(SOKOBAN S, int x, int y){
	draw_fill_rectangle(S.la_case[x][y].hd, S.la_case[x][y].bg, COUL_CAISSE_PLACE);
}

void dessine_bonhomme(SOKOBAN S, int x, int y){
	POINT centre;
	centre.x = (S.la_case[x][y].hd.x + S.la_case[x][y].bg.x)/2;
	centre.y = (S.la_case[x][y].hd.y + S.la_case[x][y].bg.y)/2;
	draw_fill_circle(centre, TAILLE_CASE/2, COUL_BONHOMME);
}

void dessine_emplacement(SOKOBAN S, int x, int y){
	POINT hg, bd;
	hg.x = S.la_case[x][y].bg.x; 
	hg.y = S.la_case[x][y].hd.y;
	bd.x = S.la_case[x][y].hd.x; 
	bd.y = S.la_case[x][y].bg.y;
	draw_line(hg, bd, COUL_EMPLACEMENT);
	draw_line(S.la_case[x][y].hd, S.la_case[x][y].bg, COUL_EMPLACEMENT);
}

void affiche_cases(SOKOBAN S, int x, int y){
			if(S.la_case[x][y].objet == VIDE) draw_fill_rectangle(S.la_case[x][y].bg, S.la_case[x][y].hd, noir);
			if(S.la_case[x][y].objet == MUR) dessine_mur(S, x, y);
			if(S.la_case[x][y].objet == CAISSE_A_BOUGER) dessine_caisse_a_bouger(S, x, y);
			if(S.la_case[x][y].objet == EMPLACEMENT) dessine_emplacement(S, x, y);
			if(S.la_case[x][y].objet == BONHOMME) dessine_bonhomme(S, x, y);
			if(S.la_case[x][y].objet == CAISSE_PLACE) dessine_caisse_place(S, x, y);
}

void affiche_tout(SOKOBAN S){
	init_graphics(LARG_FENETRE,HAUT_FENETRE);
	int x, y;
	for(x=0;x<TAILLE_SOKOBAN; x++){
		for(y=0;y<TAILLE_SOKOBAN; y++){
			affiche_cases(S, x, y);
		}
	}
	//affiche_contour_jeu();
	//affiche_bouton_deplacement();
	affiche_all();
}

