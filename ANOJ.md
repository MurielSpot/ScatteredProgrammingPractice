# ANOJ算法笔记OJ
## 1002判断三角形
难度：1；时长：20分钟；ac：1次。

类型:数学问题,模拟.

## 1003删除结点
难度：2；时长：30多分钟；ac：4次才ac。

类型:静态链表.

注意事项：
1. 格式输出非常讲究，注意区别-1和五位id的情况。所给链表开头就有可能是-1！它的格式也要注意！因为格式问题改了好多次才ac。
测试点3应该是first为-1的情况。
测试点5会有数据addr不满5位数的情况，所以高位要补0。
测试点1会有first不满5位数的情况，如果按%05d输出，又没有讨论first==-1，则测试点3就会错。

## 1004收集数码晶体
难度：5（自己没做出来）；时长：1h以上；ac：3次。

类型:图,矩阵乘法.

注意事项:
1. 用邻接矩阵,邻接表都超时了.是408考研真题中的一道,用01矩阵的乘法做.
已知有01矩阵g,1表示两个顶点之间有路径,0表示没有,则g^m中的i行i列的非零元素,表示从i到j长度为m的路径条数,进行l次乘法后,即经过l座桥,获得l个晶体时,即为结果.

## 1005还原二叉树
难度：5（自己没做出来）；时长：30分钟；ac：1次。

类型:中序层序建树!!!

注意事项:
1. 一开始忘了输入n的值,结果没输值整个程序就结束了,因为n是全局变量,被初始化为0.还以为软件出了错.

思路：
1. 将层序遍历的值一个个插入到已建好的树中，因为层序遍历先输出上面一层再输下一层，所以插入建好的树的时候肯定插入在某个结点的空孩子上，不会出现这个要插入的结点的父亲还没有插入到树中的情况。
插入时判断在左子树还是在右子树，可以根据这个新结点和当前要插入的树的根结点在中序序列中的关系判断。
手动模拟一下就知道思路了,然后让程序按照手动模拟的顺序操作.遇到这种题不要但凭脑子想不出来就放弃.

## 1006调查黑暗气息（还没做出来，测试点9未通过）
难度：4；时长：70多分钟；ac：∞次。

类型:图的遍历,最短路径,etc.

注意事项:
1. 不能用dijkstra判断层次.

## 1007那些年我们一起考过的浙大
难度:1;时长:40分钟;ac:3次.

类型:排序吧,忘了.

注意事项:
1. 这么简单的题3次才ac...注意输出格式%013lld,不是%13lld,不能少了0!"准考证号必须按照输入原样输出"意思就是高位要补0,不是说要记录输入的先后次序.
2. 预编译有一些技巧可以让写代码速度变快.
3. 输入流重定向之后freopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r", stdin);不用scanf,而用cin输入数据,也可以.<br/>
网上是这样说的:从底层上来说，C++ 的 cin 与 C语言的 scanf 都采用 stdin 作为输入源， 但cin和scanf 采用了不同的缓冲区，可以通过 ios 头文件里面的 sync_with_stdio () 函数设置缓冲区共享，使cin和scanf 共享缓冲区。C++也可以改变输入源，但这样很复杂。其实，C++对 stdin 进行了封装，用流和迭代器进行了转变了流的概念而已，而C的scanf直接操作 stdin而已

## 1008进击的二叉查找树
难度:2;时长:25分钟;ac:1次.

类型:判断两个树是否相同,树的遍历.

注意事项:
1. 判断两个树是否相同,可以把两个树的指针同时传入一个函数里,详见下面的same函数.
其它做法有分别输出两个树的中序序列,前/后/层序序列,比较这两对序列如果相同,则是相同的树.

## 10091009某计算器的超电磁炮
难度：5；时长：1h以上；ac：3次。

类型：栈的应用，中缀后缀表达式。

注意事项：
1. 没有。就是想说自己没做出来，要多做做。

思路：
1. 自己构造运算符优先级顺序表，然后用栈进行运算。
2. 简书，然后用后序表达式计算。

补充：
1. 逆波兰式（Reverse Polish notation，RPN，或逆波兰记法），也叫后缀表达式（将运算符写在操作数之后）.
2. （），（#，#），这里#表示栈底，之间无优先关系，因为表达式里不允许它们相继出现，所以在表达式没有错误的情况下，但当前符号等于）时，此时op栈的栈顶不会是（！
3. 操作数operand,运算符operator,界限符delimiter.

## 1010死亡拆分I
难度：2；时长：1h以上；ac：2次。

注意事项：
1. 注意数据范围，并不全是正数。
更好的做法：
用快拍的切分区间的做法，找pivot，直到找到正中间大小的数，把切分出两个全比pivot大和小的区间。此题数据较少，所以用sort可以，数据量很大时，需要用更优的做法，而不要用sort。《死亡拆分II》数据量比较大。
还有专门的函数可以实现找第k大元素的功能。nth_element 可以找到序列第 K 大并把序列分成小于跟大于两部分。

## 1011万妖穴
难度：2；时长：30分钟；ac：1次。

思路：
1. 老担心做错。vis数组存放洞穴是否被解除封印，need放小穴被解除封印还需要之前有几个洞穴被解除封印，g存放解除封印的前驱后继关系。
need在输入g的时候被初始化增加，在判断一个小穴被解除封印后更新减少，由于一个小穴被解除封印之后不会再被访问，所以不用担心need数组会被反复减少以致于出现负数的情况。

## 1012死亡拆分II
难度：4；时长：估计30分钟之内,没算时间；ac：第一种1次,第二种算法2次(其中第一次头文件少加了),第三种1次。

注意事项:
1. 元素有奇数个时,中位数可能时负数,所以不能直接用\[n/2,n)的和减去\[0,n/2)的和,要把中位数提出来,单独加上它的绝对值!
2. nth_element(A, A + n / 2, A + n);    // 寻找第n/2大的数，并进行切分.
3. swap函数需要iostream头文件.round需要cmath,rand和RAND_MAX需要cstdlib.
4. 写randSelect函数的时候,它的含义要确定好,不然可能出错!

做法:
1. 划分两个子集时,可以用nth_element函数.在algorithm头文件里.
2. 也可以用随机选择算法，期望时间复杂度为 O(n).不用先成函数的话,做起来很繁琐,我调试了2h多小时吧,才把后面的两种算法写完.🙄

测试数据:
<pre>7
8 7 3 1 5 4 6
//输出18
10
-10 -1 -4 -3 -7 -8 -6 -5 -2 -9
//输出25</pre>

## 1013上帝视角
难度：2；时长：40分钟以上应该是有的；ac：1次。

类型:树.

注意事项:
1. while循环老是忘了i++.
2. 找宽度时,不能用根结点一直往右走及往左走这种方式判断宽度,因为可能根结点右孩子没有右孩子了,但是根结点右孩子的左孩子的右边一直可以往右走走得很远.<br/>
给个测试数据:
<pre>//输入
8
1 2 3 4 7 5 8 6
2 1 8 7 4 5 6 3
//输出
1 2 3 4 7 8 5 6
2 8 7 6 5 4 3 1
5
4
5</pre>

思路:
从右往左就是求高度.<br/>
从右上往左下,就是求往右找最远能找多远,求解时,如果有右孩子,就把右边的长度加1,有左孩子,则右边长度不变,再开个全局变量,记录往右边去的长度的最远距离即可.<br/>
从上往下,求宽度,求解时,用一个变量记录往右或往左走了多远,向右孩子走就加1,向左孩子就减1,开全局变量记录往右的最大值,和往左的最小值,然后相减,
再加1(因为全局变量初始化最右和最左都为0,则根结点没有被计算,所以结果还要根结点那个位置).

## 1014校庆数
难度：1；时长：20；ac：1次。

类型:模拟(大数).

## 1015你们要的中缀表达式树
难度：3(哎)；时长：1h以上吧；ac：4还是5次。

类型:中缀表达式.

注意事项:
1. 输入数据时,把一个变量名字写错了,找了半个多小时,啊啊啊啊啊啊啊!
2. 表达式不用考虑没有左子树而有右子树的情况,虽然我记得之前好像做过这种只有右子树的题.
非叶子结点放的肯定时运算符,叶子结点放的是数字,所以判断左右子树如果都非空,就可以进行运算.否则直接输出数字本身即可.
最外层括号不需要输出,单个数字两边不需要加括号.

## 1016二叉树の狂欢
难度：3；时长：1h以上吧；ac：4次吧。

类型:avl,cbt,堆排序.

注意事项:
1. 变量类型不要写错.建议一个变量一行.
2. 题比较综合,堆排序不熟.

测试数据:
<pre>//不是avl
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
4</pre>

## 1017隐匿行踪
难度：5；时长：1小时以上,2小时都有；ac：5次吧。

类型:图.最短路径(最短时间).

注意事项:
1. 大于小于号不要写反.
2. 由于终点和起点未必是圆盘,所以需要单独讨论,所以初始化距离起点最短用时的数组时,应该用某个圆盘到起点的距离,而不是用INF.<br/>
因为最短路径的循环里,第一个找到的最近点不是起点,而是离起点最近的圆盘,所以此时离起点最短用时的数组都是INF的话,其它圆盘达到起点都必须经过这个第一个圆盘,会出错.<br/>
当所有圆盘用时都大于起终点直接的距离时,直接输出直接的距离即可;<br/>
最后找完最短距离时,还要加上s->d(起点到终点)的距离一起讨论,因为经过圆盘的路径可能是折线,使得路径长度反而增长了.<br/>
比较好的解决方法是,起点和终点都看作半径为0的圆盘,这样就不用单独领出来讨论它们以及它俩之间的时间对求最短时间的影响了.<br/>

其它做法:
正文代码下面还有其他人的做法,很简洁,我觉得特别好.先按到s时间长度排序,然后让后面的时长根据前面的时长更新.

## 1018龙龙跳跳跳
难度：3；时长：40分钟；ac：2次。

注意事项：
1. 仙人掌可能离恐龙很远，所以可能二次抛物线已经落到x轴以下，肯定不会碰到。
2. 思路大概就是根据三个方程组解系数，求解。用韦达定理好做一点。

## 1019千姿百态
难度：5；时长：1h；ac：3次。

注意事项：
1. 一直在想二叉树和二叉搜索树到底结果有什么区别。
对二叉查找树来说，由于中序是有序数列，因此对一棵确定形态的二叉树来说，只要以中序递增的方式填入数字，就可以得到二叉查找树。
因此实际上二叉树与二叉查找树的形态数是相同的。
2. 要用longlong类型存数据，不然后面5个测试点全都会错。
3. 也可以用卡特兰数做。

## 1020万妖瞬击
难度：5；时长：1或2个小时,或者更长,做了两次；ac：3次。

类型:关键路径(可以选择用拓扑排序),dp.

注意事项：
1. 取stl的set的元素用迭代器,用[]不合法.
2. 关键路径的内容还要反复看,我这里用的动态规划做的,可以试着用拓扑排序做.动态规划和拓扑排序两种方法都要会!

出题人旋风小晴天的说明:
Problem C 万妖瞬击<br/>
关键路径。算法细节之类的详见我书的第十章，基本上可以照抄。这里主要提一下从关键活动转为关键路径的一步。由于本题要求多条关键路径按字典序从小到大输出，因此需要保证路径前面的结点编号尽可能小。如果我们按 Dijkstra 算法中那样设置一个 pre 数组，那么做起来会相对麻烦。一个合适的做法是记录后继，即如果 u->v 是关键活动的话，我们不记录 pre[v]=u，而是记录 next[u]=v，这样在递归输出路径的时候就可以控制总是先访问编号小的结点。<br/>
可能的坑点？（1）多源点，多汇点，书上有写怎么处理（2）可能不止一个有向无环图，但好像正常来说就自然处理了，不算坑点吧。<br/>
如果题目只要求输出关键活动，但是需要按照一些排序规则来输出的话，只要把关键活动存(u,v)到 vector 里，然后排序的时候设置一下 cmp 就好了。

晴神的标程:用拓扑排序做的.https://paste.ubuntu.com/p/tB7KMdmjjt/

## 1021 ANOJ的比赛排名

## 1022

## 1023缺失数
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
<pre>
Problem B 缺失数
如果不是对时间要求非常高的场景的话，可以直接排序之后遍历找第一个 a[i]不是 i 的位置就行。对时间要求稍微高一些的话，注意到最小的缺失正整数不会超过 n，因此只要把不超过 n的数存到数组里，再排序。
如果 n 真的非常大，那就得用最标准的解法（整体思路是让每个数都回到自己的位置上，即达到 a[i] == i 的状态）：
假设数组存放下标是 1 到 n，那么遍历这个数组，如果当前 a[i] > 0 && a[i] <=n 的话，就判断 a[i]是否等于 a[a[i]]，也就是说，以当前位置的数作为数组下标的位置是否已经存在这个数，如果那个位置的数还不是 a[i]，就交换这两个数，这样交换直到 a[i]等于 a[a[i]]为止。
这样说很绕，举一个例子：4 个数，3、1、2、5。
先看 a[1]=3，由于 3（a[1]）号位是 2（a[a[1]]）（而不是 3），因此交换 3（a[1]）和 2（a[a[1]]），得到 2、1、3、5；
再看 a[1]=2，由于 2（a[1]）号位是 1（a[a[1]]）（而不是 2），因此交换 2（a[1]）和 1（a[a[1]]），得到 1、2、3、5；
此时 a[1]==a[a[1]]，判断下一位。
由于 a[2]==2==a[a[2]]，判断下一位。
由于 a[3]==3==a[a[3]]，判断下一位。
由于 a[4]==5，不在 1 到 4 的范围内，所以不管它。
好了，遍历完毕。之后只要再遍历整个数组，看哪个位置 a[i]!=i 即可。
因为本题时间很不好卡，如果是用 sort 方法过的同学也请了解一下标准解法。
当然 PAT 要考的话正常来说不会出现 n 非常大的情况（最多 10^5），所以理论上 sort 就能解决问题。
坑：负数；0；重复数；很大的数。
标程：https://paste.ubuntu.com/p/QTDKyGmJFX/</pre>

## 1024宇宙树
难度：5(做了好长时间,查出了各种不该犯的错误,除了输出大整数没有注意全0的情况)；时长：2h以上；ac：3,4次。

类型：并查集，树，大整数加法。

注意事项:
1. 用到了大整数加法！！尤其注意当所有数都为0时,数的输出问题!!
2. 学会string的用法,再大整数加法的时候可以用得上.
3. 并查集找父结点之后,在合并树时,是根节点进行合并,而不是对根下面的结点进行操作,如果操作非根结点,很可能把一棵树给拆开!

标程在正文下面.用到了string.https://paste.ubuntu.com/p/QTDKyGmJFX/

## 1025已经没什么好害怕了
难度：5；时长：2h以上；ac：无数次。

注意事项:
1. 正向反向图的0位都要讲pSpace赋值给它们，忘记g_inverted[0] = pSpace;这一句出了错。
2. 思路要正确，到k的最短距离，可以用一个超级源点连接所有的p，再通过最短路径的算法求出。但是求k到p的最短距离，不能用超级源点连接k，然后用最短路径算法，因为此时p的距离指的是p到k群体的最近距离，而具体的某个k到p群体的最短距离并不能确定。<br/>
所以应该逆向建图，即把所有路径方向都调转，则此时k到p的距离已经成了p到k的距离，再次用最短路径，则每个k的最短距离存的都是到p这个群体的最近的距离，直接累加所有k即可。
3. 题目的意思是所有的p空间都是连通的。且最后一次打完怪，不用回到p，所以这段距离如果多算了，需要去除，也就是说去除一个某个k到p群体的最长的那个距离，相当于这个k最后消灭。
4. 最短路径算法需要用堆优化，不然会超时。堆优化可以用优先队列。

补充：
1. 优先队列的使用：
priority_queue默认为大顶堆，即堆顶元素为堆中最大元素。如果我们想要用小顶堆的话需要增加使用两个参数：
<pre>
priority_queue&lt;int, vector&lt;int>, greater&lt;int> > q;  // 小顶堆  
priority_queue&lt;int, vector&lt;int>, less&lt;int> > q;     // 大顶堆  
</pre>
