#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
	FILE* fp_in = fopen("in.txt","r");
	if(fp_in==NULL) {perror("ERROR OPENNING in.txt");exit(1);}
	int tmp;
	vector<int> arr;
	while(EOF!=fscanf(fp_in,"%d",&tmp)) arr.push_back(tmp);

	vector<int> dp(arr.size(),1);
	int max_seq = 0;

	for(unsigned int i=1;i<arr.size();i++){
		int tmp_m = 0;
		for(unsigned int j=0;j<i;j++){
			if(arr[j]<arr[i]&&tmp_m<(dp[j]+1)) tmp_m = 1+dp[j];
		}
		dp[i]=tmp_m;
		max_seq = max_seq>tmp_m?max_seq:tmp_m;
	}
	cout << "LIS size:" << max_seq << endl;
}
