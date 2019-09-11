//
//  main.cpp
//  9093
//
//  Created by 이운형 on 11/09/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    cin.ignore();
    
    string str = "";
    
    while (n--) {
        stack<char> s;
        
        getline(cin, str);
        str += "\n";
        
        for (char c: str) {
            if (c == ' ' || c == '\n') {
                while (!s.empty()) {
                    cout << s.top();
                    s.pop();
                }
                cout << c;
            } else {
                s.push(c);
            }
        }
    }
    
    return 0;
}
