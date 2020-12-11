#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<int> arr(n);
	vector<int> s(n);
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		arr[i] = t;
		s[i] = t;
	}
	sort(s.begin(), s.end());
	int mn = n / 2 - 1;
	int mx = n / 2;
	for(int i = 0;i < n;i++){
		if(arr[i] <= s[mn])cout << s[mx];
		else if(arr[i] >= s[mx])cout << s[mn];
		cout << endl;
	}
}
