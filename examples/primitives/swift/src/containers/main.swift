import XCTest
import Wrapper

func runContainerExamples() {
    // [map-usage]
    let mapUsage = MapExamples()
    let item1 = MapItem(value: 5)
    mapUsage.addStringMap(info: ["a": "1"])
    mapUsage.addIntMap(info: [1 : 1])
    mapUsage.addMixedMap(info: ["a" : item1])
    let intMap = mapUsage.getIntMap()
    assert(intMap == [1 : 1])
    let strMap = mapUsage.getStringMap()
    assert(strMap == ["a": "1"])
    let mixedMap = mapUsage.getMixedMap()
    assert(mixedMap["a"]!.value == item1.value)

    //[map-usage]

    // [vector-usage]
    let vecUsage = VectorExamples()

    vecUsage.addIntVector(v: [1, 2, 3])
    let intVec = vecUsage.getIntVector()
    assert(intVec.count == 3)
    assert(intVec[1] == 2)

    vecUsage.addStringVector(v: ["a", "b"])
    let strVec = vecUsage.getStringVector()
    assert(strVec.count == 2)
    assert(strVec[1] == "b")

    let item2 = VectorItem(value: 5)
    let item3 = VectorItem(value: 1)
    vecUsage.addObjVector(v: [item2, item3])
    let objVec = vecUsage.getObjVector()
    assert(objVec.count == 2)
    assert(objVec[1].value == 1)
    // [vector-usage]

    // [pair-usage]
    let pairUsage = PairExamples()
    assert(pairUsage.getStringPair() == ("first", "second"))

    let p1 = (1, 5)
    let p2 = (2, -3)
    assert(pairUsage.sumIntPairs(p1: p1, p2: p2) == (p1.0 + p2.0, p1.1 + p2.1))

    let nestedPair = (("a", "b"), ("c", "d"))
    pairUsage.setNestedPair(p: nestedPair)

    let resultPair = pairUsage.getNestedPair()
    assert(nestedPair.0 == resultPair.0 && nestedPair.1 == resultPair.1)

    assert(pairUsage.sumPairItems(p: (1, 2)) == 3)
    // [pair-usage]

    // [json-usage]
    let jsonUsage = JsonExamples()
    assert(jsonUsage.getSimpleJsonExample() == "{\"pi\":3.14,\"status\":true}")

    var jsonList = [String]()
    jsonList.append("{\"name\":\"John\",\"status\":false}")
    jsonList.append("{\"a\":\"b\",\"list\":[0,1,2],\"object\":{\"key\":\"value\"}}")
    for json in jsonList {
        jsonUsage.setJson(j: json)
        assert(jsonUsage.getJson() == json)
    }

    let jsonObj = jsonUsage.getJson()
    let jsonMatrix : [[String]] = [[jsonObj]]
    jsonUsage.setJsonMatrix(jm: jsonMatrix)
    assert(jsonUsage.getJsonMatrix()[0][0] == jsonObj)
    // [json-usage]

    // [nested-containers-usage]
    let nestedUsage = NestedExamples()

    let nestedIntList = [[1, 2], [3], []]
    nestedUsage.setNestedIntVector(v: nestedIntList)
    assert(nestedUsage.getNestedIntVector() == nestedIntList)

    let nestedIntMap : [Int: [Int: Int]] = [1: [1: 2], 2: [-1000: 10000000, 0: 0]]
    nestedUsage.setNestedIntMap(m: nestedIntMap)
    assert(nestedUsage.getNestedIntMap() == nestedIntMap)

    nestedUsage.mixedExampleWithManyArgs(v1: nestedIntList, v2: nestedIntList, m1: nestedIntMap, m2: nestedIntMap)

    let vectorOfIntMaps : [[Int: Int]] = [[1: 2, 3: 4], [-1: 0]]
    nestedUsage.setVectorOfIntMaps(v: vectorOfIntMaps)
    assert(nestedUsage.getVectorOfIntMaps() == vectorOfIntMaps)

    let mapOfIntVectors : [Int: [Int]] = [1 : [], 2: [3, 4]]
    nestedUsage.setMapOfIntVectors(m: mapOfIntVectors)
    assert(nestedUsage.getMapOfIntVectors() == mapOfIntVectors)

    let complexNestedStringVector : [[[String]]] = [[["a", "bc"], []]]
    nestedUsage.setComplexStringVector(v: complexNestedStringVector)
    assert(nestedUsage.getComplexStringVector() == complexNestedStringVector)

    let complexNestedStringMap : [String : [String : [String : String]]] = ["a" : ["b" : ["c" : "d"]]]
    nestedUsage.setComplexStringMap(m: complexNestedStringMap)
    assert(nestedUsage.getComplexStringMap() == complexNestedStringMap)
    // [nested-containers-usage]

    // checking pair + containers combinations
    let nestedVectorOfPairs : [[(Int, String)]] = [[(1, "one")], [(2, "two"), (3, "three")]]
    pairUsage.setNestedVectorOfPairs(v: nestedVectorOfPairs)
    let resultVec = pairUsage.getNestedVectorOfPairs()
    assert(resultVec[0][0].0 == nestedVectorOfPairs[0][0].0 && resultVec[0][0].1 == nestedVectorOfPairs[0][0].1)
    assert(resultVec[1][0].0 == nestedVectorOfPairs[1][0].0 && resultVec[1][0].1 == nestedVectorOfPairs[1][0].1)
    assert(resultVec[1][1].0 == nestedVectorOfPairs[1][1].0 && resultVec[1][1].1 == nestedVectorOfPairs[1][1].1)

    let mapItemObj = MapItem(value: 1)
    let complexPairObj : (MapItem, [MapItem]) = (mapItemObj, [mapItemObj])
    pairUsage.complexPairObj = complexPairObj
    let resultObj = pairUsage.complexPairObj
    assert(resultObj.0.value == mapItemObj.value && resultObj.1[0].value == mapItemObj.value)
}

#if os(Linux)
runContainerExamples()
#elseif os(OSX)
class ContainersTests: XCTestCase {

    func testRun() throws {
        runContainerExamples()
    }
}
#endif
