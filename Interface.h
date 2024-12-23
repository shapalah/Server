/** @file
 *  @author Рыбаков Е.М.
 *  @version 1.0
 *  @date 23.12.2024
 *  @copyright ИБСТ ПГУ
 *  @brief Заголовочный файл для класса Interface
 *
 *  Этот класс управляет взаимодействием с пользователем через интерфейс командной строки.
 */

#pragma once
#include "Logger.h"
#include <string>

/** @class Interface
 *  @brief Класс интерфейса пользователя.
 *
 *  Этот класс отвечает за обработку команд и взаимодействие с пользователем.
 */
class Interface {
    int PORT; 

public:
    /** @brief Конструктор класса Interface.
     */
    Interface() {}
    
    /** @brief Метод обработки командной строки.
     *  @param argc Количество аргументов командной строки.
     *  @param argv Массив аргументов командной строки.
     *  @return Возвращает статус выполнения (0 - успех, другой код - ошибка).
     */
    int comm_proc(int argc, const char** argv);
};
