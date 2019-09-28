//
//  main.cpp
//  2563
//
//  Created by 이운형 on 28/09/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>

using namespace std;

int paper[101][101];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, result = 0;
    cin >> n;
    
    while (n--) {
        int x, y;
        cin >> x >> y;
        
        for (int i = y; i < y+10; i++) {
            for (int k = x; k < x+10; k++) {
                if (paper[i][k] == 1) continue;
                paper[i][k] = 1;
                result++;
            }
        }
    }
    
    cout << result << '\n';
    
    return 0;
}
