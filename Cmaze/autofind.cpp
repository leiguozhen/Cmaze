//#include"maze.h"
//#include<vector>
//#include<algorithm>
//#include<stack>
//
//stack<pair<int,int>> st;
//
//using namespace std;
//
//bool pass(pair<int, int> &pr)
//{
//	if (map[pr.first][pr.second] == road&&sign[pr.first][pr.second] != flag)
//	{
//		st.push(pr);
//		sign[pr.first][pr.second] = flag;
//		return true;
//	}
//	return false;
//}
//
//void autofind()
//{
//	pair<int, int> pr(nrow, ncol), pt;
//	int dir[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
//	st.push(pr);
//	while (!st.empty())
//	{
//		pt = st.top();
//		int i = 0;
//		bool flat = false;
//		while (i<4)
//		{
//			pt.first = nrow + dir[i][0];
//			pt.second = ncol + dir[i][1];
//			if (pass(pt))
//			{
//				nrow =pt.first;
//				ncol = pt.second;
//				//gotoxy(2 * ncol - 2, nrow - 1);
//				print(nrow, ncol);
//				flat = true;
//				break;
//			}
//			i++;
//		}
//		if (!flat)
//			st.pop();
//	}
//
//
//}