//
//  main.swift
//  1004
//
//  Created by 이운형 on 25/01/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
//  원과 점의 교점을 이용한 문제
//  (x-rx)^2 + (y-ry)^2 = r^2 을 이용
//

var (princeX, princeY) = (0,0)
var (roseX, roseY) = (0,0)
var minimunResult = 0

func calculateOrbital(_ x:Int, _ y:Int, _ r:Int) {
    let (dxP, dxR) = (power(princeX-x), power(roseX-x))
    let (dyP, dyR) = (power(princeY-y), power(roseY-y))
    let powR = power(r)
    
    if (dxP+dyP < powR) && (dxR+dyR < powR) {
        return
    } else if dxP+dyP < powR {
        minimunResult += 1
    } else if dxR+dyR < powR {
        minimunResult += 1
    }
}

func power (_ num:Int)->Int {
    return num*num
}
let caseCount = Int(readLine()!)

for _ in 1...caseCount! {
    let point = readLine()!.split(separator: " ").map{Int($0)!}
    (princeX, princeY) = (point[0], point[1])
    (roseX, roseY) = (point[2], point[3])
    minimunResult = 0
    
    let planetCount = Int(readLine()!)
    for _ in 1...planetCount! {
        let planet = readLine()!.split(separator: " ").map{Int($0)!}
        calculateOrbital(planet[0], planet[1], planet[2])
    }
    print(minimunResult)
}


