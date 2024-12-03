#include "Calculator.h"

Calculator::Calculator(std::vector<double> input_data) {
    for (double i:input_data) {
    	results += i;
    }
}

double Calculator::send_res() {
    return results;
}
