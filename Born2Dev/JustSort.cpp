#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 5;
	vector<int> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	sort(arr.rbegin(), arr.rend());
	for(int i = 0;i < n;i++)cout << arr[i] << endl;
}
