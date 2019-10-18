//
//  main.cpp
//  14002
//
//  Created by 이운형 on 2019/10/17.
//  Copyright © 2019 201302458. All rights reserved.
//

/*
 기본 점화식
    D[i] = Max(D[k]) + 1 (0 < k < i, seq[i] > seq[k])
 */
#include <iostream>
#include <deque>
using namespace std;

int seq[1001];
int dp[1001];
int memo[1001];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        memo[i] = i;
        for (int k = 1; k < i; k++) {
            if (seq[k] < seq[i] && dp[k] + 1 > dp[i]) {
                dp[i] = dp[k] + 1;
                memo[i] = k;
            }
        }
    }
    
    int result = 0;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > result) {
            result = dp[i];
            idx = i;
        }
    }

    deque<int> q;
    q.push_front(idx);
    while (memo[idx] != idx) {
        q.push_front(memo[idx]);
        idx = memo[idx];
    }
    
    cout << result << '\n';
    
    int size = (int)q.size();
    
    while (!q.empty()) {
        cout << seq[q.front()];
        q.pop_front();
        size--;
        if (size) {
            cout << ' ';
        } else {
            cout << '\n';
        }
    }
    
    return 0;
}
