#include "Master.h"
#include "DrawSdl.h"

using namespace  std;

SDL_Color sdl_black = { 0,0,0,0 };
SDL_Color sdl_white = { 230,230,230,0 };


DrawSdl::DrawSdl()
{
  screen              = NULL;
  carre               = NULL;

  text                = NULL;

  score_surface       = NULL;
  clock_surface       = NULL;
  level_surface       = NULL; 
  line_number_surface = NULL;
  
  font_large          = NULL;
  font_medium         = NULL;
  font_small          = NULL;  

  clock[0]=0;
  score[0]=0;
  level[0]=0;

  game_over_1[0]=0;
  game_over_2[0]=0;
  game_over_3[0]=0;
  game_over_4[0]=0;
  
}


void DrawSdl::init_colors(void)
{
  couleurs[C_NOIR]          = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
  couleurs[C_BLEU_FONCE]    = SDL_MapRGB(screen->format, 0x00, 0x00, 0x80);
  couleurs[C_VERT_FONCE]    = SDL_MapRGB(screen->format, 0x00, 0x80, 0x00);
  couleurs[C_CYAN_FONCE]    = SDL_MapRGB(screen->format, 0x00, 0x80, 0x80);
  couleurs[C_ROUGE_FONCE]   = SDL_MapRGB(screen->format, 0x80, 0x00, 0x00);
  couleurs[C_MAGENTA_FONCE] = SDL_MapRGB(screen->format, 0x80, 0x00, 0x80);
  couleurs[C_OCRE]          = SDL_MapRGB(screen->format, 0x80, 0x80, 0x00);
  couleurs[C_GRIS_CLAIR]    = SDL_MapRGB(screen->format, 0xC0, 0xC0, 0xC0);
  couleurs[C_GRIS]          = SDL_MapRGB(screen->format, 0x80, 0x80, 0x80);
  couleurs[C_BLEU]          = SDL_MapRGB(screen->format, 0x00, 0x00, 0xFF);
  couleurs[C_VERT]          = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
  couleurs[C_CYAN]          = SDL_MapRGB(screen->format, 0x00, 0xFF, 0xFF);
  couleurs[C_ROUGE]         = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
  couleurs[C_MAGENTA]       = SDL_MapRGB(screen->format, 0xFF, 0x00, 0xFF);
  couleurs[C_JAUNE]         = SDL_MapRGB(screen->format, 0xFF, 0xFF, 0x00);
  couleurs[C_BLANC]         = SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF);
}


void DrawSdl::refresh()
{
  SDL_Flip(screen);  
}



void DrawSdl::load_ttf_data()
{
  font_large  = TTF_OpenFont(TIME_FONT, 30);
  font_medium = TTF_OpenFont(TIME_FONT, 25);
  font_small  = TTF_OpenFont(TIME_FONT, 20);
}

void DrawSdl::free_ttf_data()
{
  TTF_CloseFont(font_small);
  TTF_CloseFont(font_medium);
  TTF_CloseFont(font_large);
}


void DrawSdl::enable_sdl_and_ttf()
{
  char env_to_put[128];
  strcpy(env_to_put,"SDL_VIDEO_CENTERED=1");
  //putenv("SDL_VIDEO_CENTERED=1");
  putenv(env_to_put);
  SDL_Init(SDL_INIT_VIDEO); 
  TTF_Init(); 
}

void DrawSdl::disable_sdl_and_ttf()
{
  TTF_Quit();
  SDL_Quit();
}

void DrawSdl::free_sdl_screen_data()
{
  SDL_FreeSurface(grey_box);
  SDL_FreeSurface(tetris_splash);
  SDL_FreeSurface(tetris_blocks);
}



void DrawSdl::load_sdl_screen_data()
{
  tetris_splash = SDL_LoadBMP(GRAPHIC_TETRIS_SPLASH);
  grey_box      = SDL_LoadBMP(GRAPHIC_GREY_BOX);
  tetris_blocks = SDL_LoadBMP(GRAPHIC_RED_BOX);
}

void DrawSdl::draw_block(int x,int y,int color)
{
  SDL_Rect sqrRect;
  sqrRect.x=x;
  sqrRect.y=y;
  //  sqrRect.w=SQUARE_SIZE;
  //  sqrRect.h=SQUARE_SIZE;
  sqrRect.w=PIXEL_BLOCK_SIZE;
  sqrRect.h=PIXEL_BLOCK_SIZE;

  SDL_FillRect(screen , &sqrRect , 0x772233);
}


void DrawSdl::screen_activate()
{
  screen = SDL_SetVideoMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, SCREEN_BIT_RESOLUTION, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption(WM_CAPTION, NULL);
}


void DrawSdl::draw_number_of_line(int number_of_line)
{
  SDL_Rect position;
  //position.x = 70;
  position.x=PIXEL_BLOCK_SIZE*7;
  //position.y = 220;
  position.y=PIXEL_BLOCK_SIZE*22;

  sprintf(nb_line, "Line:  %d", number_of_line);

  line_number_surface = TTF_RenderText_Shaded(font_medium, nb_line, sdl_white,sdl_black);
  SDL_BlitSurface(line_number_surface, NULL, screen, &position);
  SDL_FreeSurface(line_number_surface); 
}

void DrawSdl::draw_level_number(int level_number)
{
  SDL_Rect position;

  //position.x = 70;
  position.x=PIXEL_BLOCK_SIZE*7;
  //position.y = 250;
  position.y=PIXEL_BLOCK_SIZE*25;

  sprintf(level, "Level: %d", level_number);

  level_surface = TTF_RenderText_Shaded(font_medium, level, sdl_white,sdl_black);
  SDL_BlitSurface(level_surface, NULL, screen, &position);
  SDL_FreeSurface(level_surface); 
}


void DrawSdl::draw_score(int current_score)
{
  SDL_Rect position;

  //position.x = 70;
  position.x=PIXEL_BLOCK_SIZE*7;
  
  //position.y = 280;
  position.y=PIXEL_BLOCK_SIZE*28;

  sprintf(score, "Score: %d", current_score);

  score_surface = TTF_RenderText_Shaded(font_medium, score, sdl_white,sdl_black);
  SDL_BlitSurface(score_surface, NULL, screen, &position);
  SDL_FreeSurface(score_surface); 
}


void DrawSdl::draw_time(int number_of_seconds)
{
  SDL_Rect position;
  //  position.x = 70;
  position.x=PIXEL_BLOCK_SIZE*7;
    //  position.y = 310;
  position.y=PIXEL_BLOCK_SIZE*31;


  sprintf(clock, "Time:  %d", number_of_seconds);

  clock_surface = TTF_RenderText_Shaded(font_medium, clock, sdl_white, sdl_black);
  SDL_BlitSurface(clock_surface, NULL, screen, &position);
  SDL_FreeSurface(clock_surface); 
}


void DrawSdl::clean_screen()
{
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
}


void DrawSdl::init_game_info()
{
  sprintf(clock,"Time : %d", 0);
  sprintf(score,"Score: %d", 0);         
  sprintf(level,"Level: %d", 0);
  
  score_surface = TTF_RenderText_Shaded(font_large,  score,   sdl_color_black, sdl_color_white);  
  clock_surface = TTF_RenderText_Shaded(font_medium, clock, sdl_color_black, sdl_color_white);
  level_surface = TTF_RenderText_Shaded(font_medium, level, sdl_color_black, sdl_color_white);
}


void DrawSdl::draw_border()
{

  //Y axis left

  //  board_position.x=292;
  //  board_position.y=92;
  //  board_position.x=PIXEL_BLOCK_SIZE*(22-1);
  board_position.x=X_BORDER_LEFT;
  //printf("%d",BORDER_LEFT);
  board_position.y=PIXEL_BLOCK_SIZE*(NB_BLOCK_Y-1);
  for (int i=0;i<NB_BLOCK_Y;i++)
    {
      //SDL_BlitSurface(grey_box, NULL, screen, &board_position);
      draw_block(board_position.x,board_position.y,0x223344);
      board_position.y+=PIXEL_BLOCK_SIZE;
    }


  //Y axis right
  //  board_position.x=687;
  //board_position.y=92;
  //board_position.x=PIXEL_BLOCK_SIZE*32;
  board_position.x=X_BORDER_RIGHT;
  board_position.y=PIXEL_BLOCK_SIZE*(NB_BLOCK_Y-1);
  for (int i=0;i<NB_BLOCK_Y;i++)
    {
      //SDL_BlitSurface(grey_box, NULL, screen, &board_position);
      draw_block(board_position.x,board_position.y,0x223344);
      board_position.y+=PIXEL_BLOCK_SIZE;
    }

  //X axis left to right
  //board_position.x=292;
  //board_position.y=508;
  //  board_position.x=PIXEL_BLOCK_SIZE*22;
  board_position.x=X_BORDER_LEFT+PIXEL_BLOCK_SIZE;
  //board_position.y=PIXEL_BLOCK_SIZE*39;
  board_position.y=Y_BORDER_BOTTOM;
  for (int i=0;i<NB_BLOCK_X;i++)
    {
      //SDL_BlitSurface(grey_box, NULL, screen, &board_position);
      draw_block(board_position.x,board_position.y,0x223344);
      board_position.x+=PIXEL_BLOCK_SIZE;
    }
}




// Draw the tetronimo played 
void DrawSdl::draw_active_shape_on_board(Shape * shape)
				   
{
  std::vector<Block> block_v=shape->block_v;
  
  //  SDL_Rect fill_xy;
  //  fill_xy.x=SQUARE_SIZE;
  //  fill_xy.y=SQUARE_SIZE;

  for(int i = 0;i< 4; i++)
    {
      //position.x = PIXEL_BLOCK_SIZE*(shape->block_v[i].get_x()+14)-5;
      //position.y = PIXEL_BLOCK_SIZE*(shape->block_v[i].get_y()+4);
      //SDL_BlitSurface(tetris_blocks, NULL, screen, &position);
      //position.x = SQUARE_SIZE*(shape->block_v[i].get_x()+PIXEL_BLOCK_SIZE);
      //position.y = SQUARE_SIZE*(shape->block_v[i].get_y());
      //      position.x=OFFSET_X_DISPLAY_SHAPE+(shape->block_v[i].get_x())*PIXEL_BLOCK_SIZE;


      //      position.x=(PIXEL_BLOCK_SIZE*27)+(shape->block_v[i].get_x())*PIXEL_BLOCK_SIZE;
      //      position.y=(PIXEL_BLOCK_SIZE*2)+(shape->block_v[i].get_y())*PIXEL_BLOCK_SIZE;
      position.x=22*PIXEL_BLOCK_SIZE+(shape->block_v[i].get_x())*PIXEL_BLOCK_SIZE;
      position.y=19*PIXEL_BLOCK_SIZE+shape->block_v[i].get_y()*PIXEL_BLOCK_SIZE;
      draw_block(position.x,position.y,0x223344);
    }
}

// Draw the next tetronimo on the upper left of the screen
void DrawSdl::draw_next_shape(Shape * shape)
{
  std::vector<Block> block_v=shape->block_v;
  SDL_Rect pos;

  for(int i = 0;i< 4; i++)
    {
      //pos.x = PIXEL_BLOCK_SIZE*(block_v[i].get_x()-2);
      //pos.y = PIXEL_BLOCK_SIZE*(block_v[i].get_y()+3);
      //SDL_BlitSurface(tetris_blocks, NULL, screen, &pos);

      //pos.x = PIXEL_BLOCK_SIZE*(block_v[i].get_x()-2);
      //pos.y = PIXEL_BLOCK_SIZE*(block_v[i].get_y()+3);

      pos.x = (5*PIXEL_BLOCK_SIZE)+(block_v[i].get_x()*PIXEL_BLOCK_SIZE);
      pos.y = (15*PIXEL_BLOCK_SIZE)+(block_v[i].get_y()*PIXEL_BLOCK_SIZE);
      
      draw_block(pos.x,pos.y,0x223344);
    }
}


// Draw the dead tetronimo on the board
void DrawSdl::draw_dead_shape_on_board(GameBoard GB)
{
  for (int i = 0 ; i < NB_BLOCK_Y ; i++)
    for (int j = 0 ; j < NB_BLOCK_X   ; j++)
      if (GB.map[i][j]!=0)
	{
	  //position.x = (j+14) * PIXEL_BLOCK_SIZE-5;
	  //position.y = (i+4)  * PIXEL_BLOCK_SIZE;	  
	  //SDL_BlitSurface(tetris_blocks, NULL, screen, &position);	  

	  //position.x = SQUARE_SIZE * ((j+14)-5);
	  //position.y = SQUARE_SIZE * ((i+4) );	  
	  position.x = (22*PIXEL_BLOCK_SIZE)+(j*PIXEL_BLOCK_SIZE);
	  position.y = (19*PIXEL_BLOCK_SIZE)+(i*PIXEL_BLOCK_SIZE);
	  draw_block(position.x,position.y,GB.map[i][j]);
	} 
}



void DrawSdl::draw_splash_screen()
{
  SDL_Rect position;

  //position.x=130;
  //position.y=200;
  //position.x=(SCREEN_SIZE_X/3)*2;
  position.x=PIXEL_BLOCK_SIZE*20;
  //position.y=(SCREEN_SIZE_Y/3)*2;
  position.y=PIXEL_BLOCK_SIZE*20;

  //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  //SDL_BlitSurface(tetris_splash, NULL, screen, &position);
}


void DrawSdl::draw_press_enter_to_play()
{
  SDL_Rect position;
  SDL_Color sdl_black = { 0,0,0,0 };
  SDL_Color sdl_white = { 230,230,230,0 };
  SDL_Surface * txt_sdl_surface;
  
  //  return;
  //position.x = 250;
  //position.y = 400;
  position.x = (SCREEN_SIZE_X*2)/5;
  position.y = (SCREEN_SIZE_Y*2)/3;

  sprintf(score, "Press Enter To Play");

  txt_msg = TTF_RenderText_Shaded(font_large, score, sdl_white,sdl_black);
  SDL_BlitSurface(txt_msg, NULL, screen, &position);
  SDL_FreeSurface(txt_msg); 
}

void DrawSdl::game_over(int score,int level_number,int number_of_line)
{

  SDL_Rect position;
  SDL_Surface * txt_sdl_surface;


  position.x = (SCREEN_SIZE_X/4)*2;
  position.y = (SCREEN_SIZE_Y/4)*3;

  sprintf(game_over_1, "Game Over");
  sprintf(game_over_2, "Level : %d",level_number);
  sprintf(game_over_3, "Score : %d",score);
  sprintf(game_over_4, "Lines : %d",number_of_line);

  txt_sdl_surface = TTF_RenderText_Shaded(font_large, game_over_1, sdl_white,sdl_black);
  SDL_BlitSurface(txt_msg, NULL, screen, &position);
  SDL_FreeSurface(txt_msg);

  position.x+=30;
  position.y+=50;

  txt_msg = TTF_RenderText_Shaded(font_medium, game_over_2, sdl_white,sdl_black);
  SDL_BlitSurface(txt_msg, NULL, screen, &position);
  SDL_FreeSurface(txt_msg);

  position.y+=30;

  txt_msg = TTF_RenderText_Shaded(font_medium, game_over_3, sdl_white,sdl_black);
  SDL_BlitSurface(txt_msg, NULL, screen, &position);
  SDL_FreeSurface(txt_msg);

  position.y+=30;

  txt_msg = TTF_RenderText_Shaded(font_medium, game_over_4, sdl_white,sdl_black);
  SDL_BlitSurface(txt_msg, NULL, screen, &position);
  SDL_FreeSurface(txt_msg);
}




