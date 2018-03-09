/*
https://logn.me/problem/1013
---------------------------------------------------------------------------------------------
上帝视角
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 28      Total Submission: 62

查看我的提交显示标签
Problem Description
给一棵二叉树的层序遍历序列和中序遍历序列，求这棵二叉树的先序遍历序列和后序遍历序列，并给出从右往左、从右上往左下、从上往下分别能看到的结点个数。注意，此处均把二叉树的每条边都设置为等长，角度为45度，因此结点可能在视觉上重叠。所谓从右往左看是指，对同一层的结点，右边的结点会挡住左边的结点，这样同一层结点就只能看到最右边的那一个；同样的，从右上往左下看是指，右上角的结点会挡住左下角45度的结点；从上往下看是指，对同一竖直位置来说，只能看到最上方的结点。

例如对下图来说，从右往左能看到3个结点，从右上往左下能看到3个结点，从上往下能看到5个结点。


Input
每个输入文件中一组数据。

第一行一个正整数N（1<=N<=30），代表二叉树的结点个数（结点编号为1~N）。

接下来两行，每行N个正整数，分别代表二叉树的层序遍历序列和中序遍历序列。数据保证序列中1~N的每个数出现且只出现一次。

Output
先输出两行，每行N个正整数，分别代表二叉树的先序遍历序列和后序遍历序列。

接下来分三行输出从右往左、从右上往左下、从上往下分别能看到的结点个数。

每行末尾均不允许输出多余的空格。

Sample Input
7
1 2 3 4 5 6 7
4 2 5 1 6 3 7
Sample Output
1 2 4 5 3 6 7
4 5 2 6 7 3 1
3
3
5
Author
Shoutmon
Source
16浙大考研机试模拟赛
---------------------------------------------------------------------------------------------
难度：2；时长：40分钟以上应该是有的；ac：1次。

类型:树.

注意事项:
1. while循环老是忘了i++.
2. 找宽度时,不能用根结点一直往右走及往左走这种方式判断宽度,因为可能根结点右孩子没有右孩子了,但是根结点右孩子的左孩子的右边一直可以往右走走得很远.
给个测试数据:
//输入
8
1 2 3 4 7 5 8 6
2 1 8 7 4 5 6 3
//输出
1 2 3 4 7 8 5 6
2 8 7 6 5 4 3 1
5
4
5

思路:
从右往左就是求高度.
从右上往左下,就是求往右找最远能找多远,求解时,如果有右孩子,就把右边的长度加1,有左孩子,则右边长度不变,再开个全局变量,记录往右边去的长度的最远距离即可.
从上往下,求宽度,求解时,用一个变量记录往右或往左走了多远,向右孩子走就加1,向左孩子就减1,开全局变量记录往右的最大值,和往左的最小值,然后相减,
再加1(因为全局变量初始化最右和最左都为0,则根结点没有被计算,所以结果还要根结点那个位置).
*/
#include"stdafx.h"

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
#define pt(a) printf("%d",a)
#define sc(a) scanf("%d",&a)

//typedef long long ll;
const int INF = 1000000000;
//const double INF = 1000000000;
//const long long INF = 1000000000;

struct node {
	node *left, *right;
	int data;
	node() {
		left = right = NULL;
	}
};

const int MAXN = 32;

int n;
int level[MAXN];
int in[MAXN];

int getInPos(int data) {
	rep(i, n) {
		if (data == in[i])return i;
	}
	return n;
}

void insert(node* &root, const int nowIndex) {
	if (root) {
		int rootIndex=getInPos(root->data);
		if (nowIndex < rootIndex) {
			insert(root->left, nowIndex);
		}
		else {
			insert(root->right, nowIndex);
		}
	}
	else {
		root = new node;
		root->data = in[nowIndex];
	}
}

bool blank;
int maxRight, maxDepth;

int preOrder(node* root,int right) {
	if (root) {
		if (maxRight < right) {
			maxRight = right;
		}
		if (blank)printf(" "); else blank = true;
		printf("%d", root->data);
		int tmp = preOrder(root->left, right);
		return max(tmp, preOrder(root->right, right + 1)) + 1;
		//return max(preOrder(root->right, right + 1), preOrder(root->left,right)) + 1;//发现右子树要写在前面!
	}
	else {
		return 0;
	}
}

int leftWidth, rightWidth;
void postOrder(node* root,int width) {
	if (root) {
		if (width < leftWidth) {
			leftWidth = width;
		}
		if (width > rightWidth) {
			rightWidth = width;
		}
		postOrder(root->left,width-1);
		postOrder(root->right,width+1);
		if (blank)printf(" "); else blank = true;
		printf("%d", root->data);
	}
}

int getLeft(node* root) {
	int cnt=0;
	while (root) {
		cnt++;
		root = root->left;
	}
	return cnt;
}

int getRight(node* root) {
	int cnt = 0;
	while (root) {
		cnt++;
		root = root->right;
	}
	return cnt;
}

int main() {
	sc(n);
	rep(i, n) {
		sc(level[i]);
	}
	rep(i, n) {
		sc(in[i]);
	}
	node* root=NULL;
	rep(i, n) {
		int j=0;
		while (j < n) {
			if (level[i] == in[j])break;
			j++;//别忘加!!!!!
		}
		insert(root, j);
	}
	blank = false;
	maxRight = -1;
	maxDepth = preOrder(root, 1);
	printf("\n");

	blank = false;
	leftWidth = 0; rightWidth = 0;
	postOrder(root,0);
	printf("\n");
	printf("%d\n%d\n%d\n", maxDepth, maxRight, rightWidth-leftWidth+1);
	return 0;
}
