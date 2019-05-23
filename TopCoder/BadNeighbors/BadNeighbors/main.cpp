//
//  main.cpp
//  BadNeighbors
//
//  Created by 이운형 on 23/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;

/*
 2~40개의 요소가 있는 배열입니다. 각 요소는 1~1000 사이의 값입니다.
 */
class BadNeighbors {
public:
    int maxDonations(vector<int> donations) {
        
        int dp_01[41] = {0,};
        int dp_02[41] = {0,};
        
        for (int i = 0; i < donations.size()-1; i++) {
            dp_01[i] = donations[i];
            
            if (i > 0) dp_01[i] = max(dp_01[i],dp_01[i-1]);
            if (i > 1) dp_01[i] = max(dp_01[i],dp_01[i-2]+donations[i]);
        }
        
        for (int i = 1; i < donations.size(); i++) {
            dp_02[i] = donations[i];
            
            if (i > 0) dp_02[i] = max(dp_02[i],dp_02[i-1]);
            if (i > 1) dp_02[i] = max(dp_02[i],dp_02[i-2]+donations[i]);
        }
        
        return max(dp_01[donations.size()-2], dp_02[donations.size()-1]);
    }
};

int main() {
    BadNeighbors b = BadNeighbors();
    
    vector<int> donations = {10,3,2,5,7,8};
    cout << b.maxDonations(donations) << '\n';
}
