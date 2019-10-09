//
//  main.cpp
//  2309
//
//  Created by 이운형 on 2019/10/09.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int person[9];
int sum = 0;

void input() {
    int n;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &n);
        person[i] = n;
        sum += n;
    }
}

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int k = 1; k < 9-i; k++) {
            if (person[k-1] > person[k]) {
                int temp = person[k-1];
                person[k-1] = person[k];
                person[k] = temp;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            if (i == k) continue;
            
            if (sum - person[i] - person[k] == 100) {
                for (int j = 0; j < 9; j++) {
                    if ( j == i || j == k) continue;
                    printf("%d\n", person[j]);
                }
                return;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    input();
    solve();
    return 0;
}
