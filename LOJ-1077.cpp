// USER: "Ab.Mahin"
// Problem: How Many Points?
// Contest: LightOJ
// URL: https://lightoj.com/problem/how-many-points
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
const ll N = 2e5 + 5;


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
	
    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        
        vector<pair<ll, ll>> v;
        
        v.push_back({a, b});
        v.push_back({c, d});
        
        if(v[0] > v[1]){
        	swap(v[0], v[1]);
        }
        
        a = v[0].first;
        b = v[0].second;
        c = v[1].first - a;
        d = v[1].second - b;

		a = 0, b = 0;
		
		ll ans = __gcd(abs(c), abs(d)) + 1;
        cout << "Case " << tt++ << ": " << ans << '\n';
    }
    
    
    return 0;
}