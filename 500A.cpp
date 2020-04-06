#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, t;cin >> n >> t;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	for(int i = 1;i <= n;){
		if(i == t)return cout << "YES", 0;
		if(i == n)break;
		i += arr[i - 1];
	}
	cout << "NO";
}
