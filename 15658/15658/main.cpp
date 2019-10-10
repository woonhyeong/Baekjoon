//
//  main.cpp
//  15658
//
//  Created by 이운형 on 2019/10/09.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;

int num[11];
int oper[4]; // + - * /
int n;
int max_num = INT_MIN;
int min_num = INT_MAX;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }
}

void brute(int idx, int sum) {
    if (idx == n) {
        if (sum > max_num) {
            max_num = sum;
        }
        
        if (sum < min_num) {
            min_num = sum;
        }
        return;
    }
    
    if (oper[0] > 0) {
        oper[0]--;
        brute(idx+1, sum+num[idx]);
        oper[0]++;
    }
    
    if (oper[1] > 0) {
        oper[1]--;
        brute(idx+1, sum-num[idx]);
        oper[1]++;
    }
    
    if (oper[2] > 0) {
        oper[2]--;
        brute(idx+1, sum*num[idx]);
        oper[2]++;
    }
    
    if (oper[3] > 0) {
        oper[3]--;
        brute(idx+1, sum/num[idx]);
        oper[3]++;
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    
    brute(1, num[0]);
    
    printf("%d\n",max_num);
    printf("%d\n",min_num);
    return 0;
}
