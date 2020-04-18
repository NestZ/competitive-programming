#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<bool> arr(55, true);

void is(){
	arr[1] = false;
	arr[2] = false;
	for(int i = 2;i < 55;i++){
		for(int j = 2;i * j < 55;j++){
			arr[i * j] = false;
		}
	}
}

int next(int n){
	for(int i = n + 1;;i++){
		if(arr[i])return i;
	}
}

int main(){
	is();
	int a, b;cin >> a >> b;
	if(next(a) == b)cout << "YES";
	else cout << "NO";
}
