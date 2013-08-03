#ifndef DEF_MASTER
#define DEF_MASTER


//Define data path
#define TIME_FONT             "data/font/time.ttf"

#define GRAPHIC_TETRIS_SPLASH "data/graphics/tetris_splash.bmp"
#define GRAPHIC_GREY_BOX      "data/graphics/grey_box.bmp"
#define GRAPHIC_RED_BOX       "data/graphics/red_box.bmp"

#define WM_CAPTION            "-=[Tetris]=-"


//Include the standard library
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#endif



#ifndef DEF_CONST
#define DEF_CONST

#define TETROMINO_BLOCK_SIZE 4

#define GAME_BOARD_HEIGHT       16
#define GAME_BOARD_WEIGHT       10


#define PIXEL_BLOCK_SIZE        23 
//#define PIXEL_BLOCK_SIZE        10
#define BLOCK_WIDTH             10
//#define BLOCK_WIDTH             8
//#define BLOCK_LENGTH            10
#define BLOCK_LENGTH            16

#define SCREEN_SIZE_X           800
#define SCREEN_SIZE_Y           600


#define SQUARE_SIZE             8

#define NB_BLOCK_Y              16
#define NB_BLOCK_X              10

//#define SCREEN_SIZE_X           320
//#define SCREEN_SIZE_Y           240


#define SCREEN_BIT_RESOLUTION   32

#define WINDOW_WIDTH            PIXEL_BLOCK_SIZE * BLOCK_WIDTH
#define WINDOW_LENGTH           PIXEL_BLOCK_SIZE * BLOCK_LENGTH


enum
  {
    EMPTY, 
    RED,
    GREEN,
    BLUE,
    YELLOW,
    PINK,
    BLACK,
    WHITE
  };


enum {
  C_NOIR, 
  C_BLEU_FONCE, 
  C_VERT_FONCE, 
  C_CYAN_FONCE, 
  C_ROUGE_FONCE,
  C_MAGENTA_FONCE, 
  C_OCRE, 
  C_GRIS_CLAIR, 
  C_GRIS, 
  C_BLEU, 
  C_VERT,
  C_CYAN, 
  C_ROUGE, 
  C_MAGENTA, 
  C_JAUNE, 
  C_BLANC, 
  NB_COLORS
};


#endif

