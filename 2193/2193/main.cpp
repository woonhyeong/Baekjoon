//
//  main.cpp
//  2193
//
//  Created by 이운형 on 2019/10/17.
//  Copyright © 2019 201302458. All rights reserved.
//


/*
 D[i][0] = D[i-1][1] + D[i-1][0]
 D[i][1] = D[i][1] + D[i-1][0] = D[i-2][1] + D[i-2][0]
 마지막에 1이 오는경우, 앞 i-1 에 올 수 있는 값은 0 밖에 없다.
 그래서 i-2에 오는 경우의 수를 구하면 된다.
 
 결과, D[i] = D[i-1] + D[i-2]
 */
#include <stdio.h>

long long dp[91];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    printf("%lld\n",dp[n]);
    
    return 0;
}
