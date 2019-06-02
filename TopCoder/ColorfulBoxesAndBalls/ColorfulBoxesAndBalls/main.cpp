//
//  main.cpp
//  ColorfulBoxesAndBalls
//
//  Created by 이운형 on 31/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

class ColorfulBoxesAndBalls {
public:
    int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors){
        if (bothColors*2 > onlyRed + onlyBlue) {
            int ans = 0;
            while (numRed > 0 && numBlue > 0) {
                numRed -= 1;
                numBlue -= 1;
                ans += bothColors*2;
            }

            if (numRed > 0 ) ans += numRed*onlyRed;
            else ans += numBlue*onlyBlue;

            return ans;
        }
        return numRed*onlyRed + numBlue*onlyBlue;
    }
};

//class ColorfulBoxesAndBalls {
//public:
//    int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors){
//        int ans = INT_MIN;
//        int change = min(numRed, numBlue);
//
//        for (int i = 0 ; i <= change ; i++) {
//            int myScore = (numRed-i)*onlyRed + (numBlue-i)*onlyBlue + 2*i*bothColors;
//            ans = max(ans, myScore);
//        }
//        return ans;
//    }
//};
