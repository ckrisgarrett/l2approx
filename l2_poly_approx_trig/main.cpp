#include <iostream>
#include <iomanip>
#include <cmath>
#include "highprecisionmath.h"
#include "polynomial.h"
#include "orthopolys.h"
#include "l2approx.h"
using namespace std;


static const char* VERSION = "1.0";         // Version of software.
static int const NUM_POLYS = 24;            // number of orthogonal polynomials to create

static mpf_class lows[]  = 
    {(-PI), (-PI/2), (-PI/4)};              // lower bounds for inner product interval
static mpf_class highs[] = 
    {( PI), ( PI/2), ( PI/4)};              // upper bounds for inner product interval


static mpf_class infErrorSin(Polynomial* p, mpf_class low, mpf_class high);
static mpf_class infErrorCos(Polynomial* p, mpf_class low, mpf_class high);


/*
    main
    Starts the program.
*/
int main()
{
    // Set precision of decimals.  20 should be big enough for long double precision 
    // (80 bits).
    cout << scientific << setprecision(20);
    
    cout << endl;
    cout << endl;
    
    
    // Print Version
    cout << "This software prints the best L2 approximations to sin and cos over certain "
         << "ranges." << endl;
    cout << "Version: " << VERSION << endl;
    cout << endl << endl;
    
    
    for(int interval = 0; interval < 3; interval++)
    {
        // Print orthonormal basis.
        cout << "Basis of orthogonal polynomials from " 
             << lows[interval] << " to " << highs[interval] << endl;
        Polynomial* polyArray[NUM_POLYS];
        createOrthoPolys(polyArray, NUM_POLYS, lows[interval], highs[interval]);
        for(int i = 0; i < NUM_POLYS; i++)
        {
            cout << "p[" << i << "] = ";
            polyArray[i]->print();
        }
        cout << endl;
        cout << endl;
        
        
        // Print sin approximations.
        cout << "L2 polynomial approximations of sin from " 
             << lows[interval] << " to " << highs[interval] << endl;
        for(int i = 1; i < NUM_POLYS; i+=2)
        {
            Polynomial* p = getL2ApproxSin(polyArray, i, lows[interval], highs[interval]);
            p->print();
            cout << "\tPointwise Error Estimate: " 
                 << infErrorSin(p, lows[interval], highs[interval]) << endl;
            delete p;
        }    
        cout << endl;
        cout << endl;

        
        // Print cos approximations.
        cout << "L2 polynomial approximations of cos from " 
             << lows[interval] << " to " << highs[interval] << endl;
        for(int i = 0; i < NUM_POLYS; i+=2)
        {
            Polynomial* p = getL2ApproxCos(polyArray, i, lows[interval], highs[interval]);
            p->print();
            cout << "\tPointwise Error Estimate: " 
                 << infErrorCos(p, lows[interval], highs[interval]) << endl;
            delete p;
        }
        cout << endl;
        cout << endl;
    }
    
    return 0;
}



mpf_class infErrorSin(Polynomial* p, mpf_class low, mpf_class high)
{
    mpf_class error = mpf_class(0, NUM_BITS);
    mpf_class h = (high - low) / 10000;
    
    for(int i = 0; i <= 10000; i++)
    {
        mpf_class x = low + i * h;
        mpf_class tempError = hpAbs(mpf_class(sin(x.get_d()), NUM_BITS) - p->eval(x));
        if(tempError > error)
            error = tempError;
    }
    
    return error;
}


mpf_class infErrorCos(Polynomial* p, mpf_class low, mpf_class high)
{
    mpf_class error = mpf_class(0, NUM_BITS);
    mpf_class h = (high - low) / 10000;
    
    for(int i = 0; i <= 10000; i++)
    {
        mpf_class x = low + i * h;
        mpf_class tempError = hpAbs(mpf_class(cos(x.get_d()), NUM_BITS) - p->eval(x));
        if(tempError > error)
            error = tempError;
    }
    
    return error;
}


