#include "EGame.h"
EGame* getGame()
{
	static EGame game;
	return &game;
}
bool game_init(EGame* game, int w, int h, int flag)
{
	HWND hWnd = initgraph(w, h);
	//去掉标题栏
	SetWindowLong(hWnd, GWL_STYLE,
		GetWindowLong(hWnd, GWL_STYLE) - WS_CAPTION);
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, w, h, SWP_SHOWWINDOW);
	//setbkcolor(WHITE);
	game->inRunning = true;
	srand(time(NULL));

	for (size_t i = 0; i < STR_NUM; i++)
	{
		initRain(&game->rain[i], i);
	}
	//获取当前时间
	game->t1 = game->t2 = GetTickCount();


	//设置帧率
	game->fps = 1000 / 1000;
	game->startTime = 0;
	return game->inRunning;
}

void game_clean(EGame* game)
{

}

bool game_isRunnig(EGame* game)
{
	return game->inRunning;
}

void game_quit(EGame* game)
{
	game->inRunning = false;
}

void game_handleEvents(EGame* game)
{
	if (_kbhit())
	{
		if (' ' == _getch())
		{
			game_quit(game);
		}
	}
}

void game_render(EGame* game)
{
	//setbkmode(TRANSPARENT);
	for (size_t i = 0; i < STR_NUM; i++)
	{
		showRain(&game->rain[i]);
	}
}

void game_update(EGame* game)
{
	for (int i = 0; i < STR_NUM; ++i)
	{
		rainFallDown(&game->rain[i]);
	}
	game->t2 = GetTickCount();
	if (game->t2 - game->t1 >= 20)
	{
		game->t1 = game->t2;
		for (size_t i = 0; i < STR_NUM; i++)
		{
			changCh(&game->rain[rand() % STR_NUM]);
		}
	}
	
}

void game_setfps(EGame* game, int fps)
{
	game->fps = fps;
}

float game_fps(EGame* game)
{
	return game->fps;
}

void game_frameStart(EGame* game)
{
	game->startTime = clock();
}

void game_frameEnd(EGame* game)
{
	game->frameTime = clock() - game->startTime;
	if (game->fps - game->frameTime > 0)
	{
		Sleep(game->fps - game->frameTime);
	}
}