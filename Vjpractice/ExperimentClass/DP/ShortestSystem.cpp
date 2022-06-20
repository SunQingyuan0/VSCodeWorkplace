/*某国为了防御敌国的导弹袭击,发展出一种导弹拦截系统.但是这种导弹拦截系统有一个缺陷:虽然它的第一发炮弹能够到达任意的高度,但是以后每一发炮弹都不能超过前一发的高度.某天,雷达捕捉到敌国的导弹来袭.由于该系统还在试用阶段,所以只有一套系统,因此有可能不能拦截所有的导弹.
怎么办呢?多搞几套系统呗!你说说倒蛮容易,成本呢?成本是个大问题啊.所以俺就到这里来求救了,请帮助计算一下最少需要多少套拦截系统.
Input
输入若干组数据.每组数据包括:导弹总个数(正整数),导弹依此飞来的高度(雷达给出的高度数据是不大于30000的正整数,用空格分隔)
Output
对应每组数据输出拦截所有导弹最少要配备多少套这种导弹拦截系统.
Sample Input
8 389 207 155 300 299 170 158 65
Sample Output
2*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	int dp[305];
	while(scanf("%d",&n)!=EOF) {
		int j,sum=0;//sum计算拦截导弹系统的套数
		memset(dp,0,sizeof(dp));
		for(int t=0; t<n; t++) {
			int k;
			int m;
			scanf("%d",&k);
			for(j=0; j<sum; j++) {
				if(dp[j]>=k) {
					dp[j]=k;//判断dp[j]与k的关系
					break;
				}
			}
			if(j==sum) {
				sum++;
				dp[sum-1]=k;
			}

		}
		printf("%d\n",sum);
	}

	return 0;
}