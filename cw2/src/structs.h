/*
 * structs.h
 *
 *  Created on: 20 Apr 2016
 *      Author: jake
 */

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct player
{
	float x, y; //co-ordinates of player
	float dx, dy; //movement velocities
	int lives; //lives of player
	char *name; //name of player
	int onLedge;

	//used for motion
	int currentSprite, walking, facingLeft, slowingDown;
	int jumpCount;
	//Texture for sprite animation
	SDL_Texture *sheetTexture;
}Player;

typedef struct enemy
{
	int x,y; //co-ordinates of enemy
}Enemy;

//parameters for map generation
typedef struct Map
{
	int startX, startY; //starting coordinates
	int maxX, maxY; //max coordinates 
} Map;

//parameters for the ledge
typedef struct Ledge
{
  int x, y, w, h;
  float by, bx;
} Ledge;

//gamestate struct - used to load all the sprites and textures.
typedef struct gameState
{
	int globalTime;
	int	gameStatus;
	Map map; //used for map
	Player player; //creates a player

	
	Enemy plog [50]; //enemy type 1
	Enemy sprog[50]; //enemy type 2
	Ledge ledge [3000]; //TODO: Make Dynamic for efficient memory use.
	int tileCount;

	//objects for map creation
	SDL_Texture *brick;
	SDL_Texture *enemy; //texture for enemy
	SDL_Renderer *renderer;

	//font generation - SDL_TTF required
	TTF_Font *font;
	SDL_Texture *label;
	int labelW, labelH;

}GameState;

#endif /* STRUCTS_H_ */
