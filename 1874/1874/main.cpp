//
//  main.cpp
//  1874
//
//  Created by 이운형 on 28/09/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    stack<int> s;
    string str = "";
    int m = 0;
    
    while (n--) {
        int num;
        cin >> num;
        
        if (m < num) {
            while (m < num) {
                s.push(++m);
                str += "+";
            }
            
            str += "-";
            s.pop();
        } else {
            bool found = false;
            
            if (!s.empty()) {
                int top = s.top();
                s.pop();
                str += "-";
                
                if (top == num) {
                    found = true;
                }
            }
            
            if (!found) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    
    for (char c : str) {
        cout << c << '\n';
    }
    
    return 0;
}
