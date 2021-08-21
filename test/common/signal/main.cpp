
// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

class SlotTest : public unit_test::Suite
{
public:
    SlotTest()
        : Suite("SlotTest")
    {
        add_test([this]() { slot_lambda_0(); }, "slot_lambda_0");
        add_test([this]() { slot_lambda_1(); }, "slot_lambda_1");
        add_test([this]() { slot_lambda_many(); }, "slot_lambda_many");
        add_test([this]() { slot_member_0(); }, "slot_member_0");
        add_test([this]() { slot_member_1(); }, "slot_member_1");
        add_test([this]() { slot_member_many(); }, "slot_member_many");
        add_test([this]() { slot_self_disconnect(); }, "slot_self_disconnect");
    }

private:
    void slot_lambda_0()
    {
        int value = 0;

        Signal<> s;

        auto id = s.connect([&value]() { value += 42; });

        s();

        TEST_ASSERT(value == 42, "Signal connect not working");

        s.disconnect(id);

        s();

        TEST_ASSERT(value == 42, "Signal disconnect not working");

        s.disconnect(id);
        s.disconnect(0);
        s.disconnect(1);
        s.disconnect(22222);

        s();

        TEST_ASSERT(value == 42, "Signal disconnect not working");
    }

    void slot_lambda_1()
    {
        int value = 0;

        Signal<int> s;

        auto id = s.connect([&value](int a) { value += a; });

        s(1);

        TEST_ASSERT(value == 1, "Signal connect not working");

        s.disconnect(id);

        s(1);

        TEST_ASSERT(value == 1, "Signal disconnect not working");

        s.disconnect(id);
        s.disconnect(0);
        s.disconnect(1);
        s.disconnect(22222);

        s(1);

        TEST_ASSERT(value == 1, "Signal disconnect not working");
    }

    void slot_lambda_many()
    {
        int value = 0;

        Signal<int, float, char> s;

        auto id = s.connect([&value](int a, float b, char c) { value += static_cast<int>(a + b + c); });

        s(1, 1.0f, 1);

        TEST_ASSERT(value == 3, "Signal connect not working");

        s.disconnect(id);

        s(1, 1.0f, 1);

        TEST_ASSERT(value == 3, "Signal disconnect not working");

        s.disconnect(id);
        s.disconnect(0);
        s.disconnect(1);
        s.disconnect(22222);

        s(1, 1.0f, 1);

        TEST_ASSERT(value == 3, "Signal disconnect not working");
    }

    void slot_member_0()
    {
        class Slot
        {
        public:
            void plus_one()
            {
                value += 1;
            }

            void no_action() const
            {
                no_action_called = true;
            }

            int32 get_value() const
            {
                return value;
            }

            int32 value                   = 0;
            mutable bool no_action_called = false;
        };

        Slot slot;
        Signal<> signal;

        auto id1 = signal.connect(slot, &Slot::plus_one);
        auto id2 = signal.connect(slot, &Slot::plus_one);

        signal();

        TEST_ASSERT(slot.value == 2, "Signal connect not working");

        signal.disconnect(id1);
        signal.connect(slot, &Slot::no_action);

        signal();

        TEST_ASSERT(slot.value == 3, "Signal disconnect not working");
        TEST_ASSERT(slot.no_action_called == true, "Signal connect not working");

        signal.disconnect(id2);

        signal();

        TEST_ASSERT(slot.value == 3, "Signal disconnect not working");
    }

    void slot_member_1()
    {
        class Slot
        {
        public:
            void plus(int a)
            {
                value += a;
            }

            void no_action(int) const
            {
                no_action_called = true;
            }

            int32 get_value() const
            {
                return value;
            }

            int32 value                   = 0;
            mutable bool no_action_called = false;
        };

        Slot slot;
        Signal<int> signal;

        auto id1 = signal.connect(slot, &Slot::plus);
        auto id2 = signal.connect(slot, &Slot::plus);

        signal(1);

        TEST_ASSERT(slot.value == 2, "Signal connect not working");

        signal.disconnect(id1);
        signal.connect(slot, &Slot::no_action);

        signal(1);

        TEST_ASSERT(slot.value == 3, "Signal disconnect not working");
        TEST_ASSERT(slot.no_action_called == true, "Signal connect not working");

        signal.disconnect(id2);

        signal(1);

        TEST_ASSERT(slot.value == 3, "Signal disconnect not working");
    }

    void slot_member_many()
    {
        class Slot
        {
        public:
            void plus(int a, float b, char c)
            {
                value += static_cast<int>(a + b + c);
            }

            void no_action(int, float, char) const
            {
                no_action_called = true;
            }

            int32 get_value() const
            {
                return value;
            }

            int32 value                   = 0;
            mutable bool no_action_called = false;
        };

        Slot slot;
        Signal<int, float, char> signal;

        auto id1 = signal.connect(slot, &Slot::plus);
        auto id2 = signal.connect(slot, &Slot::plus);

        signal(1, 1.0f, 1);

        TEST_ASSERT(slot.value == 6, "Signal connect not working");

        signal.disconnect(id1);
        signal.connect(slot, &Slot::no_action);

        signal(1, 1.0f, 1);

        TEST_ASSERT(slot.value == 9, "Signal disconnect not working");
        TEST_ASSERT(slot.no_action_called == true, "Signal connect not working");

        signal.disconnect(id2);

        signal(1, 1.0f, 1);

        TEST_ASSERT(slot.value == 9, "Signal disconnect not working");
    }

    void slot_self_disconnect()
    {
        Signal<> signal1;
        int count1 = 0;

        signal1.connect([&signal1, &count1]() {
            signal1.clear();
            count1++;
        });

        signal1.connect([&signal1, &count1]() {
            signal1.clear();
            count1++;
        });

        signal1.connect([&signal1, &count1]() {
            signal1.clear();
            count1++;
        });

        signal1.connect([&signal1, &count1]() {
            signal1.clear();
            count1++;
        });

        signal1();

        TEST_ASSERT(signal1.has_connections() == false, "Signal clear not working");
        TEST_ASSERT(count1 == 1, "Signal clear not working");

        Signal<usize> signal2;
        int count2 = 0;

        auto id1 = signal2.connect([&signal2, &count2](usize a) {
            signal2.disconnect(a);
            count2++;
        });

        auto id2 = signal2.connect([&signal2, &count2](usize a) {
            signal2.disconnect(a);
            count2++;
        });

        auto id3 = signal2.connect([&signal2, &count2](usize a) {
            signal2.disconnect(a);
            count2++;
        });

        signal2(id1);
        TEST_ASSERT(count2 == 3, "Signal disconnect not working");

        signal2(id2);
        TEST_ASSERT(count2 == 5, "Signal disconnect not working");

        signal2(id3);
        TEST_ASSERT(count2 == 6, "Signal disconnect not working");

        TEST_ASSERT(signal2.has_connections() == false, "Signal disconnect not working");
    }
};

int main()
{
    return run_tests(SlotTest());
}
