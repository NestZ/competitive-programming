#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<vector<int>> arr(2, vector<int>(n));
	for(int i = 0;i < 2;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];
	for(int i = 0;i < 2;i++){
		for(int j = 0;j < n;j++){
			int cur = arr[i][j];
			if(j - 1 >= 0)
				arr[i][j] = max(arr[i][j], arr[i][j - 1] + cur);
			if(i - 1 >= 0)
				arr[i][j] = max(arr[i][j], arr[i - 1][j] + cur);
		}
	}
	cout << arr[1][n - 1] << endl;
}
