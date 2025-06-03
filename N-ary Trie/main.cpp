#define _CRT_SECURE_NO_WARNINGS 1
#include"Ntree.h"
#include"oper.h"
#include"picture.h"

int main() {
	// 读取文本文档并索引化
	string filename = "text.txt";
	indexTextFile(filename, Ti);

	//图形化界面
	picture();
	
	//关闭窗口
	getchar();
	closegraph();
}