#include "pch.h"
#include "../Project14/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
    Baseball game{ "123" };
    void assertIllegalArgument(string guessNumber) {
        try {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e) {
            // PASS
        }
    }
};

TEST_F(BaseballFixture, ThrowExxceptionWhenInvalidCase) {
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
    assertIllegalArgument("121");
}
TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);
}
TEST_F(BaseballFixture, ReturnSolved2Strikes) {
    GuessResult result = game.guess("124");

    EXPECT_TRUE(!result.solved);
    EXPECT_EQ(2, result.strikes);
    EXPECT_EQ(0, result.balls);
}