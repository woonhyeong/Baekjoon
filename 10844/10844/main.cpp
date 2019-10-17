//
//  main.cpp
//  10844
//
//  Created by 이운형 on 2019/10/16.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#define DIVIDER 1000000000

long long dp[101][10];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i < 10; i++) dp[1][i] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int k = 0; k < 10; k++) {
            if (k-1 >= 0) dp[i][k] += dp[i-1][k-1];
            if (k+1 <= 9) dp[i][k] += dp[i-1][k+1];
            dp[i][k] = dp[i][k]%DIVIDER;
        }
    }
    
    long long result = 0;
    
    for (int i = 0; i < 10; i++) {
        result += dp[n][i];
    }
    
    printf("%lld\n", result%DIVIDER);
    
    return 0;
}
