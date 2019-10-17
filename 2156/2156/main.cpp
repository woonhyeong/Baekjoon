//
//  main.cpp
//  2156
//
//  Created by 이운형 on 2019/10/17.
//  Copyright © 2019 201302458. All rights reserved.
//

/*
 나의 점화식
    D[i][0] = MAX(D[i-1][0], D[i-1][1], D[i-1][2])
    D[i][1] = D[i-1][0] + A[i];
    D[i][2] = D[i-1][1] + A[i];
 
 백준 점화식
    D[i] = D[i-1] => 마시지 않음
            D[i-2] + A[i] => 1번째로 마심
             D[i-3] + A[i-1] + A[i] => 2번째로 마심
    D[i] = MAX(D[i-1], D[i-2] + A[i], D[i-3] +A[i-1] + A[i])
 */

#include <iostream>
using namespace std;

int dp[10001];
int juice[10001];

int max(int a, int b) {
    return a<b?b:a;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> juice[i];
    }
    
    dp[1] = juice[1];
    dp[2] = max(juice[1], max(juice[2], juice[1]+juice[2]));
    
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 1], max(dp[i - 2] + juice[i], dp[i - 3] + juice[i - 1] + juice[i]));
    }
    
    cout << dp[n] <<'\n';
    return 0;
}
