#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n][n];
        ll count = 1;
        for(ll i=0;i<n;i++){
            if(i%2==0){
                for(ll j=0;j<n;j++){
                    a[i][j] = count;
                    count++;
                }
            }else{
                for(ll j=n-1;j>=0;j--){
                    a[i][j] = count;
                    count++;
                }
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}