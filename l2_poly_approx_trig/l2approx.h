/*
    File:       l2approx.h
    Author:     Kris Garrett
    Created:    May 01 2010
*/



#ifndef __L2_APPROX_H
#define __L2_APPROX_H

#include "polynomial.h"
#include "highprecisionmath.h"


/*
    Computes the L2 approximation of sin and cos using the orthogonal family of 
    polynomials in polyArray up to the given degree.
*/
Polynomial* getL2ApproxSin(Polynomial** polyArray, int degree, mpf_class low, 
                           mpf_class high);
Polynomial* getL2ApproxCos(Polynomial** polyArray, int degree, mpf_class low, 
                           mpf_class high);

#endif
