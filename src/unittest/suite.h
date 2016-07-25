#ifndef FRAMEWORK_UNITTEST_SUITE_H
#define FRAMEWORK_UNITTEST_SUITE_H

#include <vector>
#include <string>

namespace test {

class Suite
{
public:
    Suite();

    virtual ~Suite() = default;

    void run();

    bool isSuccessed();

protected:
    using TestFunction = void(Suite::*)();

    virtual void setup();
    virtual void tearDown();

    void addTest(TestFunction func, const std::string& name);

    void testFailed(const std::string& file, int line, const std::string& message);

private:
    struct TestData
    {
        TestFunction function;
        std::string name;
        bool success;
    };

    struct Status
    {
        std::string file;
        int line;
        std::string message;
        const TestData& test;
    };

    void outputFail(const Status& status);

    void outputSuccess(const TestData& test);

    bool m_success;
    std::string m_name;
    std::vector<TestData> m_tests;
    std::vector<TestData>::iterator m_current_test;
};

} // namspace test


#define ADD_TEST(FUNC) \
    addTest(static_cast<TestFunction>(&FUNC), #FUNC)

#endif
