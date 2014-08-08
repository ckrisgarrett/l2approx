/*
    File:       highprecisionmath.h
    Author:     Kris Garrett
    Created:    May 02 2010
*/



#ifndef __HIGH_PRECISION_MATH_H
#define __HIGH_PRECISION_MATH_H

#include <gmpxx.h>

static const int NUM_BITS = 256;

// From CRC Standard Mathematical Tables 26th Edition.
static const mpf_class PI("3.14159265358979323846264338327950288419716939937511", NUM_BITS, 10);




/*
    Computes square root of x to mpf_class tolerance.
*/
mpf_class hpSqrt(mpf_class x);

/*
    Computes absoulte value of x to mpf_class tolerance.
*/
mpf_class hpAbs(mpf_class x);

/*
    Expects x to be -pi, -pi/2, -pi/4, 0, pi/4, pi/2, or pi.  If x is not within .001 of these values, 
    the functions return 0.
*/
mpf_class exactSin(mpf_class x);
mpf_class exactCos(mpf_class x);

#endif
