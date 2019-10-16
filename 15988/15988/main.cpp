//
//  main.cpp
//  15988
//
//  Created by 이운형 on 2019/10/16.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#define DIVISOR 1000000009
using namespace std;

long long dp[1000001];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 1000000; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%DIVISOR;
    }

    while (T--) {
        int n;
        cin >> n;
    
        cout << dp[n] << '\n';
    }
    
    return 0;
}
