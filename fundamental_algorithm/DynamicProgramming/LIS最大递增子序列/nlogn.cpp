#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

/**
 * 1.for 循环结尾的i--,在什么时候执行?如果for中break,是否还做i--?
 * **/

using namespace std;

void update_dp(vector<int> & dp, int v);

int main(){
	FILE* fp_in;
	if((fp_in=fopen("in.txt","r"))==NULL) {perror("ERROR OPENNING in.txt");exit(1);}
	vector<int> arr;
	int buffer;
	while(EOF!=fscanf(fp_in,"%d",&buffer)) arr.push_back(buffer);

	vector<int> dp;
	for(unsigned int i=0;i<arr.size();i++) update_dp(dp,arr[i]);
	cout << "LIS size:" << dp.size()-1 << endl;
}

void update_dp(vector<int> & dp, int v){
	if(dp.size()==0) {dp.push_back(v);dp.push_back(v);} // consider of idx 0
	else{
		int i = dp.size()-1, last_idx=dp.size()-1;
		for(;i>0;i--){
			if(dp[i]<v) break;
		}
		if(i==last_idx) dp.push_back(v);
		else if(i>0&&i<last_idx) dp[i]=dp[i]<v?dp[i]:v;
		else dp[1]=dp[1]<v?dp[1]:v;
	}
}
