#include "Calculator.h"
Calculator::Calculator(std::vector<double> input_data) {
    if (input_data.empty()) {
        results = 0;
    }

    for (double i : input_data) {
        results += i;
    }
}

double Calculator::send_res() {
    return results;
}
