#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 2000000000000000000LL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

/*
  Author: Junior Andrade
*/ 

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}



int main() {
  while(1) {
    ll n, n1, c1, n2, c2;
    scanf("%lld", &n);
    if(!n) break;
    scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);
    ll q1, q2, best;
    best = LINF;
    for(int i = 0; i < 1000000; ++i) {
      ll x1 = 1LL * i * n1;
      if( x1 <= n && (n - x1) % n2 == 0 ) {
        ll j = (n - x1) / n2;
        ll cost = i * c1 + j * c2;
        if( cost < best ) {
          best = cost;
          q1 = i;
          q2 = j;
        }
      }
      ll x2 = i * n2;
      if( x2 <= n && (n - x2) % n1 == 0 ) {
        ll j = (n - x2) / n1;
        ll cost = i * c2 + j * c1;
        if( cost < best ) {
          best = cost;
          q1 = j;
          q2 = i;
        }
      }
    }
    if( best == LINF ) puts("failed");
    else printf("%lld %lld\n", q1, q2);
  }
  return 0;
}
