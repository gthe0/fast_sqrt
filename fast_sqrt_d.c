/*
	Author: gtheo

	fast_sqrt_d.c

	This file contains the implementation of the double
	precision version
*/

#include <fast_sqrt.h>

double fast_sqrt_d(double x)
{
	double y;
	long long i;

	/* evil floating point bit level hacking */                      
	i  = * ( long long * ) &x; 
	
	 /* what the fuck? */             
	i  = 0x1FF7FFFDCFB74000LL + ( i >> 1 );

	y  = * ( double * ) &i;
	
	y = y/2 + x/(2*y); /* 1st iteration */
	y = y/2 + x/(2*y); /* 2nd iteration, this can be removed */

	return y;
}