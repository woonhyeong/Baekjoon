//
//  main.cpp
//  1912
//
//  Created by 이운형 on 2019/10/17.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
int dp[100001];

int main() {
    int n;
    scanf("%d",&n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d",&dp[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i] = std::max(dp[i], dp[i-1]+dp[i]);
    }
    
    int ans = dp[1];
    for (int i = 1; i <= n; i++){
        ans = std::max(dp[i],ans);
    }
    
    printf("%d\n",ans);
    return 0;
}
