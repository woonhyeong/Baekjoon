//
//  main.cpp
//  5373
//
//  Created by 이운형 on 11/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int N;
char U[9] = {'w','w','w','w','w','w','w','w','w'};
char F[9] = {'r','r','r','r','r','r','r','r','r'};
char D[9] = {'y','y','y','y','y','y','y','y','y'};
char L[9] = {'g','g','g','g','g','g','g','g','g'};
char R[9] = {'b','b','b','b','b','b','b','b','b'};
char B[9] = {'o','o','o','o','o','o','o','o','o'};

void rotate_U(int direction) {
    if (direction == 1) {
        char u1 = U[1], u2 = U[2];
        U[2] = U[0]; U[1] = U[3]; U[0] = U[6]; U[3] = U[7]; U[6] = U[8];U[8] = u2; U[5] = u1;
        
        char f0 = F[0], f1 = F[1], f2 = F[2];
        F[0] = R[6]; F[1] = R[3]; F[2] = R[0];
        R[6] = B[8]; R[3] = B[7]; R[0] = B[6];
        B[8] = L[2]; B[7] = L[5]; B[6] = L[8];
        L[2] = f0; L[5] = f1; L[8] = f2;
    } else {
        rotate_U(1); rotate_U(1); rotate_U(1);
    }
}

void rotate_F(int direction) {
    if (direction == 1) {
        char f1 = F[1], f2 = F[2];
        F[2] = F[0]; F[1] = F[3]; F[0] = F[6]; F[3] = F[7]; F[6] = F[8]; F[8] = f2; F[5] = f1;
        
        char u6 = U[6], u7 = U[7], u8 = U[8];
        U[6] = L[6]; U[7] = L[7]; U[8] = L[8];
        L[8] = D[0]; L[7] = D[1]; L[6] = D[2];
        D[0] = R[8]; D[1] = R[7]; D[2] = R[6];
        R[6] = u6; R[7] = u7; R[8] = u8;
    } else {
        rotate_F(1); rotate_F(1); rotate_F(1);
    }
}

void rotate_D(int direction) {
    if (direction == 1) {
        char d1 = D[1], d2 = D[2];
        D[2] = D[0]; D[1] = D[3]; D[0] = D[6]; D[3] = D[7]; D[6] = D[8]; D[7] = D[5]; D[8] = d2; D[5] = d1;
        
        char f6 = F[6], f7 = F[7], f8 = F[8];
        F[6] = L[0]; F[7] = L[3]; F[8] = L[6];
        L[0] = B[2]; L[3] = B[1]; L[6] = B[0];
        B[2]= R[8]; B[1] = R[5]; B[0] = R[2];
        R[8] = f6; R[5] = f7; R[2] = f8;
    } else {
        rotate_D(1); rotate_D(1); rotate_D(1);
    }
}

void rotate_L(int direction) {
    if (direction == 1) {
        char l1 = L[1], l2 = L[2];
        L[2] = L[0]; L[1] = L[3]; L[0] = L[6]; L[3] = L[7]; L[6] = L[8];L[8] = l2; L[5] = l1;

        char u0 = U[0], u3 = U[3], u6 = U[6];
        U[0] = B[0]; U[3] = B[3]; U[6] = B[6];
        B[6] = D[6]; B[3] = D[3]; B[0] = D[0];
        D[6] = F[6]; D[3] = F[3]; D[0] = F[0];
        F[6] = u6; F[3] = u3; F[0] = u0;
    } else {
        rotate_L(1); rotate_L(1); rotate_L(1);
    }
}

void rotate_R(int direction) {
    if (direction == 1) {
        char r1 = R[1], r2 = R[2];
        R[2] = R[0]; R[1] = R[3]; R[0] = R[6]; R[3] = R[7]; R[6] = R[8];R[8] = r2; R[5] = r1;
        
        char u8 = U[8], u5 = U[5], u2 = U[2];
        U[8] = F[8]; U[5] = F[5]; U[2] = F[2];
        F[2] = D[2]; F[5] = D[5]; F[8] = D[8];
        D[2] = B[2]; D[5] = B[5]; D[8] = B[8];
        B[2] = u2; B[5] = u5; B[8] = u8;
    } else {
        rotate_R(1); rotate_R(1); rotate_R(1);
    }
}

void rotate_B(int direction) {
    if (direction == 1) {
        char b1 = B[1], b2 = B[2];
        B[2] = B[0]; B[1] = B[3]; B[0] = B[6]; B[3] = B[7]; B[6] = B[8];B[8] = b2; B[5] = b1;
        
        char u2 = U[2], u1 = U[1], u0 = U[0];
        U[0] = R[0]; U[1] = R[1]; U[2] = R[2];
        R[0] = D[8]; R[1] = D[7]; R[2] = D[6];
        D[8] = L[0]; D[7] = L[1]; D[6] = L[2];
        L[0] = u0; L[1] = u1; L[2] = u2;
    } else {
        rotate_B(1); rotate_B(1); rotate_B(1);
    }
}

void init() {
    for (int d = 0; d < 9; d++) {U[d] = 'w';}
    for (int d = 0; d < 9; d++) {F[d] = 'r';}
    for (int d = 0; d < 9; d++) {D[d] = 'y';}
    for (int d = 0; d < 9; d++) {L[d] = 'g';}
    for (int d = 0; d < 9; d++) {R[d] = 'b';}
    for (int d = 0; d < 9; d++) {B[d] = 'o';}
}

void output() {
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            cout << U[3*i + k];
        }
        cout << endl;
    }
}

int main() {
    
    cin >> N;
    while(N--){
        int iter;
        cin >> iter;
        for (int k = 0; k < iter; k++) {
            string str;
            cin >> str;
            char dimension = str[0];
            int direction = str[1]=='+'?1:0;
            
            if (dimension == 'L') {
                rotate_L(direction);
            } else if (dimension == 'U') {
                rotate_U(direction);
            } else if (dimension == 'R') {
                rotate_R(direction);
            } else if (dimension == 'B') {
                rotate_B(direction);
            } else if (dimension == 'F') {
                rotate_F(direction);
            } else if (dimension == 'D') {
                rotate_D(direction);
            }
        }
        output();
        init();
    }
}
