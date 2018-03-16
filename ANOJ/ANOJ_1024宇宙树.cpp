/*
https://logn.me/problem/1024
---------------------------------------------------------------------------------------
宇宙树
Case Time Limit: 200 MS (Others) / 400 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 94      Total Submission: 984

查看我的提交显示标签
Problem Description
在传承至今的典籍中认为，每个宇宙都是十种宇宙中的一种：炎之宇宙、光之宇宙、冰之宇宙、风之宇宙、雷之宇宙、土之宇宙、水之宇宙、木之宇宙、钢之宇宙、暗之宇宙，各表示了一个宇宙内部的主要元素。在最初始的大爆炸之后，在混沌中产生了最初的若干个宇宙，这些宇宙的类型是以上十种之一，可能相同，可能不同。从这些宇宙开始，每过一个纪元，各个宇宙都有可能孕育出多个新的宇宙（类型可能相同，可能不同）。可以预见，从任何一个初始宇宙开始，在经过若干个纪元之后，就有可能得到非常多新的宇宙。

在更高的维度上，一种名为“孵化者”的生物在观测着这些宇宙。“孵化者”们把宇宙之间的孕育关系表示成一棵树，称为“宇宙树”。下图便是一棵可能的宇宙树，其中用0~9来分别代表十种宇宙的类型，那么这棵宇宙树便是从一个类型为2的初始宇宙开始，孕育出了类型分别为6、1、2的三个宇宙，而类型为6的那个宇宙又孕育出了类型为0和9的两个宇宙，类型为2的那个非初始宇宙孕育出了类型为5的宇宙。


“孵化者”们发现，一个宇宙与它孕育出的新宇宙之间并不是完全没有联系的，旧宇宙的信息会被携带一部分到新的宇宙中。它们猜想，既然宇宙类型的生成是“随机”的，那么在很多很多个纪元之后，再孕育出的新宇宙，其宇宙内部很可能会是十种元素达到平衡的状态。“孵化者”们认为，可以观测就可以干涉，可以干涉就可以控制，那么研究当前这些宇宙的类型便十分重要。

“孵化者”们认为，每一个处于宇宙树叶结点的宇宙，都是其所在分支上的最新宇宙，可以把这些叶结点的宇宙称为“新宇宙”。根据它们的猜想，这些宇宙的类型虽然从主要元素上来说属于十种中的一种，但如果把它们划分得更细致的话，是可以得到更准确的类型信息的。“孵化者”们把一个宇宙的“准确类型”定义为：从单棵宇宙树的初始宇宙开始、沿着孕育关系向下到达该宇宙的过程中形成的路径上的各类型的拼接结果就是这个宇宙的“准确类型”。例如在上图中，主类型为0的宇宙的“准确类型”是260，主类型为9的的宇宙的“准确类型”是269，主类型为1的的宇宙的“准确类型”是21，主类型为5的宇宙的“准确类型”是225。

为了研究宇宙类型的混合结果，“孵化者”们把一棵宇宙树的所有“新宇宙”的“准确类型”求和，并将得到的结果称为这棵宇宙树的类型，这有助于它们进行下一步研究。例如对上面的图来说，这棵宇宙树的类型便是260+269+21+225=775。

现在“孵化者”们想知道，当前存在的所有宇宙树的类型分别是什么。

Input
每个输入文件中一组数据。
对每组数据，第一行为两个正整数N（1 <= N <= 10000, 0 <= M < N），分别表示宇宙的个数与孕育关系的条数。假设宇宙的编号为0~N-1，且每棵宇宙树的初始宇宙的编号一定是这棵宇宙树中最小的。
接下来一行N个整数，其中第i个整数表示编号为i-1的宇宙的主类型。
接下来M行，每行两个整数u和v（0 <= u < N, 0 <= v < N, u != v），表示编号为u的宇宙孕育了编号为v的宇宙。数据保证同一对(u,v)只会出现一次。

Output
第一行一个整数，表示宇宙树的个数K。
第二行K个整数，分别表示这K个宇宙树的类型。输出顺序为，如果一棵宇宙树的初始宇宙编号比其他宇宙树的小，那么就优先输出。
行末不允许有多余的空格。

Sample Input
10 8
2 6 1 2 0 9 5 0 3 6
0 1
0 2
0 3
1 4
1 5
3 6
7 8
8 9
Sample Output
2
775 36
Author
Shoutmon
Source
18浙大考研机试模拟赛
---------------------------------------------------------------------------------------
难度：5(做了好长时间,查出了各种不该犯的错误,除了输出大整数没有注意全0的情况)；时长：2h以上；ac：3,4次。

类型：并查集，树，大整数加法。

注意事项:
1. 用到了大整数加法！！尤其注意当所有数都为0时,数的输出问题!!
2. 学会string的用法,再大整数加法的时候可以用得上.
3. 并查集找父结点之后,在合并树时,是根节点进行合并,而不是对根下面的结点进行操作,如果操作非根结点,很可能把一棵树给拆开!

标程在正文下面.用到了string.https://paste.ubuntu.com/p/QTDKyGmJFX/
*/
#include <cstdio>
#include<iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

void outputAns();

typedef long long ll;

const int MAXN = 10005;
const ll INF = 100000000000000000;

#define rep(i,j,n) for(int i=j;i<n;i++)
#define sc(a) scanf("%d",&a)

//因为outputAns函数每次输出都会把sum数组清空,所以调试的时候如果用到了这个函数,最终的结果是打印不出来的!
#define P 0

int n;//宇宙个数.[0,n-1].
int m;//孕育关系,边.

vector<int> type(MAXN);//宇宙主类型.
vector<int> g[MAXN];

vector<int> father(MAXN);

void init_set() {
	rep(i,0, MAXN) {
		father[i] = i;
	}
}

int findFather(int a) {
	if (father[a] == a) {
		return a;
	}
	else {
		return father[a] = findFather(father[a]);
	}
}

void unite(int a, int b) {
	int af = findFather(a);
	int bf = findFather(b);
	if (af != bf) {
		//又出错了!!!不是类型号小的做父亲,而是编号最小的应该做父亲,它将会是树的根!!!!!
		//if (type[af] < type[bf]) {//这里也不是type[a] < type[b],是根结点比较!
		//	//father[b] = af;//这里写错了,下面也是,是根结点指向另一个根结点!!!
		//	father[bf] = af;
		//}
		//else {
		//	//father[a] = bf;
		//	father[af] = bf;
		//}
		if (af < bf) {
			father[bf] = af;
		}
		else {
			father[af] = bf;
		}
	}
}

//s最后一位是个位,d第一位是个位,s和d相加,结果存在d里.所以ds可能会改变.
//ds和ss分别是d和s数组的大小.
void add(int d[],int &ds,int s[],int ss) {
	int carry = 0;
	int tmp;

	//应该从ss-1开始加!!!!
	ss--;
	int i = 0;
	while (ss>=0) {
		tmp = d[i]+s[ss]+carry;
		carry = tmp / 10;
		d[i] = tmp % 10;
		ss--;
		i++;
	}
	//i < ds&&carry,循环判断结束不能是左边那样,因为不管有没有超过ds,有进位就要继续算!
	while (carry) {//当s加完了,但是进位还没结束,则继续进位.
		tmp = d[i] + carry;
		carry = tmp / 10;
		d[i] = tmp % 10;
		i++;
	}
	ds = max(i,ds);//ds是需要更新的.
}

int big[MAXN] = { 0 }; int bigPtr = 0;//大数和大数指针.这里数字是正着存的.
int sum[MAXN] = { 0 }; int sumPtr = 0;//sum数字是倒着存的!!!!!
void dfs(int now) {
	big[bigPtr++] = type[now];
	if (g[now].size()==0) {//不写==0含义真好反了,脑子又糊涂了!
		add(sum,sumPtr, big,bigPtr);
#if P
		outputAns();
#endif
		bigPtr--;
		return;
	}
	rep(i, 0, g[now].size()) {
		//int next = g[now][i];
		dfs(g[now][i]);
	}
	bigPtr--;
}

void outputAns() {
	bool leading0 = true;
	if (sumPtr == 0) {
		printf("0");
	}
	else {//注意这里,可能所有位都是0,这种情况可能什么都不输出,从而出错,因为这种情况下也是要输出0的!
		while (sumPtr > 0) {
			sumPtr--;//应该先减再输出,因为最开始的sumPtr指向的位置是无效的!
			if (leading0) {
				if (sum[sumPtr] != 0) {
					printf("%d", sum[sumPtr]);
					leading0 = false;
				}
			}
			else {
				printf("%d", sum[sumPtr]);
			}
			sum[sumPtr] = 0;
			/*sumPtr--;*/
		}
		if (leading0) {//这里还需要判断是否全位0.
			printf("0");
		}
	}
}

int main(){
	init_set();

	cin >> n >> m;
	rep(i, 0, n) {
		scanf("%d", &type[i]);
	}
	rep(i, 0, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		unite(u, v);
	}
	int cosmosCnt = 0;
	set<int> root;
	rep(i,0,n) {//查树的个数.
		if (father[i] == i) {
			cosmosCnt++;
			root.insert(i);//分清宇宙类型和宇宙编号.
		}
	}
	printf("%d\n", cosmosCnt);
	set<int>::iterator it = root.begin();
	int blank = root.size();
	while (it != root.end()) {
		sumPtr = 0;//sum在outputAns里已经置0了.
		bigPtr = 0;
		dfs(*it);//计算一颗树的宇宙类型.
		outputAns();
		blank--;
		if (blank)printf(" ");
		it++;
	}
	return 0;
}

//标程
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 10010;
struct Node {
    string data;
    vector<int> child;
} node[MAXN];
int n, m;
int father[MAXN]; // 存放父亲结点
bool isRoot[MAXN]; // 记录每个结点是否作为某个集合的根结点
int findFather(int x) { // 查找x所在集合的根结点
    int a = x;
    while(x != father[x]) {
       x = father[x];
    }
    // 路径压缩
    while(a != father[a]) {
       int z = a;
       a = father[a];
       father[z] = x;
    }
    return x;
}
void Union(int a, int b) { // 合并a和b所在的集合
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        if(faA < faB) {     // 以较小编号的作为fater
            father[faB] = faA;
        } else {
            father[faA] = faB;
        }
    }
}
void init(int n) { // 初始化father[i]为i，且flag[i]为false
    for(int i = 0; i < n; i++) {
        father[i] = i;
        isRoot[i] = false;
    }
}
string removeLeadingZero(string str) {      // 去掉前导0
    while(str.length() > 1 && str.back() == '0') {
        str.pop_back();
    }
    return str;
}
string sum = "0", tempSum = "";     // 和，临时和
string getSum(string a, string b) {     // 求大整数的和
    string result = "";
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < a.length() || i < b.length() || carry; i++) {
        int numA = i < a.length() ? (a[i] - '0') : 0;
        int numB = i < b.length() ? (b[i] - '0') : 0;
        result += (numA + numB + carry) % 10 + '0';
        carry = (numA + numB + carry) / 10;
    }
    result = removeLeadingZero(result);
    reverse(result.begin(), result.end());
    return result;
}
void DFS(int u) {   // 先序，求整棵树的所有从根到叶子所代表的数的和
    if(!node[u].child.size()) {     // 递归边界，叶子结点
        sum = getSum(sum, tempSum);     // sum = sum + tempSum
        return;
    }
    for(int i = 0; i < node[u].child.size(); i++) {     // 遍历所有子结点
        int v = node[u].child[i];   // v为子结点编号
        tempSum += node[v].data;    // 临时和拼接上这个数位
        DFS(v);     // 递归遍历以子结点v为根节点的树
        tempSum.pop_back();     // 把刚才拼接上的数位去掉
    }
}
int main() {
    // freopen("2.in", "r", stdin);
    // freopen("2.out", "w", stdout);
    scanf("%d%d", &n, &m);
    init(n);        // 初始化
    for(int i = 0; i < n; i++) {
        char str[2];
        scanf("%s", str);
        node[i].data = string(str);     // 结点数据域
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        Union(u, v);    // 合并u和v所在的两棵树
        node[u].child.push_back(v);     // 建边u->v
    }
    for(int i = 0; i < n; i++) {
        isRoot[findFather(i)] = true; // i的根结点是findFather(i)
    }
    int num = n - m;
    printf("%d\n", num);    // 树的个数等于点数减去边数
    for(int i = 0; i < n; i++) {    // 遍历所有结点
        if(isRoot[i]) { // 如果是一棵树的根
            sum = "0";  // 初始化sum为0
            tempSum = node[i].data;     // 初始化临时和为根节点的数
            DFS(i);     // 递归求解整棵树的和
            printf("%s", sum.c_str());  // 输出结果
            if(--num) {
                printf(" ");    // 格式控制
            }
        }
    }
    printf("\n");
    return 0;
}
