//
//  main.cpp
//  14806
//
//  Created by 이운형 on 25/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ci pair<string,int>
using namespace std;

vector<string> red;
vector<string> yellow;
vector<string> blue;

void make_single(int R, int O, int Y, int G, int B, int V) {
    if (O > 0) {
        string s;
        for (int i = 0 ; i < O; i++) {
            s += "BO";
            B--;
        }
        
        if (B>0) {
            s+= "B";
            B--;
        }
        blue.push_back(s);
    }
    
    if (G > 0) {
        string s;
        for (int i = 0 ; i < G; i++) {
            s += "RG";
            R--;
        }
        
        if (R>0) {
            s+= "R";
            R--;
        }
        red.push_back(s);
    }
    
    if (V > 0) {
        string s;
        for (int i = 0 ; i < V; i++) {
            s += "YV";
            Y--;
        }
        
        if (Y>0) {
            s+= "Y";
            Y--;
        }
        yellow.push_back(s);
    }
    
    for (int i = 0 ; i < R; i++) red.push_back("R");
    for (int i = 0 ; i < Y; i++) yellow.push_back("Y");
    for (int i = 0 ; i < B; i++) blue.push_back("B");
}

bool is_impossible(int R, int O, int Y, int G, int B, int V) {
    // O > B, O == B
    if (O != 0 && (O > B || (O == B && G+R+V+Y != 0))) return true;
    
    if (G != 0 && (G > R || (G == R && O+B+V+Y != 0))) return true;
    
    if (V!= 0 && (V > Y || (V == Y && O+B+G+R != 0))) return true;
    
    int r = B - O;
    int y = R - G;
    int b = Y - V;
    
    if (r+y < b || r+b < y || y+b < r) return true;
    
    return false;
}

bool cmp(const vector<string> &A, const vector<string> &B) {
    return A.size() < B.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, round = 1;
    cin >> T;
    
    while (T--) {
        red.clear();
        yellow.clear();
        blue.clear();
        int N;
        cin >> N;
        
        vector<vector<string>> single;
        
        int R, O, Y, G, B, V;
        cin >> R >> O >> Y >> G >> B >> V;
        
        if (is_impossible(R, O, Y, G, B, V)) {
            cout << "Case #" << round << ": IMPOSSIBLE" << '\n';
            round++;
            continue;
        }
        
        make_single(R, O, Y, G, B, V);
        
        single.push_back(red);
        single.push_back(yellow);
        single.push_back(blue);
        sort(single.begin(), single.end(), cmp);
        
        string ans;
        
        while (single[0].size() > 0) {
            ans += single[0][single[0].size()-1];
            single[0].pop_back();
            
            if (single[0].size() > 0) {
                if (single[2].size() >= single[1].size()) {
                    ans += single[2][single[2].size()-1];
                    single[2].pop_back();
                } else {
                    ans += single[1][single[1].size()-1];
                    single[1].pop_back();
                }
            }
        }
        
        sort(single.begin(), single.end(), cmp);
        
        while (single[2].size() > 0) {
            ans += single[2][single[2].size()-1];
            single[2].pop_back();
            
            if (single[1].size() > 0) {
                ans += single[1][single[1].size()-1];
                single[1].pop_back();
            }
        }
        
        cout << "Case #" << round << ": " << ans << '\n';
        round++;
    }
}
