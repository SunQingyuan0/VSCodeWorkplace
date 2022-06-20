/*N (1 ≤ N ≤ 100) cows, conveniently numbered 1..N, are participating in a programming contest. As we all know, some cows code better than others. Each cow has a certain constant skill rating that is unique among the competitors.

The contest is conducted in several head-to-head rounds, each between two cows. If cow A has a greater skill level than cow B (1 ≤ A ≤ N; 1 ≤ B ≤ N; A ≠ B), then cow A will always beat cow B.

Farmer John is trying to rank the cows by skill level. Given a list the results of M (1 ≤ M ≤ 4,500) two-cow rounds, determine the number of cows whose ranks can be precisely determined from the results. It is guaranteed that the results of the rounds will not be contradictory.

Input
* Line 1: Two space-separated integers: N and M
* Lines 2..M+1: Each line contains two space-separated integers that describe the competitors and results (the first integer, A, is the winner) of a single round of competition: A and B

Output
* Line 1: A single integer representing the number of cows whose ranks can be determined
　

Sample Input
5 5
4 3
4 2
3 2
1 2
2 5
Sample Output
2*/
#include<stdio.h> 
#include<string.h>
const int INF = 0x3f3f3f3f;
bool map[120][120];
 
void floyd(int n){ 
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(map[i][k] && map[k][j]){
				
					map[i][j] = true;   
				}
			}
		}
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF){
		memset(map,false,sizeof(map));
		int u,v;
		for(int i = 0;i < m;i++){
			scanf("%d%d",&u,&v);
			map[u][v] = true;
		}
		floyd(n);
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			bool flag = true;
			for(int j = 1;j<=n;j++){
				if(i!=j){
					if(!map[i][j] && !map[j][i]){ 
					
						flag = false;
						break;
					}
				}
			}
			if(flag){
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}