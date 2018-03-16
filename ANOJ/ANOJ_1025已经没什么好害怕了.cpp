/*
https://logn.me/problem/1025
---------------------------------------------------------------------------------------
已经没什么好害怕了
Case Time Limit: 2000 MS (Others) / 4000 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 11      Total Submission: 177

查看我的提交显示标签
Problem Description
《魔法少女小圆》是一部由“爱”的战士——虚渊玄老师创作的、宣扬“爱”与“希望”的优秀作品，在动漫史上留下了浓墨重彩的一笔。该片十分治“愈”，希望各位同学在心情不好的时候能多看看这部作品，它一定会给你的心情带来一个非常大的改变。只要你的脑电波和它同步，这可能将是你这十年看过的最优秀、印象最深刻的作品。


“已经没什么好害怕了”（也有翻译成“已经没什么好怕的了”）——这句名言出自《魔法少女小圆》中的一位重要登场角色——巴麻美学姐。


麻美学姐是一位实力强大的战士，她使用缎带魔法，之后又自己开发出了枪炮魔法。


她的大招是Tiro Finale，有无数魔女“丧命”在其大招之下，比如：




也有下面这种倒霉的魔女被麻美学姐调戏：



是的，魔女是怪物（不要被名字所骗噢，魔女不是人类），是害人的，需要将它们尽快解决，防止它们危害生命。如果麻美学姐感觉某次斩杀魔女很顺利的话，就会自信地说：“已经没什么好害怕了”。


今天麻美学姐跟踪一些被魔女控制了心神的人类来到了魔女设下的结界前，这次要对付的魔女叫做分身魔女。分身魔女设下的结界内部共有N个空间，空间之间通过M条通道相连接。受到邪恶能量的影响，这些通道只能沿着指定的方向通过，且消耗麻美学姐体力的程度比平时更多。魔女平时化为K个分身，处于K个不同的空间中，只有将它们全部消灭，本体才会出现。麻美学姐可以随意进出魔女结界。


麻美学姐计划先消灭K个分身，然后消灭本体。研究结界之后发现，在结界中的许多空间并不能在进入结界时直接到达，而必须通过其他空间才能到达，但有P个空间可以在进入结界时直接到达，所有空间中只有这P个空间与外界连通，如果要离开结界也必须通过这P个空间。麻美学姐可以将这P个空间的任意一个作为出发点，然后沿着通道到达K个分身之一所在的空间（为了少消耗体力，麻美学姐总是选择消耗总体力最少的路径；在经过有分身的空间时也可以不消灭这个分身而前往其他空间）。用大招Tiro Finale消灭这个分身后，将沿着通道回到P个初始空间中的任意一个（同样也选择消耗总体力最少的路径），恢复体力后再去消灭下一个分身。而在最后一个分身被消灭后，魔女本体将直接出现在最后一个分身的空间，学姐将用她娴熟的战斗技巧打败她，并且自信满满地说：“已经没什么好害怕了”。魔女被消灭后，整个结界就会消失。

Input
每个输入文件一组数据。
对每组数据，第一行为四个整数N、M、P、K（0 < N <= 1000000, 0 <= M <= 1000000, 0 < P <= N, 0 < K <= N）。假设N个空间的编号为1到N。
接下来一行，包括P个正整数，表示P个初始空间的编号。
接下来一行，包括K个正整数，表示K个分身所在的空间编号。
接下来M行，每行三个正整数u、v、w（0 < u <= N, 0 < v <= N, u != v, 0 < w <= 10000000），表示一条从u号空间到达v号空间的通道，通过该通道需要消耗的体力值为w。

Output
输出一个整数，表示麻美学姐需要消耗的总体力值（就是把所有的消耗加起来）。数据保证所有分身都能被消灭。

Sample Input
4 6 2 2
1 2
3 4
1 3 1
3 1 1
2 4 3
4 2 5
1 4 4
3 4 1
Sample Output
4
Author
Shoutmon
Source
18浙大考研机试模拟赛
---------------------------------------------------------------------------------------
难度：5；时长：2h以上；ac：7,8,9次，提交了很多次，有的通过有的没通过，有的代码出现了莫名其妙的错误，和正确的代码只有轻微的差别，但并不清楚到底怎么错了。

注意事项:
1. 正向反向图的0位都要讲pSpace赋值给它们，忘记g_inverted[0] = pSpace;这一句出了错。
2. 思路要正确，到k的最短距离，可以用一个超级源点连接所有的p，再通过最短路径的算法求出。但是求k到p的最短距离，不能用超级源点连接k，然后用最短路径算法，因为此时p的距离指的是p到k群体的最近距离，而具体的某个k到p群体的最短距离并不能确定。
所以应该逆向建图，即把所有路径方向都调转，则此时k到p的距离已经成了p到k的距离，再次用最短路径，则每个k的最短距离存的都是到p这个群体的最近的距离，直接累加所有k即可。
3. 题目的意思是所有的p空间都是连通的。且最后一次打完怪，不用回到p，所以这段距离如果多算了，需要去除，也就是说去除一个某个k到p群体的最长的那个距离，相当于这个k最后消灭。
4. 最短路径算法需要用堆优化，不然会超时。堆优化可以用优先队列。

补充：
1. 优先队列的使用：
priority_queue默认为大顶堆，即堆顶元素为堆中最大元素。如果我们想要用小顶堆的话需要增加使用两个参数：
priority_queue<int, vector<int>, greater<int> > q;  // 小顶堆  
priority_queue<int, vector<int>, less<int> > q;     // 大顶堆  
*/
#include <cstdio>
#include<iostream>
#include <cstring>
#include <vector>
#include <functional>//优先队列里的greater需要它.
#include <queue>//用优先队列需要它.
#include<utility>
using namespace std;

typedef long long ll;

const int MAXN = 1000005;
const ll INF = 100000000000000000;

#define rep(i,j,n) for(int i=j;i<n;i++)
#define sc(a) scanf("%d",&a)

int n;//空间数。
int m;//通道数.
int p;//初始空间编号.
int k;//分身空间编号.

struct info {
	int v1, v2;
	int w;
	info() {
		v1 = v2 = w = -1;
	}
	info(int from, int to, int weight) {
		v1 = from; v2 = to;
		w = weight;
	}
};

vector<info> g_posi[MAXN];
vector<info> g_inverted[MAXN];
vector<int> kSpace;
vector<info> pSpace; 

bool vis[MAXN];
vector<ll> dist(MAXN);

void dijkstra(int now,vector<info> g[]) {
	priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > q;//pair里是距离和编号.
	fill(dist.begin(), dist.end(), INF);
	dist[now] = 0;
	q.push(make_pair(0,now));
	ll minDist = INF;
	while (!q.empty()) {
		now = q.top().second;
		minDist = q.top().first;//堆顶是当前距离最小的结点.
		q.pop();
		if (dist[now] >= minDist && dist[now]<INF) {//mindist是当前最小距离，比它更小的结点肯定已经是最小距离，则它的相邻结点之前已经更新过，不需要更新了！这是我的理解，可能有误。
			for (int j = 0; j < g[now].size(); j++) {//以now为中介更新其它结点值.
				int v = g[now][j].v2;
				if (dist[v] > dist[now] + g[now][j].w) {
					dist[v] = dist[now] + g[now][j].w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
	}
}
int main() {
	cin >> n >> m >> p >> k;
	rep(i, 0, p) {
		int tmp; sc(tmp);
		pSpace.push_back(info(0,tmp,0));
    //不考虑p到0点也可到达，只考虑0到p可达，并不影响结果。
//		g_posi[0].push_back(info(0,tmp,0));
//		g_posi[tmp].push_back(info(tmp,0,0));
//		g_inverted[0].push_back(info(0,tmp,0));
//		g_inverted[tmp].push_back(info(tmp,0,0));
	}
	rep(i, 0, k) {
		int tmp; sc(tmp);
		kSpace.push_back(tmp);
	}
	rep(i, 0, m) {
		int u, v;
		ll w;
		scanf("%d%d%d", &u, &v, &w);
		g_posi[u].push_back(info(u, v, w));
		g_inverted[v].push_back(info(v, u, w));//反向建图。
	}
	//将0看作源点,连接所有p,计算处0到所有顶点的距离也就计算出了p到k的最短距离.
	g_posi[0]=pSpace;
	dijkstra(0,g_posi);
	ll ans = 0;
	rep(i, 0, kSpace.size()) {
//		if (dist[k_v] != INF) {
//			ans += dist[k_v];
//		}
		ans += dist[kSpace[i]];
	}
	g_inverted[0]=pSpace;
	dijkstra(0,g_inverted);
	ll subtract = 0;//因为消灭最后一个洞穴后不需要返回p,所以找一个从k出发到p最远的,把这个距离减去.
	rep(i, 0, kSpace.size()) {
		int k_v = kSpace[i];
    //下面这个注释，以及上面kSpace的里的那个注释，一用注释里的代替不再注释里的语句，也就是说，多判断一次dist的值是否是INF，即是否有效，就会出错，把判断是否等于INF的语句去掉，就能通过。不知道为什么
//		if (dist[k_v] != INF) {
//			ans += dist[k_v];
//			if (dist[k_v] > subtract) {
//				subtract = dist[k_v];
//			}
//		}
		ans += dist[k_v];
		if (dist[k_v] > subtract) {
			subtract = dist[k_v];
		}
	}
	ans -= subtract;
	printf("%lld", ans);
	return 0;
}
