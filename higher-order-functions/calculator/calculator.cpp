#include <assert.h>
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

auto op_add = [](int operand1, int operand2) { return operand1 + operand2; };

auto op_sub = [](int operand1, int operand2) { return operand1 - operand2; };

auto op_mul = [](int operand1, int operand2) { return operand1 * operand2; };

auto op_div = [](int operand1, int operand2) { return operand1 / operand2; };

void testOperations() {
    assert(op_add(1, 2) == 3);
    assert(op_sub(5, 3) == 2);
    assert(op_mul(5, 8) == 40);
    assert(op_div(20, 4) == 5);
}

typedef int (*opt_t)(int, int);

//int (*getOpt(char *operator))(int, int) {
opt_t getOpt(string inputOperator) {
    map<string, opt_t> operators = {{"+", op_add}, {"-", op_sub}, {"*", op_mul}, {"/", op_div}};
    for(auto Operator : operators){
        if ( Operator.first == inputOperator)
            return Operator.second;
    }
    return NULL;
}

void testGetOpt() {
    assert(getOpt("unknown operator") == NULL);
    assert(getOpt("+") == op_add);
    assert(getOpt("-") == op_sub);
    assert(getOpt("*") == op_mul);
    assert(getOpt("/") == op_div);
}

int main(int argc, char *argv[]) {
    testOperations();
    testGetOpt();

    int operand1, operand2, result;
    string Operator;
    cin >> operand1;
    cin >> Operator;
    cin >> operand2;

    opt_t op = getOpt(Operator);
    if (op != NULL) {
        result = op(operand1, operand2);
        cout << result << endl;
    } else {
        cerr << argv[0] <<": error: Unknown operator " << Operator << endl;
        return EXIT_FAILURE;
    }
}