//
//  main.cpp
//  14891
//
//  Created by 이운형 on 09/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
using namespace std;

int map[4][8];
int contact[4][2] = {{6,2},{6,2},{6,2},{6,2}};
int rotate[4];
bool check[4];
int k;

int cal_n(int d) {
    if (d >= 2) return d-2;
    else if (d == 1) return 7;
    else return 6;
}

int cal(int d) {
    if (d > 7) {
        return 0;
    } else if ( d < 0) {
        return 7;
    } else return d;
}

void rotate_dir(int direction, int idx) {
    if (direction == -1) {
        contact[idx][0] = cal(contact[idx][0]+1);
        contact[idx][1] = cal(contact[idx][1]+1);
    }
    if (direction == 1) {
        contact[idx][0] = cal(contact[idx][0]-1);
        contact[idx][1] = cal(contact[idx][1]-1);
    }
}

int calculate() {
    int ans = 0;
    if (map[0][cal_n(contact[0][1])] == 1){
        ans += 1;
    }
    if (map[1][cal_n(contact[1][1])] == 1) {
        ans += 2;
    }
    if (map[2][cal_n(contact[2][1])] == 1) {
        ans += 4;
    }
    if (map[3][cal_n(contact[3][1])] == 1) {
        ans += 8;
    }
    return ans;
}

// 1 시계 -1 반시계
void solve(int n, int dir){
    rotate[n] = dir;
    if (n-1 >= 0 && !check[n-1]) {
        if (map[n-1][contact[n-1][1]] != map[n][contact[n][0]]){
            rotate[n-1] = -dir;
            
            check[n-1] = true;
            solve(n-1, -dir);
            check[n-1] = false;
        }
    }
    
    if (n+1 < 4 && !check[n+1]) {
        if (map[n][contact[n][1]] != map[n+1][contact[n+1][0]]) {
            rotate[n+1] = -dir;
            
            check[n+1] = true;
            solve(n+1, -dir);
            check[n+1] = false;
        }
    }
}

int main() {
    for (int i = 0 ; i<4; i++) {
        for(int j = 0; j<8; j++) {
            scanf("%1d",&map[i][j]);
        }
    }
    
    scanf("%d",&k);
    for (int i = 0; i<k; i++) {
        int num, dir;
        scanf("%d %d", &num, &dir);
        check[num-1] = true;
        solve(num-1,dir);
        check[num-1] = false;
        for (int i = 0; i<4; i++) rotate_dir(rotate[i],i);
        for (int i = 0; i<4; i++) rotate[i] = 0;
    }
    
    int ans = calculate();
    printf("%d\n",ans);
}
