/*
https://logn.me/problem/1017
---------------------------------------------------------------------------------------------
隐匿行踪
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 27      Total Submission: 98

查看我的提交显示标签
Problem Description
在数码世界的某次战争中，年轻的狮子兽收到了一封密函，密函中指出需要让他从当前坐标赶往另一个坐标去狙击敌人的精英部队。但是狮子兽知道，整个战场都有可能被敌方的飞行兽从上往下侦查到，因此需要注意隐匿自己的行踪。

狮子兽虽然年轻，但他对战场非常了解，他知道在战场上存在N个无法被飞行兽侦查到的浮空圆盘，只要在浮空圆盘内部（包括圆盘边界，下同）就不会被飞行兽侦查到（浮空圆盘可能重叠）。

现在狮子兽想要从当前坐标前往指定坐标（假设其行进速度恒定，1单位时间行进1单位距离），但是为了减少暴露自己的可能，所以想使不在浮空圆盘内部的时间尽可能少。

注意：整个战场是一个连续二维坐标平面，地势平缓，且狮子兽的行进可以是任何方向、可以是直线也可以是曲线。

Input
每个输入文件中一组数据。

第一行一个正整数N（1<=N<=1000），表示浮空圆盘的个数。

接下来N行，每行三个整数x, y, r（-1000<=x,y<=1000、0<=r<=10），分别代表浮空圆盘的坐标(x,y)和半径r。

最后分两行给出狮子兽的当前坐标和目的坐标，每行两个整数x, y（-1000<=x,y<=1000）。

Output
输出不在浮空圆盘内部的最少时间（即不得不暴露在飞行兽侦查下的最少时间）。结果精度保留两位小数。

Sample Input
1
0 0 1
2 0
0 2
Sample Output
2.00
Author
Shoutmon
Source
17浙大考研机试模拟赛
---------------------------------------------------------------------------------------------
难度：5；时长：1小时以上,2小时都有；ac：5次吧。

类型:图.最短路径(最短时间).

注意事项:
1. 大于小于号不要写反.
2. 由于终点和起点未必是圆盘,所以需要单独讨论,所以初始化距离起点最短用时的数组时,应该用某个圆盘到起点的距离,而不是用INF.
因为最短路径的循环里,第一个找到的最近点不是起点,而是离起点最近的圆盘,所以此时离起点最短用时的数组都是INF的话,其它圆盘达到起点都必须经过这个第一个圆盘,会出错.
当所有圆盘用时都大于起终点直接的距离时,直接输出直接的距离即可;
最后找完最短距离时,还要加上s->d(起点到终点)的距离一起讨论,因为经过圆盘的路径可能是折线,使得路径长度反而增长了.

比较好的解决方法是,起点和终点都看作半径为0的圆盘,这样就不用单独领出来讨论它们以及它俩之间的时间对求最短时间的影响了.

下面还有其他人的做法,很简洁,我觉得特别好.
*/

#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<cmath> 
using namespace std;

#define sc(a) scanf("%d",&a)
#define rep(i,n) for(int i=0;i<n;i++)

#define P 0

const int MAXN = 1010;
const double INF = 10000000000000;

int n;

struct info {
	int x, y, r;
	info() {
		x = y = -1;
		r = 0;
	}
}vertex[MAXN];

double getTime(info v1, info v2) {
	return max(sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2)) - v1.r - v2.r,0.0);//减半径可能会出现负数,所以取0.
}

void dijkstra(info s, info d, double &time) {
	bool vis[MAXN] = { false };
	double least[MAXN];
	//fill(least, least + MAXN, INF);

	//先找第一个离当前s最近的点.
	double minTime = INF, tmpTime;
	int minIndex = -1;
	rep(i, n) {
		tmpTime = getTime(s, vertex[i]);
		least[i] = tmpTime;//least此时也需要初始化.
#if P
		printf("least[i]=%.2lf\n",least[i]);
#endif
		if (tmpTime < minTime) {
			minTime = tmpTime;
			minIndex = i;
		}
	}
	if (minIndex != -1) {
		least[minIndex] = minTime;
		vis[minIndex] = true;
	}
	time = getTime(s, d);
	if (minTime > time) {
		return;
	}

	rep(i, n - 1) {//循环n-1次.
		rep(v, n) {
			if (vis[v] == false) {
				tmpTime = getTime(vertex[minIndex], vertex[v]);
				if (least[v] > minTime + tmpTime) {
					least[v] = minTime + tmpTime;
#if P
					printf("now=%d,v=%d,least[v]=%.2lf,minTime=%.2lf,tmpTime=%.2lf\n", minIndex, v, least[v], least[minIndex],tmpTime);
#endif
				}
			}
		}
		minIndex = -1; minTime = INF;
		rep(v, n) {
			if (vis[v] == false) {
				if (least[v] < minTime) {//是大于号不是小于号........
				/*if (least[v] > minTime) {*///小于号没错.....是下面的赋值写反了......
					/*least[v] = minTime;*/
					minTime= least[v];
					minIndex = v;
				}
			}
		}
		if (minIndex == -1)break;
		vis[minIndex] = true;
	}

	//最后找离s到某圆盘再到d最近的点.
	minIndex = -1; minTime = INF;
	rep(v, n) {
		tmpTime = getTime(d, vertex[v]) + least[v];
		if (minTime > tmpTime) {
			minTime = tmpTime;
			minIndex = v;
		}
	}
	time = minTime;
	tmpTime = getTime(s, d);//最后还要确定所选路径长度是否比直接到达终点要小.
	if (minTime > tmpTime) {
		time = tmpTime;
		return;
	}
}

int main() {
	cin >> n;
	rep(i, n) {
		scanf("%d%d%d", &vertex[i].x, &vertex[i].y, &vertex[i].r);
	}
	info s, d;
	scanf("%d%d", &s.x, &s.y);
	scanf("%d%d", &d.x, &d.y);
	double time = 0;
	dijkstra(s, d, time);
	printf("%.2lf\n", time);
	return 0;
}

/*
其它人的做法.
特别好!
*/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std; 

const int maxn = 1005;  
const int inf = 1000000007; 
struct circle {
	double x, y, r; 
	double dis; //距离起点的距离 
	double res; //结果 
} circles[maxn];

//距离起点短的排在前面,或者距离起点时间一样长但半径更大的放在前面.
bool cmp(circle a, circle b) {
	return (a.dis < b.dis || (a.dis == b.dis && a.r > b.r)); 
}

double computeDis(circle a, circle b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); 
}

int main() {
	int n; scanf("%d", &n); 
	for(int i = 1; i <= n; i++) {
		scanf("%lf %lf %lf", &circles[i].x, &circles[i].y, &circles[i].r); 
	}
  //0号存起点.
	scanf("%lf %lf", &circles[0].x, &circles[0].y); 
	circles[0].dis = circles[0].res = circles[0].r = 0; 
  //n+1号为存终点.
	scanf("%lf %lf", &circles[n+1].x, &circles[n+1].y); 
	circles[n+1].dis = circles[n+1].res = computeDis(circles[0], circles[n+1]); //初始化到起点的时间和最终结果都为到起点的时间.
	circles[n+1].r = 0; 
	for(int i = 1; i <= n; i++) {//初始化所有圆盘到起点的时间.
		circles[i].dis = computeDis(circles[0], circles[i]);  
		circles[i].res = circles[i].dis; 
	}
	sort(circles + 1, circles + 1 + n, cmp);//将圆盘按照到起点时间从小到大排序.
	for(int i = 1; i <= n + 1; i++) {//判断第i大小的圆盘,经过前0到i-1大小的圆盘,时间能不能变短.
		for(int j = 0; j < i; j++) {
			//计算从j到i的用时,还没有减去半径.
			double curdis = computeDis(circles[j], circles[i]); 
			//printf("j:%d, i:%d dis:%.2f res:%.2f\n", j, i, curdis, circles[j].res); 
			if(curdis <= circles[i].r + circles[j].r) {//用时长度比半径短,
				circles[i].res = min(circles[i].res, circles[j].res); //j到i不耗时,取其中更小的即可.
			} 
			else {
				circles[i].res = min(circles[i].res, circles[j].res + (curdis - (circles[i].r + circles[j].r))); //j到i耗时,则取i的时间,或j的时间加上耗时,这两者之间更小的.
			}
		}
	}
	printf("%.2f\n", circles[n+1].res); 
	
	return 0; 
} 
