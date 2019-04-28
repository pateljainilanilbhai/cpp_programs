#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct poly{
    int coeff;
    int pow;
    poly *next;
};

class mul2poly
{
   poly *poly1, *poly2, *poly3;
   public:
   mul2poly(){poly1=poly2=poly3=NULL;}
   void mulpoly();
   void display();
};

void mul2poly :: mulpoly(){
      int i,p;
      poly *newl=NULL,*end=NULL;
      cout<<"Enter highest power for x of first polynomial \n";
      cin>>p;
    //Read first poly
      cout<<"\nFirst Polynomial\n";
      for(i=p;i>=0;i--)
      {
      newl=new poly;
      newl->pow=i;
      cout<<"Enter Co-efficient for degree"<<i<<"::  ";
      cin>>newl->coeff;
      newl->next=NULL;
      if(poly1==NULL)
         poly1=newl;
      else
         end->next=newl;
      end=newl;
      }

    //Read Second poly
        cout<<"Enter highest power for x of second polynomial \n";
      cin>>p;
      cout<<"\n\nSecond Polynomial\n";
      end=NULL;
      for(i=p;i>=0;i--)
      {
      newl=new poly;
      newl->pow=i;
      cout<<"Enter Co-efficient for degree"<<i<<"::  ";
      cin>>newl->coeff;
      newl->next=NULL;
      if(poly2==NULL)
         poly2=newl;
      else
         end->next=newl;
      end=newl;
      }

      //mul Logic
      poly *p1=poly1,*p2=poly2;
      int flag;
      end=NULL;
      while(p1 !=NULL){
    p2=poly2;
    while(p2!=NULL){
        //if(p1->pow == p2->pow){
            newl=new poly;
            newl->pow=p1->pow + p2->pow;
            newl->coeff=p1->coeff * p2->coeff;
            newl->next=NULL;
            if(poly3==NULL)
               poly3=newl;
            else{
               flag=1;

               //search if element already exist in poly3//flag will be zero if item already exist//1 otherwise
                 poly *tmp=poly3;
                 while(tmp!=NULL){
                   if(tmp->pow==newl->pow){
                    tmp->coeff += newl->coeff;
                    flag=0;
                   }
                   tmp=tmp->next;
                }

                //if item not present simply append it.if(flag==1)
                  end->next=newl;
            }
            end=newl;
            p2=p2->next;
        }
        p1=p1->next;
      }
}

void mul2poly :: display(){
   poly *t=poly3;
   cout<<"\n\nAnswer after addition is : ";
   while(t!=NULL){
      cout.setf(ios::showpos);
      cout<<t->coeff;
      cout.unsetf(ios::showpos);
      cout<<"X^"<<t->pow;
      t=t->next;
   }
}


int  main(){

    mul2poly obj;
    obj.mulpoly();
    obj.display();
    getch();
}
