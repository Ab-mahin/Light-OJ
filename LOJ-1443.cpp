// USER: "Ab.Mahin"
// Problem: Printing Divisors
// Contest: LightOJ
// URL: https://lightoj.com/problem/printing-divisors
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
const ll N = 1e5 + 5;
bitset<N> pr;
vector<ll> v;
void siv(){
	for(ll i = 2; i < N; i++){
		if(!pr[i]){
			v.push_back(i);
			for(ll j = i; j < N; j += i){
				pr[j] = 1;
			}
		}
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
        ll n;
        cin >> n;
        
        vector<ll> ans;
        ans.push_back(1);
        
        for(ll i = 0; i < v.size() && v[i] <= n; i++){
        	ll cnt = 0;
        	while(n % v[i] == 0){
        		n /= v[i];
        		cnt++;
        	}
        	vector<ll> res;
        	res = ans;
        	ll x = v[i], ck = 1;
        	while(cnt){
        		if(ck){
        			for(ll j = res.size() - 1; j >= 0; j--){
        				ans.push_back(res[j] * x);
        			}
        		}
        		else{
        			for(ll j = 0; j < res.size(); j++){
        				ans.push_back(res[j] * x);
        			}
        		}
        		cnt--;
        		ck ^= 1;
        		x *= v[i];
        	}
        }
        
        if(n != 1){
        	vector<ll> res;
        	res = ans;
        	for(ll j = res.size() - 1; j >= 0; j--){
				ans.push_back(res[j] * n);
			}
        }
        
        
        cout << "Case " << tt++ << ":\n";
        
        for(auto i : ans){
        	cout << i << ' ';
        }
        cout << '\n';
        
    }
    
    
    return 0;
}