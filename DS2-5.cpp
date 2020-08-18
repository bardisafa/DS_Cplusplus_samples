#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

typedef long long llint;
const int maxn = 2000005;
const llint mod = 1e9 + 7;
string s;
//const int under=0, over=0, empt=0, full=0;


int stack_adad[maxn], stack_amal[maxn], top_adad = 0, top_amal = 0;
const int ZARB = 1, JAM = 2, MENHA = 3, BAZ = 4, BASTE = 5;

int compute(llint x1, llint x2, int type){
    if (type == JAM)
        return (x1 + x2) % mod;
    if (type == MENHA)
        return (x1 - x2 + mod) % mod;
    assert(1 == 2);
}

void pop_adad(){
        top_adad--;
}
void pop_amal(){
        top_amal--;
}

int pick_adad(){
    if (top_adad == 0) return -1;
    return stack_adad[top_adad - 1];
}

int pick_amal(){
    if (top_amal == 0) return -1;
    return stack_amal[top_amal - 1];
}

void push_adad(int x){
        stack_adad[top_adad]=x;
        top_adad++;

        if (pick_amal() == ZARB){
           // cout << "zarb mikonam!" << endl;
            llint x1 = pick_adad();
            pop_adad();
            llint x2 = pick_adad();
            pop_adad();
            pop_amal(); // you should place this func before push_adad
            push_adad(x1 * x2 % mod);
        }
}
void push_amal(int x){
        stack_amal[top_amal]=x;
        top_amal++;
}

int relaxNum[maxn], relaxOp[maxn], relaxSz;

void relax(){
    relaxSz = 0;
    pop_amal();  // for ')'
    while (pick_amal() != BAZ){
        relaxOp[relaxSz] = pick_amal();
        pop_amal();
        relaxNum[relaxSz] = pick_adad();
        pop_adad();
        relaxSz++;
    }
    pop_amal();   // for '('
    relaxNum[relaxSz] = pick_adad();
    pop_adad();

    llint res = 0;
    for (int i = relaxSz - 1; i >= 0; i--){
        llint cur = compute(relaxNum[i+1], relaxNum[i], relaxOp[i]);
        relaxNum[i] = cur;
    }
    push_adad(relaxNum[0]);
}

int main(){
    int ans=0;

    cin >> s;
    s = "(" + s + ")";
  //  cout << s << endl;

    for (int ptr = 0; ptr < s.length();){
        if (isdigit(s[ptr])){
            int adad = 0;
            while (ptr < s.length() && isdigit(s[ptr])){
                adad *= 10;
                adad += (s[ptr] - '0');
                ptr++;
            }

            push_adad(adad);
        }
        else {
            int type = 0;
            if (s[ptr] == '*') type = ZARB;
            if (s[ptr] == '+') type = JAM;
            if (s[ptr] == '-') type = MENHA;
            if (s[ptr] == '(') type = BAZ;
            if (s[ptr] == ')') type = BASTE;

            push_amal(type);

            ptr++;

            if (type == BASTE){
                relax();
            } else { /*do nothing*/}
        }

    }

    cout << pick_adad() << endl;


}

