#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll p[n];
        ll initial_revenue = 0,final_revenue = 0;
        for(ll i=0;i<n;i++){
            cin>>p[i];
            initial_revenue+=p[i];
            if(p[i]>k){
                final_revenue+=k;
            }else{
                final_revenue+=p[i];
            }
        }
        cout<<(initial_revenue-final_revenue)<<endl;

    }
    return 0;
}