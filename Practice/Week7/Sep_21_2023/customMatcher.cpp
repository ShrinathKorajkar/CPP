#include <gmock/gmock.h>

// name, param,..., description
MATCHER(IsEven, "Checks if a number is even")
{
    // custom message on failure
    *result_listener << "value " << arg << " is not even " << divisor;

    return (arg % 2) == 0;
}

MATCHER_P(ContainsSubstring, substring, "")
{
    return arg.find(substring) != std::string::npos;
}

class MockDatabase
{
public:
    MOCK_METHOD1(Search, bool(const std::string &query));
};

TEST(DatabaseTest, CustomMatcherExample)
{
    MockDatabase mockDb;

    EXPECT_CALL(mockDb, Search(ContainsSubstring("GMock")))
        .Times(1)
        .WillOnce(::testing::Return(true));

    bool result = mockDb.Search("Testing GMock Library");
    ASSERT_TRUE(result);
    EXPECT_THAT(4, IsEven()); // 4 is arg here
}
