#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> arr(3, vector<int>(3));
	vector<int> a(3);
	vector<int> b(3);
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			cin >> arr[i][j];
		}
	}
	a[0] = 0;
	b[0] = arr[0][0];
	a[1] = arr[1][0] - b[0];
	a[2] = arr[2][0] - b[0];
	b[1] = arr[0][1] - a[0];
	b[2] = arr[0][2] - a[0];
	bool flag = true;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(arr[i][j] != a[i] + b[j])flag = false;
		}
	}
	if(flag)cout << "Yes";
	else cout << "No";
	cout << endl;
}
