/*
https://logn.me/problem/1011
----------------------------------------------------------------------------------------------
万妖穴
Case Time Limit: 500 MS (Others) / 1000 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 30      Total Submission: 48

查看我的提交显示标签
Problem Description
“万妖穴中有若干小穴，每处小穴中皆有一只恶妖。小穴外设有封印，汝需消灭指定几处小穴中的恶妖方能解除该小穴封印，进而消灭穴中恶妖。”

“此处石壁所刻便是万妖穴中各穴的封印解除关系。”

“万妖穴中或有部分小穴未设封印，汝可以此作为突破口。”

“吾将根据石壁所示，将各穴消灭顺序给予汝，汝自珍重。”

Input
每个输入文件中一组数据。

第一行两个正整数N、M（1<=N<=1000，0<=M<=N*(N-1)），表示万妖穴中小穴的个数及封印解除关系的条数。

接下来M行，每行两个整数a、b，表示小穴b封印的解除依赖于消灭小穴a中的恶妖。假设N处小穴的编号分别是0~N-1。数据保证a不等于b，且每组封印解除关系a b最多出现一次。

Output
如果能够消灭所有小穴，那么输出一行YES，并在第二行给出用空格隔开的N处小穴的消灭顺序（此处规定，总是消灭当前能消灭的编号最小的小穴）；如果不能消灭所有小穴，那么输出一行NO，并在第二行给出无法解除封印的小穴个数。行末均不允许输出多余的空格。

Sample Input 1
3 3
0 1
0 2
2 1
Sample Output 1
YES
0 2 1
Sample Input 2
4 5
0 1
0 2
0 3
2 1
1 2
Sample Output 2
NO
2
Author
Shoutmon
Source
16浙大考研机试模拟赛
----------------------------------------------------------------------------------------------
难度：2；时长：30分钟；ac：1次。

思路：
1. 老担心做错。vis数组存放洞穴是否被解除封印，need放小穴被解除封印还需要之前有几个洞穴被解除封印，g存放解除封印的前驱后继关系。
need在输入g的时候被初始化增加，在判断一个小穴被解除封印后更新减少，由于一个小穴被解除封印之后不会再被访问，所以不用担心need数组会被反复减少以致于出现负数的情况。
*/
#include<cstdio>
#include<iostream>

#include<vector>
#include<stack>

#include<map>

#include<string>

#include<algorithm>

#include <exception>  
using namespace std;

#define IN 0
#define P 0

#define rep(i,n) for(int i=0;i<n;i++)

const int MAXN = 1010;
const int INF = 1000000000;

typedef long long ll;

int n, m;
int need[MAXN] = { 0 };
vector<int> g[MAXN];
bool vis[MAXN] = { false };

//找数组里没被解除且可以解除封印的最小穴的序号，没有找到则返回-1.
int findMin() {
	rep(i, n) {
		if (vis[i] == false && need[i] == 0) {
			return i;
		}
	}
	return -1;
}

//更新受index制约的小穴的还有多少制约。
void updataNeed(int index) {
	int v;
	rep(i, g[index].size()) {
		v = g[index][i];
		if (vis[v] == false) {
			need[v]--;
		}
	}
}

int main() {
	cin >> n >> m;
	rep(i, m) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		need[v2]++;//v2之前需要解除的封印数。
	}
	vector<int> ans;
	rep(i, n) {//循环n次，应该每次找到一个，然后正好找完，不会出现返回负一的情况，否则就是不能完全解除封印。
		int minIndex=findMin();
		if (minIndex == -1) {
			break;
		}
		else {
			vis[minIndex] = true;
			ans.push_back(minIndex);
			updataNeed(minIndex);
		}
	}
	if (ans.size() != n) {
		printf("NO\n%d\n",n-ans.size());
	}
	else {
		printf("YES\n");
		rep(j, n) {
			if (j)printf(" ");
			printf("%d", ans[j]);
		}
	}
	return 0;
}

