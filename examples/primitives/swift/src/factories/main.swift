import XCTest
import Wrapper

func runFactoriesExamples() {

// [factories-usage-start]
let school1 = School()
let teacher = Teacher()
school1.addTeacher(teacher: teacher)
assert(school1.teachers.count == 1)
let school2 = School(teachers: [teacher])
assert(school2.teachers.count == 1)
// [factories-usage-end]

}


#if os(Linux)
runFactoriesExamples()
#elseif os(OSX)
class FactoriesTests: XCTestCase {

    func testRun() throws {
        runFactoriesExamples()
    }
}
#endif
