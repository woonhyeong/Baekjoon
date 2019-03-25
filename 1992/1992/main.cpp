//
//  main.cpp
//  1992
//
//  Created by 이운형 on 25/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

char map[65][65];

bool isSame(int x, int y, int n) {
    for (int i = x; i < n+x; i++) {
        for (int k = y; k < y+n; k++) {
            if (map[x][y] != map[i][k]) {
                return false;
            }
        }
    }
    return true;
}

void divide(int x, int y, int n) {
    if (isSame(x, y, n)) {
        printf("%c",map[x][y]);
        return;
    }
    
    int mid = n/2;
    printf("(");
    divide(x, y, mid);
    divide(x, y+mid, mid);
    divide(x+mid, y, mid);
    divide(x+mid, y+mid, mid);
    printf(")");
}

int main() {
    int n;
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s",map[i]);
    }
    
    divide(0, 0, n);
}
