#include <limits>
#include <utility>

using namespace std;

pair<bool, float> calculator(float number1, char op, float number2)
{
    bool zeroErr = true;
    switch (op)
    {
    case '+':
    {
        if (numeric_limits<float>::max() - number2 < number1 && number2 > 0 || numeric_limits<float>::min() - number2 > number1 && number2 < 0)
        {
            zeroErr = false;
        }
        return {zeroErr, number1 + number2};
    }
    case '-':
    {
        if (numeric_limits<float>::min() + number2 > number1 && number2 > 0 || numeric_limits<float>::max() + number2 < number1 && number2 < 0)
        {
            zeroErr = false;
        }
        return {zeroErr, number1 - number2};
    }
    case '*':
    {
        if (numeric_limits<float>::max() / number1 < number2 && number1 > 0 || (numeric_limits<float>::max() / number1 > number2 && (number1 < 0 && number2 < 0)) || (numeric_limits<float>::min() / number1 > number2 && number2 < 0) || (numeric_limits<float>::min() / number1 < number2 && number1 < 0))
        {
            zeroErr = false;
        }
        return {zeroErr, number1 * number2};
    }
    case '/':
    {
        if (number2 == 0)
        {
            zeroErr = false;
        }
        return {zeroErr, number1 / number2};
    }
    default:
        return {false, 0};
    }
}