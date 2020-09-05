#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MAX = 1e6 + 10;
vector<int> BIT(MAX);

void add(int idx, int n){
	for(int i = idx;i <= MAX;i += (i & -i))BIT[i] += n;
}

int get(int idx){
	int res = 0;
	for(int i = idx;i > 0;i -= (i & -i))res += BIT[i];
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
