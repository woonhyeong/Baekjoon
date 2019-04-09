//
//  main.cpp
//  14888
//
//  Created by 이운형 on 08/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num[11];
int op_num[4];
int n;
// + - x /
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i<n; i++) cin >> num[i];
    
    vector<int> op_set;
    for (int i = 0; i<4; i++) {
        int n1; cin >> n1;
        for (int k = 0; k < n1; k++) {
            op_set.push_back(i);
        }
    }
    
    int ans_max = -1000000001;
    int ans_min = 1000000001;
    do {
        int sum = num[0];
        for (int i = 1; i < n; i++) {
            int x = num[i];
            
            switch (op_set[i-1]) {
                case 0:
                    sum = sum + x;
                    break;
                case 1:
                    sum = sum - x;
                    break;
                case 2:
                    sum = sum * x;
                    break;
                case 3:
                    sum = sum / x;
                    break;
                default:
                    break;
            }
        }
        
        if (sum > ans_max) {
            ans_max = sum;
        }
        if (sum < ans_min) {
            ans_min = sum;
        }
    } while(next_permutation(op_set.begin(), op_set.end()));
    
    printf("%d\n%d\n",ans_max,ans_min);
}
