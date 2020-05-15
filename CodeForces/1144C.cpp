#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> a;
	vector<int> b;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	for(int i = 0;i < n;i++){
		if(i == 0){
			a.push_back(arr[i]);
		}
		else{
			if(arr[i] == arr[i - 1])b.push_back(arr[i]);
			else a.push_back(arr[i]);
		}
	}
	int k = b.size();
	for(int i = 1;i < k;i++){
		if(b[i] == b[i - 1])return cout << "NO", 0;
	}
	cout << "YES" << endl;
	cout << a.size() << endl;
	for(int i : a)cout << i << ' ';
	cout << endl;
	reverse(b.begin(), b.end());
	cout << b.size() << endl;
	for(int i : b)cout << i << ' ';
}
