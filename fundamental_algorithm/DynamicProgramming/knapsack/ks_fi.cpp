#include <iostream>
#include <cstdio>

using namespace std;

int sv[510][100000];

int main(){
	freopen("onlineEXPL/data.in","r",stdin);
	int C,n;
	while(EOF!=scanf("%d %d",&n,&C)){
		int w[100],v[100];
		for(int i=1;i<=n;i++) scanf("%d %d",&w[i],&v[i]);

		for(int i=1;i<=n;i++){
			for(int j=0;j<=C;j++)
				if(j>=w[i]){
					sv[i][j]=max(sv[i-1][j-w[i]]+v[i],sv[i-1][j]);
				}
				else{
					sv[i][j]=sv[i-1][j];
				}
		}
		cout << sv[n][C] << endl;
	}
	return 0;
}
