/*
ID: nestz
LANG: C++14
TASK: combo
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;

int p_mod(int num, int p){
	for(int i = 0;i < p;i++){
		num++;
		if(num > n)num = 1;
	}
	return num;
}

int m_mod(int num, int m){
	for(int i = 0;i < m;i++){
		num--;
		if(num == 0)num = n;
	}
	return num;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("combo.out", "w", stdout);
	freopen("combo.in", "r", stdin);
	
	cin >> n;
	set<tuple<int, int, int>> valid;
	for(int i = 0;i < 2;i++){
		set<int> pos1;
		set<int> pos2;
		set<int> pos3;
		int a, b, c;cin >> a >> b >> c;
		pos1.insert(a);
		pos1.insert(p_mod(a, 1));
		pos1.insert(p_mod(a, 2));
		pos1.insert(m_mod(a, 1));
		pos1.insert(m_mod(a, 2));
		pos2.insert(b);
		pos2.insert(p_mod(b, 1));
		pos2.insert(p_mod(b, 2));
		pos2.insert(m_mod(b, 1));
		pos2.insert(m_mod(b, 2));
		pos3.insert(c);
		pos3.insert(p_mod(c, 1));
		pos3.insert(p_mod(c, 2));
		pos3.insert(m_mod(c, 1));
		pos3.insert(m_mod(c, 2));
		for(int j : pos1){
			for(int k : pos2){
				for(int l : pos3){
					valid.insert(make_tuple(j, k, l));
				}
			}
		}
	}
	cout << valid.size() << endl;
}
