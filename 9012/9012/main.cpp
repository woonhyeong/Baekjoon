//
//  main.cpp
//  9012
//
//  Created by 이운형 on 28/09/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    while (n--) {
        string str;
        cin >> str;
        
        int result = 0;
        
        for(char c : str) {
            if (c == '(') {
                result ++;
            } else if (c == ')') {
                result --;
            }
            
            if (result < 0) {
                result = 1;
                break;
            }
        }
        
        if (result == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
