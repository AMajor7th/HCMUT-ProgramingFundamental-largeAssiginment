#include <iostream>
#include "study_in_pink1.h"
using namespace std;

MathStruct math;

// duoi day la 3 ham tuong ung voi 3 thong tin cua TH2 cua Nv1
    void inf2(int &exp2, int e1){ exp2 += ceil(e1/9.0 + 21); }
    void inf1(int &exp2, int e1){ exp2 += ceil(e1/4.0 + 19); }
    void inf3(int &exp2, int e1){ exp2 += ceil(e1/16.0 + 17); }

int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 <= 3) { // Truong hop 1
        switch(e1) {
            case 0: exp2 += 29; break;
            case 1: exp2 += 45; break;
            case 2: exp2 += 75; break;
            case 3: exp2 += 29 + 45 + 75; break;
            default: break;
        }
        int d = ceil(e1*3 + exp1*7);
        if (d % 2 == 0) exp1 += ceil(d/200);
        else exp1 -= ceil(d/100);
    } 


    else { // Truong hop 2
        if (e1 <= 19) {
            // code TH1
            inf1(exp2, e1);
        }
        else if (e1 <= 49) {
            //code TH2
            inf2(exp2, e1);
        }
        else if (e1 <= 65) {
            //code TH3
            inf3(exp2, e1);
        }
        else if (e1 <= 79) {
            //code TH4
            inf1(exp2, e1);
            if (exp2 > 200) inf2(exp2, e1);
        }
        else {
            // code TH5
            inf1(exp2, e1);
            inf2(exp2, e1);
            if (exp2 > 400) {
                inf3(exp2, e1);
                exp2 *= ceil(0.85*exp2);
            }
        }
        exp1 -= e1;
    }
    math.checkExp(exp1);
    math.checkExp(exp2);
    return exp1 + exp2;
}

int main() {
    int m1 = 0;
    int m2 = 0;
    int exp1 = 0;
    int exp2 = 0;
    int hp1 = 0;
    int hp2 = 0;

    int e1 = 0;

    cin >> exp1 >> exp2 >> e1;
    cout << firstMeet(exp1, exp2, e1);
    return 0;
}
 