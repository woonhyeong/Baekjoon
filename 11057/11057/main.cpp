//
//  main.cpp
//  11057
//
//  Created by 이운형 on 2019/10/16.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#define DIVIDER 10007

long long dp[1001][10];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j <= k; j++) {
                dp[i][k] += dp[i-1][j];
                dp[i][k]%=DIVIDER;
            }
        }
    }
    
    long long result = 0;
    for (int i = 0; i < 10; i++) {
        result += dp[n][i];
    }
    
    printf("%lld\n", result%DIVIDER);
    
    return 0;
}
