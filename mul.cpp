#include <iostream>
using namespace std;
class poly
{
	private :
		struct polynode
		{
			float coeff ;
			int exp ;
			polynode *link ;
		} *p ;
	public :
		poly( ) ;
		void poly_append ( float c, int e ) ;
		void display_poly( ) ;
		void poly_multiply ( poly &p1, poly &p2 ) ;
		void padd ( float c, int e ) ;
		~poly( ) ;
} ;
poly :: poly( )
{
	p = NULL ;
}
void poly :: poly_append ( float c, int e )
{
	polynode *temp ;
	temp = p ;
	if ( temp == NULL )
	{
		temp = new polynode ;
		p = temp ;
	}
	else
	{
		while ( temp -> link != NULL )
			temp = temp -> link ;
		temp -> link = new polynode ;
		temp = temp -> link ;
	}
	temp -> coeff = c ;
	temp -> exp = e ;
	temp -> link = NULL ;
}
void poly :: display_poly( )
{
	polynode *temp = p ;
	int f = 0 ;
	while ( temp != NULL )
	{
		if ( f != 0 )
		{
			if ( temp -> coeff > 0 )
				cout << " + " ;
			else
				cout << " " ;
		}
		if ( temp -> exp != 0 )
			cout << temp -> coeff << "x^" << temp -> exp ;
		else
			cout << temp -> coeff ;
		temp = temp -> link ;
		f = 1 ;
	}
}
void poly :: poly_multiply ( poly &p1, poly &p2 )
{
	polynode *temp1, *temp2 ;
	float coeff1, exp1 ;
	temp1 = p1.p ;
	temp2 = p2.p ;
	if ( temp1 == NULL && temp2 == NULL )
		return ;
	if ( temp1 == NULL )
		p = p2.p ;
	else
	{
		if ( temp2 == NULL )
			p = temp1 ;
		else		{
			while ( temp1 != NULL )
			{
				while ( temp2 != NULL )
				{
					coeff1 = temp1 -> coeff * temp2 -> coeff ;
					exp1 = temp1 -> exp + temp2 -> exp ;
					temp2 = temp2 -> link ;
					padd ( coeff1, exp1 ) ;
				}
				temp2 = p2.p ;
				temp1 = temp1 -> link ;
			}
		}
	}
}
void poly :: padd ( float c, int e )
{
	polynode *r, *temp ;
	temp = p ;
	if ( temp == NULL || c > temp -> exp )
	{
		r = new polynode ;
		r -> coeff = c ;
		r -> exp = e ;
		if ( p == NULL )
		{
			r -> link = NULL ;
			p = r ;
		}
		else
		{
			r -> link = temp ;
			p = r ;
		}
	}
	else
	{
		while ( temp != NULL )
		{
			if ( temp -> exp == e )
			{
				temp -> coeff += c ;
				return ;
			}
			if ( temp -> exp > c && ( temp -> link -> exp < c ||
						temp -> link == NULL ) )
			{
				r = new polynode ;
				r -> coeff = c;
				r -> exp = e ;
				r -> link = NULL ;
				temp -> link = r ;
				return ;
			}
			temp = temp -> link ;
		}
		r -> link = NULL ;
		temp -> link = r ;
	}
}
poly :: ~poly( )
{
	polynode *q ;
	while ( p != NULL )
	{
		q = p -> link ;
		delete p ;
		p = q ;
	}
}
int main( )
{
	poly p1 ;
	p1.poly_append ( 3, 5 ) ;
	p1.poly_append ( 2, 4 ) ;p1.poly_append ( 1, 2 ) ;cout << "\nFirst polynomial: " << endl ;
	p1.display_poly( ) ;
	poly p2 ;
	p2.poly_append ( 1, 6 ) ;
	p2.poly_append ( 2, 5 ) ;
	p2.poly_append ( 3, 4 ) ;
	cout << "\nSecond polynomial: " << endl ;
	p2.display_poly( ) ;
	poly p3 ;
	p3.poly_multiply ( p1, p2 ) ;
	cout << "\nResultant polynomial: " << endl ;
	p3.display_poly( ) ;
}
