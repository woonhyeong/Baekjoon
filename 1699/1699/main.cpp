//
//  main.cpp
//  1699
//
//  Created by 이운형 on 2019/10/18.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i*i <= 100000; i++) {
        dp[i*i] = 1;
    }
    
    if (dp[n] == 1) {
        cout << 1 << '\n';
        return 0;
    }
    
    for (int i = 2; i <= n; i++) {
        dp[i] = i;
        for (int k = 1; k*k < i; k++) {
            dp[i] = min(dp[i-k*k] + 1, dp[i]);
        }
    }
    
    cout << dp[n] << '\n';
    return 0;
}
