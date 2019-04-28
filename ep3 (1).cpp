#include<iostream>
using namespace std;
int main(){
char  initial,accept,inter;
string ips;
int i,j,r,c,cn=0;
cout<<"Enter row & column: ";
cin>>r>>c;
char s[r][c];
cout<<"Enter table  :-";
for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        cin>>s[i][j];
    }
}
cout<<"enter initial state :- ";
cin>>initial;
cout<<"enter accepting state :- ";
cin>>accept;
cout<<"enter string :- ";
cin>>ips;
for(i=0;i<ips.length();i++){
 if(ips[i]=='0' || ips[i]=='1'){
    cn++;
 }
}
if(cn==ips.length()){
 inter=initial ;
for(i=0;i<(ips.length());i++){
   for(j=0;j<r;j++)
    {
      if(s[j][0]==inter && s[j][1]==ips[i]){
            inter=s[j][2];
        }
    }
}
if(inter==accept){
    cout<<"string is valid.";
}
else{
    cout<<"string is invalid.";
}
}
else{
    cout<<"String is not in 01 format ";
}
return 0;
}
