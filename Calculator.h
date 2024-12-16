#pragma once
#include <vector>
#include <cstdint>
class Calculator {
    double results = 0;

public:
    Calculator(std::vector<double> input_data);
    double send_res();
};
