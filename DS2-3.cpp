#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long llint;
const llint maxn = 2000001;
//const int under=0, over=0, empt=0, full=0;

struct Element{
llint index;
llint value;

} A[maxn];

llint Stack[2][maxn], L[maxn], R[maxn], top;

void push(struct Element x){
//    if(top >= maxn)
//        over =1;
//    else {
        top++;
        Stack[0][top]=x.value;
        Stack[1][top]=x.index;
//    }

}
void pop(){
//    if(top <= 0 )
//        under = 1;
//    else{
        top--;
//    }

}
llint peek(){
    return Stack[0][top];

}



int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

llint i, n, p;

cin >> n;
for (i=0; i<n; i++){

    cin >> A[i].value;
    A[i].index = i;
}
top =-1;
llint result;
for (i=0;i<n;i++){
    result =-1;
    while (top>=0){
            p = peek();
//            if(i==0){
//                L[i]==-1;
//                break;
//            }

            if(A[i].value>p){
                result=Stack[1][top]+1;
                push(A[i]);
                break;
            }
            else if(A[i].value<=p){
                pop();
            }
    }
    if(result==-1)
    {
        L[i] = 0;
        push(A[i]);
    }
    else L[i] = result;

}

top = -1;

for (i=n-1;i>=0;i--){

    result=-1;
    while (top>=0){
            p = peek();
//            if(top == -1){
//                push(A[i]);
//                R[i] = 0;
//                break;
//            }
            if(A[i].value>p){
                result=Stack[1][top]+1;
                push(A[i]);
                break;
            }
            else if(A[i].value<=p){
                pop();
            }


    }
    if (result==-1){
        push(A[i]);
        R[i] = 0;
    } else R[i] =result;


}
//for(i=0;i<n;i++){
//        L[i] = L[i]+1;
//        R[i] = R[i]+1;
//
//}


for(i=0;i<n;i++){
    cout << L[i] << " " << R[i] << "\n" ;
}

}
