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

/*
晴神给的答案
Problem C  二叉树の狂欢
这题是把多个知识点进行融合的综合题。
（1） 判断是否是 AVL 树：只要左子树是 AVL 树、右子树是 AVL 树、abs(左子树高
度 - 右子树高度) < 2 即为 AVL 树。于是可以进行后序遍历，使得在访问根结
点时已经知道左子树和右子树的高度，这样就可以知道当前根结点所在子树
是否是 AVL 树。细节可以看代码。
（2） 不平衡的结点个数：在（1）的过程中可以直接统计每个结点是否不平衡，
用全局变量记录一下即可。
（3） 判断是否是完全二叉树：就是 PAT A1110，扫习题集 9.2 节二维码就行。
（4） 饱和的最后一层层号：其实就是（3）中 return false 前的最后一行层号，可
以每一次遍历一整行的结点来做（就是标程那种层次遍历写法）。
（5） 建堆过程中统计交换父结点和子结点的次数：书上 downAdjust 函数里有明
确的 swap 函数，开一个全局变量统计一下那部分执行了多少次就行。
标程： http://paste.ubuntu.com/24158263/
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int maxn = 30;
bool isRoot[maxn];  // 结点是否是根结点
struct Node {
    int data;
    int left, right;    // 左孩子和右孩子的下标
} node[maxn];   // 二叉树结点静态数组
int Heap[maxn];
// input函数输入数据
int input() {
    char id[3];
    scanf("%s", id);    // 输入结点编号
    if(id[0] == '-') {
        return -1;      // 如果是'-',说明是空结点,返回-1
    } else {
        if(strlen(id) == 1) return id[0] - '0';     // 编号小于10
        else return (id[0] - '0') * 10 + (id[1] - '0');     // 编号大于等于10
    }
}
// findRoot函数找到根结点编号
int findRoot(int n) {
    for(int i = 1; i <= n; i++) {
        if(isRoot[i]) {     // isRoot为true时直接返回根结点编号i
            return i;
        }
    }
}
int numNotBalanced = 0;     // 不平衡的结点个数
bool isAVL(int root, int &height) {     // 判断是否是AVL树,height记录当前子树的高度
    if(root == -1) {    // 空结点
        height = 0;     // 高度为0
        return true;    // 空树是AVL树
    }
    int leftH, rightH;  // 左子树高度和右子树高度
    bool isLeftAVL = isAVL(node[root].left, leftH);     // 左子树是否是AVL树(同时计算左子树高度)
    bool isRightAVL = isAVL(node[root].right, rightH);  // 右子树是否是AVL树(同时计算右子树高度)
    height = max(leftH, rightH) + 1;    // 当前子树高度
    bool isBalanced = abs(leftH - rightH) <= 1;     // 当前子树是否平衡
    if(!isBalanced) numNotBalanced++;   // 统计不平衡结点个数
    return isLeftAVL && isRightAVL && isBalanced;   // 判断当前子树是否平衡
}
int lastFull = 0;   // 最后一层饱和的层号
// isComplete函数判断完全二叉树,root为根结点编号,n为结点个数
bool isComplete(int root, int n) {
    queue<int> q;       // 定义队列
    q.push(root);       // 根结点入队
    int indexHeapNode = 1;      // 顺带把二叉树的层序存到数组里作为下一步的heap使用,indexHeapNode为当前存储的下标
    while(n) {      // 只要n不为0,即还没有访问完全部非空结点
        int size = q.size();    // 当前层的结点个数
        for(int i = 0; n && i < size; i++) {    // 只要还没有访问玩全部非空结点,就遍历当前层的所有结点
            int front = q.front();      // 队首结点front
            q.pop();        // 弹出队首结点
            if(front == -1) return false;   // 访问到空结点,一定是非完全二叉树
            Heap[indexHeapNode++] = node[front].data;   // 顺带把二叉树的层序存到数组里作为下一步的heap使用
            n--;    // 已访问的非空结点减少1
            q.push(node[front].left);       // 左孩子入队(包括空结点)
            q.push(node[front].right);      // 右孩子入队(包括空结点)
        }
        lastFull++;
    }
    return true;    // 已经访问完所有非空结点,还没有碰到空结点,一定是完全二叉树
}
// 对Heap数组在[low, high]范围进行调整
// 其中low为欲调整结点的数组下标，high一般为堆的最后一个元素的数组下标
int downAdjust(int low, int high) {
    int numSwap = 0;      // 统计交换次数
    int i = low, j = i * 2;    // i为欲调整结点，j为其左孩子
    while(j <= high) {    // 存在孩子结点
        // 如果右孩子存在，且右孩子的值大于左孩子
        if(j + 1 <= high && Heap[j + 1] > Heap[j]) {
            j = j + 1;    // 让j存储右孩子下标
        }
        // 如果孩子中最大的权值比父亲大
        if(Heap[j] > Heap[i]) {
            swap(Heap[j], Heap[i]);    // 交换最大权值的孩子与父亲
            i = j;    // 令i为j、令j为i的左孩子，进入下一层
            j = i * 2;
            numSwap++;      // 累计交换次数
        } else {
            break;    // 孩子的权值均比父亲小，调整结束
        }
    }
    return numSwap;     // 返回交换次数
}
int makeHeap(int n) {    // 堆排序
    int numSwap = 0;    // 交换次数
    for(int i = n / 2; i >= 1; i--) {
        numSwap += downAdjust(i, n);    // 建堆
    }
    return numSwap;     // 返回交换次数
}
int main() {
    int n;
    scanf("%d", &n);    // 输入结点个数
    for(int i = 1; i <= n; i++) {
        scanf("%d", &node[i].data);
    }
    memset(isRoot, true, sizeof(isRoot));       //初始化所有结点都是根结点
    for(int i = 1; i <= n; i++) {        // 对每一个结点
        int left = input(), right = input();    // 输入左右孩子编号
        if(left != -1) isRoot[left] = false;
        if(right != -1) isRoot[right] = false;
        isRoot[left] = isRoot[right] = false;   // 这两个编号一定不是根结点
        node[i].left = left;        // 记录左孩子
        node[i].right = right;      // 记录右孩子
    }
    int root = findRoot(n), height;       // 寻找根结点root,定义最后一个结点last
    if(!isAVL(root, height)) {      // 非AVL树
        printf("NOT AVL TREE!!!\n%d\n", numNotBalanced);
    } else if(!isComplete(root, n)) {   // 非完全二叉树
        printf("NOT COMPLETE TREE!!!\n%d\n", lastFull);
    } else {    // 建堆
        printf("OHHHHH HEAP!!!\n%d\n", makeHeap(n));
    }
    return 0;
}
