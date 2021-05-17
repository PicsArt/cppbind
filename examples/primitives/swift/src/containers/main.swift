import Wrapper

// [map-usage]
let mapUsage = MapExamples()
let item1 = MapItem(_value: 5)
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

let item2 = VectorItem(_value: 5)
let item3 = VectorItem(_value: 1)
vecUsage.addObjVector(v: [item2, item3])
let objVec = vecUsage.getObjVector()
assert(objVec.count == 2)
assert(objVec[1].value == 1)
// [vector-usage]

