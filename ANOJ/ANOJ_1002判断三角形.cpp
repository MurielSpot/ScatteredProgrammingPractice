/*
https://logn.me/problem/1002
-------------------------------------------------------------------------------------------
判断三角形
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 43      Total Submission: 63

查看我的提交显示标签
Problem Description
Shoutmon给萌萌兽出了一个题：给出三条线段的长度，问能否组成三角形。不过线段的长度是通过每一个数位的英文给出的。你能帮助萌萌兽吗？

Input
每个输入文件中一组数据。

分三行分别给出三条线段的长度。每行以一个整数N（1<=N<=5）开始，表示后面给出的单词个数；接下来跟着N个英文单词，每个单词表示一个数位，线段的长度由这些英文单词直接拼接而成（例如one two three代表123，one one代表11），每两个单词之间用一个空格隔开。数字0到9分别用下面十个单词表示：zero、one、two、three、four、five、six、seven、eight、nine。数据保证每条线段的长度都不为0。

Output
如果可以组成三角形，那么输出YES；否则输出NO。

Sample Input
1 one
2 one one
3 one one one
Sample Output
NO

Author
Shoutmon
Source
15浙大考研机试模拟赛
-------------------------------------------------------------------------------------------
难度：1；时长：20分钟；ac：1次。
*/
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

#define P 0
#define R 0
#define IN 0

const int MAXID =10010;
const int INF = 1000000000;

bool judge(int a, int b, int c) {
	if (a&&b&&c) {
		if (a + b <= c || a + c <= b || b + c <= a) {
			return false;
		}
		return true;
	}
	else return false;//如果有为0的值，输出false。
}

int main() {
	/*FILE *fp = fopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r");*/
#if IN
	freopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r", stdin);//重定向输入输出流.
#endif
	char hash[10][6] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	int edge[3] = { 0 };
	for (int i = 0; i < 3; i++) {//遍历三条边。
		int n; scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			char num[6];
			scanf("%s", num);
			for (int k = 0; k < 10; k++) {
				if (strcmp(num, hash[k]) == 0) {
					edge[i] = edge[i] * 10 + k;//i对应三条边，第i条边长度累加。
					break;
				}
			}
		}
	}
	if (judge(edge[0], edge[1], edge[2])) {
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}
