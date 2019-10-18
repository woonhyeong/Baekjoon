//
//  main.cpp
//  2225
//
//  Created by 이운형 on 2019/10/18.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

long long dp[201][201];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i <= N; i++) {
        dp[1][i] = 1;
    }
    
    for (int i = 0; i <= K; i++) {
        dp[i][0] = 1;
    }
    
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000000;
        }
    }
    
    cout << dp[K][N] << '\n';
    
    return 0;
}
