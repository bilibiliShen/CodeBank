/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][6] G
* @file         :G:\My Source Code\��ACM��ѵ��\[NWPU][2014][TRN][6][0716]������dp\G.cpp
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

const int MaxN = 50005;
int t, n;
int a[MaxN], f[2][MaxN];

//  ��������������Ӵ���
//  f[0][i]��ʾ����i������iΪ��β���Ӵ���������i���������ֵ
//	f[1][i]��ʾ�Ӻ���ǰ������i������iΪ��β���Ӵ���������i���������ֵ
//  ����Ӵ��͵���⣬��dp[i]��ʾ
//  ת�Ʒ��̣��ж������һ��������󣬻��������¿�һ������
//  dp[i] = max(dp[i - 1] + a[i], a[i])
//  res = max{dp[i]};
//  ����Ĵ�ans = max{f[0][i] + f[1][i + 1]}

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    memset(f, 0, sizeof(f));

    f[0][0] = a[0]; f[1][n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
        if (f[0][i - 1] > 0) f[0][i] = f[0][i - 1] + a[i];
        else f[0][i] = a[i];
    for (int i = 1; i < n; i++) updateMax(f[0][i], f[0][i - 1]);

    for (int i = n - 2; i >= 0; i--)
        if (f[1][i + 1] > 0) f[1][i] = f[1][i + 1] + a[i];
        else f[1][i] = a[i];
    for (int i = n - 2; i >= 0; i--) updateMax(f[1][i], f[1][i + 1]);

    int ans = f[0][0] + f[1][1]; // �в���ֱ�Ӹ�ֵΪ0
    for (int i = 0; i < n - 1; i++)
        updateMax(ans, f[0][i] + f[1][i + 1]);
    printf("%d\n", ans);
}

int main()
{
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
