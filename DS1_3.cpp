
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>


using namespace std;
typedef long long llint;

const int maxn = 105;
const llint mod = 1e9 + 7;
llint A[maxn][maxn], ans[maxn][maxn];

void matpower(llint pw){
    llint cur[maxn][maxn];
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++){
            cur[i][j] = A[i][j];
            ans[i][j] = (i == j);
        }

    llint temp[maxn][maxn];


    while (pw > 0){
        if (pw % 2 == 1){

            for (int i = 0; i < maxn; i++)
                for (int j = 0; j < maxn; j++){
                    temp[i][j] = 0;
                    for (int k = 0; k < maxn; k++)
                        (temp[i][j] += (ans[i][k] * cur[k][j])) %= mod;
                }
            for (int i = 0; i < maxn; i++)
                for (int j = 0; j < maxn; j++)
                    ans[i][j] = temp[i][j];
        }


        for (int i = 0; i < maxn; i++)
                for (int j = 0; j < maxn; j++){
                    temp[i][j] = 0;
                    for (int k = 0; k < maxn; k++)
                        (temp[i][j] += (cur[i][k] * cur[k][j])) %= mod;
                }
            for (int i = 0; i < maxn; i++)
                for (int j = 0; j < maxn; j++)
                    cur[i][j] = temp[i][j];

        pw /= 2;
    }
}



int main(){
    int t, i, j;
    long long unsigned n, v;
   // long long unsigned x = pow(10, 9) + 7;

    // Getting Inputs
    cin >> n >> t;
    llint f[maxn], F[maxn], a[maxn];
    for (i=0; i<=t; i=i+1)
    {
        F[i]=0;
    }

    for (i=0; i<=t; i=i+1)
    {
        cin >> a[i];
    }

    for (i=0; i<t; i=i+1)
    {
        cin >> f[i];
    }
    ////////////////
    llint f1[maxn];
    for(i=0; i<t; i=i+1)
    {
        f1[i] = f[i];
    }
    f1[t] = 1;
    ////////////////
    // A matrix
    long long B[maxn][maxn];
    // Initialize A
    for (i=0; i<=t; i=i+1)
    {
        for (j=0; j<=t; j=j+1)
        {
            A[i][j] = 0;
        }
    }
    ////
    for (i=0; i<=t; i=i+1)
    {
        for (j=0; j<=(t-2); j=j+1)
        {
            if (i == (j+1))
                A[i][j] = 1;
        }
    }
    for (i=0; i<=t; i=i+1)
    {
        A[i][t-1] = (a[t-i] + mod) % mod;
    }
    A[t][t] = 1;
    //////

   // B = bb(t, n-t+1, x);
   if (n<t)
   {
       cout << f[n];
       return 0;
   }
    matpower(n-t+1);


    for (int i = 0; i <= t; i++)
        for (int j = 0; j <= t; j++)
            B[i][j] = ans[i][j];

    for (i=0; i<=t; i=i+1)
    {
        for (j=0; j<=t; j=j+1)
        {
            B[i][j] = B[i][j]% mod;
        }
    }

    for (i=0; i<=t; i=i+1)
        {
            for (j=0; j<=t; j=j+1)
            {
                F[i] = (F[i] + f1[j]*B[j][i])% mod;
            }
        }

    if((F[t-1]% mod)<0)
        v = (F[t-1]% mod + mod) % mod;
    else
        v = F[t-1]% mod;

    cout << v;






}
