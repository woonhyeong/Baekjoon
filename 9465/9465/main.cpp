//
//  main.cpp
//  9465
//
//  Created by 이운형 on 2019/10/17.
//  Copyright © 2019 201302458. All rights reserved.
//

/*
 나의 점화식
    D[0][i] = MAX(D[1][i-1], D[1][i-2])
    D[1][i] = MAx(D[0][i-1], D[0][i-2])
    복잡도 O(n)
 백준 점화식
    D[i][0] = MAX(D[i-1][0], D[i-1][1], D[i-1][2])
    D[i][1] = MAX(D[i-1][0], D[i-1][2]) + Card value
    D[i][2] = MAX(D[i-1][0], D[i-1][1]) + Card value
 */

#include <stdio.h>

#define UP 0
#define DOWN 1

long long dp[2][100001];


long long max(long long a, long long b) {
    return a < b? b:a;
}

int main(int argc, const char * argv[]) {
    int T;
    scanf("%d",&T);
    
    while (T--) {
        int n;
        scanf("%d",&n);
        
        for(int k = 0; k < 2; k++) {
            for (int i = 1; i <= n; i++) {
                scanf("%lld",&dp[k][i]);
            }
        }
        
        for (int i = 2; i <= n; i++) {
            dp[UP][i] = max(dp[DOWN][i-1], dp[DOWN][i-2]) + dp[0][i];
            dp[DOWN][i] = max(dp[UP][i-1], dp[UP][i-2]) + dp[1][i];
        }
        
        printf("%lld\n", max(dp[UP][n], dp[DOWN][n]));
    }
    return 0;
}
