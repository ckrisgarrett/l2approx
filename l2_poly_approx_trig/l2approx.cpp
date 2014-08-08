/*
    File:       l2approx.cpp
    Author:     Kris Garrett
    Created:    May 01 2010
*/

#include "l2approx.h"
#include "highprecisionmath.h"


/*
    These two functions calculate the integral(p*sin, low, high) and 
    integral(p*cos, low, high) recursively using integration by parts.
*/
static mpf_class integratePolyAndSin(Polynomial* p, mpf_class low, mpf_class high);
static mpf_class integratePolyAndCos(Polynomial* p, mpf_class low, mpf_class high);


/*
    getL2ApproxSin
*/
Polynomial* getL2ApproxSin(Polynomial** polyArray, int degree, mpf_class low, 
                           mpf_class high)
{
    Polynomial* p = new Polynomial(0);
    for(int i = 0; i <= degree; i++)
    {
        Polynomial* temp = Polynomial::mult(polyArray[i], 
            integratePolyAndSin(polyArray[i], low, high));
        p = Polynomial::add(p, temp);
        delete temp;
    }
    
    return p;
}


/*
    getL2ApproxCos
*/
Polynomial* getL2ApproxCos(Polynomial** polyArray, int degree, mpf_class low, 
                           mpf_class high)
{
    Polynomial* p = new Polynomial(0);
    for(int i = 0; i <= degree; i++)
    {
        Polynomial* temp = Polynomial::mult(polyArray[i], 
            integratePolyAndCos(polyArray[i], low, high));
        p = Polynomial::add(p, temp);
        delete temp;
    }
    
    return p;
}


/*
    integratePolyAndSin
*/
mpf_class integratePolyAndSin(Polynomial* p, mpf_class low, mpf_class high)
{
    if(p->getDegree() == 0)
    {
        return p->get(0) * (exactCos(low) - exactCos(high));
    }
    
    // Integration by parts recursion.
    // u = p, dv = sin, v = -cos, du = p'
    Polynomial* diff = Polynomial::differentiate(p);
    mpf_class result = p->eval(low) * exactCos(low) - p->eval(high) * exactCos(high) + 
        integratePolyAndCos(diff, low, high);
    delete diff;
    
    return result;
}


/*
    integratePolyAndCos
*/
mpf_class integratePolyAndCos(Polynomial* p, mpf_class low, mpf_class high)
{
    if(p->getDegree() == 0)
    {
        return p->get(0) * (exactSin(high) - exactSin(low));
    }
    
    // Integration by parts recursion.
    // u = p, dv = cos, v = sin, du = p'
    Polynomial* diff = Polynomial::differentiate(p);
    mpf_class result = p->eval(high) * exactSin(high) - p->eval(low) * exactSin(low) - 
        integratePolyAndSin(diff, low, high);
    delete diff;
    
    return result;
}

