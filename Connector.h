/** @file
 *  @author Рыбаков Е.М.
 *  @version 1.0
 *  @date 23.12.2024
 *  @copyright ИБСТ ПГУ
 *  @brief Заголовочный файл для класса Connector
 *  
 *  Этот класс предназначен для подключения к базе данных и получения данных.
 */

#pragma once
#include <map>
#include <string>
#include "Errors.h"

/** @class Connector
 *  @brief Класс для подключения к базе данных.
 *  
 *  Этот класс управляет подключением к файлу базы данных и предоставляет доступ к данным.
 */
class Connector {
private:
    std::map<std::string, std::string> data_base;

public:
    /** @brief Метод для подключения к базе данных.
     *  @param base_file Имя файла базы данных (по умолчанию "test_files/auth.txt").
     *  @return Возвращает статус подключения (0 - успех, другой код - ошибка).
     */
    int connect(std::string base_file = "test_files/auth.txt");
    
    /** @brief Метод для получения данных из базы данных.
     *  @return Возвращает карту с данными базы.
     */
    std::map<std::string, std::string> get_data();
};
