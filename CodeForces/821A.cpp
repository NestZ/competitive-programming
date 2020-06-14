#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];
	bool flag = true;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(arr[i][j] == 1)continue;
			bool f = false;
			for(int k = 0;k < n;k++){
				for(int l = 0;l < n;l++){
					if(arr[k][j] + arr[i][l] == arr[i][j])f = true;
				}
			}
			if(!f)flag = false;
		}
	}
	if(flag)cout << "Yes";
	else cout << "No";
}
