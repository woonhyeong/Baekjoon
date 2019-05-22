//
//  main.cpp
//  12865
//
//  Created by 이운형 on 22/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
#include <iostream>
using namespace std;

int dp[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int input = 1; input <= N; input++) {
        int w, p;
        cin >> w >> p;

        for (int i = K; i >= w; i--) {
            dp[i] = max(dp[i], dp[i-w]+p);
        }
    }

    cout << dp[K] << '\n';
}

//#include <iostream>
//using namespace std;
//
//int dp[101][100001];
//int w[101];
//int p[101];
//
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    int N, K;
//    cin >> N >> K;
//
//    for (int input = 1; input <= N; input++) {
//        cin >> w[input] >> p[input];
//    }
//
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= K; j++) {
//            dp[i][j] = dp[i-1][j];
//            if (j - w[i] >= 0) {
//                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+p[i]);
//            }
//        }
//    }
//
//    cout << dp[N][K] << '\n';
//}

