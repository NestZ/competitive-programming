#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> a;
	vector<int> b;
	vector<int> arr;
	for(int i = 1;i <= n * n;i++)arr.push_back(i);
	for(int i = 0;i < n * n / 2;i++){
		if(i <= n * n / 4){
			a.push_back(arr[i]);
			a.push_back(arr[n * n - i - 1]);
		}
		else{
			b.push_back(arr[i]);
			b.push_back(arr[n * n - i - 1]);
		}
	}
	for(int i : a)cout << i << ' ';
	cout << endl;
	for(int i : b)cout << i << ' ';
}
