#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define WIDTH 1366//800//1366
#define HEIGHT 768//800//768
#define W_MAP (WIDTH - (WIDTH / 3))
#define H_MAP (HEIGHT - (HEIGHT / 15))
#define M 45
#define N (int)(M / (16.0/9.0)) //Grille de N*M
#define LARGEUR_EDIT (WIDTH / M)
#define LARGEUR_CASE (W_MAP / M)

enum{HUD, CASE};
enum{VIDE, EAU, TERRE, HERBE};
typedef struct{int x, y;}coords;

int *init_map();
void aff_map(int *A);
void SDL_ExitWithError(const char *message, SDL_Window *w, SDL_Renderer *r, SDL_Texture *t);
void editeur_map(SDL_Window *window, SDL_Renderer *renderer, int *map);
void creer_map_rendu(SDL_Window *window, SDL_Renderer *renderer);
SDL_Texture *creerTexture(SDL_Window *window, SDL_Renderer *renderer, char sourceIMG[30]);
void creerTexte(SDL_Renderer *renderer, TTF_Font *police, char str[], int x, int y);
void aff_texture(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, int x_texture, int y_texture, int type_texture, int type_largeur);
SDL_bool valides(int x, int y);