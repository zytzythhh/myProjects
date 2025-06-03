#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<Windows.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<easyx.h>
#include<graphics.h>

//pvp记录
struct chessmsg{
	int PLAYER;
	int ROW, COL;
}*pa;

//pve记录
struct chessmsg2{
	int PLAYER2;
	int ROW2, COL2;
}*pb;

//游戏时间
struct runtime{
	clock_t start;
	clock_t stop;
	double duration;
}runtime;
struct runtime t;

//游戏界面状态
enum grah{
	begin,
	pvp,
	pve
};
enum grah hm = begin;//默认为开始界面

//棋子状态：无、黑棋、白棋
enum chess{
	none,
	black,
	white
};

//棋盘数组
int map[15][15] = { 0 };

//鼠标状态
struct mouse{
	int row;
	int col;
	bool show;
	int player;
}mouse = { -1,-1,false,black };//初始化为黑棋

//背景图片
IMAGE img;

bool judge(int x, int y);//判断胜负
void back();//对局回放
void chessAI();//AI下棋