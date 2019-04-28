#include<iostream>
using namespace std;
class array
{
    public:
    double *d;
    int len;
    void getdata()
    {
        cout<<"enter no of terms\n";
        cin>>len;
        d=new double[len];
        cout<<"enter "<<len<<" numbers\n";
        for(int i=0;i<len;i++)
        {
            cin>>d[i];
        }
    }
    void putdata()
    {
        for(int i=0;i<len;i++)
        {
            cout<<d[i]<<" ";
        }
    }
    friend ostream & operator <<(ostream & ccout,array & obj);
    friend istream & operator >>(istream & ccin,array & obj);
    friend int operator ==(array a,array b);
    friend int operator !=(array a,array b);
    void operator =(array a)
    {
        d=a.d;
        len=a.len;
    }
};


int operator ==(array a,array b)
{
    int flag =1;
    if(a.len==b.len)
    {
        for(int i=0;(i<a.len)&&(flag==1);i++)
        {
            if((a.d[i])!=(b.d[i]))
            {
                flag=0;
            }

        }
        if(flag==1)
        {
            return 1;
        }
        else if(flag==0)
        {
            return 0;
        }
    }
    else
        {return 0;}
}




int operator !=(array a,array b)
{
    int flag =1;
    if(a.len==b.len)
    {
        for(int i=0;(i<a.len)&&(flag==1);i++)
        {
            if((a.d[i])!=(b.d[i]))
            {
                flag=0;
            }

        }
        if(flag==1)
        {
            return 0;
        }
        else if(flag==0)
        {
            return 1;
        }
    }
    else
        {return 1;}
}






ostream & operator <<(ostream & ccout,array & obj)
{
ccout<<"\n Entered Array is:\n";
for(int i=0;i<obj.len;i++)
        {
           ccout<<obj.d[i]<<" ";
        }

return ccout;
}





istream & operator >>(istream & ccin,array & obj)
{
        cout<<"enter no of terms\n";
        cin>>obj.len;
        obj.d=new double[obj.len];
        cout<<"enter "<<obj.len<<" numbers\n";
        for(int i=0;i<obj.len;i++)
        {
            cin>>obj.d[i];
        }
        return ccin;
}






int main()
{
    int choice;
    array a;
    array b;
    start:
        cout<<"1. == operator for array comparision\n";
        cout<<"2. != operator for array comparision\n";
        cout<<"3. for subscript operator\n";
        cout<<"4. = operator to copy array\n";
        cout<<"0. to end the program\n";
        cin>>choice;




        switch(choice)
        {
        case 1:
            {
                cin>>a;
                cin>>b;
                if(a!=b)
                {
                    cout<<"a is not equal to b"<<endl;
                }
                else
                {
                    cout<<"a is equal to b"<<endl;
                }
                break;
            }
        case 2:
            {
                 cin>>a;
                cin>>b;
                if(a==b)
                {
                    cout<<"a is equal to b"<<endl;
                }
                else
                {
                    cout<<"a is not equal to b"<<endl;
                }
                break;
            }
        case 3:
            {
                break;
            }
        case 4:
            {
                cin>>a;
                b=a;
                cout<<"a is\n";
                cout<<a;
                cout<<"b is\n";
                cout<<b;
            }

            }
            if(choice!=0)
            {
                goto start;
            }

}

