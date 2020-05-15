#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	int sum = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	int curr = 0;
	for(int i = 0;i < n;i++){
		curr += arr[i];
		if(curr >= (sum + 1) / 2)return cout << i + 1, 0;
	}
}
