/*
https://logn.me/problem/1008
-----------------------------------------------------------------------------------
进击的二叉查找树
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 29      Total Submission: 52

查看我的提交显示标签
Problem Description
给定1~N的两个排列，使用这两个排列分别构建两棵二叉查找树（也就是通过往一棵空树中依次插入序列元素的构建方式）。如果这两棵二叉查找树完全相同，那么输出YES；否则输出NO。之后，输出第一个排列对应的二叉查找树的后序序列、层序序列。

Input
每个输入文件中一组数据。


第一行1个正整数N（1<=N<=30），表示二叉查找树中的结点个数。


接下来两行，代表1~N的两个排列。

Output
如果两个排列代表的二叉查找树完全相同，那么输出一行YES，否则输出一行NO。


接下来两行分别输出第一个排列对应的二叉查找树的后序序列、层序序列，整数之间用空格隔开。


每行末尾不允许有多余的空格。

Sample Input
5
4 2 1 3 5
4 5 2 3 1
Sample Output
YES
1 3 2 5 4
4 2 5 1 3
Author
Shoutmon
Source
16浙大考研机试模拟赛
-----------------------------------------------------------------------------------
难度:2;时长:25分钟;ac:1次.

注意事项:
1. 判断两个树是否相同,可以把两个树的指针同时传入一个函数里,详见下面的same函数.
其它做法有分别输出两个树的中序序列,前/后/层序序列,比较这两对序列如果相同,则是相同的树.
*/
#include<cstdio>
#include<iostream>

#include<vector>
#include<queue>

#include<algorithm>
using namespace std;

#define IN 0

#define rep(i,n) for(int i=0;i<n;i++)
#define pt(a) printf("%d",a)

const int MAXN = 32;
const int INF = 1000000000;

int n;
int seq_1[MAXN];
int seq_2[MAXN];

struct node {
	node* left;
	node* right;
	int data;
	node() {
		left = right = NULL;
	}
};

void insert(node* &root,int data) {
	if (root) {
		if (data < root->data) {
			insert(root->left,data);
		}
		else insert(root->right,data);
	}
	else {
		root = new node;
		root->data = data;
	}
}

bool same(node *r1,node *r2) {
	if (r1 == NULL && r2 == NULL) {
		return true;
	}
	else if (r1&&r2) {
		return same(r1->left, r2->left)&&same(r1->right,r2->right);
	}
	else return false;
}

bool blank = false;
void postSeq(node *root) {
	if (root) {
		postSeq(root->left);
		postSeq(root->right);
		if (blank)printf(" "); else blank = true;
		pt(root->data);
	}
}
void levelSeq(node *root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		root = q.front();
		if (blank)printf(" "); else blank = true;
		pt(root->data);
		q.pop();
		if (root->left) {
			q.push(root->left);
		}
		if (root->right) {
			q.push(root->right);
		}
	}
}

int main() {
#if IN
	freopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r", stdin);
#endif
	cin >> n;
	node* root_1 = NULL;
	rep(i, n) {
		int data;
		cin >> data;
		insert(root_1,data);
	}
	node* root_2 = NULL;
	rep(i, n) {
		int data;
		cin >> data;
		insert(root_2, data);
	}
	if (same(root_1, root_2)) {
		printf("YES\n");
	}else printf("NO\n");

	blank = false;
	postSeq(root_1);
	printf("\n");

	blank = false;
	levelSeq(root_1);
	return 0;
}
