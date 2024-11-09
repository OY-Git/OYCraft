#pragma once
#pragma GCC optimize(3, "Ofast", "inline")
#define qwq ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MAX_X 88	// 最大X值，可根据屏幕尺寸可自行调整。
#define MAX_Y 47 // 最大Y值，可根据屏幕尺寸可自行调整。
#define MIN_X 1	// 最小X值，必须为1。
#define MIN_Y 1	// 最小Y值，必须为1。
#define SPACE 32	// 多功能键
#define ESC 27	// 退出

class std2d {
public:
	bool operator==(const std2d& other) const
	{
		return false;
	}
	std2d();
	~std2d();
	bool up();	// 向上
	bool dn();	// 向下
	bool lf();	// 向左
	bool rh();	// 向右
	int x;	// 角色X值
	int y;	// 角色Y值
};

inline std2d::std2d()
{
	this->x = 1;
	this->y = 1;
}

inline std2d::~std2d()
{
}

bool std2d::up() {
	if (y - 1 < MIN_Y)
		return false;
	else
		y--;
	return true;
}

bool std2d::dn() {
	if (y + 1 > MAX_Y)
		return false;
	else
		y++;
	return true;
}

bool std2d::lf() {
	if (x - 1 < MIN_X)
		return false;
	else
		x--;
	return true;
}

bool std2d::rh() {
	if (x + 1 > MAX_X)
		return false;
	else
		x++;
	return true;
}
