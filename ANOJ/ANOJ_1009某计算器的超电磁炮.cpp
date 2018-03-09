/*
https://logn.me/problem/1009
---------------------------------------------------------------------------------------------
某计算器的超电磁炮
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 29      Total Submission: 64

查看我的提交显示标签
Problem Description
输入由非负整数、+、-、*、/、(、)组成的计算表达式，计算该表达式的值。

Input
每个输入文件中一组数据。


输入只有一行，不超过200个字符，其中不存在空格。数据保证表达式一定合法，且所有的整数都不小于0、不大于1024。中间结果保证不超过15位有效数位精度。

Output
输出一行，即表达式的值，结果精度保留小数点后2位。

Sample Input
3+(12/(2*2+1))
Sample Output
5.40
Author
Shoutmon
Source
16浙大考研机试模拟赛
---------------------------------------------------------------------------------------------
难度：5；时长：1h以上；ac：3次。

类型：栈的应用，中缀后缀表达式。

注意事项：
1. 没有。就是想说自己没做出来，要多做做。

思路：
1. 自己构造运算符优先级顺序表，然后用栈进行运算。
2. 建树，再用后序表达式计算。
逆波兰式（Reverse Polish notation，RPN，或逆波兰记法），也叫后缀表达式（将运算符写在操作数之后）.
补充：不过代码里用不到这个知识点，（），（#，#），这里#表示栈底，之间无优先关系，因为表达式里不允许它们相继出现，所以在表达式没有错误的情况下，c等于）时，此时op栈顶不会是（！
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include <exception>  
using namespace std;

const int MAXN = 1010;

map<char, int> prior;

inline void init_priority() {
	prior['('] = prior[')'] = 0;
	prior['+'] = prior['-'] = 1;
	prior['*'] = prior['/'] = 2;
}

inline double cal(char op, double n1, double n2) {
	switch (op) {
	case '+':return n1 + n2;
	case '-':return n1 - n2;
	case '*':return n1 * n2;
	case '/':return n1 / n2;
	default:return -1;
	}
}

stack<char> op;
stack<double> digit;

int main() {
	init_priority();

	string exp;
	cin >> exp;
	/*
	C++中for(auto i : v).c++11的新特性，范围for，相当于java的for each。
	v是一个可遍历的容器或流，比如vector类型，i就用来在遍历过程中获得容器里的每一个元素。
	*/
	double num = 0, n1, n2;
	for (auto c : exp) {
		if (isdigit(c)) {
			num = num * 10 + c - '0';
		}
		else {
			if (num) {
				digit.push(num);
				num = 0;
			}
			if (c == '(') {
				op.push(c);
			}
			else if (c == ')') {
				while (op.top() != '(') {
					n2 = digit.top(); digit.pop();
					n1 = digit.top(); digit.pop();
					digit.push(cal(op.top(), n1, n2));
					op.pop();
				}
				op.pop();//（出栈。
			}
			else {//c为+-*/
				while (op.size() && prior[op.top()] >= prior[c]) {
					n2 = digit.top(); digit.pop();
					n1 = digit.top(); digit.pop();
					digit.push(cal(op.top(), n1, n2));
					op.pop();
				}
				op.push(c);
			}
		}
	}
	if (op.size()) {
		if (num) {
			digit.push(num);
		}
		while (op.size()) {//处理栈中剩下的元素。因为）不会入栈，且每次遇到）都会处理到前面的（，所以栈中不会剩下（），所以直接处理即可。
			n2 = digit.top(); digit.pop();
			n1 = digit.top(); digit.pop();
			digit.push(cal(op.top(), n1, n2));
			op.pop();
		}
	}
	printf("%.2lf\n", digit.top());
	return 0;
}
