#include <iostream>
#include <algorithm>


using namespace std;

long long int module (long long int A[],long n, long i)
{
    long j;
    long long int c=1;
    for(j=0; j<n; j=j+1){
                if(j==i){
                    continue;
                }
                c = (c*A[j])%A[i];

        }
    return c%A[i];

}

long long int FindPeak(long long int A[], long n, long low, long high)
{

    if(low == high)
        return low;
    long int mid = (low + high)/2;
    if(mid == 0)
    {

        if(module(A,n,mid) >= module(A,n,mid+1))
            return mid;
        else
            return mid+1;
    }

    if(mid==(n-1))
    {
        if(module(A,n,mid) >= module(A,n,mid-1))
            return mid;
        else
            return mid-1;
    }

    if ((module(A,n,mid) >= module(A,n,mid+1)) & (module(A,n,mid) >= module(A,n,mid-1)))
        return mid;
    else if (module(A,n,mid)<module(A,n,mid+1))
        return FindPeak(A, n, mid+1, high);
    else
        return FindPeak(A, n, low, mid);

}


int main(){

  long n;

  cin >> n;

  long long int A[n] = {}, B[n];
//  fill_n(B, n, 1);
  long i;
//  long c=1;


  for(i=0; i<n; i=i+1){
    cin >> A[i];
//    c = c*A[i];
  }
//  for(i=0; i<n; i=i+1){
//        for(j=0; j<n; j=j+1){
//                if(j==i){
//                    continue;
//                }
////                B[i] = (B[i]*A[j])%A[i];
//                  B[i] = B[i]*A[j];
//        }
//        B[i] = B[i]%A[i];
//
//  }
//

//  for(i=0; i<n; i=i+1){
//        cout << B[i];
//  }


  cout << FindPeak(A, n, 0, n-1)+1;

}
