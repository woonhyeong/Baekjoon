//
//  main.cpp
//  InterestingDigits
//
//  Created by 이운형 on 26/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class InterestingDigits {
    public :
    vector<int> digits(int base) {
        vector<int> ans;

        for (int i = 2; i < base; i++) {
            if ((base-1)%i == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//class InterestingDigits {
//    public :
//    vector<int> digits(int base) {
//        vector<int> ans;
//
//        for (int i = 2; i < base; i++) {
//            bool flag = true;
//
//            for (int k1 = 0; k1 < base; k1++) {
//                for (int k2 = 0; k2 < base; k2++) {
//                    for (int k3 = 0; k3 < base; k3++) {
//                        if ((k1*base*base + k2*base + k3)%i == 0 && (k1+k2+k3)%i != 0) {
//                            flag = false;
//                            break;
//                        }
//                    }
//                    if (!flag) break;
//                }
//                if (!flag) break;
//            }
//
//            if (flag) {
//                ans.push_back(i);
//            }
//        }
//
//        return ans;
//    }
//};
