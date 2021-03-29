#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	vector<int> arr(n);
	multiset<int, greater<int>> ms;
	for(int i = 0;i < n;i++)cin >> arr[i];
	ms.insert(arr[0]);
	for(int i = 1;i < n;i++){
		auto ptr = ms.upper_bound(arr[i]);	
		if(ptr != ms.end())ms.erase(ptr);
		ms.insert(arr[i]);
	}
	cout << ms.size() << endl;
}
