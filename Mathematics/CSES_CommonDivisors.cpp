#include <bits/stdc++.h>
#define INF INT_MAX
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

using namespace std;

const int MAX_X = 1000001;
int m[MAX_X];
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin >> n;
    int x;
    for(int i = 0 ; i < n ; ++i){
        cin >>x;
        m[x]++;
    }
    int res = 0;
    for(int i = 1 ; i < MAX_X ; ++i){
        int count = 0;
        for(int j = i ; j < MAX_X; j+=i){
            if(m[j])
                count+=m[j];
        }
        if(count > 1)
            res = i;
    }
    cout << res;
    return 0;
}