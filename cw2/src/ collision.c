/*
 *  collision.c
 *
 *  Created on: 29 Apr 2016
 *      Author: jake
 */
#include "defs.h"

void collisionDetect(GameState *game)
{
  float mw = 32, mh = 48;
  //Check for collision with any ledges (brick blocks)
  for(int i = 0; i < 2560; i++)
  {
	float bx = game->ledge[i].bx;
	//printf("ledge %d: %g\n", i, bx);
	float by = game->ledge[i].by;
    float mx = game->player.x, my = game->player.y;
    float bw = 32, bh = 32;
    //printf("%g %g %g %g\n",bw, by, bw, bw);

    if(mx+mw/2 > bx && mx+mw/2<bx+bw)
    {
      //are we bumping our head?
      if(my < by+bh && my > by && game->player.dy < 0)
      {
        //correct y
        game->player.y = by+bh;
        my = by+bh;

        //bumped our head, stop any jump velocity
        game->player.dy = 0;
        game->player.onLedge = 1;
      }
    }
    if(mx+mw > bx && mx<bx+bw)
    {
      //are we landing on the ledge
      if(my+mh > by && my < by && game->player.dy > 0)
      {
        //correct y
        game->player.y = by-mh;
        my = by-mh;

        //landed on this ledge, stop any jump velocity
        game->player.dy = 0;
        game->player.onLedge = 1;
      }
    }

    if(my+mh > by && my<by+bh)
    {
      //rubbing against right edge
      if(mx < bx+bw && mx+mw > bx+bw && game->player.dx < 0)
      {
        //correct x
        game->player.x = bx+bw;
        mx = bx+bw;
        //printf("Collided against left!\n");
        game->player.dx = 0;
		game->player.walking = 0;
		game->player.currentSprite = 9;
      }
      //rubbing against left edge
      else if(mx+mw > bx && mx < bx && game->player.dx > 0)
      {
        //correct x
        game->player.x = bx-mw;
        mx = bx-mw;
        //printf("Collided against left!\n");
        game->player.dx = 0;
		game->player.walking = 0;
		game->player.currentSprite = 9;
      }
    }
  }
}
