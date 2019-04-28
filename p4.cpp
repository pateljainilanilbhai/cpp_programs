#include<iostream>
#include<string.h>
using namespace std;
int main(){
int i,j,k=0,a=0,b=0,e=0,d=0,m;
string ips,table[10],toke[10],ex[10],exto[10];
char op[8]={'+','-','*','/','=','<','>','^'},s[10]={'!','@','#','$','%','&','?',',','.',';'};
string sa[10]={"!","@","#","$","%","&","?",",",".",";"};
cout<<"Enter String:- ";
cin>>ips;
int l=ips.length();
char stack1[l],c;
cout<<endl;
for(i=0;i<ips.length();i++){
    stack1[i]=ips[i];
}
for(i=0;i<ips.length();i++){
    b=0;
    c=stack1[i];
    for(m=0;m<10;m++){
        if(c==s[m]){
            table[a]+=c;
            toke[a]="Symbol";
            a++;
        }
    }
    for(j=0;j<8;j++){
        if(c==op[j]){
            table[a]+=c;
             k=0;
        while(k!=1){
                d=0;
                c=stack1[i+1];
                for(e=0;e<8;e++){
                    if(c==op[e]){
                    table[a]+=c;
                    d++;
                    i++;j++;
                    }
                }
                if(d==0){
                    k=1;
                }
            }
            toke[a]="operator";
            a++;
        }
    }
    if(isalpha(ips[i])){
      table[a]+=c;
        k=0;
        while(k!=1){
            if(isalpha(stack1[i+1])){
           table[a]+=stack1[i+1];
            i++;
            }
            else{
                k=1;
            }
        }
        toke[a]="identifiers";
        a++;
    }
}
for(m=0;m<a;m++){
d=0;
    for(i=0;i<a;i++){
            if(ex[i]==table[m]){
            d++;
            }
    }
    if(d==0){
        ex[m]=table [m];
        exto[m]=toke[m];
    }
    else{
      for(j=0;j<10;j++){
        if(table[m]==sa[j]){cout<<"in";
             ex[m]=table [m];
             exto[m]=toke[m];
        }
    }
    }
}
for(i=0;i<a;i++){
    cout<<ex[i];
    cout<<"\t "<<exto[i];
    cout<<endl;
}
return 0;
}
