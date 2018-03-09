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
难度：4；时长：估计30分钟之内,没算时间；ac：第一种1次,第二种算法2次(其中第一次头文件少加了),第三种1次。

注意事项:
1. 元素有奇数个时,中位数可能时负数,所以不能直接用[n/2,n)的和减去[0,n/2)的和,要把中位数提出来,单独加上它的绝对值!
2. nth_element(A, A + n / 2, A + n);    // 寻找第n/2大的数，并进行切分.
3. swap函数需要iostream头文件.round需要cmath,rand和RAND_MAX需要cstdlib.
4. 写randSelect函数的时候,它的含义要确定好,不然可能出错!

做法:
1. 划分两个子集时,可以用nth_element函数.
2. 也可以用随机选择算法，期望时间复杂度为 O(n).不用先成函数的话,做起来很繁琐,我调试了2h多小时吧,才把后面的两种算法写完.🙄

测试数据:
7
8 7 3 1 5 4 6
//输出18
10
-10 -1 -4 -3 -7 -8 -6 -5 -2 -9
//输出25
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

//二.用随机选择算法:randSelect直接调用randPartition,而没有递归调用自己,下面还有一种递归调用自己的.
#include<cstdio>
#include<iostream>

#include<cstdlib>
#include<ctime> 
#include<cmath>

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

const int MAXN = 10000010;

int n;
int num[MAXN];

template<class T>
void outputArr(T arr[], int left,int right) {
	while (left <= right) {
		cout << arr[left++] << ", ";
	}
	cout << endl;
}

int randPartition(int arr[], int left, int right) {//[].
	int pivot = round(1.0*rand() / RAND_MAX * (right - left)) + left;
	swap(arr[pivot], arr[left]);//别忘了交换.
	int save = arr[left];
	while (left < right) {
		while (left<right&&arr[right]>save)right--;
		arr[left] = arr[right];//注意不用arr[left] = arr[right--];!!!!!!!!!!!!
		while (left < right&&arr[left] <= save)left++;//<=!!!!!!!!!而且这里不是arr[left] <= arr[pivot]!!!!!!!!!!!!!因为此时主元的位置已经改变pivot没有意义了!!!变量名起的不好,应该让元素值赋到pivot里,而不应该让pivot表示下标.
		arr[right] = arr[left];
	}
	arr[left] = save;
	return left;//返回相遇时的下标.
}

//index表示当前找到了第几大的数,由于index的大小顺序与它的下标是对应的,所以如果比kth小,就继续在[index+1,right]里划分,找大小在index+1到right次序里的数,大于或等于kth同理.
void randSelect(int arr[], int left, int right, int kth) {//[].
	if (left >= right)return;
	int kIndex = kth;
	int index = randPartition(arr, left, right);
	while (left < right) {
		if (index<kIndex) {
			left = index + 1;
			index = randPartition(arr, left, right);
		}
		else if (index == kIndex) {
			return;
		}
		else {
			right = index - 1;
			index = randPartition(arr, left, right);
		}
	}
	
}

int main() {
	sc(n);
	long long sum = 0;
	rep(i, n) {
		sc(num[i]);
		sum += num[i];
	}
	randSelect(num, 0, n - 1, n / 2);
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

//二.用随机选择算法:randSelect递归调用自己.
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>

#include<iostream>//swap需要这个头文件. 
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define pt(a) printf("%d",a)
#define sc(a) scanf("%d",&a)

const int MAXN = 10000010;

int n;
int num[MAXN];

int randPartition(int arr[], int left, int right) {//[].
	int pivot = round(1.0*rand() / RAND_MAX * (right - left)) + left;
	swap(arr[pivot], arr[left]);//别忘了交换.
	int save = arr[left];
	while (left < right) {
		while (left<right&&arr[right]>save)right--;
		arr[left] = arr[right];//注意不用arr[left] = arr[right--];!!!!!!!!!!!!
		while (left < right&&arr[left] <= save)left++;
		arr[right] = arr[left];
	}
	arr[left] = save;
	return left;//返回相遇时的下标.
}

//注意这个函数的含义:是[left,right]内找第k大的,不是[0,n)内的.
//所以下面的xth=randPartition(arr, left, right)中的xth不能代表[left,right]中第x大的元素,而仅是一个下标.
void randSelect(int arr[], int left, int right,int kth) {//[].kth是从0开始算的.
	if (left >= right)return;
	//改动后的xth.
	int xth=randPartition(arr, left, right)-left;//xth=randPartition(arr, left, right)-left+1中不需要+1.
	if (xth < kth) {
		randSelect(arr, left+xth+1, right,kth-xth-1);//kth在新的[left+xth+1,right]区间里为第kth-xth-1大.
	}
	else if(xth==kth){
		return;
	}
	else {
		randSelect(arr, left, left + xth - 1,kth);
	}
}

int main() {
	sc(n);
	long long sum = 0;
	rep(i, n) {
		sc(num[i]);
		sum += num[i];
	}
	randSelect(num, 0, n - 1, n / 2);
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
