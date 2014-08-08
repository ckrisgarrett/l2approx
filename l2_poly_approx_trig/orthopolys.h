/*
    File:       orthopolys.h
    Author:     Kris Garrett
    Created:    Apr 29 2010
*/



#ifndef __ORTHO_POLYS_H
#define __ORTHO_POLYS_H

#include "polynomial.h"
#include "highprecisionmath.h"


/*
    polyArray is an array of pointers to polynomials which is to be filled in.
    size is the size of polyArray
    low/high are the bounds at which to take the L2 norm or inner product.
*/
void createOrthoPolys(Polynomial** polyArray, int size, mpf_class low, mpf_class high);

#endif
