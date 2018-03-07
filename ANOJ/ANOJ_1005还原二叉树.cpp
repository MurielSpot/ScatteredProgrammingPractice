/*
https://logn.me/problem/1005
-----------------------------------------------------------------------------------------
还原二叉树
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 39      Total Submission: 50

查看我的提交显示标签
Problem Description
给一棵二叉树的层序遍历序列和中序遍历序列，求这棵二叉树的先序遍历序列和后序遍历序列。

Input
每个输入文件中一组数据。


第一行一个正整数N（1<=N<=30），代表二叉树的结点个数（结点编号为1~N）。接下来两行，每行N个正整数，分别代表二叉树的层序遍历序列和中序遍历序列。数据保证序列中1~N的每个数出现且只出现一次。

Output
输出两行，每行N个正整数，分别代表二叉树的先序遍历序列和后序遍历序列。每行末尾不输出额外的空格。

Sample Input
7
3 5 4 2 6 7 1
2 5 3 6 4 7 1
Sample Output
3 5 2 4 6 7 1
2 5 6 1 7 4 3

Author
Shoutmon
Source
15浙大考研机试模拟赛
-----------------------------------------------------------------------------------------
难度：5（自己没做出来）；时长：30分钟；ac：1次。

注意事项:
1. 一开始忘了输入n的值,结果没输值整个程序就结束了,因为n是全局变量,被初始化为0.还以为软件出了错.

思路：
1. 将层序遍历的值一个个插入到已建好的树中，因为层序遍历先输出上面一层再输下一层，所以插入建好的树的时候肯定插入在某个结点的空孩子上，不会出现这个要插入的结点的父亲还没有插入到树中的情况。
插入时判断在左子树还是在右子树，可以根据这个新结点和当前要插入的树的根结点在中序序列中的关系判断。
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

#define P 0
#define R 0
#define IN 0

const int MAX = 32;
const int INF = 1000000000;

int n;
int level[MAX] = { 0 };
int in[MAX] = { 0 };

struct node {
	node* left;
	node* right;
	int data;
	node() {
		left = right = NULL;
	}
};

/**
 * 找当前根结点在中序序列中的位置.
 */
inline int findPosInorder(int data) {
	for (int i = 0; i < n; i++) {
		if (in[i] == data)return i;
	}
	return n;
}

void insert(node* &root,int data,int index) {
	if (root == NULL) {
		root = new node;
		root->data = data;
		return;
	}
	//找当前根结点在中序序列中的位置.
	int rootPos = findPosInorder(root->data);
	//元素的序号在根结点序号的左边,则肯定插入左子树.否则右子树.
	if (index < rootPos)insert(root->left, data, index);
	else insert(root->right, data, index);
}
bool blank = false;
void preTraversal(node* root) {
	if (root) {
		if (blank)printf(" "); else blank = true;
		printf("%d", root->data);
		preTraversal(root->left);
		preTraversal(root->right);
	}
}
void postTraversal(node* root) {
	if (root) {
		postTraversal(root->left);
		postTraversal(root->right);
		if (blank)printf(" "); else blank = true;
		printf("%d", root->data);
	}
}

int main() {
#if IN
	freopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r", stdin);//重定向输入输出流.
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &level[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	node* root = NULL;
	//依次找层序的结点在中序序列中的位置.
	for (int i = 0; i < n; i++) {
		int j = 0;
		for (; j < n; j++) {
			if (level[i] == in[j]) {
				break;
			}
		}
		//当前j是层序结点在中序中的位置,根据中序中一个个结点在中序序列中的先后顺序,即序号值,判断这个元素应该插入到左边还是右边.
		insert(root, in[j], j);

	}
	blank = false;
	preTraversal(root);
	printf("\n");
	blank = false;
	postTraversal(root);
	printf("\n");
	return 0;
}
