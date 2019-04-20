//
//  main.cpp
//  Numbering_Baseball
//
//  Created by 이운형 on 21/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int get_one(int num, int idx) {
    for(int i = 2; i > idx; i--) num /= 10;
    return num%10;
}

bool overriding_check(int a) {
    if(get_one(a,0) == get_one(a,1) || get_one(a,0) == get_one(a,2) || get_one(a,1) == get_one(a,2)) return true;
    if(get_one(a,0) == 0 || get_one(a,1) == 0 || get_one(a,2) == 0) return true;
    return false;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    for(int a = 123; a < 988; a++) {
        if(overriding_check(a)) continue;
        
        bool flag = true;
        for (int b = 0; b < baseball.size(); b++) {
            if(baseball[b][1] == 3) {
                if (a == baseball[b][0]) break;
            }
            
            int strike = 0, ball = 0;
            int b_num = baseball[b][0];
            
            for(int c = 0; c < 3; c++) {
                for(int d = 0; d < 3; d++) {
                    if(c == d && get_one(a,c) == get_one(b_num,d)) {
                        strike++;
                    } else if(get_one(a,c) == get_one(b_num,d)) {
                        ball++;
                    }
                }
            }
            
            if(strike != baseball[b][1] || ball != baseball[b][2]) {
                flag = false;
                break;
            }
        }
        
        if (flag) answer += 1;
    }
    return answer;
}
