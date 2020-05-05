#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 0;i < (1 << n);i++){
		int curr = 0;
		for(int j = 0;j < n;j++){
			if(i  & (1 << j))curr += arr[j];
			else curr -= arr[j];
			curr = (curr + 360) % 360;
		}
		if(curr == 0)return cout << "YES", 0;
	}
	cout << "NO";
}
