/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRM][2] F
* @file         :G:\My Source Code\��ACM��ѵ��\[NWPU][2014][TRM][2][0715]ǰ���һ������ˮ��\F.cpp
* @date         :2014/07/15 18:53
* @algorithm    :Easy
******************************************************************************/

#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int n, tt = 0;
	while (scanf("%d", &n) && (n > 0))
	{
		int t = 1, ans = 0;
		for ( ;t < n; ) { ans++; t *= 2; }
		printf("Case %d: %d\n", ++tt, ans);
	}
	return 0;
}
