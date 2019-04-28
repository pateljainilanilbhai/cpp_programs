#include<iostream>
#include<cstring>
using namespace std;

class gate
{
    static int ecv_cnt;
    static int ecs_cnt;
    static int eca_cnt;
    long int number;
    char name[30];
    string area;
    int centre;

    public:
    void getdata()
    {
        cout<<"enter registration number:";
        cin>>number;
        cout<<"enter name:";
        cin>>name;
        start:
        cout<<"enter your exam centre:";
        cin>>area;
        if(area!="vadodara"&&area!="ahmedabad"&&area!="surat")
        {
            cout<<"please enter correct exam centre \n you can select from\n1.ahmedabad\n2.surat\n3.vadodara"<<endl;
            goto start;
        }
        if(area=="vadodara")
          ecv_cnt+=1;
        if(area=="surat")
            ecs_cnt+=1;
        if(area=="ahmedabad")
            eca_cnt+=1;

    }
     void getcount()
    {
        cout<<"total number of students in vadodara is:"<<ecv_cnt<<endl;
        cout<<"total number of students in surat is:"<<ecs_cnt<<endl;
        cout<<"total number of students in ahmedabad is:"<<eca_cnt<<endl;


    }

};
int gate::ecv_cnt;
int gate::ecs_cnt;
int gate::eca_cnt;
int main()
{
    int i;
    gate g[5];
    for(i=0;i<5;i++)
    {
        g[i].getdata();
    }
    g[0].getcount();

}






