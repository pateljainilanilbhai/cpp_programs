
#include <complex>
#include <cstdlib>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<conio.h>
#include<cmath>
#include<cstring>
#include<iomanip>

const double PI = 3.14159265358979323846;

//----------------------------------------------------------------------------
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
//----------------------------------------------------------------------------
bool solveCubic(double &a, double &b, double &c, double &d, double &root)
{
	if(a == 0.0 || abs(a/b) < 1.0e-6)
		return solveQuadratic(b, c, d, root);

	double B = b/a, C = c/a, D = d/a;

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
//----------------------------------------------------------------------------
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
int main()
{
    double a=1,b=2,c=3,d=4,e=5,ro;
    solveCubic(a,b,c,d,ro);
    std::cout<<ro;

}
