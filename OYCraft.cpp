// OYCraft.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// OYCraft 1.2

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "std2d.h"
using namespace std;

// 可执行文件路径: C:\Users\OY\source\repos\OYCraft\x64\Debug\OYCraft.exe

bool world[MAX_Y + 10][MAX_X + 10];
std2d player;

static void init() {
	for (int i = MIN_Y; i <= MAX_Y; i++) {
		for (int j = MIN_X; j <= MAX_X; j++) {
			world[i][j] = false;
		}
	}
	return;
}

void noedit() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	mode &= ~ENABLE_INSERT_MODE;
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, mode);
}

void ShowCursor(bool visible) {	// 隐藏光标
	CONSOLE_CURSOR_INFO cursor_info = { 20, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void print() {
	qwq;
	system("cls");
	cout << ' ';
	for (int i = MIN_X; i <= MAX_X; i++) cout << "__";
	cout << endl;
	for (int i = MIN_Y; i <= MAX_Y; i++) {
		cout << '|';
		for (int j = MIN_X; j <= MAX_X; j++) {
			if (i == player.y && j == player.x)
				cout << "你";
			else
				world[i][j] ? cout << "00" : i == MAX_Y ? cout << "__" : cout << "  ";
		}
		cout << '|' << endl;
	}
	cout << "X: " << player.x << ' ' << "Y: " << player.y << endl;
}

int main() {
	qwq;
	noedit();
	system("title OYCraft 1.2");	// 设置cmd窗口的名字
	bool err = false;
	cout << "==================== Welcome to OYCraft 1.2 ====================" << endl;
	cout << "此处汉字出现可能比较慢，请耐心等待!" << endl << "请全屏后";
	system("pause");
	ShowCursor(false);
	init();
	print();
	while (true) {
		char mod = _getch();
		bool ex = false;
		bool flag = false;	// 是否刷新屏幕
		if (mod == ESC)
			system("exit");
		if (mod == SPACE && err) {
			cout << "\b\b\b\b\b\b      \b\b\b\b\b\b";
			err = false;
			flag = true;
			ex = true;
		}
		if (mod == 'w')
			flag = player.up();
		if (mod == 's')
			flag = player.dn();
		if (mod == 'a')
			flag = player.lf();
		if (mod == 'd')
			flag = player.rh();
		if (mod == 'e') {
			flag = true;
			cout << "检测到E已按下, 正在等待下一个命令..." << endl;
			char e = _getch();
			switch (e) {
				case 'f':{
					cout << "作者is努力开发此功能ing...";
					char c = _getch();
					break;
					string s = NULL;
					cout << "move_console :: -> \n\t";
					getline(cin, s);
					size_t len = s.size();
					for (int j = 0; j < len; j++) {
						if (mod == 'w')
							player.up();
						if (mod == 's')
							player.dn();
						if (mod == 'a')
							player.lf();
						if (mod == 'd')
							player.rh();
					}
					break;
				}
			}
		}
		if (mod == ' ' && !ex)	// 只能放最后一个判断条件，以承接else if。
			world[player.y][player.x] = !world[player.y][player.x];
		else if (flag && !ex) {
			print();
			err = false;
		}
		else if (!err && !ex) {
			cout << "Error!";
			err = true;
		}
	}
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
