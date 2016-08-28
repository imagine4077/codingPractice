#include <iostream>
#include <cstdio>

using namespace std;

int sv[100100];

int main(){
	freopen("onlineEXPL/data.in","r",stdin);
	int C,n;
	while(EOF!=scanf("%d %d",&n,&C)){
		int w[100],v[100];
		for(int i=1;i<=n;i++) scanf("%d %d",&w[i],&v[i]);

		for(int i=1;i<=n;i++)
			for(int j=C;j>=0;j--)
				sv[j]= j>=w[i]?max(sv[j-w[i]]+v[i],sv[j]):sv[j];
		cout << sv[C] << endl;
	}
	return 0;
}
