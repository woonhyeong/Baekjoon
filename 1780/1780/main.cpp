//
//  main.cpp
//  1780
//
//  Created by 이운형 on 24/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int map[2187][2187];
int result[3];

bool isSame(int x, int y, int n) {
    for (int i = x; i < n+x; i++) {
        for (int k = y; k < n+y; k++) {
            if (map[x][y] != map[i][k]) {
                return false;
            }
        }
    }
    return true;
}

void divide(int x, int y, int n) {
    if (isSame(x, y, n)) {
        result[map[x][y]+1]++;
    } else {
        int mid = n/3;
        for (int i = 0; i < n; i+=mid) {
            for (int k = 0; k < n; k+=mid) {
                divide(x + i, y + k, mid);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            scanf("%d",&map[i][k]);
        }
    }
    
    divide(0, 0, n);
    
    for (int i = 0; i< 3; i ++) {
        printf("%d ", result[i]);
    }
    puts("");
    return 0;
}
