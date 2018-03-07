/*
https://logn.me/problem/1004
--------------------------------------------------------------------------------------------------
收集数码晶体
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 31      Total Submission: 119

查看我的提交显示标签
Problem Description
数码世界的国王Shoutmon想要在n个小岛上举办一个游戏，来让数码宝贝们好好玩耍。背景是这样的：在这n个小岛之间事先安放了一些单向通道，每个通道连接两个不同的小岛，且只能按一个给定的方向通过。数码宝贝每次由通道到达一个小岛时都会令体内增加一个“数码晶体”。

Shoutmon制定了一项规则，即数码宝贝们可以从某个小岛出发，到达一个目的小岛，如果到达目的小岛后体内的“数码晶体”数量恰好为L，那么此时可以在小岛上的兑奖处领取奖品（领完奖品后自动退出游戏）。注意，到达目的小岛后如果“数码晶体”数量不足，那么仍然可以离开小岛，直到某次回到目的小岛时“数码晶体”的数量恰好为L。每个小岛（包括起始小岛和目的小岛）与每条通道都不限制到达和通过次数。初始状态下体内的“数码晶体”数量为0。

为了保证活动正常进行，Shoutmon想要知道，有多少条路径可以从起始小岛S到达目的小岛T并领奖（可能有多次查询）。

Input
每个输入文件中一组数据。

第一行三个整数n、m、L（2<=n<=30，0<=m<=n*(n-1)，1<=L<=100），分别代表小岛个数、单向通道条数、恰好需要的“数码晶体”数。

接下来m行，每行两个整数u和v，代表从小岛u到小岛v有一条单向通道（假设小岛编号为从0到n-1）。数据保证u不等于v，且相同的有序对(u,v)最多出现一次。

然后一个正整数k（k<=n*n），表示查询次数。

接着k行，每行两个整数S和T，表示需要查询有多少条路径可以从起始小岛S到达目的小岛T并领奖。

Output
输出k行，每行一个整数，对应查询的结果，即从起始小岛到达目的小岛并领奖的路径条数。由于路径条数可能很多，因此将结果模上1000000007。

Sample Input
3 4 4
0 1
0 2
1 2
2 0
3
1 1
0 2
2 0
Sample Output
0
2
1

Author
Shoutmon
Source
15浙大考研机试模拟赛
--------------------------------------------------------------------------------------------------
难度：5（自己没做出来）；时长：1h以上；ac：3次。

注意事项:
1. 用邻接矩阵,邻接表都超时了.是408考研真题中的一道,用01矩阵的乘法做.
*/
#include"stdafx.h"
#include<cstdio>
#include<iostream>

#include <string>
#include <cstring>

#include <algorithm>
#include<cmath> 

#include<vector>
#include<stack>
#include<queue>
#include<set>

#include<map>
#include <utility>//pair
using namespace std;

const int MAXN = 32;
const int MAXM = 1000;
const int MAXL = 110;
const int INF = 1000000007;
const int MOD = 1000000007;

int n;//islands.
int m;//directed paths.
int l;//crystals.

vector<vector<int> > g(MAXN,vector<int>(MAXN,0));//graph.32x32得数组,初始化为0.
vector<vector<int> > ans(MAXN, vector<int>(MAXN, 0));//存储结果,g^m中的i行i列的非零元素,表示从i到j长度为m的路径条数,进行l次乘法后,即为结果.

void multiple(vector<vector<int> > &g, vector<vector<int> > &ans) {
	vector<vector<int> > tmp(MAXN, vector<int>(MAXN, 0));//存放中间结果.
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			for (int i = 0; i < n; i++) {
				tmp[r][c] += ans[r][i] * g[i][c];
				tmp[r][c] %= MOD;
			}
		}
	}
	ans = tmp;
}

int main() {
	scanf("%d%d%d", &n,&m,&l);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u][v] = ans[u][v] = 1;
	}
	for (int i = 0; i < l-1; i++) {//不循环表示g^1,循环一次就是g^2了,所以循环L-1次即可.
		multiple(g, ans);
	}
	int k;//queries.
	scanf("%d", &k);
	int s;//source.
	int t;//desitination.
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &s, &t);
		printf("%d\n", ans[s][t]);
	}
	return 0;
}
