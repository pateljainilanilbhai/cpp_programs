#include<iostream>
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
int main()
{
    int choice;
    cout<<"enter 1 for addition:\nenter 2 for subtraction:\nenter 3 for += operation:\nenter 4 for -= operation:\n "<<endl;
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
    }//switch ends
}
