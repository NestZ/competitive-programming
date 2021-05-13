/*
ID: nestz
LANG: C++14
TASK: word
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("word.out", "w", stdout);
	freopen("word.in", "r", stdin);

	int n, k;cin >> n >> k;
	vector<string> arr(n);
	for(int i = 0;i < n;i++)cin >> arr[i];
	int cur = 0;
	int ptr = 0;
	for(int i = 0;i < n;i++){
		if(cur + (int)arr[ptr].length() <= k){
			if(cur != 0)cout << ' ';
			cout << arr[ptr];
			cur += arr[ptr].length();
		}
		else{
			cout << endl;
			cout << arr[ptr];
			cur = arr[ptr].length();
		}
		ptr++;
	}
	cout << endl;
}
