#include<iostream>
#include<time.h>
#include<conio.h>
#include<windows.h>
//-1���ױ�־
//-2��ʱ�ƶ���־
//-3����������ױ�
//-4���ױ�ʾ����
//-5���������
//-6-7-8
using namespace std;
class SL
{
public:
	SL()
	{
		int i, j;
		for (i = 0; i < 16; i++)
		{
			for (j = 0; j < 16; j++)
			{
				zi[i][j] = 0;
				gb[i][j] = 0;
			}
		}
	}
    friend void gotoXY(int x, int y);
	void jp();                    //���ܼ�����Ϣ
    void map();
	void start();
private:
	int g = 0;
	char c;                       //�ж��Ƿ��������Ϸ
	int d;                        //��������
	int zz=0;                     //��������
	int k = 0;                    //��������
	int gb[16][16];           //��ʾ������
	int NUM;         //��־��ʣ������
	int qi = 0;       //1Ϊ����ף�0Ϊδ�����
	int zi[16][16];   //����
};
void gotoXY(int x, int y)
{
	COORD coord;           //����һ������ṹ���� 
	HANDLE hscr;           //����һ����� 
	coord.X = x;             //�����긳ֵ 
	coord.Y = y;
	hscr = GetStdHandle(STD_OUTPUT_HANDLE);  //��ñ�׼��������������ʾ���� 
	SetConsoleCursorPosition(hscr, coord);  //���ù��̨���굽ָ������ 
}
void SL::map()
{
	int hang, lie;
	for (hang = 0; hang < 16; hang++)
	{
		for (lie = 0; lie < 16; lie++)
		{
			if (zi[hang][lie] == -3 || zi[hang][lie] == -5)
				cout << "��";
			else if (zi[hang][lie] == -1)
			{
				cout << "��";
				g++;
			}
			else if (zi[hang][lie] == -2)
				cout << "��";
			else if (zi[hang][lie] == -4)
				cout <<" "<< gb[hang][lie];
			else 
				cout << "��";
		}
		cout << endl;
	}
	if (NUM >= 10)
	{
		gotoXY(60, 5);
		cout << "ʣ�������������ο�����" << NUM;

	}
	else
	{
		gotoXY(61, 5);
		cout << "ʣ�������������ο�����" << NUM;

	}
}
void SL::start()
{
	int x = 0, y = 0;
	int i, j;                   //��������ѭ������,�ж�ѭ��
	int hang, lie;               //�������
	int s;                        //��ʱ������
	int keyCode;
	gotoXY(25, 2);
m:	cout << "��ӭ����ɨ����Ϸ!" << endl;
	gotoXY(3, 8);
	cout << "��Ϸ˵����p��Ϊ���ף�o��λȡ�����ף��س���Ϊ���ף�wsad�������������ң���Ϊ�ƶ���־����Ϊ�׵ı�־�����������ʼ��Ϸ";
	_getch();
	system("cls");
	gotoXY(25, 5);
I:cout << "������ͼ16*16����40���ף�������������Ҫ���õ�������1--255��:";

	cin >> d;
	NUM = d;
	//zz = d;
	if (d<1 || d>255)
	{
		goto I;
	}
	    srand((unsigned)time(NULL));
		for (i = 0; i < d; i++)
		{
			hang = rand() % 16;
			lie = rand() % 16;
			zi[hang][lie] = -1;
			gb[hang][lie] = -1;
		}
		for (x = 0; x < 16; x++)
		{
			for (y = 0; y < 16; y++)
			{
				if (zi[x][y] == -1)
					continue;
				else
				{
					for (i = x; i >= x - 1 && i >= 0; i--)
					{
						for (j = y; j >= y - 1 && j >= 0; j--)
						{
							if (zi[i][j] == -1)
								k++;
							//����
						}
					}
					for (i = x; i >= x - 1 && i >= 0; i--)
					{
						for (j = y + 1; j <= y + 1 && j < 16; j++)
						{
							if (zi[i][j] == -1)
								k++;
							//����
						}
					}
					for (i = x + 1; i <= x + 1 && i <= 16; i++)
					{
						for (j = y; j >= y - 1 && j >= 0; j--)
						{
							if (zi[i][j] == -1)
								k++;
							//����
						}
					}
					for (i = x + 1; i <= x + 1 && i < 16; i++)
					{
						for (j = y + 1; j <= y + 1 && j < 16; j++)
						{
							if (zi[i][j] == -1)
								k++;
							//����
						}
					}
					zi[x][y] = k;
					gb[x][y] = k;
					k = 0;
				}
			}
		}
		s = zi[0][0];
		zi[0][0] = -2;
		system("cls");
		map();
		zi[0][0] = s;
		x = 0;
		y = 0;
		while (1)
		{
			keyCode = _getch();
			if (keyCode == 119)
			{
				x = x - 1;
				if (x < 0)
					x = 0;
				gotoXY(y * 2, x);
				s = zi[x][y];
				zi[x][y] = -2;
				gotoXY(0, 0);
				map();
				zi[x][y] = s;
				//printf("w��");
			}
			else if (keyCode == 115)
			{
				x++;
				if (x > 15)
					x = 15;
				gotoXY(y * 2, x);
				s = zi[x][y];
				zi[x][y] = -2;
				gotoXY(0, 0);
				map();
				zi[x][y] = s;
				//printf("s��");
			}
			else if (keyCode == 97)
			{
				y = y - 1;
				if (y < 0)
					y = 0;
				gotoXY(y * 2, x);
				s = zi[x][y];
				zi[x][y] = -2;
				gotoXY(0, 0);
				map();
				zi[x][y] = s;
				//printf("a��");
			}
			else if (keyCode == 100)
			{
				y++;
				if (y > 15)
					y = 15;
				gotoXY(x, y * 2);
				s = zi[x][y];
				zi[x][y] = -2;
				gotoXY(0, 0);
				map();
				zi[x][y] = s;
				//printf("d��");
			}
			else if (keyCode == 13)
			{
				gotoXY(y * 2, x);
				if (zi[x][y] != -5)
				{
					if (zi[x][y] == -1 || zi[x][y] == -3)
					{
						cout << "���ң���ȵ����ˣ��ǣ��ͣţϣ֣ţң��Ƿ�Ҫ����һ�֣�!��y/n��";
						cin >> c;
						if (c == 'y' || c == 'Y')
						{
							goto m;
						}
						else
							exit(1);
					}
					if (zi[x][y] == 0)
					{
						zi[x][y] = -4;
						for (i = x - 1; i <= x + 1 && i >= 0 && i < 16; i++)
						{
							for (j = y - 1; j <= y + 1 && j >= 0 && j < 16; j++)
							{
								zi[i][j] = -4;
							}
						}
					}
					if (zi[x][y] != 0)
						zi[x][y] = -4;
					gotoXY(0, 0);
					map();
				}
				else
					cout << "��";
				//printf("�س���");
			}
			else if (keyCode == 112)
			{
				gotoXY(y * 2, x);
				if (zi[x][y] != -4)
				{
					if (zi[x][y] != -5 && zi[x][y] != -3)
					{
						if (NUM > 0)
						{
							if (zi[x][y] == -1)
								zi[x][y] = -3;
							else
							{
								zi[x][y] = -5;
							}
						}
						if (NUM <= 0)
							NUM = 0;
						if (NUM > 0)
							NUM--;
						gotoXY(0, 0);
						map();
						for (i = 0; i < 16; i++)
						{
							for (j = 0; j < 16; j++)
							{
								if (zi[i][j] == -1)
									zz++;
							}
						}
						if (zz == 0)
						{
							gotoXY(60, 7);
							cout << "������ȫ���ҳ�����Ӯ�ˣ��Ƿ�Ҫ����һ�֣�!��y/n��";
							cin >> c;
							if (c == 'y' || c == 'Y')
							{
								goto m;
							}
							else
								exit(1);
						}
						zz = 0;
					}
				}
				else
					cout << " " << gb[x][y];
				//p��  ����
			}
			else if (keyCode == 111)
			{
				gotoXY(y * 2,x);
				if (zi[x][y] == -3 || zi[x][y] == -5)
				{
					zi[x][y] = gb[x][y];
					if (NUM <= d)
						NUM++;
					gotoXY(0, 0);
					map();
				}
				//o��
			}
		}
	}
int main()
{
	SL sl;
	sl.start();
	return 0;
}


