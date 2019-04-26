//
//  main.cpp
//  Cryptography
//
//  Created by 이운형 on 26/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Cryptography {
public:
    long long encrypt(vector<int> numbers) {
        int min_idx = 0;
        
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[min_idx] > numbers[i]) {
                min_idx = i;
            }
        }
        
        numbers[min_idx]++;
        
        long long ans = 1;
        for (int i = 0; i < numbers.size(); i++) {
            ans = ans*numbers[i];
        }
        return ans;
    }
};
