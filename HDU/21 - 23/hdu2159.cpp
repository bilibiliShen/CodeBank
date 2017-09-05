/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:cfrpg
* @name         :[NWPU][2014][TRN][7] B
* @file         :G:\My Source Code\��ACM��ѵ��\[NWPU][2014][TRN][7][0717]��������\B.cpp
* @date         :2014/07/17 10:54
* @algorithm    :Package
******************************************************************************/

#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std; 
template<class T>inline bool updateMin(T& a,  T b){ return a > b ? a  =  b,  1 : 0;  }
template<class T>inline bool updateMax(T& a,  T b){ return a < b ? a  =  b,  1 : 0;  }

//@author cfrpg
// ��ά���ñ���
// f[j][l] = max(f[j][l], f[j - b[i]][l - 1] + a[i])
// ��j�����Ͷȣ���ɱl����֮������õ��������

int n; // ���辭��
int m; // ���Ͷ�
int k; // ������
int s; // ˢ����
int a[105], b[105]; 
int f[105][105]; // f[���Ͷ�][ˢ����]

void solve()
{
	memset(a, 0, sizeof(a)); 
	memset(b, 0, sizeof(b)); 
	memset(f, 0, sizeof(f)); 
	for (int i = 1; i <= k; i++)
		scanf("%d%d", &a[i], &b[i]); 
	int min = m + 1; 
	for (int i = 1; i <= k; i++)
		for (int j = b[i]; j <= m; j++)
			for (int l = 1; l <= s; l++)
	{
		updateMax(f[j][l],  f[j - b[i]][l - 1] + a[i]);
		if (f[j][l] >= n) updateMin(min, j);
	}
	if (min == m + 1) printf("-1\n"); 
	else printf("%d\n", m - min); 
}

int main()
{
	while (~scanf("%d%d%d%d", &n, &m, &k, &s)) solve(); 
	return 0; 
}