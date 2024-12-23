/** @file
 *  @author Рыбаков Е.М.
 *  @version 1.0
 *  @date 23.12.2024
 *  @copyright ИБСТ ПГУ
 *  @brief Заголовочный файл для классов ошибок
 *  
 *  Этот файл содержит определения классов для обработки критических и некритических ошибок.
 */

#pragma once
#include <system_error>
#include <stdexcept>
#include <string>

/** @class crit_err
 *  @brief Класс для критических ошибок.
 *  Этот класс используется для обработки критических ошибок в программе.
 */
class crit_err: public std::runtime_error {
public:
    /** @brief Конструктор класса crit_err.
     *  @param s Сообщение об ошибке.
     */
    crit_err(const std::string& s): std::runtime_error(s) {}
};

/** @class no_crit_err
 *  @brief Класс для некритических ошибок.
 * 
 * Этот класс используется для обработки некритических ошибок в программе.
 */
class no_crit_err: public std::runtime_error {
public:
    /** @brief Конструктор класса no_crit_err.
     *  @param s Сообщение об ошибке.
     */
    no_crit_err(const std::string s): std::runtime_error(s) {}
};

