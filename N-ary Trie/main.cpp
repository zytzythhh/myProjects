#define _CRT_SECURE_NO_WARNINGS 1
#include"Ntree.h"
#include"oper.h"
#include"picture.h"

int main() {
	// ��ȡ�ı��ĵ���������
	string filename = "text.txt";
	indexTextFile(filename, Ti);

	//ͼ�λ�����
	picture();
	
	//�رմ���
	getchar();
	closegraph();
}