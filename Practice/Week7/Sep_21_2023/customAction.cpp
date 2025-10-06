#include <gtest/gtest.h>
#include <gmock/gmock.h>

class CustomReturnAction
{
public:
    CustomReturnAction(int value) : value_(value) {}

    int operator()() const
    {
        return value_;
    }

private:
    int value_;
};

ACTION(PrintAndReturn42)
{
    std::cout << "Custom action executed!" << std::endl;
    return 42;
}

ACTION_P(ReturnSum, add_value)
{
    // arg0 is the first argument passed to the mock method
    // arg0, arg1, arg2, … depending on how many your mock method takes.
    return arg0 + add_value;
}

ACTION_P2(MultiplyAndAdd, mul, add)
{
    // if mock.Process(4) is passed and
    // expect_call(mock, process(_)).willonce(multiplyAndAdd(3,2));
    // 4 * 3 + 2
    return arg0 * mul + add;
}

class MockCalculator
{
public:
    MOCK_METHOD(int, Add, (int a, int b), ());
};

TEST(CalculatorTest, CustomActionExample)
{
    MockCalculator mockCalculator;

    EXPECT_CALL(mockCalculator, Add(2, 3)).WillOnce(CustomReturnAction(5));
    EXPECT_CALL(mockCalculator, Add(2, 3)).WillOnce(PrintAndReturn42());

    int result = mockCalculator.Add(2, 3);
    ASSERT_EQ(result, 5);
}
