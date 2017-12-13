#include "matlib.h"
#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

static const double ROOT_2_PI = sqrt( 2.0 * PI );

static inline double hornerFunction(
	double x,
	double a0,
	double a1) {
	return a0 + x*a1;
}

template<typename T>
static void print_vector(vector<T> v) {
	for (const auto& x : v) {
		cout << x << endl;
	}
}

static inline double hornerFunction(vector<double> a) {
	
	if (a.size() < 3) {
		cout << "not enough elements" << endl;
		return 0;
	}else if (a.size() == 3) {
		return hornerFunction(a[0], a[1], a[2]);
	}else{
		double a0 = a[1];
		a.erase(a.begin()+1);
		return a0 + a[0]*hornerFunction(a);
	}
}



/**
 *  Arguably this is a little easier to read than the original normcdf
 *  function as it makes the use of horner's method obvious.
 */
double normcdf( double x ) {
    if (x<=0) {
        return 1-normcdf(-x);
    }
    double k = 1/(1 + 0.2316419*x);
	vector<double> elements{ k,0.0, 0.319381530, -0.356563782,1.781477937,-1.821255978,1.330274429};
    double poly = hornerFunction(elements);
    double approx = 1.0 - 1.0/ROOT_2_PI * exp(-0.5*x*x) * poly;
    return approx;
}

static const double a0 = 2.50662823884;
static const double a1 = -18.61500062529;
static const double a2 = 41.39119773534;
static const double a3 = -25.44106049637;
static const double b1 = -8.47351093090;
static const double b2 = 23.08336743743;
static const double b3 = -21.06224101826;
static const double b4 = 3.13082909833;
static const double c0 = 0.3374754822726147;
static const double c1 = 0.9761690190917186;
static const double c2 = 0.1607979714918209;
static const double c3 = 0.0276438810333863;
static const double c4 = 0.0038405729373609;
static const double c5 = 0.0003951896511919;
static const double c6 = 0.0000321767881768;
static const double c7 = 0.0000002888167364;
static const double c8 = 0.0000003960315187;

double norminv( double x ) {
    // We use Moro's algorithm
    double y = x - 0.5;
    if (y<0.42 && y>-0.42) {
        double r = y*y;

		return y*hornerFunction(vector<double>{r, a0, a1, a2, a3}) / hornerFunction(vector<double>{r, 1.0, b1, b2, b3, b4});
    } else {
        double r;
        if (y<0.0) {
            r = x;
        } else {
            r = 1.0 - x;
        }
        double s = log( -log( r ));
		double t = hornerFunction(vector<double>{s, c0, c1, c2, c3, c4, c5, c6, c7, c8});
        if (x>0.5) {
            return t;
        } else {
            return -t;
        }
    }
}


