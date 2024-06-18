#include <fast_sqrt.h>

float fast_sqrt(float x)
{
	float y;
    long i;

	/* evil floating point bit level hacking */                      
    i  = * ( long * ) &x; 
    
	 /* what the fuck? */             
	i  = 0x1FC00000 + ( i >> 1 );

    y  = * ( float * ) &i;
    
    y = y/2 + x/(2*y); /* 1st iteration */
    y = y/2 + x/(2*y); /* 2nd iteration, this can be removed */

    return y;
}
