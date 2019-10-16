//
//  main.cpp
//  15990
//
//  Created by 이운형 on 2019/10/16.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

long long dp[100001][3];

int main(int argc, const char * argv[]) {
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    
    for (int i = 4; i < 100001; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2])%1000000009;
        dp[i][1] = (dp[i-2][0] + dp[i-2][2])%1000000009;
        dp[i][2] = (dp[i-3][0] + dp[i-3][1])%1000000009;
    }
    
    int T, n;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d",&n);
        printf("%d\n",(dp[n][0] + dp[n][1] + dp[n][2])%1000000009);
    }
    
    return 0;
}
