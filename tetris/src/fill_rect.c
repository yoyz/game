//#include "SDL.h"
#include <SDL/SDL.h>


int FPS = 50;    // Assign a FPS
int NextTick , interval ;

// Initialize FPS_Fn( )
void FPS_Initial(void) {
NextTick = 0 ;
interval = 1 * 1000 / FPS ;
return;
}

// Frame Per Second Function  , put this in a loop
void FPS_Fn(void) {
if ( NextTick > SDL_GetTicks( ) ) SDL_Delay( NextTick - SDL_GetTicks( ) );
NextTick = SDL_GetTicks( ) + interval ;
return;
}

int main(int argc, char *argv[])
{

SDL_Event event;
int bRun = 1;
int pidx = 0;
int aTick = 0;
SDL_Surface *screen ;
enum walk { justice1 , justice2 , justice3 , justice4
    , justice5 , justice6 , justice_No  };
SDL_Surface *anim[justice_No];
SDL_Rect animRect , sqrRect;
animRect.x = 300 ;
animRect.y = 220 ;
animRect.w = 60 ;  // Set the width of this rectangle area
animRect.h = 20 ;  // Set the height of this rectangle area
sqrRect.x = 0 ;
sqrRect.y = 0 ;
int rgColor = 100;  // Use this integer to change color

atexit(SDL_Quit);

if( SDL_Init(SDL_INIT_VIDEO) < 0 ) exit(1);

SDL_WM_SetCaption("SDL Window", NULL);

screen = SDL_SetVideoMode( 640 , 480 , 32 , SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_ANYFORMAT);

anim[0] = SDL_LoadBMP("./anim/justice1.bmp");
anim[1] = SDL_LoadBMP("./anim/justice2.bmp");
anim[2] = SDL_LoadBMP("./anim/justice3.bmp");
anim[3] = SDL_LoadBMP("./anim/justice4.bmp");
anim[4] = SDL_LoadBMP("./anim/justice5.bmp");
anim[5] = SDL_LoadBMP("./anim/justice6.bmp");

FPS_Initial( );

while(bRun) {
    aTick++;
    rgColor+=4;  // rgColor = rgColor + 4 for each time
    if(rgColor >= 255) rgColor = 100;
    SDL_FillRect(screen , NULL , 0x221122);
    SDL_FillRect(screen , &animRect , SDL_MapRGB(screen->format , rgColor , rgColor , 20 ) );
    SDL_BlitSurface( anim[pidx] , NULL , screen , &sqrRect );
    SDL_Flip(screen);
    FPS_Fn();
    if( aTick%10 == 0 ) pidx++;
    if(pidx >= justice_No) pidx = 0;
    while( SDL_PollEvent( &event ) ){
        switch( event.type ){
            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
                    case SDLK_UP:
                        animRect.y = animRect.y - 10;
                        break;
                    case SDLK_DOWN:
                        animRect.y = animRect.y + 10;
                        break;
                    case SDLK_LEFT:
                        animRect.x = animRect.x - 10;
                        break;
                    case SDLK_RIGHT:
                        animRect.x = animRect.x + 10;
                        break;
                    case SDLK_ESCAPE:
                        bRun = 0 ;
                        break;
                    default:
                        break;
                    } // switch( event.key.keysym.sym ){ END
                break; // case SDL_KEYDOWN: END
            case SDL_QUIT:
                bRun = 0;
                break;
            default:
                break;
            } // switch( event.type ){ END
        } // while( SDLK_PollEvent( &event ) ){ END
    }; // while(bRun) { END
    

return 0;
}
