/*
https://logn.me/problem/1006
--------------------------------------------------------------------------------------------
调查黑暗气息
Case Time Limit: 200 MS (Others) / 400 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 34      Total Submission: 193

查看我的提交显示标签
Problem Description
在数码世界中有一个叫做“Radiation Zone”的区域，里面荒无人烟，仿佛遗迹一般。在这个区域中有N个城市（假设编号为从0到N-1），每个城市中都有一定数量的辐能。有M条已知长度的道路连接它们，每条道路都可以双向来往。

近期这个区域似有黑暗气息蛰伏，国王Shoutmon派出调查队前来调查这个区域中的城市。调查队的飞船降落在S号城市。由于飞船降落时气流不稳定，因此产生了辐能波，导致以S号城市为中心的L层以内（假设S号城市为最内层，记为第0层）的城市的辐能都会上升（只上升一次），上升的数值为 “城市的当前辐能乘以百分比p”的向上取整。其中百分比p在S号城市时为100%，且每向外扩散一层，百分比降低100%/L（例如，如果L为5，那么第0层（即S号城市）为100%，第1层为80%，第2层为60%，第3层为40%，第4层为20%，其中百分比均为浮点数）。所谓第X层是指，连接某城市与S号城市的最少数量的道路数，例如下图是一个例子，图中的数字为其层号。


之后调查队需要前往T号城市调查。为了顺便清除城市中的辐能，他们准备了一个容量为K的辐能吸收器。辐能吸收器可以自动吸收城市中的辐能，且满容量时会自动将容器内的所有辐能都燃烧完毕，以继续吸收辐能。假设调查队总是把城市（含S号和T号城市）中的辐能吸收完毕。

为了节省体力，调查队希望选择一条长度最短的路径前往T号城市；如果这样的路径有多条，那么从中选择到达T号城市时辐能吸收器内当前辐能最大的路径；如果这样的路径仍然有多条，那么从中选择路径后半段的城市的辐能之和最小的路径（所谓后半段是指，如果路径上有m个城市，那么后m/2个城市（含T号城市）是后半段的城市。例如，如果路径上有7个城市，那么路径的后3个城市（除法为向下取整）为后半段的城市）。数据保证这样的路径一定唯一。

Input
每个输入文件中一组数据。

第一行六个整数N、M、L、K、S、T（2<=N<=500, M<=N*(N-1)/2, 1<=L<=500, 2<=K<=100, S != T），分别代表城市个数、道路条数、辐能上升的层数、辐能吸收器的容量、起点城市编号、终点城市编号。

接下来一行有N个正整数，分别给出N个城市的初始辐能（均为不超过100的正整数）。

接下来M行，每行三个数字u、v、w，代表一条道路，其中u和v为道路的两个端点城市编号，w为道路的长度（w为不超过1000的正整数）。数据保证u不等于v，且相同的无序对(u,v)只出现一次。

Output
如果从S号城市不能到达T号城市，那么只输出-1。

如果从S号城市能到达T号城市，那么输出两行：

第一行输出四个整数， 即S号城市到T号城市的最短距离的路径条数（数据保证不超过100000条）、S号城市到T号城市的最短距离、通过最终选择的路径到达T号城市时辐能吸收器内的当前辐能、最终选择的路径的后半段城市的辐能之和。

第二行输出最终选择的路径，路径上的城市之间用->隔开。

Sample Input
7 8 1 7 0 6
20 10 10 6 8 13 5
0 1 1
0 2 1
1 3 1
2 4 1
2 5 1
3 6 1
4 6 1
5 6 1
Sample Output
3 3 5 11
0->1->3->6

Author
Shoutmon
Source
15浙大考研机试模拟赛
--------------------------------------------------------------------------------------------
难度：4；时长：70多分钟；ac：∞次。

注意事项:
1. 不能用dijkstra判断层次.
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

const int MAXN = 510;
const int INF = 1000000007;

int n;//number of cities.[0,n).
int m;//number of roads.
int l;//level.
int k;//capacity.
int s;//source.
int t;//destination.

int energy[MAXN];
int level[MAXN];
int g[MAXN][MAXN] = { 0 };

void getLevel(int now) {
	bool inq[MAXN] = { false };
	queue<int> q;
	q.push(now);
	inq[now] = true;
	//我觉得,level初不初始化无所谓,只要连通,它得层数就等于上一层加1,所以不初始化可没关系.
	level[now] = 0;

	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int v = 0; v < n; v++) {
			if (inq[v] == false && g[now][v]) {
				q.push(v);
				inq[v] = true;
				level[v] = level[now] + 1;
			}
		}
	}
}


vector<int> pre[MAXN];
int dijkstra(int s, int d) {
	bool vis[MAXN] = { false };
	int dist[MAXN];
	fill(dist, dist + MAXN, INF);
	dist[s] = 0;

	for (int i = 0; i < n; i++) {
		int minIndex = -1, minDist = INF;
		for (int v = 0; v < n; v++) {
			if (minDist > dist[v]&&vis[v]==false) {
				minDist = dist[v];
				minIndex = v;
			}
		}
		if (minIndex == -1||minIndex==d) {//d如果已经确定最小距离,则从s到d的路径上的点的最短距离肯定已经确定了.
			break;
		}
		vis[minIndex] = true;
		for (int v = 0; v < n; v++) {
			if (g[minIndex][v]&&vis[v]==false) {
				if (dist[v] > minDist + g[minIndex][v]) {
					dist[v] = minDist + g[minIndex][v];
					pre[v].clear();
					pre[v].push_back(minIndex);
				}
				else if (dist[v] == minDist + g[minIndex][v]) {
					pre[v].push_back(minIndex);
				}
				//下面语句有错,不能用dijkstra判断层数!!!!因为有可能处于第一层的城市太远已知没有被选中为最近城市,而这个很远的城市连接了很多城市,这些很多城市则处于第二层,这个层次可能就没有被正确计算.
				////不管是不是最短距离,层数都可以更新,因为层数时按道路算的,不是按长度算的.
				//level[v] = min(level[v], level[minIndex] + 1);
			}
		}
	}
	return dist[d];
}

void updateEnergy() {
	for (int i = 0; i < n; i++) {
		if (level[i] < l) {
			energy[i] = (int)ceil((1.0 / l * (l - level[i]) + 1)*energy[i]);
		}
	}
}

int maxRE = -1;//路径上辐射能最大值.
int pathCnt = 0;//统计最短路径条数.
vector<vector<int> > ans;
vector<int> tmp;
/**
 * now: present index;
 * re: radiant energy;
 */
void dfs(int now, int re) {
	tmp.push_back(now);
	re += energy[now];
	re %= k;//注意如果容器满了要全部燃烧掉!
	if (now == s) {
		pathCnt++;
		if (maxRE < re) {
			maxRE = re;
			ans.clear();
			ans.push_back(tmp);
		}
		else if (maxRE == re) {
			ans.push_back(tmp);
		}
		tmp.pop_back();
		return;
	}
	for (int i = pre[now].size() - 1; i >= 0; i--) {
		dfs(pre[now][i], re);
	}
	tmp.pop_back();
}

int halfMaxRE = INF;
vector<int> filterAns(vector<vector<int> > &ans) {//在路径最短,总辐射能最大的路径上找出,后半段辐射能最少的.
	int least = INF;
	vector<int> leastAns;
	int tmpRE = 0;
	for (int i = ans.size() - 1; i >= 0; i--) {
		tmpRE = 0;
		tmp = ans[i];//路径是从d到s的,倒着的.
		for (int i = tmp.size()/2-1; i >=0; i--) {
			tmpRE += energy[tmp[i]];
		}
		if (tmpRE < least) {
			least = tmpRE;
			leastAns = tmp;
		}
	}
	printf(" %d\n", least);
	return leastAns;
}

int main() {
	scanf("%d%d%d%d%d%d", &n, &m, &l, &k, &s, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d", &energy[i]);
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u][v] = g[v][u] = w;
	}
	int shortestLen=dijkstra(s, t);
	if (shortestLen == INF) {
		printf("-1\n");
	}
	else {
		getLevel(s);
		updateEnergy();
		dfs(t,0);
		printf("%d %d %d", pathCnt, shortestLen, maxRE);
		tmp=filterAns(ans);
		for (int i = tmp.size() - 1; i >= 0; i--) {
			if (i) {
				printf("%d->", tmp[i]);
			}
			else {
				printf("%d", tmp[i]);
			}
		}
	}

	return 0;
}
