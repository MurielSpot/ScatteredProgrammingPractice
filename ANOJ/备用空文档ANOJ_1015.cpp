/*
https://logn.me/problem/1015
---------------------------------------------------------------------------------------------
你们要的中缀表达式树
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 28      Total Submission: 128

查看我的提交显示标签
Problem Description
给定一棵二叉树，二叉树的各个结点要么表示四则运算符+、-、*、/，要么表示一个不超过10的非负整数。将这棵二叉树看作中缀表达式树，输出对应的中缀表达式，以及该中缀表达式的计算结果。

注意，输出的中缀表达式中，除了最外层以外，内层的每个“左操作数 操作符 右操作数”形式的两侧都要加上一对小括号。例如2+(3*(4/5))就是一个可能的正确输出。

Input
每个输入文件中一组数据。

第一行一个正整数N（N<=30），代表二叉树的结点个数（结点编号为0到N-1）。

第二行按结点编号从小到大的顺序给出N个结点的值（用空格隔开），其要么是四则运算符+、-、*、/的其中一个，要么是一个不超过10的非负整数。

接下来按结点编号从小到大的顺序给出N行，每行为两个编号，分别代表该结点的左孩子编号和右孩子编号，如果不存在左(右)孩子，那么就用字符'-'代替。数据保证编号在0到N-1之间，且中缀表达式树一定是合法的。

Output
输出一行，即所求的中缀表达式与对应的计算结果（精度保留两位小数），表达式与计算结果之间用空格隔开。注意输出的中缀表达式中不允许有空格。数据保证中缀表达式合法，且计算过程中不会出现除数为0的情况。

Sample Input
5
* 3 + 4 6
1 2
- -
3 4
- -
- -
Sample Output
3*(4+6) 30.00
Author
Shoutmon
Source
17浙大考研机试模拟赛
---------------------------------------------------------------------------------------------
难度：3(哎)；时长：1h以上吧；ac：4还是5次。

注意事项:
1. 输入数据时,把一个变量名字写错了,找了半个多小时,啊啊啊啊啊啊啊!
2. 表达式不用考虑没有左子树而有右子树的情况,虽然我记得之前好像做过这种只有右子树的题.
非叶子结点放的肯定时运算符,叶子结点放的是数字,所以判断左右子树如果都非空,就可以进行运算.否则直接输出数字本身即可.
最外层括号不需要输出,单个数字两边不需要加括号.
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define pt(a) printf("%d",a)
#define sc(a) scanf("%d",&a)

const int MAXN = 32;

int n;//[0,n-1].
struct node {
	int father, left, right;
	string data;//用string更方便,虽然加减乘除的ASCII值都大于30,但是假如有些题目中的符号ascii码值比较小呢,所以不要用int又存数字又表示符号.
	node() {
		father = left = right = -1;
	}
}tree[MAXN];

double operate(string str, double left, double right) {
	if (!isdigit(str[0])) {
		char op = str[0];
		switch (op) {
		case '-':return left - right;
		case '+':return left + right;
		case '*':return left * right;
		case '/':return left / right;
		}
	}
	return -1;
}

int root;
double infix(int now) {
	if (now != -1) {
		if (tree[now].left != -1 && tree[now].right != -1) {
			double left = -1, right = -1;
			if (now != root)printf("(");
			left = infix(tree[now].left);
			cout << tree[now].data;
			right = infix(tree[now].right);
			if (now != root)printf(")");
			return operate(tree[now].data, left, right);
		}
		else {
			cout << tree[now].data;
			return stoi(tree[now].data);
		}
	}
	else return -1;
}

int main() {
	sc(n);
	rep(i, n) {
		cin >> tree[i].data;
	}
	rep(i, n) {
		string a, b;
		cin >> a >> b;
		if (isdigit(a[0])) {
			tree[i].left = stoi(a);
			tree[stoi(a)].father = i;
		}
		if (isdigit(b[0])) {
			tree[i].right = stoi(b);
			tree[stoi(b)].father = i;//复制代码导致stoi(b)写成了stoi(a)!!!!!!!!!!!出错!!!!
		}
	}
	root = -1;
	rep(i, n) {
		if (tree[i].father == -1) {
			root = i;
			break;
		}
	}
	double value = infix(root);
	printf(" %.2lf\n", value);
	return 0;
}
