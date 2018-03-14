/*
https://logn.me/problem/1020
-----------------------------------------------------------------------------------------
万妖瞬击
Case Time Limit: 2000 MS (Others) / 4000 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 67      Total Submission: 345

查看我的提交显示标签
Problem Description
“万妖穴中有若干小穴，每处小穴中皆有一只恶妖。小穴外设有封印，汝需消灭指定几处小穴中的恶妖方能解除该小穴封印，进而消灭穴中恶妖。”

“此处石壁所刻便是万妖穴中各穴的封印解除关系。”

“吾将瞬雷之法授于汝，汝消灭万妖穴中任一小穴皆仅需一瞬，愿汝尽快消灭各穴恶妖。”

“然消灭小穴后，其对下一处小穴的封印加强通道仍需若干时间方能闭上。”

“万妖穴中气息诡谲，恐有恶灵干扰，将使此段通道关闭时间变长。”

“汝需施法避免几处关键通道免于干扰，以使消灭整个万妖穴的时间免于延长。”

“万妖穴中或有部分小穴未设封印，汝可以此作为突破口。”

“吾将根据石壁所示，将各穴消灭顺序给予汝，汝自珍重。”

Input
每个输入文件中一组数据。
第一行两个正整数N、M（1<=N<=1000，0<=M<=N*(N-1)），表示万妖穴中小穴的个数及封印解除关系的条数。
接下来M行，每行三个整数a、b、c（0 <= a < N, 0 <= b < N, 0 < c <= 20），表示小穴b封印的解除依赖于消灭小穴a中的恶妖，且消灭小穴a中的恶妖后需要时长c才能关闭其对小穴b的封印加强通道（注意，必须将小穴b依赖的所有小穴中的恶妖消灭、并等待针对小穴b的封印加强通道都关闭后才能消灭小穴b）。假设N处小穴的编号分别是0~N-1。数据保证a不等于b，且每组封印解除关系a b最多出现一次。

Output
如果能够消灭所有小穴，那么在第一行输出YES与消灭所有恶妖的总时长，中间用一个空格隔开。然后从第二行开始输出关键路径，格式为用->连接的小穴编号。所谓关键路径是指，此路径上的所有通道的关闭时间均不可以被延长，否则会使消灭所有恶妖的时间变长；且关键路径上所有通道的关闭时长之和就是消灭所有恶妖的总时长。如果有多条关键路径，那么每行输出一条。注意，假设有两条关键路径a[1]->a[2]->...->a[k]->a[k+1]->...与b[1]->b[2]->...->b[k]->[k+1]->...，且a[1]==b[1]、a[2]==b[2]、...、a[k]==b[k]、a[k+1]<b[k+1]，那么把关键路径a优先输出。数据保证关键路径条数不超过10000条。

如果不能消灭所有小穴，那么只输出一行，即NO与无法解除封印的小穴个数，中间用一个空格隔开。行末均不允许输出多余的空格。

Sample Input 1
5 6
0 1 3
0 3 4
0 2 1
1 3 1
2 3 2
4 0 2
Sample Output 1
YES 6
4->0->1->3
4->0->3
Sample Input 2
3 3
0 1 1
1 0 1
2 0 1
Sample Output 2
NO 2
Author
Shoutmon
Source
18浙大考研机试模拟赛
-----------------------------------------------------------------------------------------
难度：5；时长：1或2个小时,或者更长,做了两次；ac：3次。

类型:关键路径(可以选择用拓扑排序),dp.

注意事项：
1. 取stl的set的元素用迭代器,用[]不合法.
2. 关键路径的内容还要反复看,我这里用的动态规划做的,可以试着用拓扑排序做,会复杂一点,但可以锻炼思维.
动态规划和拓扑排序两种方法都要会!
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<vector> 
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

const int MAXN=1005;
const int INF = 1000000000;

int n, m;
int g[MAXN][MAXN] = { 0 };

int indegree[MAXN]={ 0 };
int noCnt = 0;//计数不是拓扑时,最后剩几个顶点.
//vector<int> topoSeq;
bool topologicalSort() {
	bool vis[MAXN] = { 0 };
	noCnt = n;//初始化所有顶点都不是拓扑序.
	rep(i, n) {//找n次,一次应该找到一个顶点,如果最后发现还有顶点剩余,说明不是拓扑序.
		int j = 0;
		while (j < n) {//遍历[0,n-1]这些洞穴.
			if (vis[j] == false && indegree[j] == 0) {
				noCnt--;
				vis[j] = true;
				break;
			}
			j++;
		}
		if (j == n) {//n次循环应该每次找到一个入度为0的顶点,但是某一次发现n个顶点内都没有入度为0的,说明不满足拓扑排序.
			return false;
		}
		rep(k, n) {//遍历找到的当前入度为0的结点的后继.
			if (g[j][k] && vis[k] == false) {
				indegree[k]--;
			}
		}
	}
	return true;
}

set<int> maxStart;//和最长距离起始的结点序号.如果有多个不同的最长距离的起始点,而每个起始点又有多条最长距离,则用vector会把起始点重复添加.
//如果不算一共有多少条最短路径,这个放在外面来存储最长距离的起始点,由于是从0遍历到n-1,不会重复添加顶点,可以用vector.
int maxLen = 0;//最长距离.
//int yesCnt = 0;//这个的计算要放在DP数组里,因为同一个起点可能对应多条最短路径,在DP外面添加,只能增加起点一次计数.不需要算关键路径条数,这个量不需要!

vector<int> nextv[MAXN];
//通过dp来求DAG最长路.
int dp[MAXN] = { 0 };//因为从出度为0的顶点出发最长路径的长度为0,所以用0初始化dp数组.
int DP(int index) {
	//if (dp[index] > 0)return dp[index];
	if (dp[index] == 0) {
		rep(i, n) {//遍历index所有出边.找经过下一个顶点总距离距离最长的,更新或加入next.
			if (g[index][i]) {
				dp[i] = DP(i);
				if (dp[i] + g[index][i] > dp[index]) {
					nextv[index].clear();
					nextv[index].push_back(i);
					dp[index] = dp[i] + g[index][i];
				}
				else if (dp[i] + g[index][i] == dp[index]) {
					nextv[index].push_back(i);
				}
			}
		}
	}
	return dp[index];
}

vector<int> seq;
void output(int start) {
	seq.push_back(start);
	if (nextv[start].size()==0) {
		rep(i, seq.size()) {
			if (i) {
				printf("->");
			}
			printf("%d", seq[i]);
		}
		if (seq.size()) {
			printf("\n");
		}
		seq.pop_back();
		return;
	}
	rep(i, nextv[start].size()) {
		output(nextv[start][i]);
	}
	seq.pop_back();
}

void outputAns(set<int> &startsIndex) {
	for (set<int>::iterator it = startsIndex.begin(); it != startsIndex.end(); it++) {
		output(*it);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = c;
		indegree[b]++;
	}
	bool ansBool = topologicalSort();
	if (ansBool) {
		rep(i, n) {
			DP(i);
			sort(nextv[i].begin(), nextv[i].end());
			if (dp[i] > maxLen) {
				maxLen = dp[i];
				maxStart.clear();
				maxStart.insert(i);
				//yesCnt = 1;//并没有让求最短路径有多少条!
			}
			else if (dp[i] == maxLen) {
				maxStart.insert(i);
				/*yesCnt++;*/
			}
		}
		printf("YES %d\n",maxLen);
		outputAns(maxStart);
	}
	else {
		printf("NO %d", noCnt);
	}
	return 0;
}
