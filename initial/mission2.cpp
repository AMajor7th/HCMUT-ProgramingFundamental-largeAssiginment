#include<iostream>
#include "study_in_pink1.h"
using namespace std;

MathStruct math;



//dưới đây là 3 hàm tương ứng với 3 con đường ở nhiệm vụ 2
//3 hàm này sẽ trả về xác xuất của từng đoạn đường
//xac xuat theo % = xac xuat output * 100 -> ep ve int

int nearestSquare(int x) {
    int a = 1;
    int diff = abs(x - a);
    while (true) {
        a++;
        if (abs(x -pow(a, 2)) > diff) {
            return pow(a-1, 2);    
        }
        diff = abs(x - pow(a, 2));
    }
}


int route1(int & HP1, int & EXP1, int & M1, int E2) {
    if (EXP1 >= nearestSquare(EXP1)) return 100;
    else return round((double(EXP1)/nearestSquare(EXP1) + 80)*100/123);
}

// dưới đây là code cho route2:

void r2_event1(int & HP1, int & EXP1, int & M1, int &moneySpent) {
    if (HP1 < 200) {
        HP1 = ceil(HP1 * 1.3);
        M1 -= 150;
        moneySpent += 150;
    } else {
        HP1 = ceil(HP1 * 1.1);
        M1 -= 70;
        moneySpent += 70;
    }
}

void r2_event2(int & HP1, int & EXP1, int & M1, int &moneySpent) {
    if (EXP1 < 400) {
        M1 -= 200;
        moneySpent += 200;
    } else {
        M1 -= 120;
        moneySpent += 120;
    }
    EXP1 = ceil(EXP1 * 1.13);
}

void r2_event3(int & HP1, int & EXP1, int & M1, int &moneySpent) {
    if (EXP1 < 300) {
        M1 -= 100;
        moneySpent += 100;
    } else {
        M1 -= 120;
        moneySpent += 120;
    }
    EXP1 = ceil(EXP1 * 0.9);
}

int route2(int & HP1, int & EXP1, int & M1, int E2) { // hàm tổng cho route 2
    int maxSpent;
    int moneySpent = 0;
    if (E2 % 2 == 1) { // neu e2 le, tien chi = 50% so tien ban dau, lap lai ko gioi han
        maxSpent = ceil(M1 / 2);
        while(true) {
            r2_event1(HP1, EXP1, M1, moneySpent);
            if (moneySpent >= maxSpent) break;
            r2_event2(HP1, EXP1, M1, moneySpent);
            if (moneySpent >= maxSpent) break;
            r2_event3(HP1, EXP1, M1, moneySpent);
            if (moneySpent >= maxSpent) break;
        }
    } else {
        maxSpent = M1;
        while(true) {
            r2_event1(HP1, EXP1, M1, moneySpent);
            if (moneySpent >= maxSpent) break;
            r2_event2(HP1, EXP1, M1, moneySpent);
            if (moneySpent >= maxSpent) break;
            r2_event3(HP1, EXP1, M1, moneySpent);
            if (moneySpent >= maxSpent) break;
            break;
        }
    }
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    math.checkM(M1);
    math.checkExp(EXP1);
    math.checkHp(HP1);
    
    return route1(HP1, EXP1, M1, E2);
}

int route3(int & HP1, int & EXP1, int & M1, int E2) {
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 / 10 != 0) { //neu e2 co 2 chu so
        i = ((E2/10) + (E2 % 10)) % 10;
    } else i = E2;
    return P[i];
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int P1 = route1(HP1, EXP1, M1, E2);
    int P2 = route2(HP1, EXP1, M1, E2);
    int P3 = route3(HP1, EXP1, M1, E2);
    if (P1 == 100 && P2 == 100 && P3 == 100) EXP1 = ceil(EXP1*0.75);
    int Pavg = round((P1 + P2 + P3)/3);
    if (Pavg < 50) {
        HP1 = ceil(HP1 * 0.85);
        EXP1 = ceil(EXP1 * 1.15);
    } else {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 1.2);
    }
    math.checkExp(EXP1);
    math.checkHp(HP1);
    return HP1 + EXP1 + M1;
}

int main() {
    int hp1, exp1, m1, e2;
    cin >> hp1 >> exp1 >> m1 >> e2;
    cout << traceLuggage(hp1, exp1, m1, e2);


    return 0;
}