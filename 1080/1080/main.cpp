//
//  main.cpp
//  1080
//
//  Created by 이운형 on 22/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char a[50][50];
char b[50][50];

void convert(int row, int col) {
    for (int i = row; i < row+3; i++) {
        for (int k = col; k < col+3; k++) {
            a[i][k] = '0' + '1' - a[i][k];
        }
    }
}

int main() {
    int n, m, i, k, r = 0;
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", a[i]);
    for (i = 0; i < n; i++) scanf("%s", b[i]);
    
    for (i = 0; i < n-2; i++) {
        for (k = 0; k < m-2; k++) {
            if (a[i][k] != b[i][k]) {
                convert(i, k);
                r++;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (strcmp(a[i], b[i])) {
            puts("-1");
            return 0;
        }
    }
    
    printf("%d",r);
    return 0;
}
