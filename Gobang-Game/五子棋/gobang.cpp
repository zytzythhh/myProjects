#include "gobang.h"

//���ƺ���
void draw(){
	if (hm !=begin){
		//���Ʊ���
		putimage(0, 0, &img);

		//��������
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID, 1);
		for (int i = 50; i <= 470; i += 30){
			line(50, i, 470, i);//����
			line(i, 50, i, 470);//����
		}
		setlinestyle(PS_SOLID, 2);
		rectangle(50, 50, 470, 470);

		//���������λ
		setfillcolor(BLACK);
		solidcircle(260, 260, 5);
		solidcircle(140, 140, 5);
		solidcircle(140, 380, 5);
		solidcircle(380, 140, 5);
		solidcircle(380, 380, 5);

		//��������
		for (int i = 0; i < 15; i++){
			for (int k = 0; k < 15; k++){
				if (map[i][k] == black){
					setfillcolor(BLACK);//����
					solidcircle(30 * k + 50, 30 * i + 50, 10);
				}
				else if (map[i][k] == white){
					setfillcolor(WHITE);//����
					solidcircle(30 * k + 50, 30 * i + 50, 10);
				}
			}
		}
		//���������
		setlinecolor(BLACK);
		if (mouse.show){
			rectangle(mouse.col * 30 + 35, mouse.row * 30 + 35, mouse.col * 30 + 65, mouse.row * 30 + 65);
		}
	}
}

//����ƶ�
void mousemove(ExMessage* msg){
	if (hm == pvp || hm==pve ){
		mouse.show = false;
		//���궨λ�������
		for (int i = 0; i < 15; i++){
			for (int k = 0; k < 15; k++){
				int gx = k * 30 + 50;
				int gy = i * 30 + 50;
				if (abs(msg->x - gx) <= 15 && abs(msg->y - gy) <= 15){
					mouse.show = true;
					mouse.row = i;
					mouse.col = k;
				}
			}
		}
	}
}

//�����
void mousepress(ExMessage* msg){

	//���˶�ս
	if (msg->message == WM_LBUTTONDOWN && map[mouse.row][mouse.col]==0 && hm==pvp){
		map[mouse.row][mouse.col] = mouse.player;

		//�����ļ�
		FILE* fp;
		fp = fopen("D:\\��ѧ\\��������Ϸ\\������\\pvp.txt", "at+");
		if (fp == NULL){
			printf("Fail to open!\n");
		}
		struct chessmsg ch[100] = {0};
		ch->PLAYER = mouse.player;
		ch->ROW = mouse.row;
		ch->COL = mouse.col;
		pa = ch;
		fprintf(fp, "%d %d %d\n", pa->PLAYER, pa->ROW, pa->COL);
		fclose(fp);

		//�ж���Ӯ
		if (judge(mouse.row, mouse.col) && mouse.player == black){
			MessageBoxA(NULL, "����Ӯ��", "������", MB_OK | MB_SYSTEMMODAL);
			back();
		}
		else if (judge(mouse.row, mouse.col) && mouse.player == white){
			MessageBoxA(NULL, "����Ӯ��", "������", MB_OK|MB_SYSTEMMODAL);
			back();
		}

		//�л�����
		mouse.player = (mouse.player == black ? white : black);
	}

	//�˻���ս
	else if (msg->message == WM_LBUTTONDOWN && map[mouse.row][mouse.col] == 0 && hm == pve){
		mouse.player = black;
		map[mouse.row][mouse.col] =black ;

		//�����ļ�
		FILE* fp;
		fp = fopen("D:\\��ѧ\\��������Ϸ\\������\\pve.txt", "at+");
		if (fp == NULL){
			printf("fail!\n");
		}
		struct chessmsg2 sh[100] = { 0 };
		sh->PLAYER2 = black;
		sh->ROW2 = mouse.row;
		sh->COL2 = mouse.col;
		pb = sh;
		fprintf(fp, "%d %d %d\n", pb->PLAYER2, pb->ROW2, pb->COL2);
		fclose(fp);

		//�ж���Ӯ
		if (judge(mouse.row, mouse.col)){
			MessageBoxA(NULL, "����Ӯ��", "������", MB_OK | MB_SYSTEMMODAL);
			back();
		}

		//AI����
		chessAI();
	}

	//�л�ҳ��
	else if (msg->message == WM_LBUTTONDOWN && hm == begin ){
		if (msg->x > 150 && msg->x < 450 && msg->y>120 && msg->y < 240){
			hm = pvp;
		}
		else if (msg->x > 150 && msg->x < 450 && msg->y>360 && msg->y < 480){
			hm = pve;
		}
	}
}

//AI����
void chessAI(){
	mouse.player = white;
	int mannum = 0;//�˵�����������
	int pcnum = 0;//���Ե�����������
	int empty = 0;//���˿�����
	int score[15][15] = { 0 };//ÿ��λ�õ�����

	//�������̣�����ÿ����λ�ķ���
	for (int r = 0; r < 15; r++){
		for (int c = 0; c < 15; c++){
			if (map[r][c] != none)
				continue;
			//�����ĸ�����ˮƽ����ֱ�������Խ��ߣ�
			for (int y = -1; y <= 0; y++){
				for (int x = -1; x <= 1; x++){
					if (y == 0 && x != 1)
						continue;
					//����
					mannum = 0;
					pcnum = 0;
					empty = 0;
					//��Χ�˵�������(�ĸ�����)
					for (int i = 1; i < 5; i++){
						int curRow = r+i*x;
						int curCol = c+i*y;
						if (curRow >= 0 && curRow < 15 && curCol >= 0 && curCol < 15){
							if (map[curRow][curCol] == black){
								mannum = mannum + 1;
							}
							else if (map[curRow][curCol] == none){
								empty = empty + 1;
								break;
							}
							else
								break;
					    }
					}
					//�����ĸ�����
					for (int i = 1; i < 5; i++){
						int curRow = r - i * x;
						int curCol = c - i * y;
						if (curRow >= 0 && curRow < 15 && curCol >= 0 && curCol < 15){
							if (map[curRow][curCol] == black){
								mannum = mannum + 1;
							}
							else if (map[curRow][curCol] == none){
								empty = empty + 1;
								break;
							}
							else
								break;
						}
					}
					switch (mannum){
					case 1://���
						score[r][c] += 10;
						break;
					case 2:
						if (empty == 1){//����
							score[r][c] += 30;
							break;
						}
						else if (empty == 2){//����
							score[r][c] += 40;
							break;
						}
					case 3:
						if (empty == 1){//����
							score[r][c] += 60;
							break;
						}
						else if (empty == 2){//����
							score[r][c] += 2000;
							break;
						}
					case 4:
						score[r][c] += 10000;
						break;
					}
					empty = 0;
					//��Χ���Ե�������(�ĸ�����)
					for (int i = 1; i < 5; i++){
						int curRow = r + i * x;
						int curCol = c + i * y;
						if (curRow >= 0 && curRow < 15 && curCol >= 0 && curCol < 15){
							if (map[curRow][curCol] == white){
								pcnum = pcnum + 1;
							}
							else if (map[curRow][curCol] == none){
								empty = empty + 1;
								break;
							}
							else
								break;
						}
					}
					//�����ĸ�����
					for (int i = 1; i < 5; i++){
						int curRow = r - i * x;
						int curCol = c - i * y;
						if (curRow >= 0 && curRow < 15 && curCol >= 0 && curCol < 15){
							if (map[curRow][curCol] == white){
								pcnum = pcnum + 1;
							}
							else if (map[curRow][curCol] == none){
								empty = empty + 1;
								break;
							}
							else
								break;
						}
					}
					switch (pcnum){
					case 0:
						score[r][c] += 5;
						break;
					case 1://���
						score[r][c] += 10;
						break;
					case 2:
						if (empty == 1){//����
							score[r][c] += 25;
							break;
						}
						else if (empty == 2){//����
							score[r][c] += 50;
							break;
						}
					case 3:
						if (empty == 1){//����
							score[r][c] += 55;
							break;
						}
						else if (empty == 2){//����
							score[r][c] +=100;
							break;
						}
					case 4:
						score[r][c] += 30000;
						break;
					}
				}
			}
		}
	}
	int max = 0,k=0;
	int Mrow[100] = { 0 };
	int Mcol[100] = { 0 };
	int row2, col2;
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			if (map[i][j] == none){
				if (score[i][j] > max){
					memset(Mrow, 0, sizeof(Mrow));
					memset(Mcol, 0, sizeof(Mcol));
					k = 0;
					max = score[i][j];
					Mrow[k] = i;
					Mcol[k] = j;
				}
				else if (score[i][j] == max){
					k = k + 1;
					Mrow[k] = i;
					Mcol[k] = j;
				}
			}
		}
	}
	if (k > 0){//�������ж������
		int z = rand() % k;
		map[Mrow[z]][Mcol[z]] = white;
		row2 = Mrow[z];
		col2 = Mcol[z];
	}
	else{
		map[Mrow[k]][Mcol[k]] = white;
		row2 = Mrow[k];
		col2 = Mcol[k];
	}

	//�����ļ�
	FILE* fp;
	fp = fopen("D:\\��ѧ\\��������Ϸ\\������\\pve.txt", "at+");
	if (fp == NULL){
		printf("Fail to open!\n");
	}
	struct chessmsg2 dh[100] = { 0 };
	dh->PLAYER2 = white;
	dh->ROW2 =row2;
	dh->COL2 = col2;
	pb = dh;
	fprintf(fp, "%d %d %d\n", pb->PLAYER2, pb->ROW2, pb->COL2);
	fclose(fp);
	fp = NULL;
	//�ж���Ӯ
	if (judge(row2,col2)){
		MessageBoxA(NULL, "����Ӯ��", "������", MB_OK | MB_SYSTEMMODAL);
		back();
	}
}

//�Ծֻط�
void back(){
	//���³�ʼ�����ں�����
	initgraph(600, 600);
	loadimage(&img, L"01.jpg", 0, 0);
	putimage(0, 0, &img);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	for (int i = 50; i <= 470; i += 30){
		line(50, i, 470, i);
		line(i, 50, i, 470);
	}
	setlinestyle(PS_SOLID, 2);
	rectangle(50, 50, 470, 470);
	setfillcolor(BLACK);
	solidcircle(260, 260, 5);
	solidcircle(140, 140, 5);
	solidcircle(140, 380, 5);
	solidcircle(380, 140, 5);
	solidcircle(380, 380, 5);

    //ͳ�����Ӳ���
	int b = 0, w = 0;

	//��ȡ�ļ���Ϣ���ط�
	if (hm == pvp){
		FILE* fp = fopen("D:\\��ѧ\\��������Ϸ\\������\\pvp.txt", "at+");
		if (fp == NULL){
			printf("Fail to open!\n");
		}
		while (!feof(fp)){
			fscanf(fp, "%d %d %d", &pa->PLAYER, &pa->ROW, &pa->COL);
			mouse.player = pa->PLAYER;
			mouse.row = pa->ROW;
			mouse.col = pa->COL;
			if (mouse.player == black){
				setfillcolor(BLACK);
				solidcircle(30 * mouse.col + 50, 30 * mouse.row + 50, 10);
				b = b + 1;
			}
			else if (mouse.player == white){
				setfillcolor(WHITE);
				solidcircle(30 * mouse.col + 50, 30 * mouse.row + 50, 10);
				w = w + 1;
			}
			Sleep(500);//ÿ�����0.5��
		}
		fclose(fp);
		t.stop = clock();
		t.duration = ((double)(t.stop - t.start)) / ((clock_t)1000);
		cleardevice();

		if (mouse.player == black){
			printf("����ʤ\n");
		}
		else if (mouse.player == white){
			printf("����ʤ\n");
		}
		printf("��������%d��\n",b);
		printf("��������%d��\n",w);
		printf("һ������%d��\n", b+w);
		printf("����ʱ��Ϊ��%lf��\n", t.duration);
		b = 0;
		w = 0;
		exit(-1);
	}

	else if (hm == pve){
		FILE* fp = fopen("D:\\��ѧ\\��������Ϸ\\������\\pve.txt", "at+");
		if (fp == NULL){
			printf("Fail to open!\n");
		}
		while (!feof(fp)){
			fscanf(fp, "%d %d %d", &pb->PLAYER2, &pb->ROW2, &pb->COL2);
			mouse.player = pb->PLAYER2;
			mouse.row = pb->ROW2;
			mouse.col = pb->COL2;
			if (mouse.player == black){
				setfillcolor(BLACK);
				solidcircle(30 * mouse.col + 50, 30 * mouse.row + 50, 10);
				b = b + 1;
			}
			else if (mouse.player == white){
				setfillcolor(WHITE);
				solidcircle(30 * mouse.col + 50, 30 * mouse.row + 50, 10);
				w = w + 1;
			}
			Sleep(500);
		}
		fclose(fp);
		fp = NULL;
		t.stop = clock();
		t.duration = ((double)(t.stop - t.start)) / ((clock_t)1000);
		printf("��������%d��\n", b);
		printf("��������%d��\n", w);
		printf("һ������%d��\n", b + w);
		printf("����ʱ��Ϊ��%lf\n", t.duration);
		b = 0;
		w = 0;
		exit(-1);
	}
}

//ʤ���ж�
bool judge(int x, int y){
	int n = 0;//��������

	//�жϺ���
	for (int i = x - 4; i <= x; i++){
		for (int k = 0; k <= 4; k++){
			if (map[i+k][y] == mouse.player && (i+k)>=0 && (i+k)<15){
				n = n + 1;
			}
		}
		if (n == 5){
			return true;
		}
		n = 0;
	}

	//�ж�����
	for (int i = y - 4; i <= y; i++){
		for (int k = 0; k <= 4; k++){
			if (map[x][i + k] == mouse.player && (i+k)>=0 && (i+k)<15){
				n = n + 1;
			}
		}
		if (n == 5){
			return true;
		}
		n = 0;
	}

	//�ж�б��
	for (int i = x - 4; i <= x; i++){
		int s = x + y;
		for (int k = 0; k <= 4; k++){
			if (map[i + k][s - i - k] == mouse.player && (i + k) >= 0 && (i + k) < 15 && (s - i - k) >= 0 && (s - i - k) < 15){
				n = n + 1;
			}
		}
		if (n == 5){
			return true;
		}
		n = 0;
	}
	for (int i = x - 4; i <= x; i++){
		for (int k = 0; k <= 4; k++){
			if (map[i + k][y+i-x+k] == mouse.player && (i + k) >= 0 && (i + k) < 15 && (y + i - x + k) >= 0 && (y + i - x + k) < 15){
				n = n + 1;
			}
		} 
		if (n == 5){
			return true;
		}
		n = 0;
	}
	return false;
}

int main(){
	//��ʼ�����ںͱ���
	initgraph(600, 600);
	loadimage(&img, L"01.jpg", 0, 0);
	putimage(0, 0, &img);
	//���ƿ�ʼ���水ť
	setlinestyle(PS_SOLID, 2);
	rectangle(150,120,450,240);
    settextstyle(120, 40, _T("����"));
	outtextxy(150, 120, _T("���˶�ս"));
	rectangle(150, 360, 450, 480);
	settextstyle(120, 40, _T("����"));
	outtextxy(150, 360, _T("�˻���ս"));

	//��¼��Ϸ��ʼʱ��
	t.start = clock();

	//��ѭ��
	while (true){
		BeginBatchDraw();//��ʼ������ͼ
		draw();
		EndBatchDraw();

		//���������Ϣ
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE)){
			switch (msg.message){
			case WM_MOUSEMOVE:
				mousemove(&msg);
				break;
			case WM_LBUTTONDOWN:
				mousepress(&msg);
				break;
			default:
				break;
			}
		}
	}
	getchar();
	return 0;
}