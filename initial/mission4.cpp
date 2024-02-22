#include<iostream>
#include<cmath>
#include "study_in_pink1.h"
using namespace std;

MathStruct math;

int checkSubStr(const char *parent, const char *child) {// ham tra ve vi tri dau tien cua chuoi con, tra -1 neu khong phai chuoi con
    if (strlen(parent) < strlen(child)) return -1;
    for (int i = 0; i < strlen(parent); i++) {
        if (parent[i] == child[0]) {
            for (int j = 1; (j < strlen(child) && i + j < strlen(parent)); j++) {
                if (parent[i + j] != child[j]) return -1;
            }
            return i;
        }
    }
    return -1;
}

int checkLength(const char *s) {// -1 ngan hon quy dinh, -2 dai hon quy dinh, 0 hop le
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;
    return 0;
}

int checkRepeat(const char *s) {// tra sci, khong co chuoi lap thi tra -1
    for (int i = 0; i < strlen(s) - 1; i++) {
        if (s[i] == s[i + 1]) return i;
    }
    return -1;
}

bool containSpecial(const char *s) {
    char spec[] = {'@', '#', '%', '$', '!'};
    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j < 5; j++) {
            if (s[i] == spec[j]) return true;
        }
    }
    return false;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[100] = {'\0'};
    for (int i = 0, iSe = 0; i < strlen(email); i++) {
        if (email[i] != '@') {
            se[iSe] = email[i];
            iSe++;
        }
        else break;
    }
    cout << se << endl;
    int sei = checkSubStr(s, se);
    int sci = checkRepeat(s);
    if ( //truong hop mat khau hop le
        (checkLength(s) == 0) &&
        (sei == -1) &&
        (sci == -1) &&
        (containSpecial(s) == true)
    ) return -10;
    if (checkLength(s) != 0) return checkLength(s);
    if (sei != -1) return -(300 + sei);
    if (sci != -1) return -(400 + sci);
    if (!containSpecial(s)) return 5;
    return -99;
}


int main() {
    char s[] = "012345pink#pink";
    char email[] = "pink@gmail.com";
    cout << checkPassword(s, email);

    return 0;
}