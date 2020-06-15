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
	set<int> s;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i == j)continue;
			if(arr[i][j] == 1 || arr[i][j] == 3)s.insert(i);
		}
	}
	cout << n - s.size() << endl;
	for(int i = 0;i < n;i++)if(s.count(i) == 0)cout << i + 1 << ' ';
}
