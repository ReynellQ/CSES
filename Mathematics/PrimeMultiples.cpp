#include<bits/stdc++.h>
using namespace std;

#define MINF INT_MIN
#define ll long long
#define PB push_back 
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)

const ll INF = 2e18 ;
ll n;
int k;

ll intersection(ll n, ll primes){
    return n/primes;
}
ll inclusionExclusion(int pos, int l, vector<ll>&a, ll prod){
    ll res = 0ll;
    for( ; pos < k ; ++pos){
        ll p;
        if(prod == INF || INF/a[pos] < prod){
            p = INF;
        }else{
            p = prod*a[pos];
        }
        res+= (l % 2 ? 1 : -1)*intersection(n, p) + 
            inclusionExclusion(pos + 1, l + 1, a, p);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> k;
    vector<ll> a(k);
    for(int i = 0 ; i < k ; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    ll res = inclusionExclusion(0, 1, a, 1);
    cout << res << "\n";
    return 0;
}
