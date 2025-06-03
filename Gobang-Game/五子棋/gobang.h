#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<Windows.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<easyx.h>
#include<graphics.h>

//pvp��¼
struct chessmsg{
	int PLAYER;
	int ROW, COL;
}*pa;

//pve��¼
struct chessmsg2{
	int PLAYER2;
	int ROW2, COL2;
}*pb;

//��Ϸʱ��
struct runtime{
	clock_t start;
	clock_t stop;
	double duration;
}runtime;
struct runtime t;

//��Ϸ����״̬
enum grah{
	begin,
	pvp,
	pve
};
enum grah hm = begin;//Ĭ��Ϊ��ʼ����

//����״̬���ޡ����塢����
enum chess{
	none,
	black,
	white
};

//��������
int map[15][15] = { 0 };

//���״̬
struct mouse{
	int row;
	int col;
	bool show;
	int player;
}mouse = { -1,-1,false,black };//��ʼ��Ϊ����

//����ͼƬ
IMAGE img;

bool judge(int x, int y);//�ж�ʤ��
void back();//�Ծֻط�
void chessAI();//AI����