//
//  main.cpp
//  14890
//
//  Created by 이운형 on 08/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int N, L;
int map[100][100];
bool check[100][100];
bool slope[100][100];
int ANS;

int difference(int a1, int a2) {
    return a1 < a2? a2-a1: a1-a2;
}

bool row_flat(int idx, int a1, int a2) {
    int prev = map[idx][a1];
    if (check[idx][a1]) return false;
    
    for (int i = a1+1; i <= a2; i++) {
        if (prev != map[idx][i] || check[idx][i]) {
            return false;
        }
    }
    return true;
}

bool column_flat(int idx, int a1, int a2) {
    int prev = map[a1][idx];
    if (check[a1][idx]) return false;
    
    for (int i = a1+1; i<=a2; i++) {
        if ((prev != map[i][idx]) || check[i][idx]) {
            return false;
        }
    }
    return true;
}

void left_right(int idx) {
    int prev = map[idx][0];
    bool flag = true;
    
    for (int i = 1; i < N; i++) {
        int diff = difference(prev, map[idx][i]);
        
        if (diff > 1) return;
        
        if (diff == 1) {
            
            if (prev > map[idx][i]) {
                if (i+L-1 < N && row_flat(idx, i, i+L-1)) {
                    i = i+L-1;
                    prev = map[idx][i];
                    check[idx][i] = true;
                } else {
                    return;
                }
            } else if(prev < map[idx][i]){
                if (i-L >= 0 && row_flat(idx, i-L, i-1)) {
                    prev = map[idx][i];
                    check[idx][i-L] = true;
                } else {
                    return;
                }
            }
            
        } else if(diff == 0) {
            prev = map[idx][i];
        }
    }
    
    if (flag) {
        ANS+=1;
    }
}

void top_down(int idx) {
    int prev = map[0][idx];
    bool flag = true;
    
    for (int i = 1; i < N; i++) {
        int diff = difference(prev, map[i][idx]);
        
        if (diff > 1) return;
        
        if (diff == 1) {
            if (prev > map[i][idx]) {
                if (i+L-1 < N && column_flat(idx, i, i+L-1)) {
                    i = i+L-1;
                    prev = map[i][idx];
                    check[i][idx] = true;
                } else {
                    return;
                }
            } else if(prev < map[i][idx]){
                if (i-L >= 0 && column_flat(idx, i-L, i-1)) {
                    prev = map[i][idx];
                    check[i-L][idx] = true;
                } else {
                    return;
                }
            }
        } else if(diff == 0) {
            prev = map[i][idx];
        }
    }
    
    if (flag) {
        ANS+=1;
    }
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int k = 0 ; k < N; k++) {
            check[i][k] = false;
        }
    }
}

void input() {
    for (int i=0; i < N; i++) {
        for (int k=0; k < N; k++) {
            cin >> map[i][k];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;
    input();
    
    for (int i = 0; i < N; i++ ) {
        left_right(i);
    }
    
    init();
    
    for (int i = 0; i < N; i ++ ) {
        top_down(i);
    }
    
    cout << ANS << endl;
}
