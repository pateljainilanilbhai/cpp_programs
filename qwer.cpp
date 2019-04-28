#include <cstdlib>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<conio.h>
#include<cmath>
#include<cstring>
#include<iomanip>
#include <complex>
using namespace std;
const double PI = 3.14159265358979323846;
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}




void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}
bool solveQuadratic(double &a, double &b, double &c, double &root)
{
	if(a == 0.0 || abs(a/b) < 1.0e-6)
	{
		if(abs(b) < 1.0e-4)
			return false;
		else
		{
			root = -c/b;
			return true;
		}
	}

	double discriminant = b * b - 4.0 * a * c;
	if(discriminant >= 0.0)
	{
		discriminant = sqrt(discriminant);
		root = (b + discriminant) * -0.5 / a;
		return true;
	}

	return false;
}
bool solveCubic(double &a, double &b, double &c, double &d, double &root)
{
	if(a == 0.0 || abs(a/b) < 1.0e-6)
		return solveQuadratic(b, c, d, root);

	double B = b, C = c/a, D = d/a;

	double Q = (B*B - C*3.0)/9.0, QQQ = Q*Q*Q;
	double R = (2.0*B*B*B - 9.0*B*C + 27.0*D)/54.0, RR = R*R;

	// 3 real roots
	if(RR<QQQ)
	{
        /* This sqrt and division is safe, since RR >= 0, so QQQ > RR,    */
        /* so QQQ > 0.  The acos is also safe, since RR/QQQ < 1, and      */
        /* thus R/sqrt(QQQ) < 1.                                     */
        double theta = acos(R/sqrt(QQQ));
        /* This sqrt is safe, since QQQ >= 0, and thus Q >= 0             */
		double r1, r2, r3;
        r1 = r2 = r3 = -2.0*sqrt(Q);
        r1 *= cos(theta/3.0);
        r2 *= cos((theta+2*PI)/3.0);
        r3 *= cos((theta-2*PI)/3.0);

        r1 -= B/3.0;
        r2 -= B/3.0;
        r3 -= B/3.0;

		root = 1000000.0;

		if(r1 >= 0.0) root = r1;
		if(r2 >= 0.0 && r2 < root) root = r2;
		if(r3 >= 0.0 && r3 < root) root = r3;

        return true;
	}
	// 1 real root
	else
	{
        double A2 = -pow(fabs(R)+sqrt(RR-QQQ),1.0/3.0);
        if (A2!=0.0) {
			if (R<0.0) A2 = -A2;
			root = A2 + Q/A2;
		}
        root -= B/3.0;
        return true;
	}
}

bool solveQuartic(double &a, double &b, double &c, double &d, double &e, double &root)
{
	// When a or (a and b) are magnitudes of order smaller than C,D,E
	// just ignore them entirely.
	if(a == 0.0 || abs(a/b) < 1.0e-6 || abs(a/c) < 1.0e-6)
		return solveCubic(b, c, d, e, root);

	// Uses Ferrari's Method
	double aa = a*a, aaa=aa*a, bb=b*b, bbb=bb*b;
	double alpha = -3.0*bb/(8.0*aa)   + c/a, alpha2 = alpha * alpha;
	double beta  =    bbb/(8.0*aaa) + b*c/(-2.0*aa) + d/a;
	double gamma = -3.0*bbb*b/(256.0*aaa*a) + c*bb/(16.0*aaa) + b*d/(-4.0*aa) + e/a;

	if(beta == 0.0)
	{
		root = b/(-4.0*a) + sqrt(0.5 * (-alpha + sqrt(alpha2 + 4.0*gamma)));
		return true;
	}
	else
	{
		std::complex<double> P = -alpha2/12.0 - gamma;
		std::complex<double> Q = -alpha2*alpha/108.0 + alpha*gamma/3.0 - beta*beta/8.0;
		std::complex<double> R = Q*0.5 + sqrt(Q*Q*0.25 + P*P*P/27.0);
		std::complex<double> U = pow(R, 1.0/3.0);
		std::complex<double> y = -5.0*alpha/6.0 - U;
		if(U != 0.0) y += P/(3.0*U);
		std::complex<double> W = sqrt(alpha + y + y);

		std::complex<double> aRoot;
		bool foundRealRoot = false;

		double firstPart = b/(-4.0*a);
		std::complex<double> secondPart = -3.0*alpha - 2.0*y;
		std::complex<double> thirdPart = 2.0*beta/W;

		aRoot = firstPart + 0.5 * (-W - sqrt(secondPart + thirdPart));
		if(abs(aRoot.imag()) < 1.0e-10 && aRoot.real() >= 0.0)
		{
			root = aRoot.real();
			foundRealRoot = true;
		}

		aRoot = firstPart + 0.5 * (-W + sqrt(secondPart + thirdPart));
		if(abs(aRoot.imag()) < 1.0e-10 && aRoot.real() >= 0.0 &&
			 (!foundRealRoot || aRoot.real() < root))
		{
			root = aRoot.real();
			foundRealRoot = true;
		}

		aRoot = firstPart + 0.5 * (W - sqrt(secondPart - thirdPart));
		if(abs(aRoot.imag()) < 1.0e-10 && aRoot.real() >= 0.0 &&
			 (!foundRealRoot || aRoot.real() < root))
		{
			root = aRoot.real();
			foundRealRoot = true;
		}

		aRoot = firstPart + 0.5 * (W + sqrt(secondPart - thirdPart));
		if(abs(aRoot.imag()) < 1.0e-10 && aRoot.real() >= 0.0 &&
			 (!foundRealRoot || aRoot.real() < root))
		{
			root = aRoot.real();
			foundRealRoot = true;
		}

		return foundRealRoot;
	}
}

long int fact(int n)
{
    long int s=1;
    for(int i=1;i<=n;i++)
    {
        s=s*i;
    }
    return s;
}

void con(int x,int y)
{
    int  a, i, t, j;

int sum=0;
 // x as the number in base-10 and x, as the destination base
a = x;
while (x >= y)
{
    t = 1;
    for (i = 0; x > y; i++)
    {
        x /= y;

    }
    cout<<x;
    for (j = 0; j < i; j++)
    {
        t *= y;
    }
    a = a - (t*x);
    x = a;
    cout<<x;
}
}
int Nz;
int lef = -1, righ = 1, dow = Nz, u = -Nz;
int next(int dir)
{
    if(dir==lef)
    {return u;}
    else if(dir==u)
    {return righ;}
   else if(dir==righ)
    {return dow;}
    else if(dir==dow)
    {return lef;}
}

void fill(int grid[])
{
  int pos = 0, dir = u;
  for (int i = 1; i <= Nz*Nz; i++)
  {
    grid[pos] = i;
    if (pos == 0 || pos == Nz - 1 || pos == Nz*(Nz - 1) || pos == Nz*Nz - 1 || grid[pos + dir] != 0)
    {
      dir = next(dir);
    }
    pos += dir;
  }
}
class date
{
    int dd,mm,yyyy;
    public:
    void getdata()
    {
    cout<<"enter date in dd mm yyyy format:";
    cin>>dd>>mm>>yyyy;
    }
    void putdata()
    {
        cout<<dd<<":"<<mm<<":"<<yyyy<<endl;
    }
    friend void swapdates(date &a,date &b)
    {
        date t;
        t=a;
        a=b;
        b=t;
    }
};
void swap(char &a,char &b)
{
    char t;
    t=a;
    a=b;
    b=t;
}

void swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
void swap(float &a,float &b)
{
    float t;
    t=a;
    a=b;
    b=t;
}
void swap(double &a,double &b)
{
    double t;
    t=a;
    a=b;
    b=t;
}

class dist
{
    float inches;
    float feet;
    public:
    void getdata()
    {
        cout<<"enter feet"<<endl;
        cin>>feet;
        cout<<"enter inches"<<endl;
        cin>>inches;
    }
    void putdata()
    {
        cout<<feet<<"'"<<inches<<"''";
    }
    void scale(dist &a,float b)
    {
        a.feet*=b;
        a.inches*=b;
    }

};
class MyString
{
public:
char *value;
int len;

MyString()
{
len=0;
value=0;
}
~MyString()
{
}
MyString(char *s)
{
len=strlen(s);
value=new char[len+1];
strcpy(value,s);
}
MyString(MyString & s)
{
len=s.len;
value=new char[len+1];
strcpy(value,s.value);
}
friend MyString operator+(MyString obj1,MyString obj2);
friend int operator==(MyString obj1,MyString obj2);
friend int operator!=(MyString obj1,MyString obj2);
friend int operator<(MyString obj1,MyString obj2);
friend int operator<=(MyString obj1,MyString obj2);
friend int operator>(MyString obj1,MyString obj2);
friend int operator>=(MyString obj1,MyString obj2);
friend istream & operator >>(istream & ccin,MyString & obj);
friend ostream & operator <<(ostream & ccout,MyString & obj);
};
//end of class defination.



ostream & operator <<(ostream & ccout,MyString & obj)
{
ccout<<"\n Entered String is:"<<obj.value<<"\n";
return ccout;
}





istream & operator >>(istream & ccin,MyString & obj)
{
char* val;
cout<<"enter string:";
cin>>val;
obj.len=strlen(val);
obj.value=new char[obj.len+1];
strcpy(obj.value,val);
return ccin;
}


MyString operator+(MyString obj1,MyString obj2)
{
MyString obj3;
obj3.len=obj1.len+obj2.len;
obj3.value=new char[obj3.len+1];
strcpy(obj3.value,obj1.value);
strcat(obj3.value,obj2.value);
return obj3;
}




int operator==(MyString obj1,MyString obj2)
{
int rel=0;
if(strcmp(obj1.value,obj2.value)==0)
{
rel=1;
}
return rel;
}



int operator<(MyString obj1,MyString obj2)
{
int rel=0;
int result=0;
rel=strcmp(obj1.value,obj2.value);
if(rel<0)
{
result=1;
}
return result;
}



int operator<=(MyString obj1,MyString obj2)
{
int rel=0;
int result=0;
rel=strcmp(obj1.value,obj2.value);
if(rel<=0)
{
result=1;
}
return result;
}




int operator>(MyString obj1,MyString obj2)
{
int rel=0;
int result=0;
rel=strcmp(obj1.value,obj2.value);
if(rel>0)
{
result=1;
}
return result;
}



int operator!=(MyString obj1,MyString obj2)
{
int rel=0;
if(strcmp(obj1.value,obj2.value)!=0)
{
rel=1;
}
return rel;
}



int operator>=(MyString obj1,MyString obj2)
{
int rel=0;
int result=0;
rel=strcmp(obj1.value,obj2.value);
if(rel>0 || rel==0)
{
result=1;
}
return result;
}


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
    term operator*(term t2)
    {
        term t3;
        t3.coef=coef*t2.coef;
        t3.exp=exp+t2.exp;
        return t3;
    }
};
class polynomial
{
public:
int d;
term *t;
polynomial()
{}
    polynomial(int s)
    {
       d=s;
        t=new term[d+1];
        for(int i=d;i>=0;i--)
        {
            t[i].exp=i;
            t[i].coef=0;
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
    for(int i=q-p2.d-1;i>=0;i--)
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
        for(int i=p2.d-q+2;i>=0;i--)
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
    for(int i=q-p2.d-1;i>=0;i--)
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
        for(int i=p2.d-q+2;i>=0;i--)
        {
            p3.t[i].coef=t[i].coef-p2.t[i].coef;
        }
    }
    return p3;

}
 void operator +=(polynomial p2)
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
void operator -=(polynomial p2)
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
polynomial operator *(polynomial p2)
{
    int x;
    x=d+p2.d;
    polynomial p3(x);
    for(int i=d;i>=0;i--)
    {
        for(int j=p2.d;j>=0;j--)
        {
            p3.t[i+j]=p3.t[i+j]+(t[i]*p2.t[j]);
        }
    }
    return p3;
}
void operator *=(polynomial p2)
{
    int x;
    x=d+p2.d;
    polynomial p3(x);
    for(int i=d;i>=0;i--)
    {
        for(int j=p2.d;j>=0;j--)
        {
            p3.t[i+j]=p3.t[i+j]+(t[i]*p2.t[j]);
        }
    }
    d=p3.d;
    t=p3.t;
}
};
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
    start:
    int choice;
    array a;
    array b;
    cout<<"\n1. create a file"<<endl;
    cout<<"2. display content of file"<<endl;
    cout<<"3. write content in a file"<<endl;
    cout<<"4. update the content of file"<<endl;
    cout<<"5. copy file content"<<endl;
    cout<<"6. delete file permanently from storage"<<endl;
    cout<<"7. to count number of cbaracters in file"<<endl;
    cout<<"8. to write array of double in binary file"<<endl;
    cout<<"9. to read array of double from binary file"<<endl;
    cout<<"11. shut down all programs running now"<<endl;
    cout<<"12. Restart the computer"<<endl;
    cout<<"13. Shutdown the computer"<<endl;
    cout<<"14. == operator for array comparision"<<endl;
    cout<<"15. != operator for array comparision"<<endl;
    cout<<"16. for subscript operator"<<endl;
    cout<<"17. = operator to copy array"<<endl;
    cout<<"18. for  polynomial addition:"<<endl;
    cout<<"19. for  polynomial subtraction:"<<endl;
    cout<<"20. for  polynomial += operation:"<<endl;
    cout<<"21. for  polynomial -= operation:"<<endl;
    cout<<"22. for  polynomial multiplication:"<<endl;
    cout<<"23. for  polynomial *= operation"<<endl;
    cout<<"24. for string + operation"<<endl;
    cout<<"25. for string == operation"<<endl;
    cout<<"26. for string <= operation"<<endl;
    cout<<"27. for string >= operation"<<endl;
    cout<<"28. for string > operation"<<endl;
    cout<<"29. for string > operation"<<endl;
    cout<<"30. for string << operation"<<endl;
    cout<<"31. for string >> operation"<<endl;
    cout<<"32. for distance scaling"<<endl;
    cout<<"33. for name sorting"<<endl;
    cout<<"34. for swap functon "<<endl;
    cout<<"35. for date swapping"<<endl;
    cout<<"36. for printing chakrayuh"<<endl;
    cout<<"37. for base converting function"<<endl;
    cout<<"38. for factorial function"<<endl;
    cout<<"39. for combination function"<<endl;
    cout<<"40. for permutation function"<<endl;
    cout<<"41. for 21 matchstick game"<<endl;
    cout<<"42. for face printing"<<endl;
    cout<<"43. for prime numbers till n"<<endl;
    cout<<"44. for roots of eq ax^2+bx+c"<<endl;
    cout<<"45. for solution of three linear equation"<<endl;
    cout<<"46. for Celsius and Fahrenheit conversion"<<endl;
    cout<<"47. for solving determinant 4*4"<<endl;
    cout<<"48. for transpose of matrix"<<endl;
    cout<<"49. for matrix addition"<<endl;
    cout<<"50. for matrix subtraction"<<endl;
    cout<<"51. for matrix multiplication"<<endl;
    cout<<"52. for diamond printing design"<<endl;
    cout<<"53. for currency note calculator"<<endl;
    cout<<"54. for equation with degree 2"<<endl;
    cout<<"55. for equation with degree 3 cardon"<<endl;
    cout<<"56. for equation with degree 4 ferrari"<<endl;
    cout<<"57. for tic tac toe game 2 players:"<<endl;
    cout<<"58. for long beep sound:"<<endl;
      cout<<"0. to end the program"<<endl;
   cout<<"ENTER YOUR CHOICE:";
   cin>>choice;
   switch (choice)
   {
   case 1:
    {
        char c[500];
        cout<<"enter name of file to be created:";
        cin>>c;
        ofstream file(c);
        cout<<"file "<<c<<" is created now\n";
        file.close();
        break;
    }
    case 2:
    {
        char c[500];
        cout<<"enter name of file to be readed and displayed:";
        cin>>c;
        ifstream dest2(c);
        char ch;
        int i=0;
        while(!dest2.eof())
    {

        dest2.seekg(i,ios::beg);
        dest2.get(ch);
        cout<<ch;
        i++;
    }
    dest2.close();

        break;
    }
    case 3:
        {
            char c[500];
        cout<<"enter name of file to be writted from beginning :";
        cin>>c;
        ofstream sour(c);
    cout<<"\n"<<"enter data in file "<<c<<"\n";

    char ch='a';
    while(ch!=EOF)
    {
        ch=getchar();
        sour.put(ch);
    }
    sour.close();
    break;
        }
    case 4:
        {
            char c[500];
        cout<<"enter name of file to be readed and updated :";
        cin>>c;
        ifstream dest2(c);
        char ch;
        int i=0;
        while(!dest2.eof())
    {

        dest2.seekg(i,ios::beg);
        dest2.get(ch);
        cout<<ch;
        i++;

    }
    fstream sour(c);
    sour.seekg(0,ios::end);
     ch='a';
    while(ch!=EOF)
    {
        ch=getchar();
        sour.put(ch);
    }
    sour.close();

    break;
        }

    case 5:
        {
        char c1[500];
        cout<<"enter source file name :";
        cin>>c1;
        char c2[500];
        cout<<"enter destination file name :";
        cin>>c2;
        ifstream sour1(c1);
        ofstream dest1(c2);
        char ch;
        int i=0;
        while(sour1)
        {
            sour1.seekg(i,ios::beg);
            sour1.get(ch);
            dest1<<ch;
            i++;
        }
        sour1.close();
        dest1.close();
        cout<<"data copied from "<<c1<<" to "<<c2;
        break;

        }
    case 6:
        {
           char c1[500];
        cout<<"enter file to be deleted or enter path of file to be deleted: ";
        cin>>c1;
        remove(c1);
        //use of remove command in cstdio is done here to delete a file.
        break;

        }
    case 7:
        {
            char c1[500];
            cout<<"enter file so that characters are count: ";
            cin>>c1;
            ifstream dest2(c1);

        char ch;
        int i=0;
        while(!dest2.eof())
    {

        dest2.seekg(i,ios::beg);
        dest2.get(ch);
        i++;

    }
             int n=dest2.tellg();
            cout<<"the number of characters in file are:"<<i-1<<endl;
            break;

        }
    case 8:
        {
            char c1[500];
            cout<<"enter binary file name to write it: "<<endl;
            cin>>c1;
            int qq;
            cout<<"enter no of terms you like to write in double binary file:"<<endl;
            cin>>qq;
                float g[qq];
    for(int i=0;i<qq;i++)
    {
        cout<<"enter "<<i+1<<" "<<" item :";
        cin>>g[i];
    }
    ofstream f(c1);
    f.write((char *)&g,sizeof(g));
    f.close();
    break;
        }
    case 9:
        {char c1[500];
            cout<<"enter binary file name to read it: "<<endl;
            cin>>c1;
            int qq;
            cout<<"enter no of terms you like to read from double binary file:"<<endl;
            cin>>qq;
    ifstream a(c1);
    float s[qq];
    a.read((char *)&s,sizeof(s));
    a.close();
    for(int i=0;i<qq;i++)
    {
       cout<<s[i]<<" ";

        }
        break;
        }
    case 11:
        { system("shutdown -f"); break;}
    case 12:
        { system("shutdown -r");     break; }
    case 13:
    { system("shutdown -s");     break;}

case 14:
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
        case 15:
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
        case 16:
            {
                break;
            }
        case 17:
            {
                cin>>a;
                b=a;
                cout<<"a is\n";
                cout<<a;
                cout<<"b is\n";
                cout<<b;
            }
case 18:
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
    case 19:
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
        case 20:
            {int d;
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
        case 21:
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
        case 22:
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
      int x;
    x=d+p2.d;
    polynomial p3(x);
    p3=p1*p2;
    cout<<"mulptiplicaltion of  ";
    p1.putdata();
    cout<<" and ";
    p2.putdata();
    cout<<" is \n";
    p3.putdata();
break;
            }
               case 23:
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
    p1*=p2;
    cout<<"after p1*=p2\n p1 is ";
    p1.putdata();
    cout<<" and p2 is";
    p2.putdata();
break;
            }



            case 24:
    {
       MyString str1;
       MyString str2;
       cout<<"for string 1\n";
       cin>>str1;
       cout<<"for string 2\n";
       cin>>str2;
       MyString str3;
       str3=str1+str2;
       cout<<"\n\n\nafter str1+str2 result is \n";
       cout<<str3;
       break;

    }
   case 25:
     {
       MyString str1;
       MyString str2;
       cout<<"for string 1\n";
        cin>>str1;
       cout<<"for string 2\n";
       cin>>str2;
       cout<<"after str1==str2\n";
       if(str1==str2)
        {
            cout<<"\n Condition is TRUE\n string are same\n";
        }
        else
        {
        cout<<"\n Condition is FALSE \n string are not same\n";
        }
        break;

     }
   case 26:
    {

       MyString str1;
       MyString str2;
       cout<<"for string 1\n";
        cin>>str1;
       cout<<"for string 2\n";
      cin>>str2;
       cout<<"after str1<=str2\n";
       if(str1<=str2)
        {
            cout<<"\n Condition is TRUE\n str1<=str2\n";
        }
        else
        {
        cout<<"\n Condition is FALSE \n str1>str2\n";
        }
        break;
    }
   case 27:
    {
         MyString str1;
       MyString str2;
       cout<<"for string 1\n";
     cin>>str1;
       cout<<"for string 2\n";
     cin>>str2;
       cout<<"after str1>=str2\n";
       if(str1>=str2)
        {
            cout<<"\n Condition is TRUE\n str1>=str2\n";
        }
        else
        {
        cout<<"\n Condition is FALSE \n str1<str2\n";
        }
        break;
    }
   case 28:
    {
           MyString str1;
       MyString str2;
       cout<<"for string 1\n";
        cin>>str1;
       cout<<"for string 2\n";
      cin>>str2;
       cout<<"after str1<str2\n";
       if(str1<str2)
        {
            cout<<"\n Condition is TRUE\n str1<str2\n";
        }
        else
        {
        cout<<"\n Condition is FALSE \n str1>=str2\n";
        }
        break;
    }
   case 29:
    {
         MyString str1;
       MyString str2;
       cout<<"for string 1\n";
      cin>>str1;
       cout<<"for string 2\n";
      cin>>str2;
       cout<<"after str1>str2\n";
       if(str1>str2)
        {
            cout<<"\n Condition is TRUE\n str1>str2\n";
        }
        else
        {
        cout<<"\n Condition is FALSE \n str1<=str2\n";
        }
        break;
    }
   case 30:
    {
          MyString str1;
       cout<<"for string 1\n";
       cin>>str1;
       cout<<str1;
       break;
    }
    case 31:
    {
          MyString str1;
       cout<<"for string 1\n";
       cin>>str1;
       cout<<str1;
       break;
    }
    case 32:
        {
             dist d1;
        float f;
        d1.getdata();
        cout<<"enter scale value::";
        cin>>f;
        d1.scale(d1,f);
        d1.putdata();
        break;
        }
    case 33:
        {
              int no;
    char temp[50];
    cout<<"enter number of names you want to arrange:"<<endl;
    cin>>no;
    char name[no][50];
    for(int i=0;i<no;i++)
    {
        cout<<"enter "<<i<<" th name:";
        cin>>name[i];
        cout<<endl;
    }
    for(int i=0;i<no;i++)
        for(int j=0;j<no;j++)
    {
        if(strcmp(name[i],name[j])<0)
        {
            strcpy(temp,name[i]);
            strcpy(name[i],name[j]);
            strcpy(name[j],temp);
        }
    }
    cout<<"sorted list is"<<endl;
    for(int i=0;i<no;i++)
        cout<<name[i]<<endl;
        break;
        }

    case 34:
        {
             int a,b;
    cout<<"enter two integer"<<endl;
    cin>>a>>b;
    swap(a,b);
    cout<<"swapped integer are"<<a<<" "<<b<<endl;

    float e,f;
    cout<<"enter two floating  value"<<endl;
    cin>>e>>f;
    swap(e,f);
    cout<<"swapped float are"<<e<<" "<<f<<endl;

    double p,q;
    cout<<"enter two double value"<<endl;
    cin>>p>>q;
    swap(p,q);
    cout<<"swapped integer are"<<p<<" "<<q<<endl;

    char x,y;
    cout<<"enter two characters"<<endl;
    cin>>x>>y;
    swap(x,y);
    cout<<"swapped integer are"<<x<<" "<<y<<endl;
break;
        }

    case 35:
        {
        date a,b;
    a.getdata();
    b.getdata();
    swapdates(a,b);
    cout<<"after swapping"<<endl;
    a.putdata();
    b.putdata();
        break;
        }

    case 36:
        {
            cout<<"enter number to print spiral:";
cin>>Nz;
    u=-Nz; dow=Nz;
    int a[Nz*Nz];
    for(int i=0;i<Nz*Nz;i++)
    {a[i]=0;}
    fill(a);
    for(int i=0;i<=(Nz*Nz)-1;i++)
    {
        if(i%Nz==0&&i!=0)
        {
            cout<<"\n";
        }
        cout<<setw(3)<<a[i]<<" " ;
    }
    break;
        }
    case 37:
        {
                int num;
    int base;
    cout<<"enter a number in decimal";
    cin>>num;
    cout<<"enter base";
    cin>>base;
    con(num,base);
    break;
        }
    case 38:
        {
            int num;
            long int a;
            cout<<"enter a number to find its factorial";
            cin>>num;
            a=fact(num);
            cout<<a;
            break;
        }
    case 39:
        {
            int n,i;long int ans;
            cout<<"enter n"<<endl;
            cin>>n;
            cout<<"enter r"<<endl;
            cin>>i;
            ans=(fact(n)/((fact(n-i))*fact(i)));
            cout<<"nr = "<<ans;
            break;
        }
        case 40:
        {
            int n,i;long int ans;
            cout<<"enter n"<<endl;
            cin>>n;
            cout<<"enter r"<<endl;
            cin>>i;
            ans=(fact(n)/((fact(n-i))));
             cout<<"nPr = "<<ans;
             break;
        }
        case 41:
            {
                int matchstick = 21;
    int user,computer;

    while (matchstick>=1)
    {

        if (matchstick==1)
        {
            printf("\nMatch stick status:%d",matchstick);
            printf("\nYou loose!!!!!!:(:(");               break;
        }

        printf("\nMatch stick status:%d",matchstick);
        printf("\nEnter the choice (1,2,3,4)):");        scanf("%d",&user);

        printf("\nYou picked %d",user);
        if (user>=5 || user <=0)
        {
            printf("\nInvalid value");            continue;
        }

        computer = 5 - user;

        printf("\nComputer picked%d",computer);
        matchstick = matchstick - computer - user;

    }
    break;
            }
        case 42:
            {
                	printf("         ()         \n");
	printf("        (  )        \n");
	printf("       (    )       \n");
	printf("      (      )      \n");
	printf("     (        )     \n");
	printf("    ************    \n");
	printf("     | 0   0  |     \n");
	printf("     |   ||   |     \n");
	printf("     |   ||   |     \n");
	printf("     |   --   |     \n");
	printf("     ( )---(  )     \n");
	printf("      (      )      \n");
	printf("        (  )        \n");
	printf("         --         \n");
	break;
            }

        case 43:
            {
                int n;
                cout<<"enter last number"<<endl;
                cin>>n;
                	int a[n];    int i;   int j;
	for(i=0;i<n;i++)
	a[i]=i+1;

	for(i=1;i<n;i++)
	{if(a[i]!=0)
	for(j=2;j<(i);j++)
	{
	if((a[i]%j)==0)
	{a[i]=0;}
	}
	}
	for(i=1;i<n;i++)
	{
	if(a[i]!=0)
	{
	printf("%d  ",a[i]);
	}
	}
	getch();
	break;
            }
        case 44:
            {
                double a,b,c,x1,x2,D,rp,ip;

printf("enter the value of a:");
scanf("%lf",&a);
printf("enter the value of b:");
scanf("%lf",&b);
printf("enter the value of c:");
scanf("%lf",&c);
D=pow(b,2)-4*a*c;
if (D>0)
{
printf("ROOTS ARE REAL AND DISTINCT");
x1=(-b+sqrt(D))/2*a;
x2=(-b-sqrt(D))/2*a;
printf("\n%lf+%lfi",x1);
printf("\n%lf+%lfi",x2);
}
else if(D==0)
{
printf("ROOTS ARE EQUAL");
x1=x2=-b/2*a;
printf("%lf",x1);
}
else
{
printf("ROOTS ARE COMPLEX AND DISTINCT");
rp=-b/2*a;
ip=sqrt(-D)/2*a;
printf("\n%lf+%lfi",rp,ip);
printf("\n%lf-%lfi",rp,ip);
}
getch();
break;
            }
        case 45:
            {
                float a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;
	float aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk;
	printf("this is program to find perfect answer of three variable equation \n");
	printf("the equation will look like:");
	printf("\n ax+by+cz=d  \n ex+fy+gz=h   \n ix+jy+kz=l");
	printf("\n enter the value of a:");
	scanf("%f",&a);
	printf("\n enter the value of b:");
	scanf("%f",&b);
	printf("\n enter the value of c:");
	scanf("%f",&c);
	printf("\n enter the value of d:");
	scanf("%f",&d);
	printf("\n enter the value of e:");
	scanf("%f",&e);
	printf("\n enter the value of f:");
	scanf("%f",&f);
	printf("\n enter the value of g:");
	scanf("%f",&g);
	printf("\n enter the value of h:");
	scanf("%f",&h);
	printf("\n enter the value of i:");
	scanf("%f",&i);
	printf("\n enter the value of j:");
	scanf("%f",&j);
	printf("\n enter the value of k:");
	scanf("%f",&k);
	printf("\n enter the value of l:");
	scanf("%f",&l);
	dd=(a*((f*l)-(h*j)))-(b*((e*l)-(h*i)))+(d*((e*j)-(i*f)));
	aa=(a*((k*f)-(g*j)))-(b*((e*k)-(g*i)))+(c*((e*j)-(i*f)));
	bb=(d*((f*k)-(g*j)))-(b*((h*k)-(l*g)))+(c*((h*j)-(l*f)));
	cc=(a*((h*k)-(l*g)))-(d*((e*k)-(i*g)))+(c*((e*l)-(i*h)));
	ee=bb/aa;
	ff=cc/aa;
	gg=dd/aa;
	printf("your equation is \n %f x + %f y + %f z = %f  \n %f x + %f y + %f z = %f  \n %f x + %f y + %f z = %f \n",a,b,c,d,e,f,g,h,i,j,k,l);
	printf("delta= %f \n  delta1= %f \n  delta2= %f \n  delta3=%f \n",aa,bb,cc,dd);
	printf("the valueb of x is %f \n the value of y is %f \n the value of z is %f",ee,ff,gg);
	printf("\n please give only valid equation which have only one solution if you give more than one solution equation then it will generate error of infinite solutions");

	getch();
	break;
            }
        case 46:
            {
                int a; float c,f;

printf("enter 1 to change celsius to farenheit: \n");
printf("enter 2 to change farenheit to celsius: \n");
scanf("%d",&a);
if (a==1)
{printf("enter the value of celsius: \n");
scanf("%f",&c);
f=((9.0/5.0)*c)+32;
printf("farenheit is %f \n",f);
}

if (a==2)
{printf("enter the value of farenheit: \n") ;
scanf("%f",&f);
c=(f-32)*(5.0/9.0);
printf("celsius is %f \n",c);
 }
getch();
break;
            }
        case 47:
            {
                int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;  int det;

	printf("this is program to solve 4 x 4 determinant \n");
	printf("your determinant will look like:\n");
	printf(" | a b c d| \n | e f g h| \n | i j k l| \n | m n o p| \n");
	printf("please enter the value of a:::::::");
	scanf("%d",&a);
	printf("please enter the value of b:::::::");
	scanf("%d",&b);
	printf("please enter the value of c:::::::");
	scanf("%d",&c);
	printf("please enter the value of d:::::::");
	scanf("%d",&d);
	printf("please enter the value of e:::::::");
	scanf("%d",&e);
	printf("please enter the value of f:::::::");
	scanf("%d",&f);
	printf("please enter the value of g:::::::");
	scanf("%d",&g);
	printf("please enter the value of h:::::::");
	scanf("%d",&h);
	printf("please enter the value of i:::::::");
	scanf("%d",&i);
	printf("please enter the value of j:::::::");
	scanf("%d",&j);
	printf("please enter the value of k:::::::");
	scanf("%d",&k);
	printf("please enter the value of l:::::::");
	scanf("%d",&l);
	printf("please enter the value of m:::::::");
	scanf("%d",&m);
	printf("please enter the value of n:::::::");
	scanf("%d",&n);
	printf("please enter the value of o:::::::");
	scanf("%d",&o);
	printf("please enter the value of p:::::::");
	scanf("%d",&p);
	printf(" | %d %d %d %d | \n | %d %d %d %d | \n | %d %d %d %d | \n | %d %d %d %d | \n",a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p);
	det=(a*((f*((k*p)-(o*l)))-(g*((j*p)-(n*l)))+(h*((j*o)-(n*k)))))-(b*((e*((k*p)-(o*l)))-(g*((i*p)-(l*m)))+(h*((i*o)-(m*k)))))+(c*((e*((j*p)-(n*l)))-(f*((i*p)-(m*l)))+(h*((i*n)-(j*m)))))-(d*((e*((j*o)-(k*n)))-(f*((i*o)-(k*m)))+(g*((i*n)-(j*m)))));
	printf("%d",det);
break;
            }
        case 48:
            {
                int n,m;
                cout<<"Enter rows:";
                cin>>n;
                cout<<"Enter columns:";
                cin>>m;
                int a[n][m]; int i; int j;
                int b[m][n];

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{	printf("enter value of a[%d] [%d] \n",i,j);
			scanf("%d",&a[i][j]);
        }
			}
			for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    b[j][i]=a[i][j];
                }
            }
            if(n>m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{printf("%d \t ",b[i][j]);}
		printf("\n");
		}
		getch();
		break;
            }
        case 49:
            {
                int m; int n; int i; int j;

    printf("enter value of m \n");

    scanf("%d",&m);

    printf("enter value of n \n");
    scanf("%d",&n);
    int a[m][n];
    int b[m][n];
    int c[m][n];
    if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        printf("give value of a[%d][%d]",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
        printf("give value of a[%d][%d]",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    }



        if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        printf("give value of b[%d][%d]",i+1,j+1);
        scanf("%d",&b[i][j]);
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
        printf("give value of b[%d][%d]",i+1,j+1);
        scanf("%d",&b[i][j]);
    }
    }




                if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        c[i][j]=a[i][j]+b[i][j];
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
    c[i][j]=a[i][j]+b[i][j];
    }
    }

        printf("***********************************************\n");
        printf("the addition is \n \n \n \n");


    if(m>=n)
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
        {

            printf("%d    ",c[i][j]);
            if(j==n-1)
            {
                printf("\n");
            }
        }
        if(m<n)
        for(j=0;j<m;j++)
            for(i=0;i<n;i++)
        {

            printf("%d    ",c[i][j]);

            if(i==n-1)
            {
                printf("\n");
            }
        }
break;
            }
        case 50:
            {
                int m; int n; int i; int j;

    printf("enter value of m \n");

    scanf("%d",&m);

    printf("enter value of n \n");
    scanf("%d",&n);
    int a[m][n];
    int b[m][n];
    int c[m][n];
    if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        printf("give value of a[%d][%d]",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
        printf("give value of a[%d][%d]",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    }



        if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        printf("give value of b[%d][%d]",i+1,j+1);
        scanf("%d",&b[i][j]);
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
        printf("give value of b[%d][%d]",i+1,j+1);
        scanf("%d",&b[i][j]);
    }
    }

                if (m>=n)
    {
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        c[i][j]=a[i][j]-b[i][j];
    }
    }
    if (m<n)
        {
    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
    {
    c[i][j]=a[i][j]-b[i][j];
    }
    }

        printf("\n ***********************************************\n");
        printf("the subtraction is \n \n \n \n");


    if(m>=n)
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
        {

            printf("%d    ",c[i][j]);
            if(j==n-1)
            {
                printf("\n");
            }
        }
        if(m<n)
        for(j=0;j<m;j++)
            for(i=0;i<n;i++)
        {

            printf("%d    ",c[i][j]);

            if(i==n-1)
            {
                printf("\n");
            }
        }

break;
            }
        case 51:
            {
                gh:
    int m1,m2,n1,n2;
    cout<<"enter m for a"<<endl;
    cin>>m1;
    cout<<"enter n for a"<<endl;
    cin>>n1;
    cout<<"enter m for b"<<endl;
    cin>>m2;
    cout<<"enter m for b"<<endl;
    cin>>n2;
    if(n1!=m2)
    {
        cout<<"enter again"<<endl;
        goto gh;
    }

    int a[m1][n1];
    int i,j,k;
    int b[m2][n2];
    int c[m1][n2];
     for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {c[i][j]=0;}
    }

    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
           printf("enter value of a[%d][%d] \n",i,j);
           scanf("%d",&a[i][j]);
        }
    }
    printf("\n \n \n \n \n");
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
           printf("enter value of b[%d][%d] \n",i,j);
           scanf("%d",&b[i][j]);
        }
    }
    for (i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            for(k=0;k<n1;k++)
            {
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
            }
        }
    }
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n2;j++)
        {
            printf("    %d    ",c[i][j]);
        }
        printf("\n");
    }
    break;
            }
        case 52:
            {
                int nn,cc,kk, space = 1;      int iii,jjj,aaa;
                printf("Enter number of rows\n");
    scanf("%d", &nn);
    space = nn - 1;
    for (kk = 1; kk <= nn; kk++)
    {
	for (cc = 1; cc <= space; cc++)
	    printf(" ");
	space--;
	for (cc = 1; cc <= 2*kk-1; cc++)
	    printf("*");

	printf("\n");
    }
    space = 1;
    for (kk = 1; kk <= nn - 1; kk++)
    {
	for (cc = 1; cc <= space; cc++)
	    printf(" ");
space++;
	for (cc = 1 ; cc <= 2*(nn-kk)-1; cc++)
	    printf("*");

	printf("\n");
    }
    break;
            }
        case 53:
            {
                int a,hundrednotes,fiftynotes,tennotes,onenotes;
printf("please enter amount in hundreds only till 999 only \n");
scanf("%d",&a);
hundrednotes=a/100;
printf("the number of hundred notes is %d \n",hundrednotes);
a=a%100;
fiftynotes=a/50;
printf("the number of fifty notes is %d \n",fiftynotes);
a=a%50;
tennotes=a/10;
printf("the number of ten notes is %d \n",tennotes);
a=a%10;
onenotes=a;
printf("the one rupee coins to be given is %d \n",a);
getch();
break;
            }
        case 54:
            {
                double a,b,c,x1,x2,D,rp,ip;
printf("enter the value of a:");
scanf("%lf",&a);
printf("enter the value of b:");
scanf("%lf",&b);
printf("enter the value of c:");
scanf("%lf",&c);
D=pow(b,2)-4*a*c;
if (D>0)
{
printf("ROOTS ARE REAL AND DISTINCT");
x1=(-b+sqrt(D))/2*a;
x2=(-b-sqrt(D))/2*a;
printf("\n%lf+%lfi",x1);
printf("\n%lf+%lfi",x2);
}
else if(D==0)
{
printf("ROOTS ARE EQUAL");
x1=x2=-b/2*a;
printf("%lf",x1);
}
else
{
printf("ROOTS ARE COMPLEX AND DISTINCT");
rp=-b/2*a;
ip=sqrt(-D)/2*a;
printf("\n%lf+%lfi",rp,ip);
printf("\n%lf-%lfi",rp,ip);
}
getch();
break;
            }
        case 55:
            {
                double a,b,c,d,ro;
                cout<<"enter a:";
                cin>>a;
                cout<<"enter b:";
                cin>>b;
                cout<<"enter c:";
                cin>>c;
                 cout<<"enter d:";
                cin>>d;
                solveCubic(a,b,c,d,ro);
                cout<<"one root is:"<<ro;
                break;
            }
            case 56:
            {
                double a,b,c,d,e,ro;
                cout<<"enter a:";
                cin>>a;
                cout<<"enter b:";
                cin>>b;
                cout<<"enter c:";
                cin>>c;
                 cout<<"enter d:";
                cin>>d;
                cout<<"enter e:";
                cin>>e;
                if(solveQuartic(a,b,c,d,e,ro))
                cout<<ro;
                else{cout<<"no result found";}
                break;
            }
            case 57:
                {
                    int player = 1,i,choice;

	char mark;
	do
	{
		board();
		player=(player%2)?1:2;
		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;
		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')

			square[1] = mark;
		else if (choice == 2 && square[2] == '2')

			square[2] = mark;
		else if (choice == 3 && square[3] == '3')

			square[3] = mark;
		else if (choice == 4 && square[4] == '4')

			square[4] = mark;
		else if (choice == 5 && square[5] == '5')

			square[5] = mark;
		else if (choice == 6 && square[6] == '6')

			square[6] = mark;
		else if (choice == 7 && square[7] == '7')

			square[7] = mark;
		else if (choice == 8 && square[8] == '8')

			square[8] = mark;
		else if (choice == 9 && square[9] == '9')

			square[9] = mark;
		else
		{
			cout<<"Invalid move ";
			player--;
			cin.ignore();
			cin.get();
		}
		i=checkwin();
		player++;
	}while(i==-1);
	board();
	if(i==1)

		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
	break;
                }
            case 58:
                {
while(1==1)
                    {
                       cout<<"==>\aPlayer ";
                    }
                }
    }
}

