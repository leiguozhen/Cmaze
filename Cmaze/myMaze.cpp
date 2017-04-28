#include"maze.h";

stack<pair<pair<int,int>, int>> st;

using namespace std;

//int dir[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

void print(int, int);

bool nextpass(pair<pair<int, int>,int>&pr)
{
	pair<pair<int, int>, int> temp;
	//pr.second = -1;
	for (int i = 0; i < 4; i++)
	{
		pr.second++;
		switch (pr.second)
		{
		case 0:
			temp.first.first = pr.first.first - 1;
			temp.first.second = pr.first.second + 0;
			break;
		case 1:
			temp.first.first = pr.first.first + 0;
			temp.first.second = pr.first.second + 1;
			break;
		case 2:
			temp.first.first = pr.first.first + 1;
			temp.first.second = pr.first.second + 0;
			break;
		case 3:
			temp.first.first = pr.first.first + 0;
			temp.first.second = pr.first.second - 1;
			break;
		default:break;
		}
		if (map[temp.first.first][temp.first.second] == road)
		{
			pr.first.first = temp.first.first;
			pr.first.second = temp.first.second;
			pr.second = -1;
			return true;
		}
		if (map[temp.first.first][temp.first.second] == Exit)
		{
			MessageBoxA(NULL, "祝贺你!", "你走出迷宫了!", NULL);
			exit(1);
		}
	}
    return false;
	//if (map[pr.first][pr.second] == road&&sign[pr.first][pr.second] != flag)//&&sign[pr.first][pr.second] != flag
	//{
	//	//if (sign[pr.first][pr.second] != flag)
	//	//{
	//		st.push(pr);
	//		Dir.push_back(dir);
	//		//return true;
	//	//}
	//	sign[pr.first][pr.second] = flag;
	//	return true;
	//	//return true;
	//}
	//return false;
}


void autofind()
{
	gotoxy(2 * ncol - 2, nrow - 1);
	//cout << "웃";
	pair<int, int> p(nrow, ncol);
	pair<pair<int, int>,int> pr(p,-1), pt;
	map[nrow][ncol] = flag;
	int dir[4][2] = { { -1, 0 },{ 0, 1 }, { 1, 0 }, { 0, -1 } };
	st.push(pr);
	while (!st.empty())
	{
		//pt = st.top();
		//int i = 0;
		//bool flat = false;
		//while (i<4)
		//{
		//	int idir = Dir.back();
		//	if (i == (idir + 2) % 4)
		//	{
		//		i++;
		//		continue;
		//	}
		//	pt.first.first = nrow + dir[i][0];
		//	pt.first.second = ncol + dir[i][1];
		//	if (pass(pt,i))
		//	{
		//		nrow = pt.first.first;
		//		ncol = pt.first.second;
		//		gotoxy(2 * ncol - 2, nrow - 1);
		//		std::cout << "웃";
		//		//print(nrow, ncol);
		//		flat = true;
		//		break;
		//	}
		//	i++;
		//}
		//if (!flat)
		//{
		//	/*gotoxy(2 * (ncol - Dir[]))
		//	st.pop();
		//	Dir.pop_back();
		//	pt = st.top();
		//	nrow = pt.first;
		//	ncol = pt.second;
		//	std::cout << "  ";*/
		//	
		//	//print(nrow, ncol);
		//}
		pt = st.top();
		
		if (nextpass(pt))
		{
			st.push(pt);
			map[pt.first.first][pt.first.second] = flag;
			nrow = pt.first.first;
			ncol = pt.first.second;
			gotoxy(2 * ncol - 2, nrow - 1);
			cout << "웃";
			if (map[nrow][ncol]==Exit)
			{
				MessageBoxA(NULL, "祝贺你!", "你走出迷宫了!", NULL);
				return;
			}
		}
		else
		{
			st.pop();
			map[pt.first.first][pt.first.second] = unflag;
			nrow = pt.first.first;
			ncol = pt.first.second;
			gotoxy(2 * ncol - 2, nrow - 1);
			cout << "  ";
		}
		Sleep(10);
	}


}

void create(int x, int y)
{
	int c[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };  /*四个方向*/
	int i, j, t;
	/*
	*将方向打乱
	*/
	for (i = 0; i<4; i++)
	{
		j = rand() % 4;
		t = c[i][0]; c[i][0] = c[j][0]; c[j][0] = t;
		t = c[i][1]; c[i][1] = c[j][1]; c[j][1] = t;
	}
	map[x][y] = road;
	for (i = 0; i<4; i++)
	if (map[x + 2 * c[i][0]][y + 2 * c[i][1]] == wall)
	{
		map[x + c[i][0]][y + c[i][1]] = road;
		create(x + 2 * c[i][0], y + 2 * c[i][1]);
	}
}

void key_hit(char ch)
{
	switch (ch)
	{
	case UP:if (map[nrow-1][ncol] == road)
		nrow -= 1; break;
	case DOWN:
		if (map[nrow+1][ncol] == road)
			nrow += 1; break;
	case RIGHT:if (map[nrow][ncol + 1] == road)
		ncol += 1; break;
	case LEFT:if (map[nrow][ncol - 1] == road)
		ncol -= 1; break;
	default:
		break;
	}
}

void print(int x, int y)
{
	gotoxy(2 * y - 2, x - 1);
	if (map[x][y] == wall)
		std::cout << "■";
	else if (map[x][y] == road) std::cout << "  ";
	else if (map[x][y] == Exit) std::cout << "出";
	else if (map[x][y] == entry)std::cout << "入";
}
void Play_Game()
{
	gotoxy(2*ncol-2, nrow-1);
	char ch;
	while (ch = _getch())
	{
		gotoxy(2 * ncol - 2, nrow - 1);
		std::cout << "  ";
		
		key_hit(ch);
		gotoxy(2 * ncol - 2, nrow - 1);
		std::cout << "웃";
	}

}


void main()
{
	srand((unsigned)time(NULL));
	system("mode con cols=120 lines=44 ");//调整
	system("color 2b");
	for (int i = 0; i <= height+1; i++)
	{
		for (int j = 0; j <= width+1; j++)
		{
			if (i==0||j==0|| i == height+1 || j == width+1)
				map[i][j] = road;
			 else map[i][j] = wall;
		}
	}
	create(2 * (rand() % (height / 2)+1), 2 * (rand() % (width / 2)+1));
	//create(20, 20);
	      for (int i = 0; i <= height + 1; i++)    /*边界处理*/
			{
				map[i][0] = wall;
				map[i][width + 1] = wall;
			}
		
			for (int j = 0; j <= width + 1; j++)   /*边界处理*/
			{
				map[0][j] = wall;
				map[height + 1][j] = wall;
			}
			map[0][1] = entry;
			map[height - 1][width] = Exit;
	for (int i = 1; i <= height; i++)
	for (int j = 1; j <= width; j++)
	print(i,j);
	Play_Game();
	//autofind();
	system("pause");
}