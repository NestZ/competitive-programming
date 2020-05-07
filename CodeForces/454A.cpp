#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	for(int i = 0;i < n / 2;i++){
		for(int j = 0;j < n;j++){
			if(j >= n / 2 - i && j <= n / 2 + i)cout << "D";
			else cout << "*";
		}
		cout << endl;
	}
	for(int i = 0;i < n;i++)cout << "D";
	cout << endl;
	for(int i = 0;i < n / 2;i++){
		for(int j = 0;j < n;j++){
			if(j > i && j < n - i - 1)cout << "D";
			else cout << "*";
		}
		cout << endl;
	}
}
