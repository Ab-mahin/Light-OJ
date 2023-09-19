// USER: "Ab.Mahin"
// Problem: Trailing Zeroes (II)
// Contest: LightOJ
// URL: https://lightoj.com/problem/trailing-zeroes-ii
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007


template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cout.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 1e6 + 5;

struct {
	ll a = 0, b = 0;
}fac[N];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    cin >> t;
    
    for(ll i = 1; i < N; i++){
    	ll x = i;
    	
    	fac[i].a = fac[i - 1].a; 
    	fac[i].b = fac[i - 1].b;   	
    	while(x % 2 == 0){
    		fac[i].a++;
    		x /= 2;
    	}
    	while(x % 5 == 0){
    		fac[i].b++;
    		x /= 5;
    	}
    }
	
    while(t--){
        ll n, r, p, q;
        cin >> n >> r >> p >> q;
        ll x = (n - r);
                
        ll cnt = 0, crt = 0;
        while(p % 2 == 0){
        	p /= 2;
        	cnt++;
        }
        
        while(p % 5 == 0){
        	p /= 5;
        	crt++;
        }
        
        ll d = max(0ll, ((fac[n].a + (cnt * q)) - (fac[r].a + fac[x].a)));
        ll e = max(0ll, ((fac[n].b + (crt * q)) - (fac[r].b + fac[x].b)));
        
        cout << "Case " << tt++ << ": " << min(d, e) << '\n';
               
    }
    
    
    return 0;
}