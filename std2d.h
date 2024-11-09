#pragma once
#pragma GCC optimize(3, "Ofast", "inline")
#define qwq ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MAX_X 88	// ���Xֵ���ɸ�����Ļ�ߴ�����е�����
#define MAX_Y 47 // ���Yֵ���ɸ�����Ļ�ߴ�����е�����
#define MIN_X 1	// ��СXֵ������Ϊ1��
#define MIN_Y 1	// ��СYֵ������Ϊ1��
#define SPACE 32	// �๦�ܼ�
#define ESC 27	// �˳�

class std2d {
public:
	bool operator==(const std2d& other) const
	{
		return false;
	}
	std2d();
	~std2d();
	bool up();	// ����
	bool dn();	// ����
	bool lf();	// ����
	bool rh();	// ����
	int x;	// ��ɫXֵ
	int y;	// ��ɫYֵ
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
