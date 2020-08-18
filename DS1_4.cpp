
#include <iostream>
#include <algorithm>

using namespace std;

    long long A[1600][1600];
    long long B[1600][1600];
    long long C[1600][1600];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    long i, j, k;
    long n, m, r;
    cin >> n >> m >> r;

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cin >> A[i][j];
        }
    }
    for (i=0; i<m; i++)
    {
        for (j=0; j<r; j++)
        {
            cin >> B[i][j];
        }
    }
    for (i=0; i<n; i++)
    {
        for (j=0; j<r; j++)
        {
            cin >> C[i][j];
        }
    }
    ////////////
    long long c_prime[m];
    for (i=0; i<m; i++)
    {
        c_prime[i] = 0;
    }
    long long cc_prime[n];
    for (i=0; i<n; i++)
    {
        cc_prime[i] = 0;
    }

    for (i=0; i<m; i++)
    {
        for (j=0; j<r; j++)
        {
            c_prime[i] = c_prime[i] + B[i][j];
        }
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cc_prime[i] = cc_prime[i] + A[i][j]*c_prime[j];    // jamee satr haye c prime
        }
    }

    long long c[n];
    for (i=0; i<n; i++)
    {
        c[i] = 0;
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<r; j++)
        {
            c[i] = c[i] + C[i][j];
        }
    }

    long h;

    for (i=0; i<n; i++)
    {
        if ( c[i] != cc_prime[i] )
            break;
    }
    h = i;   // shomare satr ghalat

    long long d[r];
    for (i=0; i<r; i++)
    {
        d[i] = 0;
    }

    for (i=0; i<r; i++)
    {
        for (j=0; j<m; j++)
        {
            d[i] = d[i] + A[h][j]*B[j][i];    // satr h e C prime
        }
    }

    for (i=0; i<r; i++)
    {
        if(d[i] != C[h][i])
            break;
    }

    cout << h+1 << " " << i+1;










}
