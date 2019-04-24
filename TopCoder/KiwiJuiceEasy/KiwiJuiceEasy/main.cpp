//
//  main.cpp
//  KiwiJuiceEasy
//
//  Created by 이운형 on 24/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <algorithm>
#include <vector>
using namespace std;

class KiwiJuiceEasy
{
    public :
    vector<int> solve(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> todoId) {
        
        for (int i = 0; i < fromId.size(); i++) {
//            int from_idx = fromId[i];
//            int to_idx = todoId[i];
//
//            int move_value = min(bottles[from_idx], capacities[to_idx] - bottles[to_idx]);
//
//            bottles[from_idx] -= move_value;
//            bottles[to_idx] += move_value;
            int sum = bottles[fromId[i]] + bottles[todoId[i]];
            bottles[todoId[i]] = min(sum,capacities[todoId[i]]);
            bottles[fromId[i]] = sum - bottles[todoId[i]];
        }
        
        return bottles;
    }
    
};
