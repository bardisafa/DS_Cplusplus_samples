#include <iostream>
//#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

long long unsigned bb (long long unsigned a, long long unsigned b, long long unsigned x)
{
    long long unsigned c,d;
    if(b==1)
        return a;

    if ( b%2 == 0 )
    {
        c = bb(a, b/2, x)%x;
        if(c<0)
        {
            c = c+x;
        }
        d = (c*c)%x;
        if(d<0)
            d=d+x;
        return d;
    }
    else
    {

        c = bb(a, (b-1)/2, x)%x;
        if(c<0)
            c = c+x;
        d =(((c*c)%x)*a)%x;
        if(d<0)
            d=d+x;
        return d;
    }

}

int main(){

    long long unsigned x = pow(10, 9) + 7;
    long long unsigned a, b;
    cin >> a >> b;
//    for(i=0; i<b; i=i+1)
//    {
//        c=c*a;
//    }
//
    long long unsigned z = bb(a, b, x);
    if(z<0)
        z = z+x;
    cout << z;


}
