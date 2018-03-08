/*
https://logn.me/problem/1010
-----------------------------------------------------------------------------------------
死亡拆分I
Case Time Limit: 100 MS (Others) / 200 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 28      Total Submission: 163

查看我的提交显示标签
Problem Description
给定一个由整数组成的集合，集合中的整数各不相同，现在要将它分为两个子集合，使得这两个子集合的并为原集合、交为空集，同时在两个子集合的元素个数n1与n2之差的绝对值|n1-n2|尽可能小的前提下，要求它们各自的元素之和S1与S2之差的绝对值|S1-S2|尽可能大。

Input
每个输入文件中一组数据。

第一行一个正整数N（1<=N<=1000），表示集合中的整数个数。第二行是用空格隔开的N个绝对值在6666666以内的整数。

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
-----------------------------------------------------------------------------------------
难度：2；时长：1h以上；ac：2次。

注意事项：
1. 注意数据范围，并不全是正数。
更好的做法：
用快拍的切分区间的做法，找pivot，直到找到正中间大小的数，把切分出两个全比pivot大和小的区间。此题数据较少，所以用sort可以，数据量很大时，需要用更优的做法，而不要用sort。《死亡拆分II》数据量比较大。
还有专门的函数可以实现找第k大元素的功能。nth_element 可以找到序列第 K 大并把序列分成小于跟大于两部分。
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

#define IN 0
#define P 0

#define rep(i,n) for(int i=0;i<n;i++)

const int MAXN = 1010;
const int INF = 1000000000;

typedef long long ll;

int n;
ll num[MAXN];

ll sum(int left, int right) {//[left,right].
	ll summm = 0;
	while (left <= right) {
		summm += num[left++];
	}
	return summm;
}

int main() {
	cin >> n;
	rep(i, n) {
		cin >> num[i];
	}
	sort(num, num + n);
	if (n % 2) {//odd.
		printf("1 %lld", sum(n / 2 + 1, n - 1) - sum(0, n / 2-1) + abs(num[n / 2]));
	}
	else {
		printf("0 %lld", sum(n / 2, n - 1) - sum(0, n / 2 - 1));
	}
	return 0;
}
