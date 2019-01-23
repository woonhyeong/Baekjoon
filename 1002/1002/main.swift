//
//  main.swift
//  1002
//
//  Created by 이운형 on 22/01/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
func power(_ number:Int) -> Int {
    return (number * number)
}

let count = Int(readLine()!)!

for _ in 1...count {
    let input = (readLine()?.split(separator: " ").map{Int($0)!})!
    let (jx, jy) = (input[0], input[1])
    let (bx, by) = (input[3], input[4])
    let r1 = input[2], r2 = input[5]
    
    if (jx == bx) && (jy == by) {
        if r1 == r2 {
            print(-1)
            continue
        } else {
            print(0)
            continue
        }
    }
    
    let distance = power(jx - bx) + power(jy - by)
    let add = power(r1 + r2)
    let sub = power(r1 - r2)
    
    if sub > distance {
        print(0)
    } else if sub == distance {
        print(1)
    } else if add > distance {
        print(2)
    } else if add == distance {
        print(1)
    } else {
        print(0)
    }
    
}

