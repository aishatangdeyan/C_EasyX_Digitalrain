#ifndef RAIN_H
#define RAIN_H
#include <easyx.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <conio.h>

//字符串中字符的数量
#define STR_SIZE 20
//字符串的个数
#define STR_NUM 128
//字符宽高
#define STR_WIDTH 15

typedef struct  Rain
{
	char str[STR_SIZE];
	int x, y;
	int speed;
}Rain;
//实现效果
void rainFallDown(Rain* r);
//改变随机字符的值
void changCh(Rain* r);
//生成随机字符
char createCh();
//初始化一个字符串
void initRain(Rain* r, int i);
//显示字符串
void showRain(Rain* r);

#endif // !RAIN_H
