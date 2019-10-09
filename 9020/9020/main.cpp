//
//  main.cpp
//  9020
//
//  Created by 이운형 on 2019/10/09.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#define MAX_SIZE 10000

bool check[MAX_SIZE+1];

void make_decimal() {
    
    check[0] = true;
    check[1] = true;
    
    for (int i = 2; i*i < MAX_SIZE; i++) {
        if (!check[i]) {
            for (int j = i*i; j < MAX_SIZE; j+=i) {
                check[j] = true;
            }
        }
    }
}

void solve(int n) {
    for (int i = n/2; i >= 2; i--) {
        int remain = n - i;
        if (!check[i] && !check[remain]) {
            printf("%d %d\n", i, remain);
            return;
        }
    }
}

int main(int argc, const char * argv[]) {
    make_decimal();
    
    int T, n;
    scanf("%d",&T);
    
    while (T--) {
        scanf("%d",&n);
        solve(n);
    }
    
    return 0;
}
