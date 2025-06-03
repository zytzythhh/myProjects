#define _CRT_SECURE_NO_WARNINGS 1
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<bits/stdc++.h>
#include"oper.h"
#include"Ntree.h"

//界面菜单
enum MenuState {
	MAIN_MENU,//主界面
	WORD_QUERY1,//单词整体查询
	WORD_QUERY2,//单词前缀查询
	DISPLAY_WORD_LIST//查看单词表
};

MenuState currentState = MAIN_MENU;//当前界面

//窗口初始化
void init() {
	initgraph(700, 700);
	IMAGE mage;
	loadimage(&mage, _T("111.jpg"));
	putimage(0, 0, &mage);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
}

//主界面初始化
void initMenu() {
	settextstyle(55, 0, _T("楷体"));
	fillrectangle(150, 100, 550, 200);
	char arr[] = "单词整体查询";
	int w = textwidth(arr);
	int h = textheight(arr);
	int x1 = 200 - w / 2;
	int y1 = 50 - h / 2;
	outtextxy(150 + x1, 100 + y1, _T("单词整体查询"));
	fillrectangle(150, 300, 550, 400);
	outtextxy(150 + x1, 300 + y1, _T("单词前缀查询"));
	fillrectangle(150, 500, 550, 600);
	char arr1[] = "查看单词表";
	w = textwidth(arr1);
	x1 = 200 - w / 2;
	outtextxy(150 + x1, 500 + y1, _T("查看单词表"));
}

//单词整体查询
void drawWordQuery1() {
	init();
	settextstyle(50, 0, _T("楷体"));
	outtextxy(60, 100, _T("请输入要查询的单词："));
	setlinecolor(BLACK);
	rectangle(200, 200, 500, 280);
	settextstyle(30, 0, _T("楷体"));
	outtextxy(610, 650, _T("返回"));
	setlinecolor(BLACK);
	rectangle(600, 650, 680, 680);
}

//单词前缀查询
void drawWordQuery2() {
	init();
	settextstyle(50, 0, _T("楷体"));
	outtextxy(60, 100, _T("请输入要查询的单词前缀："));
	setlinecolor(BLACK);
	rectangle(200,200,500,280);
	settextstyle(30, 0, _T("楷体"));
	outtextxy(610, 650, _T("返回"));
	setlinecolor(BLACK);
	rectangle(600, 650, 680, 680);
}

//查看单词表
void drawDisplayWordList() {
	init();
	settextstyle(30, 0, _T("楷体"));
	outtextxy(30, 20, _T("单词表如下："));
	setlinecolor(BLACK);
	settextstyle(30, 0, _T("楷体"));
	outtextxy(610, 20, _T("返回"));
	setlinecolor(BLACK);
	rectangle(600, 20, 680, 50);

    //确定表格的位置和大小
	settextstyle(20, 0, _T("楷体"));
    int startX = 40,startY = 60;
    int cellWidth = 130,cellHeight = 25;
    //绘制表格框架
    for (int i = 0; i <= 25; ++i) {
        line(startX, startY + i * cellHeight, startX + 5 * cellWidth, startY + i * cellHeight); // 横线
    }
    for (int i = 0; i <= 5; ++i) {
        line(startX + i * cellWidth, startY, startX + i * cellWidth, startY + 25 * cellHeight); // 竖线
    }
	//填充
	for (int i = 0; i < num; i++) {
		outtextxy(startX + 10, startY + (i%25) * cellHeight + 9, v[i].word.c_str());
		if ((i+1) % 25 == 0) {
			startX += 130; startY = 60;
		}
	}
}

//鼠标点击
void handInput(int x, int y) {
	if (currentState == MAIN_MENU) {//主界面
		if (x > 150 && x < 550 && y > 100 && y < 200) {
			currentState = WORD_QUERY1;
			cleardevice();
			drawWordQuery1();//单词整体查询界面
		}
		else if (x > 150 && x < 550 && y > 300 && y < 400) {
			currentState = WORD_QUERY2;
			cleardevice();
			drawWordQuery2();//单词前缀查询界面
		}
		else if (x > 150 && x < 550 && y > 500 && y < 600) {
			currentState = DISPLAY_WORD_LIST;
			cleardevice();
			drawDisplayWordList();//查看单词表
		}
	}
	else if (currentState == WORD_QUERY1 || currentState == WORD_QUERY2) {//两个查询界面
		if (x > 600 && x < 680 && y>650 && y < 680) {//返回主界面
			cleardevice();
			init();
			initMenu();
			currentState = MAIN_MENU;
		}
		else if (x > 200 && x < 500 && y>200 && y < 280) {//单词查询
			line(205, 205, 205, 275);
			string s;
			cin >> s;
			settextstyle(50, 0, _T("楷体"));
			outtextxy(200, 200, s.c_str());

			//整体查询
			if (currentState == WORD_QUERY1) {
				if (Ti.search1(s)) {//单词存在
					vector<int> p = Ti.searchWord1(s);
					settextstyle(30, 0, _T("楷体"));
					outtextxy(60, 400, _T("该单词所在行号为："));
					cout << "该单词所在行号为： ";
					int w = textwidth("0 ");
					int x = 350;
					for (int pos : p) {
						string ss = to_string(pos);
						outtextxy(x + w, 400, ss.c_str());
						cout << pos << " ";
						x = x + w;
					}
					cout << endl;
				}
				else {//单词不存在
					outtextxy(60, 400, _T("该单词不存在！"));
					cout<<"该单词不存在！" << endl;
				}
			}
			//前缀查询
			else if (currentState == WORD_QUERY2) {
				if (Ti.search2(s)){//单词存在
					vector<wordNode> p = Ti.searchWord2(s);
					settextstyle(25, 0, _T("楷体"));
					outtextxy(60, 300, _T("可能的完整单词有："));
					cout << "可能的完整单词有： "<<endl;
					int k = 1, w=textheight("0");
					int y = 340;
					settextstyle(20, 0, _T("楷体"));
					for ( auto i:p) {
						int x = 320;
						string ss = '(' + to_string(k) + ')';
						outtextxy(60, y, ss.c_str());
						outtextxy(120, y, i.word.c_str());
						cout << "(" << k << ") " << i.word << " 所在行号为： ";
						outtextxy(220, y, _T("所在行号为："));
						for (auto j : i.positions) {
							string sss = to_string(j);
							outtextxy(x + w, y, sss.c_str());
							cout << j << " ";
							x = x + w;
						}
						cout << endl;
						k++; y += w;
					}
				}
				else {//单词不存在
					outtextxy(60, 400, _T("该单词不存在！"));
					cout << "该单词不存在！" << endl;
				}
			}
		}
	}
}

int main() {
	string filename = "text.txt";
	indexTextFile(filename, Ti);//读取文本文档并索引化
	
	init();
	initMenu();//图形化界面初始化

	displayTrieWords(Ti);//构造单词表

	while (true) {//鼠标点击
		MOUSEMSG m;
		m = GetMouseMsg();
		if (currentState==MAIN_MENU && m.uMsg == WM_LBUTTONDOWN) {//主界面
			handInput(m.x, m.y);
		}
		else if ((currentState == WORD_QUERY1 || currentState == WORD_QUERY2) && m.uMsg == WM_LBUTTONDOWN) {//两个查询界面
			handInput(m.x, m.y);
		}
		else if (currentState == DISPLAY_WORD_LIST && m.uMsg == WM_LBUTTONDOWN) {//单词表查找界面返回主界面
			if (m.x > 600 && m.x < 680 && m.y>20 && m.y < 50) {
				cleardevice();
				init();
				initMenu();
				currentState = MAIN_MENU;
			}
		}
	}
}