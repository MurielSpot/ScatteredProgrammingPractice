/*
https://logn.me/problem/1012
---------------------------------------------------------------------------------------------
死亡拆分II
Case Time Limit: 2200 MS (Others) / 4400 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 29      Total Submission: 218

查看我的提交显示标签
Problem Description
给定一个由整数组成的集合，集合中的整数各不相同，现在要将它分为两个子集合，使得这两个子集合的并为原集合、交为空集，同时在两个子集合的元素个数n1与n2之差的绝对值|n1-n2|尽可能小的前提下，要求它们各自的元素之和S1与S2之差的绝对值|S1-S2|尽可能大。

Input
每个输入文件中一组数据。


第一行一个正整数N（1<=N<=10000000），表示集合中的整数个数。第二行是用空格隔开的N个绝对值在6666666以内的整数。

Output
用空格隔开的两个整数，即所求的|n1-n2|与|S1-S2|。

Sample Input
5
4 2 1 3 5
Sample Output
1 9
Author
Shoutmon
Source
16浙大考研机试模拟赛
---------------------------------------------------------------------------------------------
难度：3；时长：估计30分钟之内,没算时间；ac：1次。

注意事项:
1. 元素有奇数个时,中位数可能时负数,所以不能直接用[n/2,n)的和减去[0,n/2)的和,要把中位数提出来,单独加上它的绝对值!
2. nth_element(A, A + n / 2, A + n);    // 寻找第n/2大的数，并进行切分.

做法:
1. 划分两个子集时,可以用nth_element函数.
2. 也可以用随机选择算法，期望时间复杂度为 O(n).
*/
//一.用nth_element函数.
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
#define sc(a) scanf("%d",&a)

const int MAXN = 10000010;

int n;
int num[MAXN];

int main() {
	sc(n);
	/*
	2^64/2=9223372036854775808, 2^64=18446744073709551616.
	可以支持任意18位的整数.
	*/
	long long sum = 0;
	rep(i, n) {
		sc(num[i]);
		sum += num[i];
	}
	nth_element(num, num + n / 2, num + n);
	long long sum_first_half = 0;
	rep(i, n / 2) {
		sum_first_half += num[i];
	}
	if (n % 2) {
		printf("1 %lld", sum - sum_first_half - num[n / 2] - sum_first_half + abs(num[n / 2]));
	}
	else {
		printf("0 %lld", sum - sum_first_half - sum_first_half);
	}
	return 0;
}

//二.用随机选择算法
