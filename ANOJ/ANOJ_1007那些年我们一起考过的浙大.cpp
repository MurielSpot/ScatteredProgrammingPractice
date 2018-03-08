/*
https://logn.me/problem/1007
-----------------------------------------------------------------------------------------
那些年我们一起考过的浙大
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 32      Total Submission: 61

查看我的提交显示标签
Problem Description
时光如梭。

浙大计算机考研初试总共有四门课，分值分别为100、100、150、150，其分数线分为单科线和总分线，其中四门课的单科线分别是a、b、c、d，总分线是L。也就是说，只有当每门课的分数都不低于该门课的单科线、并且总分不低于总分线时，才能够进入复试。为了简化题目，此处不考虑补分政策及其他政策。

现在给出N个学生的准考证号以及四门课的分数，计算能够进入复试的人数，并把能够进入复试的学生按总分从大到小的顺序输出他们的准考证号和总分，总分相同的则按准考证号从小到大的顺序进行输出。

Input
每个输入文件中一组数据。

第一行5个整数，分别是四门课的单科线a、b、c、d和总分线L（0<=a<=100、0<=b<=100、0<=c<=150、0<=d<=150、0<=L<=500）。

第二行一个整数N（0<=N<=300），代表学生人数。

接下来N行，每行由一个准考证号以及4个整数组成，其中准考证号的长度为13，且每一位都是0~9之间的数字，而4个整数分别代表该学生的四门课的分数。数据保证准考证号唯一，且每门课的分数都不小于0分、不大于该门课的满分分值。

Output
输出的第一行是能够进入复试的人数K。接下来K行，按照进入复试的学生的总分从大到小的顺序输出他们的准考证号和总分，总分相同的则按准考证号从小到大的顺序进行输出。准考证号必须按照输入原样输出，行末不允许有多余的空格。

Sample Input
55 55 85 85 330
6
1108060026000 72 75 118 110
1108060026001 78 53 91 115
1108060026002 80 74 130 112
1108060026003 69 70 127 89
1108060026004 76 75 118 82
1108060026005 75 85 84 100
Sample Output
3
1108060026002 396
1108060026000 375
1108060026003 355
Author
Shoutmon
Source
16浙大考研机试模拟赛
-----------------------------------------------------------------------------------------
难度:1;时长:40分钟;ac:3次.

注意事项:
1. 这么简单的题3次才ac...注意输出格式%013lld,不是%13lld,不能少了0!"准考证号必须按照输入原样输出"意思就是高位要补0,不是说要记录输入的先后次序.
2. 预编译有一些技巧可以让写代码速度变快.
*/

#include<cstdio>
#include<iostream>

#include<vector>
#include<algorithm>
using namespace std;

#define IN 0

#define rep(i,n) for(int i=0;i<n;i++)
#define scInt(a) scanf("%d",&a);
#define scLong(a) scanf("%lld",&a);

const int INF = 1000000000;

int four[4], l;

int judge(int arr[]) {
	int sum=0;
	rep(i, 4) {
		if (arr[i] < four[i])return INF;
		sum += arr[i];
	}
	if (sum < l)return INF;
	return sum;
}
struct info {
	//int four[4];
	int l;
	long long id;
	info(long long id_, int l_) {
		id = id_; l = l_;
		/*rep(i, 4) {
			four[i] = four_[i];
		}*/
	}
};

bool cmp(info a, info b) {
	if (a.l == b.l) {
		return a.id < b.id;
	}
	else return a.l > b.l;
}

vector<info> ans;
int main() {
#if IN
	freopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r", stdin);
#endif
	rep(i, 4) {
		/*cin >> four[i];*/
		scInt(four[i]);
	}
	scInt(l);
	int n;
	scInt(n);
	rep(i, n) {
		long long id;
		int score[4];
		int sum;
		scLong(id);
		rep(j, 4) {
			scInt(score[j]);
		}
		sum = judge(score);
		if (sum!=INF) {
			ans.push_back(info(id,sum));
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	rep(i, ans.size()) {
		/*printf("%13lld %d\n", ans[i].id, ans[i].l);*/
		printf("%013lld %d\n", ans[i].id, ans[i].l);
	}
	return 0;
}
