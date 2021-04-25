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

bool comp(tuple<int, int, int> &a, tuple<int, int, int> &b){
  int fst_a = get<0>(a);
  int snd_a = get<1>(a);
  int fst_b = get<0>(b);
  int snd_b = get<1>(b);
  if(fst_a == fst_b)return snd_a > snd_b;
  else return fst_a < fst_b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  vector<tuple<int, int, int>> arr_b, arr_a;
  vector<int> up(n), down(n);
  for(int i = 0;i < n;i++){
    int a, b;cin >> a >> b;
    arr_b.push_back({b, a, i});
    arr_a.push_back({a, b, i});
  }
  //e increasing s decreasing
  sort(arr_b.begin(), arr_b.end(), comp);
  //s increasing e decreasing
  sort(arr_a.begin(), arr_a.end(), comp);
  int lst = 0;
  for(int i = 0;i < n;i++){
    int s = get<1>(arr_b[i]);
    int ind = get<2>(arr_b[i]);
    if(lst >= s)up[ind] = 1;
    lst = max(lst, s);
  }
  lst = 0;
  for(int i = 0;i < n;i++){
    int e = get<1>(arr_a[i]);
    int ind = get<2>(arr_a[i]);
    if(e <= lst)down[ind] = 1;
    else lst = e;
  }
  for(int i : up)cout << i << ' ';
  cout << endl;
  for(int i : down)cout << i << ' ';
  cout << endl;
}
