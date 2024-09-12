#ifndef EGAME_H
#define EGAME_H
#include "Rain.h"

//��Ϸ�ṹ����
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
 * ��ȡ��Ϸ����
 */
EGame* getGame();
/**
 * ��ʼ����Ϸ.
 * @param game ��ȡ��Ϸʵ��
 * @param title ��Ϸ���ڱ���
 * @param w	���ڵĿ��
 * @param h ���ڵĸ߶�
 */
bool game_init(EGame* game, int w, int h, int flag);
/**
 * ������Ϸ �ͷ���Դ.
 */
void game_clean(EGame* game);
/**
 * �ж���Ϸ�Ƿ���������
 */
bool game_isRunnig(EGame* game);
/*
 * ��Ϸ����.
 */
void game_quit(EGame* game);
/*
 * �¼�
 */
void game_handleEvents(EGame* game);
/**
 * ��Ⱦ
 */
void game_render(EGame* game);
/**
 * �����¼�
 */
void game_update(EGame* game);
/*
 * ����֡��.
 */
void game_setfps(EGame* game, int fps);
float game_fps(EGame* game);
void game_frameStart(EGame* game);
void game_frameEnd(EGame* game);
/**
 * ������������.
 */

#endif // !EGAME_H
