#include "pch.h"
#include "../Project14/baseball.cpp"

TEST(A, B) {
    EXPECT_EQ(1, 1);
}

TEST(BaseballGame, ThrowExxceptionWhenInputLengthIsUnmatched) {
    Baseball game;
    EXPECT_THROW(game.guess(string("12")), length_error);
}
