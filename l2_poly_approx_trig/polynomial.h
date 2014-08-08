/*
    File:       polynomial.h
    Author:     Kris Garrett
    Created:    Apr 27 2010
*/

#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H


#include "highprecisionmath.h"


/*
    Class Polynomial
*/
class Polynomial
{
public:
    /*
        Constructor allocates storage for a new polynomial of degree 'degree'.
        The constructor ensures a polynomial with all coefficients = 0.
        Parameter degree must be greater than or equal to zero.
        
        Destructor deletes the storage for the polynomial.
    */
    Polynomial(int degree);
    ~Polynomial();
    
    /*
        Prints the polynomial to standard out.
    */
    void print();
    
    /*
        set sets the coefficient for the given degree.
        get gets the coefficient for the given degree
    */
    void set(mpf_class coeff, int deg);
    mpf_class get(int deg);
    
    /*
        Gets the degree of the polynomial.
    */
    int getDegree();
    
    /*
        Evaluates the polynomial at the value 'd'.
    */
    mpf_class eval(mpf_class d);
    
    /*
        Integrates the polynomial between the low and high values.
    */
    mpf_class integrate(mpf_class low, mpf_class high);
    
    /*
        These return a newly allocated polynomial.
        add -  returns p1 + p2
        sub -  returns p1 - p2
        mult - returns p1 * p2  or  p1 * d
        div  - returns p1 / d
        differentiate - returns dp1/dx
    */
    static Polynomial* add(Polynomial* p1, Polynomial* p2);
    static Polynomial* sub(Polynomial* p1, Polynomial* p2);
    static Polynomial* mult(Polynomial* p1, Polynomial* p2);
    static Polynomial* mult(Polynomial* p1, mpf_class d);
    static Polynomial* div(Polynomial* p1, mpf_class d);
    static Polynomial* differentiate(Polynomial* p1);
    
private:
    mpf_class*  m_poly;        // Storage for the polynomial's coefficients.
    int         m_degree;      // Degree of the polynomial.
};

#endif
