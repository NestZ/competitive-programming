#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	int a = arr[0] + arr[1] + arr[2];
	int b = arr[0] * arr[1] * arr[2];
	int c = (arr[0] + arr[1]) * arr[2];
	int d = arr[0] + (arr[1] * arr[2]);
	int e = (arr[0] * arr[1]) + arr[2];
	int f = arr[0] * (arr[1] + arr[2]);
	cout << max(a,max(b,max(c,max(d,max(e,f)))));
}
