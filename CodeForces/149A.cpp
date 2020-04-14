#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(12);
	for(int i = 0;i < 12;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	int curr = 0;
	int cnt = 0;
	for(int i = 11;i >= 0 && curr < n;i--){
		curr += arr[i];
		cnt++;
	}
	cout << (curr < n ? -1 : cnt);
}
