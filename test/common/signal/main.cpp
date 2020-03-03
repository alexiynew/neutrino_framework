
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#include <common/signal.hpp>
#include <unit_test/suite.hpp>

using namespace framework;

class slot_test : public unit_test::suite
{
public:
    slot_test() : suite("slot_test")
    {
        add_test([this]() { slot_lambda(); }, "slot_lambda");
        add_test([this]() { slot_member(); }, "slot_member");
    }

private:
    void slot_lambda()
    {
        int value = 0;

        Signal<int> s;

        auto id = s.connect([&value](int a) {
            value += a;
        });

        s(1);

        TEST_ASSERT(value == 1, "Signal connect not working");

        s.disconnect(id);

        s(1);

        TEST_ASSERT(value == 1, "Signal disconnect not working");
    }

    void slot_member()
    {
        class Slot
        {
        public:
            void plus_one()
            {
                m_value += 1;
            }

            void no_action() const
            {
            }

            int32 get_value() const 
            {
                return m_value; 
            }

        private:
            int32 m_value = 0;
        };

        Slot slot;
        Signal signal;

        auto id1 = signal.connect(slot, &Slot::plus_one);
        auto id2 = signal.connect(slot, &Slot::plus_one);
        signal.connect(slot, &Slot::no_action);

        signal();

        TEST_ASSERT(slot.get_value() == 2, "Signal connect not working");

        signal.disconnect(id1);

        signal();

        TEST_ASSERT(slot.get_value() == 3, "Signal disconnect not working");

        signal.disconnect(id2);

        signal();

        TEST_ASSERT(slot.get_value() == 3, "Signal disconnect not working");
    }
};

int main()
{
    return run_tests(slot_test());
}
