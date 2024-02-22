/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "main.h"

bool readFile( const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

struct MathStruct { // struct này để lưu các hàm liên quan đến xử lí số liệu toán học
    int roundUp(int x) {return int(x);}
    int roundUp(double x) {return int(x) + 1;}
    int roundUp(long double x) {return int(x) + 1;}
    int roundUp(float x) {return int(x) + 1;}

    int max(int a, int b) {return a >= b ? a : b;}
    int min(int a, int b) {return a <= b ? a : b;}


    // cac ham de gioi han gia tri ve range dung cua cac so lieu
    void checkHp(int &hp) {
        hp = max(0, hp);
        hp = min(666, hp);
    } 
    void checkExp(int &exp) {
        exp = max(0, exp);
        exp = min(600, exp);
    } 
    void checkM(int &m) {
        m = max(0, m);
        m = min(3000, m);
    } 

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
};

// Task 1
int firstMeet(int & exp1, int & exp2, int e1);

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
