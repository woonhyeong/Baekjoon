//
//  main.cpp
//  HandsShaking
//
//  Created by 이운형 on 26/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

/*
 n = 2~50의 짝수
 카탈란 수 문제 ( 그려보는 걸 추천 )
 */
#include <iostream>
using namespace std;

class HandsShaking {
public:
    long countPerfect(int n) {
        long dp[26] = {0,};
        dp[0] = 1;
        
        for (int i = 1; i <= n/2; i++) {
            for (int k = 0; k < i; k++) {
                dp[i] += dp[i-k-1] * dp[k];
            }
        }
        
        return dp[n/2];
    }
};

int main() {
    HandsShaking h = HandsShaking();
    cout << h.countPerfect(50) << '\n';
}
