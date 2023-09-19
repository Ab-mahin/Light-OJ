// USER: "Ab.Mahin"
// Problem: Leading and Trailing
// Contest: LightOJ
// URL: https://lightoj.com/problem/leading-and-trailing
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

    int t, tt;
    t = tt = 1;
    
    cin >> t;
	
    while(t--){
        int n, k;
        cin >> n >> k;
        
        double sum = 0, val = 0;
        sum = k * log10(n);
        
        val = sum - (ll)sum;
        
        int ans = (pow(10, val) * 100);
        int res = bigmod(n, k, 1000);
        
        printf("Case %d: %d %03d\n",tt++, ans, res);
    }
        
    return 0;
}