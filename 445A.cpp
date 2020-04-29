#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<vector<char>> arr(n, vector<char>(m));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0;i < n;i++){
		int curry = i % 2;
		for(int j = 0;j < m;j++){
			int currx = j % 2;
			if(arr[i][j] != '.'){
				cout << arr[i][j];
				continue;
			}
			if((currx + curry) & 1)cout << 'B';	
			else cout << 'W';
		}
		cout << endl;
	}
}
