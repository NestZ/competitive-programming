#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	vector<int> ans(n);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		ans[arr[i] - 1] = i + 1;
	}
	for(int i : ans)cout << i << ' ';
}
