#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int fi = 0;
	int fj = 0;
	vector<vector<char>> arr(n, vector<char>(m));
	bool fo = false;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> arr[i][j];
			if(!fo && arr[i][j] == 'B'){
				fj = j;
				fi = i;
				fo = true;
			}
		}
	}
	int w = 0;
	int h = 0;
	for(int i = fi;i < n;i++){
		if(arr[i][fj] == 'B')h++;
	}
	for(int j = fj;j < m;j++){
		if(arr[fi][j] == 'B')w++;
	}
	cout << fi + h / 2 + 1 << ' ' << fj + w / 2 + 1;
}
