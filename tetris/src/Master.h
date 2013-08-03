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

enum color
  {
    white = 0xFFFFFF,
    black = 0, 
    red   = 0xFF0000, 
    green = 0xFF00, 
    blue  = 0xFF,   
  }; 



//SetColor(red);



#define TETROMINO_BLOCK_SIZE 4

//#define NB_BLOCK_Y       20
//#define NB_BLOCK_X       10



//#define PIXEL_BLOCK_SIZE        10

//#define BLOCK_WIDTH             8
//#define BLOCK_LENGTH            10
//#define BLOCK_WIDTH             10
//#define BLOCK_LENGTH            16

#define SCREEN_SIZE_X           640
#define SCREEN_SIZE_Y           480

//#define SCREEN_SIZE_X           320
//#define SCREEN_SIZE_Y           240


//64 tile X
//48 tile y

//#define SQUARE_SIZ;E             10
#define PIXEL_BLOCK_SIZE        10
//#define PIXEL_BLOCK_SIZE        5

#define NB_BLOCK_Y              20
#define NB_BLOCK_X              10

//#define X_BORDER_LEFT            (((SCREEN_SIZE_X/2)-(PIXEL_BLOCK_SIZE*(10+1))))

//#define X_OFFSET                 
#define X_BORDER_LEFT            PIXEL_BLOCK_SIZE*21
//#define X_BORDER_RIGHT           (((SCREEN_SIZE_X/2)+(PIXEL_BLOCK_SIZE*0)))
#define X_BORDER_RIGHT           PIXEL_BLOCK_SIZE*32

#define Y_BORDER_BOTTOM          PIXEL_BLOCK_SIZE*39

//#define OFFSET_X_DISPLAY_SHAPE   ((SCREEN_SIZE_X/PIXEL_BLOCK_SIZE)/2)-(NB_BLOCK_X*SQUARE_SIZE)



//                                640/10 - 10*10
                                
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

