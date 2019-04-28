#include<iostream>
#include<math.h>
using namespace std;
class shape
{
    public:
    double area();
    double volume();
    double perimeter();
    double are;
    double perimete;
    double volum;

};
class twodimensionalshape:public shape
{
public:
    double r;
    double h;
    double l;
    double w;
    double b;
    double a;
    double c;
    void display()
    {
        cout<<"\nperimeter is "<<perimete;
        cout<<"\narea is "<<are;
    }

};
class threedimensionalshape:public shape
{
public:
    double r;
    double l;
    void display()
    {
        cout<<"\narea is "<<are;
        cout<<"\nvolume is "<<volum;
    }
};
class circle:public twodimensionalshape
{
    public:
    void getdata()
    {
        cout<<"enter radius of circle:";
        cin>>r;
    }
    double perimeter()
    {
        perimete=2*3.14*r;
        return perimete;
    }
    double area()
    {
        are=3.14*r*r;
        return are;
    }


};
class square:public twodimensionalshape
{
      public:

    void getdata()
    {
      cout<<"enter length of side of square";
      cin>>l;
    }
    double perimeter()
    {
        perimete=4*l;
        return perimete;
    }
    double area()
    {
        are=l*l;
        return are;
    }
};
class triangle:public twodimensionalshape
{
  public:
    void getdata()
    {
      cout<<"enter side a";
      cin>>a;
      cout<<"enter side b";
      cin>>b;
      cout<<"enter side c";
      cin>>c;
    }
    double perimeter()
    {
        perimete=a+b+c;
        return perimete;
    }
    double area()
    {
        int s;
        s=(a+b+c)/2.0;
        are=sqrt(s*(s-a)*(s-b)*(s-c));
        return are;
    }
};
class sphere:public threedimensionalshape
{
      public:
    void getdata()
    {
        cout<<"enter radius of circle:";
        cin>>r;
    }
    double volume()
    {
       volum=(4.0/3.0)*3.14*r*r*r;
    }
    double area()
    {
        are=4*3.14*r*r;
        return are;
    }
};
class tetrahedron:public threedimensionalshape
{
      public:
    void getdata()
    {
        cout<<"enter edge of tetrahedron";
        cin>>l;
    }
    double volume()
    {
       volum=l*l*l/(6.0*sqrt(2));
    }
    double area()
    {
        are=l*l*sqrt(3);
        return are;
    }
};
class cube:public threedimensionalshape
{
    public:
    void getdata()
    {
        cout<<"enter edge of cube";
        cin>>l;
    }
    double volume()
    {
       volum=l*l*l;
    }
    double area()
    {
        are=6.0*l*l;
        return are;
    }
};
int main()
{
    double a;
    double p;
    double v;
    int choice;
    cout<<"enter 1 for circle:\nenter 2 for square:\nenter 3 for triangle:\nenter 4 for sphere:\nenter 5 for cube:\nenter 6 for tetrahedron:\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        {
            circle c;
            c.getdata();
            a=c.area();
            p=c.perimeter();
            c.display();
            break;
        }
    case 2:
        {
            square s;
            s.getdata();
            a=s.area();
            p=s.perimeter();
            s.display();
             break;
        }
    case 3:
        {
            triangle t;
            t.getdata();
            a=t.area();
            p=t.perimeter();
            t.display();
             break;
        }
    case 4:
        {
            sphere s;
            s.getdata();
            v=s.volume();
            p=s.area();
            s.display();
             break;
        }
    case 5:
        {
            cube c;
            c.getdata();
            v=c.volume();
            p=c.area();
            c.display();
             break;
        }
    case 6:
        {
            tetrahedron t;
            t.getdata();
            v=t.volume();
            p=t.area();
            t.display();
             break;
        }
    }
}
