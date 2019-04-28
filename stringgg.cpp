#include<iostream>
#include<cstring>
using namespace std;
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




int main()
{
int choice;
start:
   cout<<"enter 1 for string + operation\nenter 2 for string == operation\nenter 3 for string <= operation\nenter 4 for string >= operation\nenter 5 for string > operation\nenter 6 for string > operation\nenter 7 for string << operation\nenter 8 for string >> operation\n";
   cin>>choice;
   if(choice<1||choice>8)
   {
       cout<<"enter valid choice\n";
       goto start;
   }

   switch(choice)
   {
   case 1:
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
   case 2:
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
   case 3:
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
   case 4:
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
   case 5:
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
   case 6:
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
   case 7:
    {
          MyString str1;
       cout<<"for string 1\n";
       cin>>str1;
       cout<<str1;
       break;
    }
    case 8:
    {
          MyString str1;
       cout<<"for string 1\n";
       cin>>str1;
       cout<<str1;
       break;
    }

   }
   cout<<"\n****************************************************************************************\nenter 1 to start again:\nenter 0 to exit:";
   cin>>choice;
   if(choice==1)
   {
       goto start;
   }
}
