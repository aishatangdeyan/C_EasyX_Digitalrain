#include "EGame.h"

int main(int argc, char argv[])
{
	EGame* game = getGame();
	game_init(game, GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYSCREEN), EX_SHOWCONSOLE);

	while (game_isRunnig(game))
	{
		BeginBatchDraw();
		cleardevice();
		game_frameStart(game);
		
		//处理事件
		game_handleEvents(game);
		//渲染
		game_render(game);
		//更新
		game_update(game);

		game_frameEnd(game);
		EndBatchDraw();
	}
	game_clean(game);
	return 0;
}