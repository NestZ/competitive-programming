#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
double dp[101][101][101];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;cin >> a >> b >> c;
	for(int i = 0;i <= 100;i++)
		for(int j = 0;j <= 100;j++)
			for(int k = 0;k <= 100;k++)
				if(i == 100 || j == 100 || k == 100)dp[i][j][k] = 0;
	for(int i = 99;i >= 0;i--){
		for(int j = 99;j >= 0;j--){
			for(int k = 99;k >= 0;k--){
				double sum = i + j + k;
				if(sum == 0)continue;
				double pa = double(i) / sum;
				double pb = double(j) / sum;
				double pc = double(k) / sum;
				dp[i][j][k] = pa * (1 + dp[i + 1][j][k]) + pb * (1 + dp[i][j + 1][k]) + pc * (1 + dp[i][j][k + 1]);
			}
		}
	}
	printf("%.10f\n", dp[a][b][c]);
}
