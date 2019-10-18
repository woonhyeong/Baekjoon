//
//  main.cpp
//  2529
//
//  Created by 이운형 on 2019/10/18.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int combi[10];
int sign[9]; // '<' = 1, '>' = 2
vector<string> ans;
int K;

void input() {
    cin >> K;
    for (int i = 0; i < 10; i++) {
        combi[i] = 1;
    }
    for (int i = 0; i <= K; i++) {
        combi[i] = 0;
    }
    for (int i = 0; i < K; i++) {
        char c;
        cin >> c;
        sign[i] = (c == '<'? 1 : 2);
    }
}

void solve() {
    
    do {
        vector<int> v;
        for (int i = 0; i < 10; i++) {
            if (combi[i] == 0) {
                v.push_back(i);
            }
        }
        
        do {
            bool flag = true;
            for (int i = 0; i < K; i++) {
                if (sign[i] == 1 && v[i] > v[i+1]) {
                    flag = false;
                    break;
                } else if (sign[i] == 2 && v[i] < v[i+1]){
                    flag = false;
                    break;
                }
            }
            
            if (!flag) continue;
            
            string str = "";
            for (int i = 0; i <= K; i++) {
                str += v[i] + '0';
            }
            
            ans.push_back(str);
        } while(next_permutation(v.begin(), v.end()));
        
    } while(next_permutation(combi, combi+10));
    
    long long max = 0, min = 9876543211;
    int maxi = 0, mini = 0;
    
    for (int i = 0; i < ans.size(); i++) {
        long long temp = stoll(ans[i]);
        if (max < temp) {
            max = temp;
            maxi = i;
        }
        
        if (min > temp) {
            min = temp;
            mini = i;
        }
    }
    
    cout << ans[maxi] << '\n';
    cout << ans[mini] << '\n';
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    solve();
    return 0;
}
