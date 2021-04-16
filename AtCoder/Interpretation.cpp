#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

vector<int> sz(100010, 1);
vector<int> p(100010);

int find(int x){
  int tmp = x;
  while(tmp != p[tmp])tmp = p[tmp];
  return p[x] = tmp;
}

bool same(int a, int b){
  return find(a) == find(b);
}

void unite(int a, int b){
  if(same(a, b))return;
  a = find(a);
  b = find(b);
  if(sz[a] < sz[b])swap(a, b);
  sz[a] += sz[b];
  sz[b] = 0;
  p[b] = a;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;cin >> n >> m;
  set<int> all;
  vector<vector<int>> people;
  for(int i = 1;i <= m;i++)p[i] = i;
  for(int i = 0;i < n;i++){
    int k;cin >> k;
    vector<int> tmp;
    for(int j = 0;j < k;j++){
      int num;cin >> num;
      all.insert(num);
      if(j > 0)unite(num, tmp.back());
      tmp.push_back(num);
    }
    people.push_back(tmp);
  }
  int cnt = 0;
  for(auto v : people){
    bool flag = false;
    for(auto lan : v){
      if(sz[find(lan)] == (int)all.size()){
        flag = true;
        break;
      }
    }
    if(flag)cnt++;
  }
  if(cnt == n)cout << "YES";
  else cout << "NO";
  cout << endl;
}
