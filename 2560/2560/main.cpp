//
//  main.cpp
//  2560
//
//  Created by 이운형 on 22/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int a, b, d, N;
int dp[1000001];

void solve() {
    for (int i = 1; i<=N; i++) {
        if (i < a) {
            dp[i] = dp[i-1]%1000;
        } else if(i < b) {
            dp[i] = (dp[i-1] + dp[i-a])%1000;
        } else {
            dp[i] = (dp[i-1] + dp[i-a] - dp[i-b] + 1000)%1000;
        }
    }
}

void input() {
    cin >> a >> b >> d >> N;
    dp[0] = 1;
}

int main(int argc, const char * argv[]) {
    input();
    solve();
    if( N-d >= 0) {
        cout << (dp[N] - dp[N-d] + 1000)%1000 <<endl;
    } else {
        cout << (dp[N] + 1000)%1000 << endl;
    }
}
