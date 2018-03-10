# ScatteredProgrammingPractice
零散的刷题练习

## 输入输出流
<pre>freopen("C:\\Users\\oakpa\\Desktop\\test.txt", "r", stdin);//重定向输入输出流.

ifstream f;
f.open("C:\\Users\\oakpa\\Desktop\\test.txt",ifstream::in);//打开一个文件.

std::stringstream fileStream;
fileStream &lt;&lt; f.rdbuf();//将ifstream流输入到stringstream流中.
f.close();//文件用完关闭是个好习惯.

cout &lt;&lt; fileStream.str();//将stringstream流输出.

//或者直接将ifstream流输出.
f.open("C:\\Users\\oakpa\\Desktop\\test.txt");
cout &lt;&lt f.rdbuf();
f.close();</pre>

## 预处理小技巧
<pre>#define zeros(a) memset(a,0,sizeof(a))
#define ones(a) memset(a,-1,sizeof(a))
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scs(a) scanf("%s",a)
#define sclld(a) scanf("%I64d",&a)
#define pt(a) printf("%d\n",a)
#define ptlld(a) printf("%I64d\n",a)
#define rep0(i,n) for(int i=0;i&lt;n;i++)
#define rep1(i,n) for(int i=1;i&lt;=n;i++)
#define rep_1(i,n) for(int i=n;i>=1;i--)
#define rep_0(i,n) for(int i=n-1;i>=0;i--)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)&lt;(b)?(a):(b))
#define lson (step&lt;&lt;1)
#define rson (lson+1)
#define esp 1e-6
#define oo 0x3fffffff
#define TEST cout&lt;&lt;"*************************"&lt;&lt;endl</pre>
