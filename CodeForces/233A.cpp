#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> arr(n);
	if(n & 1)return cout << -1, 0;
	for(int i = 0;i < n;i++)arr[i] = i + 1;
	for(int i = 0;i < n;i+=2){
		swap(arr[i], arr[i + 1]);
	}
	for(int i : arr)cout << i << ' ';
}
