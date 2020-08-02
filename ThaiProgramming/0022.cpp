#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	int r = (n % 2 == 0 ? n : n - 1);
	int c = (n % 2 == 0 ? n - 1 : n);
	for(int i = 0;i < r / 2;i++){
		for(int j = 0;j < c;j++){
			if(j == c / 2 + i || j == c / 2 - i)cout << '*';
			else cout << '-';
		}
		cout << endl;
	}
	if(n & 1){
		for(int i = 0;i < c;i++){
			if(i == 0 || i == c - 1)cout << '*';
			else cout << '-';
		}
		cout << endl;
	}
	for(int i = r / 2 - 1;i >= 0;i--){
		for(int j = 0;j < c;j++){
			if(j == c / 2 + i || j == c / 2 - i)cout << '*';
			else cout << '-';
		}
		cout << endl;
	}
}
