// USER: "Ab.Mahin"
// Problem: Efficient Pseudo Code
// Contest: LightOJ
// URL: https://lightoj.com/problem/efficient-pseudo-code
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
const ll m = 1000000007;


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
const ll N = 1e5 + 5;
bitset<N> pr;
vector<ll> v;

void siv(){
	v.push_back(2);
	for(ll i = 3; i < N; i++){
		if(!pr[i]){
			v.push_back(i);
			for(ll j = i * i; j < N; j += (2 * i)){
				pr[j] = 1;
			}
		}
	}
}


ll bigmod(ll a, ll b, ll m){
	if(b == 0) return 1;
	if(b & 1){
		return ((a % m) * (bigmod(a, b - 1, m) % m)) % m;
	}
	else{
		ll res = bigmod(a, b / 2, m);
		return (res * res) % m;
	}
}

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
    
    siv();
	
    while(t--){
        ll n, k;
        cin >> n >> k;
        
        ll ans = 1;
        
        for(ll i = 0; i < v.size() && v[i] <= n; i++){
        	ll cnt = 0;
        	
        	while(n % v[i] == 0){
        		n /= v[i];
        		cnt++;
        	}
        	cnt = (cnt * k);
        	if(cnt){
        		ll x = bigmod(v[i], cnt + 1, m) % m;
        		ll y = bigmod(v[i] - 1, m - 2, m) % m;
        		x--;
        		x += m;
        		x %= m;        		        		
        		ans = (ans * x) % m;
        		ans = (ans * y) % m;
        	}	
        }
        
        if(n > 1){
        	ll x = bigmod(n, (k + 1), m) % m;
    		ll y = bigmod(n - 1, m - 2, m) % m;
    		x--;
    		x += m;
    		x %= m;        		        		
    		ans = (ans * x) % m;
    		ans = (ans * y) % m;
        }
        
        cout << "Case " << tt++ << ": " << ans << '\n';
    }
    
    
    return 0;
}