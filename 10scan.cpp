/*10.Write a program to scan a polynomial using linked list and add two polynomial.*/
#include <iostream>
using namespace std;
class poly
{
        private :
                struct polynode
                {
                        int coeff ;
                        int exp ;
                        polynode *next ;
                } *p ;
        public :
                poly( ) ;
                void poly_append ( int c, int e ) ;
                void display_poly( ) ;
                void poly_add( poly &l1, poly &l2 ) ;
                ~poly( );
} ;
poly :: poly( )
{
        p = NULL ;
}
void poly :: poly_append ( int c, int e )
{
        polynode *temp = p ;
        if ( temp == NULL )
        {
                temp = new polynode ;
                p = temp ;
        }
        else
        {
                while ( temp -> next != NULL )
                        temp = temp -> next ;
                temp -> next = new polynode ;
                temp = temp -> next ;
        }
        temp -> coeff = c ;
        temp -> exp = e ;
        temp -> next = NULL ;
}
void poly :: display_poly( )
{
        polynode *temp = p ;
        int f = 0 ;
 
        cout << endl ;
        while ( temp != NULL )
        {
                if ( f != 0 )
                {
                        if ( temp -> coeff >= 0 )
                                cout << " + " ;
                        else
                                cout << " " ;
                }
                if ( temp -> exp != 0 )
                        cout << temp -> coeff << "x^" << temp -> exp ;
                else
                        cout << temp -> coeff ;
                temp = temp -> next ;
                f = 1;
        }
}
void poly :: poly_add ( poly &l1, poly &l2 )
{
        polynode *z ;
        if ( l1.p == NULL && l2.p == NULL )
                return ;
        polynode *temp1, *temp2 ;
        temp1 = l1.p ;
        temp2 = l2.p ;
        while ( temp1 != NULL && temp2 != NULL )
        {
                if ( p == NULL )
                {
                        p = new polynode ;
                        z = p ;
                }
                else
                {
                        z -> next = new polynode ;
                        z = z -> next ;
                }
                if ( temp1 -> exp < temp2 -> exp )
                {
                        z -> coeff = temp2 -> coeff ;
                        z -> exp = temp2 -> exp ;
                        temp2 = temp2 -> next ;
                }
                else
                {
                        if ( temp1 -> exp > temp2 -> exp )
                        {
                                z -> coeff = temp1 -> coeff ;
                                z -> exp = temp1 -> exp ;
                                temp1 = temp1 -> next ;
                        }
                        else
                        {
                                if ( temp1 -> exp == temp2 -> exp )
                                {
                                        z -> coeff = temp1 -> coeff + temp2 -> coeff ;
                                        z -> exp = temp1 -> exp ;
                                        temp1 = temp1 -> next ;
                                        temp2 = temp2 -> next ;
                                }
                        }
                }
        }
        while ( temp1 != NULL )
        {
                if ( p == NULL )
                {
                        p = new polynode ;
                        z = p ;
                }
                else
                {
                        z -> next = new polynode ;
                        z = z -> next ;
                }
                z -> coeff = temp1 -> coeff ;
                z -> exp = temp1 -> exp ;
                temp1 = temp1 -> next ;
        }
        while ( temp2 != NULL )
        {
                if ( p == NULL )
                {
                        p = new polynode ;
                        z = p ;
                }
                else
                {
                        z -> next = new  polynode ;
                        z = z -> next ;
                }
                z -> coeff = temp2 -> coeff ;
                z -> exp = temp2 -> exp ;
                temp2 = temp2 -> next ;
        }
        z -> next = NULL ;
}
poly :: ~poly( )
{
        polynode *q ;
        while ( p != NULL )
        {
                q = p -> next ;
                delete p ;
                p = q ;
        }
}
int main( )
{
        poly p1 ;
        p1.poly_append ( 4, 5) ;
        p1.poly_append ( 5, 4) ;
        p1.poly_append ( 7, 2) ;
        cout << "First polynomial:->->->->" ;
        p1.display_poly( );
	cout<<endl;
        poly p2 ;
        p2.poly_append ( 5, 6 ) ;
        p2.poly_append ( 5, 5 ) ;
        p2.poly_append ( -5, 4) ;
        cout << "Second polynomial:->->->->" ;
        p2.display_poly( ) ;
	cout<<endl;
        poly p3 ;
        p3.poly_add ( p1, p2 ) ;
        cout << "\nResultant polynomial:->->->-> " ;
        p3.display_poly( ) ;
        return 0;
}