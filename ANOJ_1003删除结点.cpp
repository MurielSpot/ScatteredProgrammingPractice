/*
https://logn.me/problem/1003
-------------------------------------------------------------------------------------------------------
删除结点
Case Time Limit: 200 MS (Others) / 1500 MS (Java)       Case Memory Limit: 256 MB (Others) / 512 MB (Java)
Accepted: 42      Total Submission: 300

查看我的提交显示标签
Problem Description
给定一条单链表，对于链表中绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。

你需要输出删除结点后的单链表。
Input
每个输入文件中一组数据。

第一行给出结点的总个数N（0<N<10^5）和单链表的第一个结点的地址。所有结点的地址要么是一个五位正整数，要么是用-1表示的空地址NULL。然后是N行，表示N个结点，每行的格式为

Address Data Next

其中Address为结点地址（不足5位的高位用零填充至5位），Data为结点的数据域（绝对值不超过10^5的整数），Next为结点的指针域（即下一个结点的地址）。数据保证Address不等于-1。

Output
输出按题目要求删除结点后的单链表。第一行为删除结点后单链表上结点的个数、第一个结点的地址。

之后每行一个结点，输出格式与输入相同，结点输出顺序为单链表连接顺序。

Sample Input
5 11111
33333 -15 44444
22222 -15 33333
11111 21 22222
05689 15 -1
44444 -7 05689
Sample Output
3 11111
11111 21 22222
22222 -15 44444
44444 -7 -1

Author
Shoutmon
Source
15浙大考研机试模拟赛

-------------------------------------------------------------------------------------------------------
难度：2；时长：30多分钟；ac：4次才ac。

注意事项：
1. 格式输出非常讲究，注意区别-1和五位id的情况。所给链表开头就有可能是-1！它的格式也要注意！因为格式问题改了好多次才ac。
测试点3应该是first为-1的情况。
测试点5会有数据addr不满5位数的情况，所以高位要补0。
测试点1会有first不满5位数的情况，如果按%05d输出，又没有讨论first==-1，则测试点3就会错。
*/
#include<cstdio>
#include<iostream>

#include <string>
#include <cstring>

#include <algorithm>
#include<cmath> 

#include<vector>
#include<stack>
#include<queue>
#include<set>

#include<map>
#include <utility>//pair
using namespace std;

#define P 0
#define R 0
#define IN 0

const int MAX =100010;
const int INF = 1000000000;

struct node{
	int addr,data,next;
	node(){
		addr=next=-1;
	}
	node(int a,int d,int n){
		addr=a;data=d;next=n;
	}
}list[MAX];

map<int,bool> tag;

vector<node> ans;

int main() {
#if IN
	freopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r", stdin);//重定向输入输出流.
#endif
	int n,first;
	scanf("%d%d",&n,&first);
	for(int i=0;i<n;i++){
		int addr,data,next;
		scanf("%d%d%d",&addr,&data,&next);
		list[addr]=node(addr,data,next);
	}
	int tmp=first;
	while(tmp!=-1){
		int absdata=abs(list[tmp].data);
		if(tag.find(absdata)==tag.end()){
			tag[absdata]=true;
			ans.push_back(list[tmp]);
		}
		tmp=list[tmp].next;
	}
	if (first == -1)printf("0 -1");
	else printf("%d %05d\n",ans.size(),first);//这里也是要用%05d输出的。但是注意并不是所有时候都是要输出5位，当它为-1时，是不能输出5位的！
	for(int i=0;i<ans.size();i++){
		if(i!=ans.size()-1){
			printf("%05d %d %05d\n",ans[i].addr,ans[i].data,ans[i+1].addr);//是%05d，不是%04d。。。
		}else{
			printf("%05d %d -1\n",ans[i].addr,ans[i].data);
		}
	}
	return 0;
}
