//
//  main.swift
//  1005
//
//  Created by 이운형 on 25/01/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
//  위상정렬을 이용한 문제풀이
//  Queue를 직접구현해서 사용했고, 위상정렬은 indegree를 사용하여 해결했다.
//

struct Queue<T> {
    fileprivate var element = [T?]()
    fileprivate var head = 0
    
    public mutating func push(_ value: T) { element.append(value) }
    
    public mutating func poll() -> T? {
        guard head < element.count, let first = element[head] else {
            return nil
        }
        
        element[head] = nil
        head += 1
        
        if element.count > 50 {
            let percentage = Double(head)/Double(element.count)
            if percentage > 0.25 {
                element.removeFirst(head)
                head = 0
            }
        }
        
        return first
    }
    
    public var pick: T? {
        if isEmpty() {
            return nil
        } else {
            return element[head]
        }
    }
    
    public func isEmpty() -> Bool {
        if head >= element.count { return true } else { return false }
    }
}
let testCount = Int(readLine()!)!

for _ in 1...testCount {
    let input = readLine()!.split(separator: " ").map{Int($0)!}
    let (buildNum, ruleNum) = (input[0], input[1])
    
    let buildInput = readLine()!.split(separator: " ").map{Int($0)!}
    
    var buildTime = [Int]()
    var resultArray = [Int](repeating: 0, count: buildNum)
    var direction = [[Bool]](repeating: [Bool](repeating: false, count: buildNum), count: buildNum)
    var indegree = [Int](repeating: 0, count: buildNum)
    
    for i in 0...(buildNum-1) {
        buildTime.append(buildInput[i])
        resultArray.append(0)
    }
    
    for _ in 1...ruleNum {
        let rule = readLine()!.split(separator: " ").map{Int($0)!}
        direction[rule[0]-1][rule[1]-1] = true
        indegree[rule[1]-1] += 1
    }
    
    let resultIndex = Int(readLine()!)!
    var q = Queue<Int>()
    
    for i in 0...(buildNum-1) {
        if indegree[i] == 0 {
            resultArray[i] = buildTime[i]
            q.push(i)
        }
    }
    
    while !q.isEmpty() {
        let element = q.poll()
        
        for i in 0...(buildNum-1) {
            if direction[element!][i] {
                resultArray[i] = max(buildTime[i] + resultArray[element!], resultArray[i])
                
                indegree[i] -= 1
                
                if indegree[i] == 0 {
                    q.push(i)
                }
            }
        }
    }
    
    print(resultArray[resultIndex-1])
}

