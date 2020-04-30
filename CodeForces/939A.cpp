#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < n;i++){
		int curr = i;
		int t = arr[curr] - 1;
		for(int j = 0;j < 2;j++){
			t = arr[t] - 1;
		}
		if(t == curr)return cout << "YES", 0;
	}
	cout << "NO";
}
