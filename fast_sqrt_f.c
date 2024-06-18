#include <fast_sqrt.h>

float fast_sqrt(float x)
{
    float  y;
    int i ;
    y  = x;
    i  = * ( int * ) &y;                      
    i  = 0x1FC00000 + ( i >> 1 );             
    y  = * ( float * ) &i;
    
    y = y/2 + float(x)/(2*y);
    y = y/2 + float(x)/(2*y);

    return (y/2 + float(x)/(2*y));
}
