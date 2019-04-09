//
//  main.cpp
//  14890
//
//  Created by 이운형 on 08/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int map[100][100];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        for (int k=0; k<n; k++) {
            cin >> map[i][k];
        }
    }
}
