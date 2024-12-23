/** @file
 *  @author Рыбаков Е.М.
 *  @version 1.0
 *  @date 23.12.2024
 *  @copyright ИБСТ ПГУ
 *  @brief Заголовочный файл для класса Calculator
 *  
 *  Этот класс предназначен для выполнения расчетов на основе входных данных.
 */

#pragma once
#include <vector>
#include <cstdint>

/** @class Calculator
 *  @brief Класс для выполнения расчетов.
 *  
 *  Данный класс принимает вектор входных данных и предоставляет метод для получения результата.
 */
class Calculator {
    double results = 0;

public:
    /** @brief Конструктор, который инициализирует класс с входными данными.
     *  @param input_data Вектор входных данных типа double.
     */
    Calculator(std::vector<double> input_data);
    
    /** @brief Метод для получения результата расчетов.
     *  @return Возвращает результат типа double.
     */
    double send_res();
};
