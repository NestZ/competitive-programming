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

int n;

int get_pos(int x, bool right, int head){
  int pos = head;
  x--;
  if(right){
    pos += x;
    if(pos > n)pos = pos % n;
  } else {
    pos -= x;
    if(pos < 1)pos = pos + n;
  }
  return pos;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;cin >> n >> m;
  vector<int> arr(n + 1);
  for(int i = 1;i <= n;i++)cin >> arr[i];
  int head = 1;
  bool right = true;
  for(int i = 0;i < m;i++){
    char c;cin >> c;
    if(c == 'a') {
      int x, y;cin >> x >> y;
      x = get_pos(x, right, head);
      y = get_pos(y, right, head);
      swap(arr[x], arr[y]);
    } else if(c == 'b') {
      int x, k;cin >> x >> k;
      x = get_pos(x, right, head);
      arr[x] = k;
    } else if(c == 'c') {
      int x;cin >> x;
      head = get_pos(x, right, head);
      right = !right;
    } else {
      int x;cin >> x;
      x = get_pos(x, right, head);
      cout << arr[x] << endl;
    }
  }
}
