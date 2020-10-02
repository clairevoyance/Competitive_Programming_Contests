#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans = 0;
        if(n&1){
            ans = n/2;
            cout<<ans<<endl;
            continue;
        }else{
            ll temp = n;
            ll count = 0;
            while(temp%2==0){
                temp/=2;
                count++;
            }
            ll i = pow(2,count+1);;
            ans = (n/i);
            cout<<ans<<endl;
            
        }
    }
    return 0;
}