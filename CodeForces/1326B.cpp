#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int curr = arr[0];
	for(int i = 1;i < n;i++){
		arr[i] += curr;
		curr = max(curr, arr[i]);
	}
	for(int i : arr)cout << i << ' ';
}
