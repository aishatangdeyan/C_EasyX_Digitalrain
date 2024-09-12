#include "Rain.h"

void rainFallDown(Rain* r)
{
	r->y += r->speed;
	if (r->y >= GetSystemMetrics(SM_CYSCREEN))
	{
		r->y = 0;
		//r->speed++;
		//if (r->speed >= 15) r->speed = 5;
	}
}

void changCh(Rain* r)
{
	//挑一个字符   来   重新生成
	r->str[rand() % STR_SIZE] = createCh();
}

char createCh()
{
	char temp = ' ';
	int flag = rand() % 3;
	switch (flag)
	{
	case 0:
		temp = '0' + rand() % 10;
		break;
	case 1:
		temp = 'a' + rand() % 26;
		break;
		temp = 'A' + rand() % 26;
	case 2:
		break;
	}
	return temp;
}

void initRain(Rain* r, int i)
{
	r->x = i * STR_WIDTH;
	r->y = rand() % GetSystemMetrics(SM_CYSCREEN);
	r->speed = rand() % 5 + 15;

	for (size_t j = 0; j < STR_SIZE; j++)
	{
		r->str[j] = createCh();
	}
}

void showRain(Rain* r)
{
	for (size_t i = 0; i < STR_SIZE; i++)
	{
		outtextxy(r->x, r->y - STR_WIDTH * i, r->str[i]);//从下往上显示
		settextcolor(RGB(0, 255 - i * 13, 0));
	}
}
