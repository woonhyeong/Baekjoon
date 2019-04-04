//
//  main.cpp
//  6603
//
//  Created by 이운형 on 04/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        
        vector<int> a(n);
        for (int i = 0; i<n; i++) cin >> a[i];
        
        vector<int> d;
        for (int i = 0; i < n-6; i++) d.push_back(0);
        for (int i = 0; i < 6; i++) d.push_back(1);
        
        vector< vector<int> > p;
        
        do {
            vector<int> current;
            for (int i = 0; i<n; i++) {
                if (d[i] == 1) {
                    current.push_back(a[i]);
                }
            }
            p.push_back(current);
        } while(next_permutation(d.begin(), d.end()));
        
        sort(p.begin(), p.end());
        
        for(int k = 0; k < (int)p.size(); k++){
            for (int i = 0; i < (int)p[k].size(); i++) {
                cout << p[k][i] << ' ';
            }
            cout << '\n';
        }
        
        cout << '\n';
    }
    return 0;
}
