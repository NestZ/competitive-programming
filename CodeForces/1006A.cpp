#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(arr[i] & 1)cout << arr[i] << ' ';
		else cout << arr[i] - 1 << ' ';
	}
}
