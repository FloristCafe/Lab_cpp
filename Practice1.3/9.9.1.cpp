#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
   vector<long long> a(n);
   for(int i=0;i<n;i++){
    cin>>a[i];

   }
   long long ans=0;
   for(int mask=0;mask<(1<<n);mask++){
    long long val=0;
    int idx=1;
    for(int j=0;j<n;j++){
    if(mask>>j & 1){
        val+=idx*a[j];
        idx++;
    }
   }
   ans ^=val;
}
   cout<<ans<<endl;
   return 0;
}