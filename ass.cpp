#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<conio.h>

class hm
{
		int bill;

	public:
		hm()
		{
			bill=0;
		}
		void getchoice();
		void breakfast();
		void pauva();
		void lunch();
		void showbill();
		void bev();
		void cbill(int,int);
		int any();
		int amt();
		void thepla();
};

void hm::getchoice()
{
	cout<<"\nWhat would u like to have..?\n";
	cout<<"\n1. Breakfast\n2. Lunch\n3. Beverages\n4. Exit"<<endl;
	cout<<"Enter Your Choice:";
	char c;
	int n=getche();
	c=n;
	switch(c)
	{
		case '1':
			breakfast();
			break;
		case '2':
			lunch();
			break;
		case '3':
			bev();
			int d;
			d=any();
			if(d==1)
				getchoice();
			else
			{
				showbill();
			}
			break;
		case '4':
			showbill();
			break;
		default:
			clrscr();
			cout<<"\nPlease Enter Valid Choice...";
			getchoice();
	}
}

void hm::breakfast()
{
	cout<<"\n1. Pauva \n2. Thepla\n3. Beverages"<<endl;
	cout<<"4. Exit";
	int q;
	cout<<"\nEnter Your Choice:";
	char c;
	int n=getche();
	c=n;
	switch(c)
	{
		case '1':
			pauva();
			break;
		case '2':
			thepla();
			break;
		case '3':
			bev();
			break;
		case '4':
			showbill();
			getch();
			exit(0);
			break;
		default:
			cout<<"\nEnter Valid Choice..."<<endl;
			breakfast();
			break;
	}
	int d;
	d=any();
	if(d==1)
		breakfast();
	else
	{
		showbill();
	}

}

void hm::pauva()
{
	cout<<"\n1. Sada Pauva ---- 15 Rs.\n2. Masala Pauva ---- 20 Rs.\n";
	cout<<"Enter Your Choice:";
	int q;
	int n=getche();
	char c;
	c=n;
	switch(c)
	{
		case '1':
			q=amt();
			cbill(q,15);
			break;
		case '2':
			q=amt();
			cbill(q,20);
			break;
		default:
		{
			cout<<"\nEnter Valid Choice...";
			pauva();
		}
	}
}

void hm::lunch()
{
	cout<<"\n1. Gujarati ---- 50 Rs.\n2. Kathiyawadi ---- 60 Rs."<<endl;
	cout<<"3. Beverages\n4. Exit"<<endl;
	int q;
	cout<<"\nEnter Your Choice:";
	int n=getche();
	char c=n;
	switch(c)
	{
		case '1':
			q=amt();
			cbill(q,50);
			break;
		case '2':
			q=amt();
			cbill(q,60);
			break;
		case '3':
			bev();
			break;
		case '4':
			showbill();
			getch();
			exit(0);
			break;
		default:
			cout<<"\nEnter Valid Choice..."<<endl;
			lunch();
			break;
	}
	int d;
	d=any();
	if(d==1)
		lunch();
	else
		showbill();
}

void hm:: thepla()
{
	cout<<"\n1. Sada Thepla ---- 20 Rs.\n2. Masala Thepla ---- 30 Rs.\n";
	cout<<"\nEnter Your Choice:";
	int q;
	int n=getche();
	char c=n;
	switch(c)
	{
		case '1':
			q=amt();
			cbill(q,20);
			break;
		case '2':
			q=amt();
			cbill(q,30);
			break;
		default:
		{
			cout<<"Please Enter Valid Choice...\n";
			thepla();
		}
	}
}

void hm::bev()
{
	cout<<"\n1. Tea ---- 30 Rs.\n2. Coffee ---- 40 Rs.\n3. Exit"<<endl;
	cout<<"Enter Your Choice:";
	int q;
	char c;
	int n=getche();
	c=n;
	switch(c)
	{
		case '1':
			q=amt();
			cbill(q,30);
			break;
		case '2':
			q=amt();
			cbill(q,40);
			break;
		case '3':
			showbill();
			getch();
			exit(0);
			break;
		default:
			cout<<"\nEnter Valid Choice..."<<endl;
			bev();
			break;
	}
}

int hm::any()
{
	cout<<"\nDo You Want Anything Else..?(Y/N)";
	int n=getche();
	char c=n;

	if(c=='y'||c=='Y')
		return 1;
	else if(c=='n'||c=='N')
		return 0;
	else
	{
		cout<<"Please Enter Valid Choice...\n";
		any();
	}
}

void hm::showbill()
{
	cout<<"\nYour Bill is:"<<bill;
	cout<<endl<<"Thank You For Shopping With Us.."<<endl;

}

int hm::amt()
{
	cout<<"\nEnter Quantity:";
	int q;
	cin>>q;

	     /*	char c;
		int n=getche();
		c=n;
		q=atoi(c);
	     */

	return q;

}

void hm::cbill(int q,int r)
{
	bill = bill + (q*r);
}

int main()
{
	clrscr();
	hm obj1;
	cout<<"Welcome..."<<endl;
	cout<<"\n\n{Press any key to continue\n";
	getch();
	clrscr();
	obj1.getchoice();
	getch();
	return 0;
}
