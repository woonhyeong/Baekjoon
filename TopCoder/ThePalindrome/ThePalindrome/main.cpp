//
//  main.cpp
//  ThePalindrome
//
//  Created by 이운형 on 26/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class ThePalindrome {
public:
    int find(string s) {
        
        int i = (int)s.size();
        while (1) {
            bool flag = true;
            for (int j = 0; j < s.size(); j++) {
                if (i-j-1 < s.size() && s[j] != s[i-j-1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
            i++;
        }
    }
};

int main() {
    ThePalindrome p = ThePalindrome();
    cout << p.find("abab") << '\n';
    cout << p.find("abacaba") << '\n';
    cout << p.find("qwerty") << '\n';
}
