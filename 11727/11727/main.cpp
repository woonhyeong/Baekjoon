//
//  main.cpp
//  11727
//
//  Created by 이운형 on 2019/10/16.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int dp[1001];

int solve(int n) {
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (dp[n] != 0) return dp[n];
    
    dp[n] = (solve(n-1) + 2*solve(n-2))%10007;
    return dp[n];
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
//    dp[1] = 1;
//    dp[2] = 3;
//
//    for (int i = 3; i <= n; i++) {
//        dp[i] = (dp[i-1] + 2*dp[i-2])%10007;
//    }
//
//    cout << dp[n] << '\n';
    cout << solve(n) << '\n';
    return 0;
}
