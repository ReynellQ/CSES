#include<bits/stdc++.h>
using namespace std;

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
#define matrix vector<vector<ll>>

const int MOD = 1000000007;
const int D = 2;
//a = {M, N}, b = {N, P}, c = {M, P}
matrix mult(matrix &a, matrix &b){
    
    int M = a.size();
    int N = a[0].size();
    int P = b[0].size();
    matrix c(M, vector<ll>(P));
    for (int i = 0; i < M; i++) { 
        for (int j = 0; j < P; j++) { 
            c[i][j] = 0; 
            for (int k = 0; k < N; k++) { 
                c[i][j] =(c[i][j] + a[i][k] * b[k][j])%MOD; 
            }
        }
    } 
    return c;
}
matrix identity(int n){
    matrix c(n, vector<ll>(n));
    for(int i = 0 ; i < n ; ++i) c[i][i] = 1;
    return c;
}
matrix p(matrix &a, ll n){
    if(n == 0){
        return identity(a.size());
    }
    if(n == 1){
        return a;
    }
    if(n % 2 != 0){
        matrix c = p(a, n - 1);
        return mult(a, c);
    }
    matrix c = p(a, n/2);
    return mult(c, c);
}

ll fibo(ll n){
    matrix a = {
        {1},
        {1},
        {2},
        {4},
        {8},
        {16}
    };
    matrix base = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1},
    };
    matrix result = p(base, n);
    result = mult(result, a);
    return result[0][0];
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll n; cin >> n;
    cout << fibo(n) << "\n";
    
    return 0;
}
