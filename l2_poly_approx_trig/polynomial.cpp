/*
    File:       polynomial.cpp
    Author:     Kris Garrett
    Created:    Apr 27 2010
*/



#include "polynomial.h"
#include <iostream>
using namespace std;


/*
    Polynomial
*/
Polynomial::Polynomial(int degree)
{
    m_poly = new mpf_class[degree + 1];
    m_degree = degree;
    
    // Zero the polynomial.
    for(int i = 0; i <= degree; i++)
    {
        m_poly[i] = mpf_class(0, NUM_BITS);
    }
}


/*
    ~Polynomial
*/
Polynomial::~Polynomial()
{
    delete[] m_poly;
}


/*
    print
*/
void Polynomial::print()
{
    for(int i = m_degree; i >= 2; i--)
    {
        if(m_poly[i] != 0)
        {
            cout << ((m_poly[i] > 0) ? " + " : " - ");
            cout << hpAbs(m_poly[i]) << "x^" << i;
        }
    }
    
    // This part is so we don't print a1*x^1.
    if(m_degree >= 1)
    {
        if(m_poly[1] != 0)
        {
            cout << ((m_poly[1] > 0) ? " + " : " - ");
            cout << hpAbs(m_poly[1]) << "x";
        }
    }
    
    // This part is so we don't print a0*x^0.
    if(m_poly[0] != 0)
    {
        cout << ((m_poly[0] > 0) ? " + " : " - ");
        cout << hpAbs(m_poly[0]);
    }
    
    cout << endl;
}


/*
    set
*/
void Polynomial::set(mpf_class coeff, int deg)
{
    m_poly[deg] = coeff;
}


/*
    get
*/
mpf_class Polynomial::get(int deg)
{
    return m_poly[deg];
}


/*
    getDegree
*/
int Polynomial::getDegree()
{
    return m_degree;
}


/*
    eval
*/
mpf_class Polynomial::eval(mpf_class d)
{
    // Evaluates by doing d*(d*(d*An + A(n-1)) + A(n-2)) + ...
    mpf_class result = mpf_class(0, NUM_BITS);
    
    for(int i = m_degree; i >= 0; i--)
    {
        result = result * d + m_poly[i];
    }
    
    return result;
}


/*
    integrate
*/
mpf_class Polynomial::integrate(mpf_class low, mpf_class high)
{
    Polynomial* p = new Polynomial(m_degree + 1);
    for(int i = 0; i <= m_degree; i++)
    {
        p->set(m_poly[i] / mpf_class(i+1, NUM_BITS), i+1);
    }
    mpf_class result = p->eval(high) - p->eval(low);
    
    delete p;
    return result;
}


/*
    add
*/
Polynomial* Polynomial::add(Polynomial* p1, Polynomial* p2)
{
    int deg = (p1->getDegree() > p2->getDegree()) ? p1->getDegree() : p2->getDegree();
    
    Polynomial* p = new Polynomial(deg);
    for(int i = 0; i <= deg; i++)
    {
        mpf_class x1 = (p1->getDegree() < i) ? mpf_class(0, NUM_BITS) : p1->get(i);
        mpf_class x2 = (p2->getDegree() < i) ? mpf_class(0, NUM_BITS) : p2->get(i);
        p->set(x1 + x2, i);
    }
    
    return p;
}


/*
    sub
*/
Polynomial* Polynomial::sub(Polynomial* p1, Polynomial* p2)
{
    int deg = (p1->getDegree() > p2->getDegree()) ? p1->getDegree() : p2->getDegree();
    
    Polynomial* p = new Polynomial(deg);
    for(int i = 0; i <= deg; i++)
    {
        mpf_class x1 = (p1->getDegree() < i) ? mpf_class(0, NUM_BITS) : p1->get(i);
        mpf_class x2 = (p2->getDegree() < i) ? mpf_class(0, NUM_BITS) : p2->get(i);
        p->set(x1 - x2, i);
    }
    
    return p;
}


/*
    mult
*/
Polynomial* Polynomial::mult(Polynomial* p1, Polynomial* p2)
{
    int deg = p1->getDegree() + p2->getDegree();
    
    Polynomial* p = new Polynomial(deg);
    for(int i1 = 0; i1 <= p1->getDegree(); i1++)
    {
        for(int i2 = 0; i2 <= p2->getDegree(); i2++)
        {
            mpf_class x1 = p1->get(i1);
            mpf_class x2 = p2->get(i2);
            p->set(p->get(i1 + i2) + x1 * x2, i1 + i2);
        }
    }
    
    return p;
}


/*
    mult
*/
Polynomial* Polynomial::mult(Polynomial* p1, mpf_class d)
{
    Polynomial* p = new Polynomial(p1->getDegree());
    for(int i = 0; i <= p->getDegree(); i++)
    {
        p->set(d * p1->get(i), i);
    }
    
    return p;
}


/*
    div
*/
Polynomial* Polynomial::div(Polynomial* p1, mpf_class d)
{
    Polynomial* p = new Polynomial(p1->getDegree());
    for(int i = 0; i <= p->getDegree(); i++)
    {
        p->set(p1->get(i) / d, i);
    }
    
    return p;
}


/*
    differentiate
*/
Polynomial* Polynomial::differentiate(Polynomial* p1)
{
    if(p1->getDegree() == 0)
    {
        return new Polynomial(0);
    }
    
    Polynomial* p = new Polynomial(p1->getDegree() - 1);
    for(int i = 0; i <= p->getDegree(); i++)
    {
        p->set(p1->get(i+1) * mpf_class(i+1, NUM_BITS), i);
    }
    
    return p;
}


