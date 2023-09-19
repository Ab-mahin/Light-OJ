// USER: "Ab.Mahin"
// Problem: Harmonic Number
// Contest: LightOJ
// URL: https://lightoj.com/problem/harmonic-number
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
const ll N = 2e5 + 5;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 0;
    
    cin >> t;
	double ans[t];
	
	vector<pair<ll, ll>> v; 
	
    while(t--){
        ll n;
        cin >> n;
        v.push_back({n, tt++});
    }
    
    sort(v.begin(), v.end());
    
    double res = 0;
    
    for(ll i = 1, j = 0; i <= 1e8; i++){
    	res += (1.0 / i);
    	while(j < tt && i == v[j].first){
    		ans[v[j].second] = res;
    		j++;
    	}
    }
        
    for(ll i = 0; i < tt; i++){
    	cout << fixed << setprecision(10) << "Case " << i + 1 << ": " << ans[i] << '\n';
    }
    
    return 0;
}