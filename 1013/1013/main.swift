//
//  main.swift
//  1013
//
//  Created by 이운형 on 08/02/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

var str:String = ""
var endIndex:String.Index = str.endIndex

func state100(_ index:String.Index) -> Bool {
    var state = ""
    var iter = index
    
    state.append(str[iter])
    for _ in 0 ..< 2 {
        if iter == endIndex {
            return false
        } else {
            iter = str.index(after: iter)
        }
        state.append(str[iter])
    }
    
    if state != "100" { return false }
    
    if iter != endIndex{
        iter = str.index(after: iter)
        if str[iter] == "0" {
            return state0(iter)
        } else if str[iter] == "1" {
            return state1(iter)
        }
    }
    return true
}

func state01(_ index:String.Index) -> Bool {
    var state = ""
    var iter = index
    
    state.append(str[iter])
    if iter == endIndex { return false }
    iter = str.index(after: iter)
    state.append(str[iter])
    
    if state != "01" { return false }
    
    if iter != endIndex {
        iter = str.index(after: iter)
        if str[iter] == "0" {
            return state01(iter)
        } else if str[iter] == "1" {
            return state100(iter)
        }
    }
    return true
    
}

func state0(_ index:String.Index) -> Bool {
    var iter = index
    while str[iter] == "0" {
        if iter == endIndex {
            return true
        }
        iter = str.index(after: iter)
    }
    
    return state1(iter)
}

func state1(_ index:String.Index) -> Bool {
    var iter = index
    var count = 0
    
    while str[iter] == "1" {
        if iter == endIndex {
            return true
        }
        iter = str.index(after: iter)
        count += 1
    }
    
    if iter == endIndex { return false }
    
    if str[str.index(after: iter)] == "1" {
        return state01(iter)
    } else if count == 1 {
        return false
    } else {
        return state100(str.index(before: iter))
    }
}
let testCase = Int(readLine()!)!

for _ in 1...testCase {
    str = readLine()!
    var result: Bool
    endIndex = str.index(before: str.endIndex)
    if str[str.startIndex] == "1" {
        result = state100(str.startIndex)
    } else {
        result = state01(str.startIndex)
    }
    
    if result {
        print("YES")
    } else {
        print("NO")
    }
}
