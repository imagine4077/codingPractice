#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 1000
#define MAXC 100000

int V[MAXN], W[MAXN], x[MAXN];
int d[MAXN][MAXC];

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int n, C,a=0;
	while(scanf("%d %d", &n, &C) != EOF){
		for(int i=0; i<n; ++i)	scanf("%d %d", &V[i], &W[i]);
		for(int i=0; i<n; ++i)	x[i] = 0; //初始化打印方案
		
		for(int i=0; i<=n; ++i){
			for(int j=0; j<=C; ++j){
				d[i][j] = i==0 ? 0 : d[i-1][j];
				if(i>0 && j>=V[i-1])	d[i][j] = d[i-1][j-V[i-1]]+W[i-1];
				a++;
			}
		}
		printf("%d\n", d[n][C]);
		
		//输出打印方案
		int j = C;
		for(int i=n; i>0; --i){
			if(d[i][j] > d[i-1][j]){
				x[i-1] = 1;
				j = j - V[i-1];
			}
		}
		for(int i=0; i<n; ++i)	printf("%d ", x[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
