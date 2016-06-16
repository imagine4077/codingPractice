#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>

/**
 * 1.ifstream
 * 2.getline
 * 3.fp.eof()
 * 4.perror
 * **/

using namespace std;

int main(){
	ifstream fp_in("in.txt");
	if(!fp_in) {perror("error: can't open in.txt");return 1;}
	while(!fp_in.eof()){
		string a,b;
		getline(fp_in,a);
		getline(fp_in,b);
		const int len_a=a.size()+1, len_b=b.size()+1;
		int dp[len_a][len_b];
		for(int i=0;i<len_a;i++) dp[i][0]=0;
		for(int j=0;j<len_b;j++) dp[0][j]=0;
		for(int i=1;i<len_a;i++){
			for(int j=1;j<len_b;j++){
				if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
				else if(dp[i-1][j]>=dp[i][j-1]) dp[i][j]=dp[i-1][j];
				else dp[i][j]=dp[i][j-1];
			}
		}
		cout <<"LCS: "<< dp[len_a-1][len_b-1]<<endl;
	}
	return 0;
}
