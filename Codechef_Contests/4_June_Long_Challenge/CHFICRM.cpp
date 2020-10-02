#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool ans = true;
        int five = 0,ten = 0,fifeteen = 0;
        for(int i=0;i<n;i++){
            if(a[i]==5){
                five++;
            }else if(a[i]==10){
                if(five>=1){
                    ten++;
                    five--;
                }else{
                    ans = false;
                    break;
                }
            }else if(a[i]==15){
                if(ten>=1 || five>=2){
                    if(ten>=1){
                        ten--;
                        fifeteen++;
                    }else if(five>=2){
                        five-=2;
                        fifeteen++;
                    }
                }else{
                    ans = false;
                    break;
                }
               
            }
        }
        if(ans){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }




    return 0;
}