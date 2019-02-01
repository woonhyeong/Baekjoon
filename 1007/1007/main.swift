//
//  main.swift
//  1007
//
//  Created by 이운형 on 01/02/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
//  DFS를 이용하였다.
//  조합(Combination) 또한 DFS와 같은 원리이기에 조합을 이용했다.
//  백터의 합을 n 개의 원소에 대해 n/2 개를 구하고 전체의 합에서 n/2개만 계산하여 처리하였다.
//
import Foundation

var minCost = Double(Int.max)
struct Point {
    let x : Int
    let y : Int
    
    init(_ x:Int, _ y:Int) {
        self.x = x
        self.y = y
    }
}

func combination(_ halfArray: inout [Int], _ halfArrayIndex:Int, _ entireNumber:Int, _ canSelectNumber:Int, _ target:Int, _ point:[Point]) {
    if canSelectNumber == 0 {
        calculateMinCost(halfArray, point)
    } else if entireNumber == target {
        return
    } else {
        halfArray[halfArrayIndex] = target
        combination(&halfArray, halfArrayIndex + 1, entireNumber, canSelectNumber - 1, target + 1, point)
        combination(&halfArray, halfArrayIndex, entireNumber, canSelectNumber, target + 1, point)
    }
}

func calculateMinCost(_ halfArray:[Int], _ point:[Point]) {
    var x = 0
    var y = 0
    var sumOfEntireX = 0
    var sumOfEntireY = 0
    
    for i in 0..<point.count {
        sumOfEntireX += point[i].x
        sumOfEntireY += point[i].y
    }
    
    for i in 0..<halfArray.count {
        x += point[halfArray[i]].x
        y += point[halfArray[i]].y
    }
    
    x = sumOfEntireX - 2*x
    y = sumOfEntireY - 2*y
    let sumOfVector = sqrt(Double(x*x + y*y))
    
    if sumOfVector < minCost {
        minCost = sumOfVector
    }
}

let testCount = Int(readLine()!)!

for _ in 1...testCount {
    let pointNumber = Int(readLine()!)!
    var pointList = [Point]()
    minCost = Double(Int.max)
    
    for _ in 1...pointNumber {
        let pointInput = readLine()!.split(separator: " ").map{Int($0)!}
        pointList.append( Point(pointInput[0], pointInput[1]) )
    }
    var isUsable:[Int] = Array(repeating: -1, count: (pointNumber/2))
    
    combination(&isUsable, 0, pointNumber, pointNumber/2, 0, pointList)
    print(String(format: "%.6f", minCost))
}
