#include <string>
#include <stdexcept>
using namespace std;

struct GuessResult {
    bool solved;
    int strikes;
    int balls;
};

class Baseball {
public:
    const int NUMBER_NUM = 3;

    explicit Baseball(const std::string& question)
        : question(question) {
    }

    GuessResult guess(const string& guessNumber) {
        assertIllegalArgument(guessNumber);
        if (guessNumber == question) return { true, NUMBER_NUM, 0 };
        return { false, getStrikes(guessNumber), getBalls(guessNumber) };
    }

    int getBalls(const std::string& guessNumber)
    {
        int balls = 0;
        for (int i = 0; i < NUMBER_NUM; i++) {
            for (int j = 0; j < NUMBER_NUM; j++) {
                if (i == j) continue;
                if (guessNumber[i] == question[j]) balls++;
            }
        }
        return balls;
    }

    int getStrikes(const std::string& guessNumber)
    {
        int strikes = 0;
        for (int i = 0; i < NUMBER_NUM; i++) {
            if (guessNumber[i] == question[i]) strikes++;
        }
        return strikes;
    }

    void assertIllegalArgument(const std::string& guessNumber)
    {

        if (guessNumber.length() != NUMBER_NUM) throw length_error("Must be three letters");

        for (char ch : guessNumber) {
            if (ch >= '0' && ch <= '9') continue;
            throw invalid_argument("Must be number");
        }

        if (isDuplicatedNumber(guessNumber)) {
            throw invalid_argument("Must be different number");
        }
    }

    bool isDuplicatedNumber(const std::string& guessNumber)
    {
        for (int i = 0; i < NUMBER_NUM; i++) {
            for (int j = i + 1; j < NUMBER_NUM; j++) {
                if (guessNumber[i] == guessNumber[j]) return true;
            }
        }
        return false;
    }

private:
    string question;
};