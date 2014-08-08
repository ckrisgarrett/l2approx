/*
    File:       orthopolys.cpp
    Author:     Kris Garrett
    Created:    Apr 29 2010
*/



#include "orthopolys.h"



/*
    The returned result is integral(p1*p2, low, high).
*/
static mpf_class innerProduct(Polynomial* p1, Polynomial* p2, mpf_class low, 
                              mpf_class high);

/*
    The returned result is integral(p^2, low, high)^(.5).
*/
static mpf_class norm(Polynomial* p, mpf_class low, mpf_class high);


/*
    createOrthoPolys
*/
void createOrthoPolys(Polynomial** polyArray, int size, mpf_class low, mpf_class high)
{
    for(int i = 0; i < size; i++)
    {
        // Create basis polynomial x^i.
        Polynomial* basisPoly = new Polynomial(i);
        basisPoly->set(mpf_class(1, NUM_BITS), i);
        
        // Create orthogonal polynomial using gram-schmidt.
        Polynomial* temp = new Polynomial(0);
        for(int j = i-1; j >= 0; j--)
        {
            Polynomial* p1 = Polynomial::mult(polyArray[j], 
                innerProduct(basisPoly, polyArray[j], low, high));
            Polynomial* p2 = temp;
            temp = Polynomial::add(p2, p1);
            delete p1;
            delete p2;
        }
        Polynomial* temp2 = Polynomial::sub(basisPoly, temp);
        polyArray[i] = Polynomial::div(temp2, norm(temp2, low, high));
        delete temp;
        delete temp2;
        delete basisPoly;
    }
}


/*
    norm
*/
mpf_class norm(Polynomial* p, mpf_class low, mpf_class high)
{
    Polynomial* temp = Polynomial::mult(p, p);
    mpf_class result = hpSqrt(temp->integrate(low, high));
    delete temp;
    return result;
}


/*
    innerProduct
*/
mpf_class innerProduct(Polynomial* p1, Polynomial* p2, mpf_class low, 
                         mpf_class high)
{
    Polynomial* temp = Polynomial::mult(p1, p2);
    mpf_class result = temp->integrate(low, high);
    delete temp;
    return result;
}

