// USER: "Ab.Mahin"
// Problem: Eid
// Contest: LightOJ
// URL: https://lightoj.com/problem/eid
// Memory Limit: 64 MB
// Time Limit: 2000 ms
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
const ll N = 1e4 + 5;
bitset<N> pr;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t = 1, tt = 1;
    cin >> t;
    vector<ll> v;
    for(ll i = 2; i < N; i++){
    	if(!pr[i]){
    		v.push_back(i);
    		for(ll j = i; j < N; j += i){
    			pr[j] = 1;
    		}
    	}
    }
    
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        
        map<ll, ll> cnt;
        
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	
        	for(ll j = 0; j < v.size() && v[j] <= a[i]; j++){
        		if(a[i] % v[j]) continue;
        		ll crt = 1;
        		while(a[i] % v[j] == 0){
        			a[i] /= v[j];
        			crt *=  v[j];
        		}
        		cnt[v[j]] = max(crt, cnt[v[j]]);
        	}
        	if(a[i] != 1) cnt[a[i]] = max(a[i], cnt[a[i]]);
        }
        
        string ans = "1";
        
        for(auto i : cnt){
        	ll c = 0;
        	string b = "", ex = "";
        	for(ll j = ans.size() - 1; j >= 0; j--){
        		c = ((ans[j] - '0') * (i.second)) + c;
        		b += to_string(c % 10);
        		c /= 10;
        	}
        	while(c){
        		b += to_string(c % 10);
        		c /= 10;
        	}
        	reverse(b.begin(), b.end());
        	ans = ex + b;
        }
        
        
        cout << "Case " << tt++ << ": " << ans << '\n';
        
    }
    
    
    return 0;
}