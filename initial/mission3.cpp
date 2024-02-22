#include<iostream>
#include<cmath>
#include "study_in_pink1.h"
using namespace std;

MathStruct math;



int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int map[10][10];
    int iMeet = 0, jMeet = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = ((E3 * j) + (2 * i))*(i - j);
            if (map[i][j] > E3*2) iMeet++;
            if (map[i][j] < (-E3)) jMeet++;
        }
    }
    while (iMeet / 10 > 0 || jMeet / 10 > 0) {// vong lap cong 2 chu so cua i va j
        if (iMeet / 10 > 0) {
            iMeet = (iMeet/10) + (iMeet % 10);
        }
        if (jMeet / 10 > 0) {
            jMeet = (jMeet/10) + (jMeet % 10);     
        }
    }
    int taxiPoint = map[iMeet][jMeet];
    int sherlockPoint = map[iMeet][jMeet];
    // duoi day la 4 vong for long, tuong ung voi 4 huong cua 2 duong cheo bat dau tu vi tri gap nhau
    for (int i = 1, j = 1; (iMeet + i < 10 && jMeet + j < 10); i++, j++) { //dong nam
        sherlockPoint = max(sherlockPoint, map[iMeet + i][jMeet + j]);
    }
    for (int i = 1, j = 1; (iMeet - i >= 0 && jMeet + j < 10); i++, j++) { //dong bac
        sherlockPoint = max(sherlockPoint, map[iMeet - i][jMeet + j]);
    }
    for (int i = 1, j = 1; (iMeet + i < 10 && jMeet - j >= 0); i++, j++) { //tay nam
        sherlockPoint = max(sherlockPoint, map[iMeet + i][jMeet - j]);
    }
    for (int i = 1, j = 1; (iMeet - i >= 0 && jMeet - j >= 0); i++, j++) { //tay bac
        sherlockPoint = max(sherlockPoint, map[iMeet - i][jMeet - j]);
    }
    
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if (abs(taxiPoint) > abs(sherlockPoint)) { //neu ko duoi kip
        EXP1 = ceil(EXP1*0.88);
        HP1 = ceil(HP1*0.9);
        EXP2 = ceil(EXP2*0.88);
        HP2 = ceil(HP2*0.9);
        return taxiPoint;
    } else { // neu duoi kip
        EXP1 = ceil(EXP1*1.12);
        HP1 = ceil(HP1*1.1);
        EXP2 = ceil(EXP2*1.12);
        HP2 = ceil(HP2*1.1);
        math.checkExp(EXP1);
        math.checkExp(EXP2);
        math.checkHp(HP1);
        math.checkHp(HP2);
        return sherlockPoint;
    }
    return -1;
}


int main() {
    int HP1 = 400, EXP1 = 600, HP2 = 350, EXP2 = 500, E3 = 99;
    // cin >> HP1 >> EXP1 >> HP2 >> EXP2 >> E3;
    cout << chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    return 0;
}