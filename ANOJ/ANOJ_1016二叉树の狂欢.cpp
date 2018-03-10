/*
https://logn.me/problem/1016
---------------------------------------------------------------------------------------------
二叉树の狂欢
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 23      Total Submission: 131

查看我的提交显示标签
Problem Description
给定一棵二叉树，判断其是否是AVL树（此处只要求考虑结点平衡，不需要考虑左右子树结点权值大小），如果不是AVL树的话，输出"NOT AVL TREE!!!"以及不平衡的结点个数；否则判断其是否是一棵完全二叉树，如果不是完全二叉树的话，输出"NOT COMPLETE TREE!!!" 以及结点个数饱和的最后一层层号（假设根结点层号为1，且第i层的结点个数饱和是指该层的结点个数等于2^(i-1)）；否则将这棵完全二叉树经过若干次向下调整变成大顶堆，输出"OHHHHH HEAP!!!"以及此过程中将父结点与子结点交换的总次数（每次父结点与子结点交换都算一次，即同一轮向下调整的过程中可能有多次交换）。

Input
每个输入文件中一组数据。


第一行一个正整数N（N<=20），代表二叉树的结点个数（结点编号为1到N）。


第二行按结点编号从小到大的顺序给出N个结点的权值（各结点的权值均小于20且各不相同）。


接下来按结点编号从小到大的顺序给出N行，每行为两个编号，分别代表该结点的左孩子编号和右孩子编号，如果不存在左(右)孩子，那么就用字符'-'代替。数据保证编号在1到N之间。

Output
分两行按题目描述中的字符串和相应统计结果。

Sample Input
5
1 2 3 4 5
2 3
4 5
- -
- -
- -
Sample Output
OHHHHH HEAP!!!
3
Author
Shoutmon
Source
17浙大考研机试模拟赛
---------------------------------------------------------------------------------------------
难度：3；时长：1h以上吧；ac：4次吧。

类型:avl,cbt,堆排序.

注意事项:
1. 变量类型不要写错.建议一个变量一行.
2. 题比较综合,堆排序不熟.

测试数据:
//不是avl
6
444 30 2 1 5 6
2 3
4 -
- 5
- -
- 6
- -
//输出
NOT AVL TREE!!!
1

//是avl,不是cbt.
8
444 30 2 1 4 5 7 6
2 3
4 -
5 6
- -
- -
7 8
- -
- -
//输出
NOT COMPLETE TREE!!!
2

//是avl和cbt
7
1 2 3 4 5 6 7
2 3
4 5
6 7
- -
- -
- -
- -
//输出
OHHHHH HEAP!!!
4

*/
#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<cmath> 
using namespace std;

#define sc(a) scanf("%d",&a)

const int MAXN = 22;

int n;//[1,n].
int w[MAXN];

int root = -1;

struct node {
	int left, right, father, weight;
	int level;
	int index;
	node() {
		left = right = father = weight = level = -1;
		index = -1;
	}
};
node tree[MAXN];

int avlCnt = 0;
bool cbt = true;
int cbtLevel = 0;//之前把它设置成了bool变量导致出错!!!!!

int judgeAvl(int root) {
	if (root == -1) {
		return 0;
	}
	else {
		int h1 = judgeAvl(tree[root].left);
		int h2 = judgeAvl(tree[root].right);
		if (abs(h1 - h2) >= 2)avlCnt++;
		return max(h1, h2) + 1;
	}
}

void judgeCbt(int now) {//层序遍历.
	queue<int> q;
	q.push(now);
	bool empty = false;
	tree[now].level = 1;
	int next;
	int i = 1;
	while (!q.empty()) {
		now = q.front();
		tree[now].index = i++;
		q.pop();
		next = tree[now].left;
		if (next != -1) {
			tree[next].level = tree[now].level + 1;
			q.push(next);
			if (empty)cbt = false;
		}
		else if (empty == false) {
			cbtLevel = tree[now].level;
			empty = true;
		}
		next = tree[now].right;
		if (next != -1) {
			tree[next].level = tree[now].level + 1;
			q.push(next);
			if (empty)cbt = false;
		}
		else if (empty == false) {
			cbtLevel = tree[now].level;
			empty = true;
		}
	}

}

void downAdjust(int now, int &cnt) {
	while (tree[now].left != -1) {
		int next = tree[now].left;
		int rchild = tree[now].right;
		if (rchild != -1 && tree[next].weight < tree[rchild].weight) {
			next = rchild;
		}
		if (tree[now].weight < tree[next].weight) {
			cnt++;
			swap(tree[now].weight, tree[next].weight);//只需要交换权值.
			now = next;
		}
		else return;//比两个孩子权值都要大,不必向下调整.
	}
}

int find_ith(int xth) {//找完全二叉树序号为xth的结点,这个需要时单独算出来的.
	for (int i = 1; i <= n; i++) {
		if (tree[i].index == xth)return i;
	}
	return -1;
}

int maxHeap(int root) {//返回交换次数值.
	int cnt = 0;
	for (int i = n / 2; i >= 0; i--) {
		downAdjust(find_ith(i), cnt);
	}
	return cnt;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sc(tree[i].weight);
	}
	for (int i = 1; i <= n; i++) {
		string a, b;
		cin >> a >> b;
		if (isdigit(a[0])) {
			tree[i].left = stoi(a);
			tree[stoi(a)].father = i;
		}
		if (isdigit(b[0])) {
			tree[i].right = stoi(b);
			tree[stoi(b)].father = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (tree[i].father == -1) {
			root = i;
			break;
		}
	}
	judgeAvl(root);
	if (avlCnt == 0) {
		judgeCbt(root);
		if (cbt) {
			printf("OHHHHH HEAP!!!\n");
			printf("%d\n", maxHeap(root));
		}
		else {
			printf("NOT COMPLETE TREE!!!\n");
			printf("%d\n", cbtLevel);
		}
	}
	else {
		printf("NOT AVL TREE!!!\n");
		printf("%d\n", avlCnt);
	}
	return 0;
}
