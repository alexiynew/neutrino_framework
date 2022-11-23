#include <algorithm>
#include <functional>
#include <thread>
#include <vector>

#include <common/instance_id.hpp>
#include <unit_test/suite.hpp>

class InstanceIdTest : public neutrino::unit_test::Suite
{
public:
    InstanceIdTest()
        : Suite("InstanceIdTest")
    {
        add_test([this]() { instance_id_threads(); }, "instance_id_threads");
    }

private:
    void instance_id_threads()
    {
        using neutrino::InstanceId;

        constexpr static size_t vectors_count = 10;
        constexpr static size_t ids_count     = 100000;

        std::vector<std::thread> threads;
        std::vector<std::vector<InstanceId>> ids_vectors(vectors_count);

        for (size_t i = 0; i < vectors_count; ++i) {
            threads.push_back(std::thread([ids = std::ref(ids_vectors[i])]() mutable {
                for (size_t c = 0; c < ids_count; ++c) {
                    ids.get().push_back(InstanceId{});
                }
            }));
        }

        for (size_t i = 0; i < vectors_count; ++i) {
            threads[i].join();
        }

        std::vector<InstanceId> check;
        for (size_t i = 0; i < vectors_count; ++i) {
            check.insert(check.end(), ids_vectors[i].begin(), ids_vectors[i].end());
        }

        std::sort(check.begin(), check.end());

        for (size_t i = 1; i < check.size(); ++i) {
            TEST_ASSERT(check[i - 1] != check[i], "Some ids are not unique.");
        }
    }
};

int main()
{
    return run_tests(InstanceIdTest());
}
