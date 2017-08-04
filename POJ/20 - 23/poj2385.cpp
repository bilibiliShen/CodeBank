/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] K
* @file         :G:\My Source Code\��ACM��ѵ��\[NWPU][2014][TRN][6][0716]������dp\K.cpp
* @date         :2014/07/16 11:59
* @algorithm    :DP
******************************************************************************/

#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1 : 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1 : 0; }

const int MaxN = 1005;
const int MaxT = 33;
int n, t, a[MaxN], dp[MaxN][MaxT];

//  dp[i][j]��ʾ��iʱ�����߶���j�������ƻ����
//  ���ţ�ڵ�һ��������j % 2 == 0
//  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + 2 - a[i];
//  ��ʼ�����dp[i][0] = dp[i - 1][0] + 2 - a[i];
//  ���ţ�ڵڶ���������j % 2 == 1
//  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i] - 1;
//  ������max{dp[n][i], i = 0, 1, 2, ...}

void solve()
{
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + 2 - a[i];
        for (int j = 1; j <= t; j++)
            if (j % 2)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i] - 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) - a[i] + 2;
    }
    int ans = dp[n][0];
    for (int i = 0; i <= t; i++) updateMax(ans, dp[n][i]);
    printf("%d\n", ans);
}

int main()
{
	while (~scanf("%d%d", &n, &t)) solve();
	return 0;
}
