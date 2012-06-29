#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


#ifdef main  //idk WHY
#undef main  //THIS IS THE ONLY WAY
#endif       //IT WORKS..FUCK IT.

SDL_Surface* g_pMainSurface = NULL;
SDL_Event g_Event;

int main(int argc, char *argv[])
{ 
	//initializes Subsystems
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)==-1) 
	{
		fprintf(stderr,"Could not initialize!\n");
		exit(1);
	}

	else
	{
		fprintf(stdout,"SDL initialized!\n");
		atexit(SDL_Quit);
	}

	g_pMainSurface = SDL_SetVideoMode(640,480,0,SDL_ANYFORMAT);

	if(!g_pMainSurface)
	{
		fprintf(stderr,"Could not create main surface!\n");
		exit(1);
	}

	for (;;)
	{
		if(SDL_WaitEvent(&g_Event)==0)
		{
			fprintf(stderr,"Error while waiting for an event!\n");
			exit(1);
		}

		//check the type of event
		if(g_Event.type==SDL_QUIT)
		{
			fprintf(stdout,"Quit event has occurred.\n");
			break;
		}

	}

	fprintf(stdout,"Terminating program normally.\n");
	return 0;

}

