/*
https://logn.me/problem/1014
---------------------------------------------------------------------------------------------
校庆数
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 43      Total Submission: 63

查看我的提交显示标签
Problem Description
2017年5月21日是浙江大学120周年校庆，丸十哥哥定义了一类数叫“校庆数”，如果一个整数本身就等于120、或是其各数位之和等于120、又或是各数位的平方和等于120，那么就称这个整数为“校庆数”。

现在输入正整数N，丸十哥哥请你判断一下N是否是“校庆数”，如果是的话输出YES，否则输出NO。

Input
每个输入文件中一组数据。

仅一行，输入一个不超过30个数位的正整数。

Output
如果这个数是“校庆数”，那么输出YES；否则输出NO。

Sample Input
66666666666666666666
Sample Output
YES
Author
Shoutmon
Source
17浙大考研机试模拟赛
Hint
---------------------------------------------------------------------------------------------
难度：1；时长：20；ac：1次。
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include <exception>

#include<fstream>
#include <sstream>
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

//const int MAXN = 310;

int main() {
	//ifstream f;
	/*f.open("C:\\Users\\oakpa\\Desktop\\test.txt",ifstream::in);

	std::stringstream fileStream;
	fileStream << f.rdbuf();

	f.close();
	cout << fileStream.str();
	return 0;*/

	/*f.open("C:\\Users\\oakpa\\Desktop\\test.txt");
	cout << f.rdbuf();
	f.close();

	freopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r",stdin);*/
	string str;
	cin >> str;
	int num=0, sum=0, square=0;
	int tmp;
	/*for(int i=str.length()-1;i>=0;i--) {*/
	rep(i,str.length()){
		tmp = str[i] - '0';
		if (num <= 120) {//等于120时不能停止计算，因为部分等于120不等于整体等于120，所以要继续加，如果会超过120说明这个数肯定不会等于120，则不需要计算。
			num = num * 10 + tmp;//对应的是从高位到低位计算，不能从低位开始这样算。
		}
		if (sum <= 120) {
			sum += tmp;
		}
		if (square <= 120) {
			square += tmp * tmp;
		}
	}
	if (num == 120 || sum == 120 || square == 120) {
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}
