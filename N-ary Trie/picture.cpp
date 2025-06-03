#define _CRT_SECURE_NO_WARNINGS 1
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<bits/stdc++.h>
#include"oper.h"
#include"Ntree.h"

//����˵�
enum MenuState {
	MAIN_MENU,//������
	WORD_QUERY1,//���������ѯ
	WORD_QUERY2,//����ǰ׺��ѯ
	DISPLAY_WORD_LIST//�鿴���ʱ�
};

MenuState currentState = MAIN_MENU;//��ǰ����

//���ڳ�ʼ��
void init() {
	initgraph(700, 700);
	IMAGE mage;
	loadimage(&mage, _T("111.jpg"));
	putimage(0, 0, &mage);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
}

//�������ʼ��
void initMenu() {
	settextstyle(55, 0, _T("����"));
	fillrectangle(150, 100, 550, 200);
	char arr[] = "���������ѯ";
	int w = textwidth(arr);
	int h = textheight(arr);
	int x1 = 200 - w / 2;
	int y1 = 50 - h / 2;
	outtextxy(150 + x1, 100 + y1, _T("���������ѯ"));
	fillrectangle(150, 300, 550, 400);
	outtextxy(150 + x1, 300 + y1, _T("����ǰ׺��ѯ"));
	fillrectangle(150, 500, 550, 600);
	char arr1[] = "�鿴���ʱ�";
	w = textwidth(arr1);
	x1 = 200 - w / 2;
	outtextxy(150 + x1, 500 + y1, _T("�鿴���ʱ�"));
}

//���������ѯ
void drawWordQuery1() {
	init();
	settextstyle(50, 0, _T("����"));
	outtextxy(60, 100, _T("������Ҫ��ѯ�ĵ��ʣ�"));
	setlinecolor(BLACK);
	rectangle(200, 200, 500, 280);
	settextstyle(30, 0, _T("����"));
	outtextxy(610, 650, _T("����"));
	setlinecolor(BLACK);
	rectangle(600, 650, 680, 680);
}

//����ǰ׺��ѯ
void drawWordQuery2() {
	init();
	settextstyle(50, 0, _T("����"));
	outtextxy(60, 100, _T("������Ҫ��ѯ�ĵ���ǰ׺��"));
	setlinecolor(BLACK);
	rectangle(200,200,500,280);
	settextstyle(30, 0, _T("����"));
	outtextxy(610, 650, _T("����"));
	setlinecolor(BLACK);
	rectangle(600, 650, 680, 680);
}

//�鿴���ʱ�
void drawDisplayWordList() {
	init();
	settextstyle(30, 0, _T("����"));
	outtextxy(30, 20, _T("���ʱ����£�"));
	setlinecolor(BLACK);
	settextstyle(30, 0, _T("����"));
	outtextxy(610, 20, _T("����"));
	setlinecolor(BLACK);
	rectangle(600, 20, 680, 50);

    //ȷ������λ�úʹ�С
	settextstyle(20, 0, _T("����"));
    int startX = 40,startY = 60;
    int cellWidth = 130,cellHeight = 25;
    //���Ʊ����
    for (int i = 0; i <= 25; ++i) {
        line(startX, startY + i * cellHeight, startX + 5 * cellWidth, startY + i * cellHeight); // ����
    }
    for (int i = 0; i <= 5; ++i) {
        line(startX + i * cellWidth, startY, startX + i * cellWidth, startY + 25 * cellHeight); // ����
    }
	//���
	for (int i = 0; i < num; i++) {
		outtextxy(startX + 10, startY + (i%25) * cellHeight + 9, v[i].word.c_str());
		if ((i+1) % 25 == 0) {
			startX += 130; startY = 60;
		}
	}
}

//�����
void handInput(int x, int y) {
	if (currentState == MAIN_MENU) {//������
		if (x > 150 && x < 550 && y > 100 && y < 200) {
			currentState = WORD_QUERY1;
			cleardevice();
			drawWordQuery1();//���������ѯ����
		}
		else if (x > 150 && x < 550 && y > 300 && y < 400) {
			currentState = WORD_QUERY2;
			cleardevice();
			drawWordQuery2();//����ǰ׺��ѯ����
		}
		else if (x > 150 && x < 550 && y > 500 && y < 600) {
			currentState = DISPLAY_WORD_LIST;
			cleardevice();
			drawDisplayWordList();//�鿴���ʱ�
		}
	}
	else if (currentState == WORD_QUERY1 || currentState == WORD_QUERY2) {//������ѯ����
		if (x > 600 && x < 680 && y>650 && y < 680) {//����������
			cleardevice();
			init();
			initMenu();
			currentState = MAIN_MENU;
		}
		else if (x > 200 && x < 500 && y>200 && y < 280) {//���ʲ�ѯ
			line(205, 205, 205, 275);
			string s;
			cin >> s;
			settextstyle(50, 0, _T("����"));
			outtextxy(200, 200, s.c_str());

			//�����ѯ
			if (currentState == WORD_QUERY1) {
				if (Ti.search1(s)) {//���ʴ���
					vector<int> p = Ti.searchWord1(s);
					settextstyle(30, 0, _T("����"));
					outtextxy(60, 400, _T("�õ��������к�Ϊ��"));
					cout << "�õ��������к�Ϊ�� ";
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
				else {//���ʲ�����
					outtextxy(60, 400, _T("�õ��ʲ����ڣ�"));
					cout<<"�õ��ʲ����ڣ�" << endl;
				}
			}
			//ǰ׺��ѯ
			else if (currentState == WORD_QUERY2) {
				if (Ti.search2(s)){//���ʴ���
					vector<wordNode> p = Ti.searchWord2(s);
					settextstyle(25, 0, _T("����"));
					outtextxy(60, 300, _T("���ܵ����������У�"));
					cout << "���ܵ����������У� "<<endl;
					int k = 1, w=textheight("0");
					int y = 340;
					settextstyle(20, 0, _T("����"));
					for ( auto i:p) {
						int x = 320;
						string ss = '(' + to_string(k) + ')';
						outtextxy(60, y, ss.c_str());
						outtextxy(120, y, i.word.c_str());
						cout << "(" << k << ") " << i.word << " �����к�Ϊ�� ";
						outtextxy(220, y, _T("�����к�Ϊ��"));
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
				else {//���ʲ�����
					outtextxy(60, 400, _T("�õ��ʲ����ڣ�"));
					cout << "�õ��ʲ����ڣ�" << endl;
				}
			}
		}
	}
}

int main() {
	string filename = "text.txt";
	indexTextFile(filename, Ti);//��ȡ�ı��ĵ���������
	
	init();
	initMenu();//ͼ�λ������ʼ��

	displayTrieWords(Ti);//���쵥�ʱ�

	while (true) {//�����
		MOUSEMSG m;
		m = GetMouseMsg();
		if (currentState==MAIN_MENU && m.uMsg == WM_LBUTTONDOWN) {//������
			handInput(m.x, m.y);
		}
		else if ((currentState == WORD_QUERY1 || currentState == WORD_QUERY2) && m.uMsg == WM_LBUTTONDOWN) {//������ѯ����
			handInput(m.x, m.y);
		}
		else if (currentState == DISPLAY_WORD_LIST && m.uMsg == WM_LBUTTONDOWN) {//���ʱ���ҽ��淵��������
			if (m.x > 600 && m.x < 680 && m.y>20 && m.y < 50) {
				cleardevice();
				init();
				initMenu();
				currentState = MAIN_MENU;
			}
		}
	}
}