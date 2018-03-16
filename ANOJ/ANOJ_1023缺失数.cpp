/*
https://logn.me/problem/1023
---------------------------------------------------------------------------------------
缺失数
Case Time Limit: 3200 MS (Others) / 6400 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 118      Total Submission: 878

查看我的提交显示标签
Problem Description
输入N个整数，求缺失的最小正整数，即1、2、3、...中不存在于这N个整数中的最小数。例如-3、-1、0、1、2、4、6中缺失的最小正整数为3。注意这N个整数可能无序。

Input
每个输入文件一组数据。
对每组数据，第一行为一个整数N（0 <= N <= 10^7），表示整数的个数；
第二行为N个整数，每个整数的绝对值都不超过10^18。

Output
输出一个正整数，即缺失的最小正整数。

Sample Input
7
-3 -1 0 1 2 4 6
Sample Output
3
Author
Shoutmon
Source
18浙大考研机试模拟赛
---------------------------------------------------------------------------------------
难度：5(时间限制特别严格)；时长：将近1h；ac：5,6次。

类型:哈希.

注意事项:
1. 注意到缺失的正整数不会超过n+1！！！！！！！因为如果给的n个数正好是1到n,则缺失的是n+1,如果不是正好1到n,则1到n里肯定有缺失的数!!!!!!
2. 别忘了数的范围比较大,要用long long型!!!!!
3. 循环用常量表示边界节省时间: if (tmp > 0 && tmp < MAXN),for (int i = 1; i < MAXN; i++) 原先MAXN处写的都是n,结果有一个测试点超时了,看了别人的代码,把它们改成一个常量就不会超时.

思路:
1. 先取n个元素内大小再[1,n]内的,如果出现,哈希数组就设置为true,最后遍历数组1到n+1的位置,哪个为false就是答案.
2. 还有一种做法,在n很大的时候更好.是出题人晴神给的标程,但是我自己还没敲一遍,代码附在文末.

晴神的解析:
Problem B 缺失数
如果不是对时间要求非常高的场景的话，可以直接排序之后遍历找第一个 a[i]不是 i 的位置
就行。对时间要求稍微高一些的话，注意到最小的缺失正整数不会超过 n，因此只要把不超过 n
的数存到数组里，再排序。如果 n 真的非常大，那就得用最标准的解法（整体思路是让每个数
都回到自己的位置上，即达到 a[i] == i 的状态）：
假设数组存放下标是 1 到 n，那么遍历这个数组，如果当前 a[i] > 0 && a[i] <=n 的话，就
判断 a[i]是否等于 a[a[i]]，也就是说，以当前位置的数作为数组下标的位置是否已经存在这个数，
如果那个位置的数还不是 a[i]，就交换这两个数，这样交换直到 a[i]等于 a[a[i]]为止。
这样说很绕，举一个例子：
4 个数，3、1、2、5。
先看 a[1]=3，由于 3（a[1]）号位是 2（a[a[1]]）（而不是 3），因此交换 3（a[1]）和 2（a[a[1]]），
得到 2、1、3、5；
再看 a[1]=2，由于 2（a[1]）号位是 1（a[a[1]]）（而不是 2），因此交换 2（a[1]）和 1（a[a[1]]），
得到 1、2、3、5；
此时 a[1]==a[a[1]]，判断下一位。
由于 a[2]==2==a[a[2]]，判断下一位。
由于 a[3]==3==a[a[3]]，判断下一位。
由于 a[4]==5，不在 1 到 4 的范围内，所以不管它。
好了，遍历完毕。之后只要再遍历整个数组，看哪个位置 a[i]!=i 即可。
因为本题时间很不好卡，如果是用 sort 方法过的同学也请了解一下标准解法。
当然 PAT 要考的话正常来说不会出现 n 非常大的情况（最多 10^5），所以理论上 sort 就能
解决问题。
坑：负数；0；重复数；很大的数。
标程：https://paste.ubuntu.com/p/QTDKyGmJFX/
*/
#include<cstdio>

#define sc(a) scanf("%d",&a)
#define rep(i,n) for(int i=0;i<n;i++)

const int MAXN = 10000002;
bool exist[MAXN];

int main() {
	int n;
	sc(n);
	rep(i, n) {
		long long tmp; 
		scanf("%lld", &tmp);
		if (tmp > 0 && tmp < MAXN) {
			exist[tmp] = true;
		}
	}
	for (int i = 1; i < MAXN; i++) {
		if (exist[i] == false) {
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

//n很大的时候的解法
#include <cstdio>
#include <map>
#include <vector>
// #include <ctime>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 10000010;
int n;
LL a[MAXN];
vector<int> vec;

int getFirstMissingPositiveInteger() {
    for(int i = 1; i <= n; i++) {   // 遍历整个数组
        while(a[i] > 0 && a[i] <= n && a[i] != a[a[i]]) {   // 只要a[i]在范围内，且以a[i]为下标的数不等于a[i]
            swap(a[i], a[a[i]]);    // 交换，让a[i]回归本位
        }
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] != i) {     // 如果a[i]不等于i，说明i就是缺失的数
            return i;
        }
    }
    return n + 1;   // 如果上面的a[i]都等于i，那么说明n+1是缺失的数
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    printf("%d\n", getFirstMissingPositiveInteger());

    // 排序的解法
    // for(int i = 0; i < n; i++) {
    //     LL x;
    //     scanf("%lld", &x);
    //     if(x > 0 && x <= n) {
    //         vec.push_back(x);    // 只把1到n之间的数加到vector中
    //     }
    // }
    // sort(vec.begin(), vec.end());    // 排序
    // int k = 0;
    // while(k < (int)vec.size() - 1 && vec[k] + 1 >= vec[k + 1]) {     // 写>=是考虑重复的数
    //     k++;
    // }
    // printf("%lld\n", vec.size() == 0 ? 1 : ((LL)vec[k] + 1));
    return 0;
}
