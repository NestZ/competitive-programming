#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	for(int i = 0;i < n + 1;i++){
		for(int j = 0;j < 2 * n + 1;j++){
			if(j > n + i)break;
			if(j == n + i)cout << "0";
			else if(j == n - i)cout << "0 ";
			else if(j < n + i && j > n - i)cout << min(abs(j - n - i), abs(j - n + i)) << " ";
			else cout << "  ";
		}
		cout << endl;
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 2 * n + 1;j++){
			if(j > 2 * n - i - 1)break;
			if(j == 2 * n - i - 1)cout << "0";
			else if(j == i + 1)cout << "0 ";
			else if(j > i + 1 && j < 2 * n - i - 1)cout << min(abs(j - i - 1), abs(j - (2 * n - i - 1))) << " ";
			else cout << "  ";
		}
		cout << endl;
	}
}
