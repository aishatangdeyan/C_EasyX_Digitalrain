#ifndef EGAME_H
#define EGAME_H
#include "Rain.h"

//游戏结构声明
typedef struct EGame
{
	ExMessage msg;
	struct Rain rain[STR_NUM];
	DWORD t1, t2;

	bool inRunning;
	float fps;
	uint32_t startTime;
	uint32_t frameTime;
}EGame;
/**
 * 获取游戏单例
 */
EGame* getGame();
/**
 * 初始化游戏.
 * @param game 获取游戏实例
 * @param title 游戏窗口标题
 * @param w	窗口的宽度
 * @param h 窗口的高度
 */
bool game_init(EGame* game, int w, int h, int flag);
/**
 * 清理游戏 释放资源.
 */
void game_clean(EGame* game);
/**
 * 判断游戏是否正常运行
 */
bool game_isRunnig(EGame* game);
/*
 * 游戏结束.
 */
void game_quit(EGame* game);
/*
 * 事件
 */
void game_handleEvents(EGame* game);
/**
 * 渲染
 */
void game_render(EGame* game);
/**
 * 更新事件
 */
void game_update(EGame* game);
/*
 * 控制帧率.
 */
void game_setfps(EGame* game, int fps);
float game_fps(EGame* game);
void game_frameStart(EGame* game);
void game_frameEnd(EGame* game);
/**
 * 其他帮助函数.
 */

#endif // !EGAME_H
