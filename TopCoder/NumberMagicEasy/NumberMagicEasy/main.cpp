//
//  main.cpp
//  NumberMagicEasy
//
//  Created by 이운형 on 19/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class NumberMagicEasy {
public:
    int theNumber(string answer) {
        string ans[15] = { "YYYY", "YYYN", "YYNY", "YYNN", "YNYY" , "YNYN", "YNNY", "YNNN", "NYYY", "NYYN", "NYNY", "NYNN", "NNYY", "NNYN", "NNNY"};
        for (int i = 0; i < 15; i++) {
            if (ans[i] == answer) {
                return (i+1);
            }
        }
        return 16;;
//        int card[4][8] = {{1,2,3,4,5,6,7,8},{1,2,3,4,9,10,11,12},{1,2,5,6,9,10,13,14},{1,3,5,7,9,11,13,15}};
//        int ans[15] = {0,};
//
//        for (int i = 0; i < 4; i++) {
//            if (answer[i] == 'Y') {
//                for (int k = 0; k < 8; k++) {
//                    if (ans[card[i][k]] == 0) {
//                        ans[card[i][k]] = 1;
//                    }
//                }
//            } else {
//                for (int k = 0; k < 8; k++) {
//                    ans[card[i][k]] = 2;
//                }
//            }
//        }
//
//        int result = 16;
//        for (int i = 0; i < 15; i++) {
//            if (ans[i] == 1) {
//                result = i;
//                break;
//            }
//        }
//        return result;
    }
};

int main() {
    NumberMagicEasy m = NumberMagicEasy();
    string a1 = "YNYY", a2 = "YNNN", a3 = "NNNN", a4 = "YYYY", a5 = "NYNY";
    printf("%d\n",m.theNumber(a1));
    printf("%d\n",m.theNumber(a2));
    printf("%d\n",m.theNumber(a3));
    printf("%d\n",m.theNumber(a4));
    printf("%d\n",m.theNumber(a5));
}
