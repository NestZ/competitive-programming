#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	for(int i = 0;i < t;i++){
		int n;cin >> n;
		int trace = 0;
		int reprow = 0;
		int repcol = 0;
		vector<vector<bool>> row(n + 1, vector<bool>(n + 1, false));
		vector<vector<bool>> col(n + 1, vector<bool>(n + 1, false));
		vector<bool> rowflag(n + 1, false);
		vector<bool> colflag(n + 1, false);
		int arr[n + 1][n + 1];
		for(int j = 0;j < n;j++){
			for(int k = 0;k < n;k++){
				cin >> arr[j][k];
				if(j == k)trace += arr[j][k];
				if(row[j][arr[j][k]] && !rowflag[j]){
					reprow++;
					rowflag[j] = true;
				}
				else row[j][arr[j][k]] = true;
				if(col[k][arr[j][k]] && !colflag[k]){
					repcol++;
					colflag[k] = true;
				}
				else col[k][arr[j][k]] = true;
			}
		}
		printf("Case #%d: %d %d %d\n", i + 1, trace, reprow, repcol);
	}
}
