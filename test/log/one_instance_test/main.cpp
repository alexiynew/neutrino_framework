
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <iostream>
#include <shared_lib/shared_lib.hpp>
#include <sstream>
#include <static_lib/static_lib.hpp>

#include <log/log.hpp>
#include <log/stream_logger/stream_logger.hpp>
#include <unit_test/suite.hpp>

using namespace framework::log;

class one_instance_test : public framework::unit_test::suite
{
public:
    one_instance_test() : suite("one_instance_test")
    {
        add_test([this]() { logger_test(); }, "logger_test");
    }

private:
    void logger_test()
    {
        const std::string test = "[info] one_instance: start\n[info] static_lib: do_log\n[info] shared_lib: do_log\n";

        std::stringstream output;

        set_logger(std::make_unique<stream_logger>(output));

        info("one_instance") << "start" << std::endl;

        static_lib().do_log();

        shared_lib().do_log();

        std::cout << output.str() << std::endl;
        std::cout << test << std::endl;

        TEST_ASSERT(output.str() == test, "Log is wrong.");
    }
};

int main()
{
    return run_tests(one_instance_test());
}
