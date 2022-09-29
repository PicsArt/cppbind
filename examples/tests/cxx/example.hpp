#include <map>

/**
* __API__
* action: gen_class
*/
class Example {
    /**
     * __API__
     * action: gen_method
     */
    int example(int i, std::map<int, std::map<int, int>> m, Example e) {
        return 0;
    };
};

/**
 * for checking custom 'gen' instruction
 *
 * __API__
 * action: gen_report
 */
class ReportExample {};
