//
//  main.cpp
//  10828
//
//  Created by 이운형 on 10/09/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int stack[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int top = 0;
    
    string str = "";
    
    cin >> n;
    
    while (n--) {
        cin >> str;
        
        if (str == "push") {
            int input;
            cin >> input;
            stack[top++] = input;
        } else if (str == "top") {
            if (top <= 0) {
                cout << -1 << '\n';
            } else {
                cout << stack[top-1] << '\n';
            }
        } else if (str == "size") {
            cout << top << '\n';
        } else if (str == "empty") {
            if (top <= 0) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (str == "pop") {
            if (top <= 0) {
                cout << -1 << '\n';
            } else {
                cout << stack[--top] << '\n';
            }
        }
    }
    
    return 0;
}
