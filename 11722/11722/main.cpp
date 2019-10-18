//
//  main.cpp
//  11722
//
//  Created by 이운형 on 2019/10/17.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int dp[1001];
int seq[1001];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n ;
    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> seq[i];
    
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int k = 1; k < i; k++) {
            if (seq[k] > seq[i] && dp[k]+1 > dp[i]) {
                dp[i] = dp[k] + 1;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (dp[i] > ans? dp[i]:ans);
    }
    
    cout << ans << '\n';
    return 0;
}
