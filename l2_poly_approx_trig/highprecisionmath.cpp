/*
    File:       highprecisionmath.cpp
    Author:     Kris Garrett
    Created:    May 02 2010
*/


#include "highprecisionmath.h"


/*
    hpSqrt
*/
mpf_class hpSqrt(mpf_class x)
{
    return sqrt(x);
}


/*
    hpAbs
*/
mpf_class hpAbs(mpf_class x)
{
    return abs(x);
}


/*
    exactSin
*/
mpf_class exactSin(mpf_class x)
{
    static double tol = .001;
    
    if(abs(x - 0) < tol)
        return mpf_class(0, NUM_BITS);
    if(abs(x - PI) < tol)
        return mpf_class(0, NUM_BITS);
    if(abs(x + PI) < tol)
        return mpf_class(0, NUM_BITS);
    if(abs(x - PI/2) < tol)
        return mpf_class(1, NUM_BITS);
    if(abs(x + PI/2) < tol)
        return mpf_class(-1, NUM_BITS);
    if(abs(x - PI/4) < tol)
        return mpf_class(hpSqrt(mpf_class(0.5, NUM_BITS)), NUM_BITS);
    if(abs(x + PI/4) < tol)
        return mpf_class(-hpSqrt(mpf_class(0.5, NUM_BITS)), NUM_BITS);
        
    return mpf_class(0, NUM_BITS);
}


/*
    exactCos
*/
mpf_class exactCos(mpf_class x)
{
    static double tol = .001;
    
    if(abs(x - 0) < tol)
        return mpf_class(1, NUM_BITS);
    if(abs(x - PI) < tol)
        return mpf_class(-1, NUM_BITS);
    if(abs(x + PI) < tol)
        return mpf_class(-1, NUM_BITS);
    if(abs(x - PI/2) < tol)
        return mpf_class(0, NUM_BITS);
    if(abs(x + PI/2) < tol)
        return mpf_class(0, NUM_BITS);
    if(abs(x - PI/4) < tol)
        return mpf_class(hpSqrt(mpf_class(0.5, NUM_BITS)), NUM_BITS);
    if(abs(x + PI/4) < tol)
        return mpf_class(hpSqrt(mpf_class(0.5, NUM_BITS)), NUM_BITS);
        
    return mpf_class(0, NUM_BITS);
}


