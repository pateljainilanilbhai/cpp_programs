#include<iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
class term
{
    public:
    int coef;
    int exp;
    term operator+(term t2)
    {
        term t3;
        t3.coef=coef+t2.coef;
        return t3;
    }


    term operator-(term t2)
    {
        term t3;
        t3.coef=coef-t2.coef;
        return t3;
    }

};
class polynomial
{
public:
int d;
term *t;

polynomial()
{

}

    polynomial(int s)
    {

       d=s;
        t=new term[d+1];
        for(int i=d;i>=0;i--)
        {
            t[i].exp=i;
        }
    }

    void getdata()
    {
        cout<<"enter coefficients "<<endl;
         for(int i=d;i>=0;i--)
        {
            int a;
            cin>>a;
            t[i].coef=a;
        }

    }
    void putdata()
    {
        for(int i=d;i>=0;i--)
        {
            cout<<t[i].coef<<"x^"<<t[i].exp;
            if(i>0)
            {
                cout<<" + ";
            }
        }
    }
    polynomial operator +(polynomial p2)
    {
    int q;
    if(d>p2.d)
    {
        q=d;
    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);
    if(d>p2.d)
    {
        for(int i=q;i>=q-p2.d;i--)
        {
                    p3.t[i].coef=t[i].coef;
        }
    for(int i=q-p2.d;i>=0;i--)
    {
        p3.t[i].coef=t[i].coef+p2.t[i].coef;
    }
    }
    else
    {
       for(int i=q;i>=p2.d-q;i--)
        {
                    p3.t[i].coef=p2.t[i].coef;
        }
        for(int i=p2.d-q+1;i>=0;i--)
        {
            p3.t[i].coef=t[i].coef+p2.t[i].coef;
        }
    }
    return p3;

}
polynomial operator -(polynomial p2)
    {
    int q;
    if(d>p2.d)
    {
        q=d;
    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);
    if(d>p2.d)
    {
        for(int i=q;i>=q-p2.d;i--)
        {
                    p3.t[i].coef=t[i].coef;
        }
    for(int i=q-p2.d;i>=0;i--)
    {
        p3.t[i].coef=t[i].coef-p2.t[i].coef;
    }
    }
    else
    {
       for(int i=q;i>=p2.d-q;i--)
        {
                    p3.t[i].coef=p2.t[i].coef;
        }
        for(int i=p2.d-q+1;i>=0;i--)
        {
            p3.t[i].coef=t[i].coef-p2.t[i].coef;
        }
    }
    return p3;

}
 operator +=(polynomial p2)
{
    int q;
    if(d>p2.d)
    {
        q=d;
    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);
    if(d>p2.d)
    {
        for(int i=q;i>=q-p2.d;i--)
        {
                    p3.t[i].coef=t[i].coef;
        }
    for(int i=q-p2.d;i>=0;i--)
    {
        p3.t[i].coef=t[i].coef+p2.t[i].coef;
    }
    }
    else
    {
       for(int i=q;i>=p2.d-q;i--)
        {
                    p3.t[i].coef=p2.t[i].coef;
        }
        for(int i=p2.d-q+1;i>=0;i--)
        {
            p3.t[i].coef=t[i].coef+p2.t[i].coef;
        }
    }

    d=p3.d;
    t=p3.t;


}
operator -=(polynomial p2)
    {
    int q;
    if(d>p2.d)
    {
        q=d;
    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);
    if(d>p2.d)
    {
        for(int i=q;i>=q-p2.d;i--)
        {
                    p3.t[i].coef=t[i].coef;
        }
    for(int i=q-p2.d;i>=0;i--)
    {
        p3.t[i].coef=t[i].coef-p2.t[i].coef;
    }
    }
    else
    {
       for(int i=q;i>=p2.d-q;i--)
        {
                    p3.t[i].coef=p2.t[i].coef;
        }
        for(int i=p2.d-q+1;i>=0;i--)
        {
            p3.t[i].coef=t[i].coef-p2.t[i].coef;
        }
    }
    d=p3.d;
    t=p3.t;


}

};
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

};
int main()
{
    int choice;
    cout<<"enter 1 for addition:\nenter 2 for subtraction:\nenter 3 for += operation:\nenter 4 for -= operation:\nenter 5 for multiplication of two polynomials:\n"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1:
    {int d;
    cout<<"for p1 enter degree:";
    cin>>d;
    polynomial p1(d);
    p1.getdata();
    cout<<"for p2 enter degree:";
    cin>>d;
    polynomial p2(d);
    p2.getdata();


     int q;
    if(d>p2.d)
    {
        q=d;

    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);

    p3=p1+p2;
    cout<<"addition of ";
    p1.putdata();
    cout<<" and ";
    p2.putdata();
    cout<<" is \n";
    p3.putdata();
    break;
    }
    case 2:
            {
                int d;
    cout<<"for p1 enter degree:";
    cin>>d;
    polynomial p1(d);
    p1.getdata();
    cout<<"for p2 enter degree:";
    cin>>d;
    polynomial p2(d);
    p2.getdata();
    int q;
    if(d>p2.d)
    {
        q=d;

    }
    else
    {
        q=p2.d;
    }
    polynomial p3(q);

    p3=p1-p2;
    cout<<"subtraction of ";
    p1.putdata();
    cout<<" and ";
    p2.putdata();
    cout<<" is \n";
    p3.putdata();
    break;
            }

        case 3:
            {
                 int d;
    cout<<"for p1 enter degree:";
    cin>>d;
    polynomial p1(d);
    p1.getdata();
    cout<<"for p2 enter degree:";
    cin>>d;
    polynomial p2(d);
    p2.getdata();
    p1+=p2;
    cout<<"after p1+=p2\n p1 is ";
    p1.putdata();
    cout<<" and p2 is ";
    p2.putdata();
break;
            }
        case 4:
            {
                 int d;
    cout<<"for p1 enter degree:";
    cin>>d;
    polynomial p1(d);
    p1.getdata();
    cout<<"for p2 enter degree:";
    cin>>d;
    polynomial p2(d);
    p2.getdata();

    p1-=p2;
    cout<<"after p1-=p2\n p1 is ";
    p1.putdata();
    cout<<" and p2 is ";
    p2.putdata();
break;
            }
        case 5:
            {
                mul2poly obj;
                obj.mulpoly();
                obj.display();
                getch();
            }
    }//switch ends
}
