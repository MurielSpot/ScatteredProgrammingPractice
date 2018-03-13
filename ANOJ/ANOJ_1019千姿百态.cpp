/*
https://logn.me/problem/1019
-----------------------------------------------------------------------------------------
千姿百态
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 101      Total Submission: 980

查看我的提交显示标签
Problem Description
对一棵N个给定结点的二叉树或二叉搜索树（BST）来说，可以有很多种形态。

例如对3个结点的二叉树来说，就有5种二叉树形态。

现在给出一个正整数N，表示结点个数，求二叉树或二叉搜索树有多少种形态。
Input
每个输入文件一组数据。
对每组数据，输入两个整数F、N（F == 0 || F == 1, 1<= N <= 1000），其中F为0时表示需要计算二叉树的形态个数，为1时表示需要计算二叉搜索树的形态个数；N表示二叉树或二叉搜索树的结点个数。

Output
输出一行，一个整数，表示N个结点的二叉树或二叉搜索树的形态数。由于结果可能很大，因此把结果模上1000000007后输出。

Sample Input 1
0 3
Sample Output 1
5
Sample Input 2
1 2
Sample Output 2
2
Author
Shoutmon
Source
18浙大考研机试模拟赛
-----------------------------------------------------------------------------------------
难度：5；时长：1h；ac：3次。

注意事项：
1. 一直在想二叉树和二叉搜索树到底结果有什么区别。
对二叉查找树来说，由于中序是有序数列，因此对一棵确定形态的二叉树来说，只要以中序递增的方式填入数字，就可以得到二叉查找树。
因此实际上二叉树与二叉查找树的形态数是相同的。
2. 要用longlong类型存数据，不然后面5个测试点全都会错。
3. 也可以用卡特兰数做。
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

const int MAXN=1005;

typedef long long ll;

int n, f;
ll dp[MAXN] = { 0 };

ll getShape(int index) {
	ll shape = 0;
	for (int i = 0; i < index; i++) {
		shape += dp[i] * dp[index - 1 - i];
		shape %= 1000000007;
	}
	return shape;
}

int main() {
	cin >> f >> n;
	dp[0] = 1;
	dp[1] = 1;//一个结点的形态数.
	dp[2] = 2;//两个结点时的形态数.
	for (int i = 3; i <= n; i++) {
		dp[i] = getShape(i);
	}
	printf("%lld", dp[n]);

	return 0;
}

//标程
#include <cstdio>
#include <cstring>
typedef long long LL;
const int MAXN = 1010;
const LL MOD = 1000000007;
int numTrees[MAXN];     // n个结点的二叉树形态数形态数
LL getNumTrees(int n) {     // 求n个结点的二叉树形态数
    if(numTrees[n] != -1) {     // 如果已经计算过
        return numTrees[n];     // 那就直接用计算过的结果
    }
    LL sum = 0;     // n个结点的结果
    for(int i = 0; i <= n - 1; i++) {   // 遍历左子树结点个数
        sum = (sum + getNumTrees(i) * getNumTrees(n - 1 - i) % MOD) % MOD;  // 累加左子树形态数乘以右子树形态数
    }
    numTrees[n] = sum;  // 存一下，方便下次用
    return sum;     // 返回结果
}
int main() {
    int flag, n;
    scanf("%d%d", &flag, &n);
    memset(numTrees, -1, sizeof(numTrees));
    numTrees[0] = 1;    // 初始化
    printf("%lld\n", getNumTrees(n));
    return 0;
}
