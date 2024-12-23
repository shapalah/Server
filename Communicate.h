/** @file
 *  @author Рыбаков Е.М.
 *  @version 1.0
 *  @date 23.12.2024
 *  @copyright ИБСТ ПГУ
 *  @brief Заголовочный файл для класса Communicate
 *  
 *  Этот класс отвечает за установление соединения и обработку коммуникаций.
 */

#pragma once
#include <string>
#include <map>

class Logger;

/** @class Communicate
 *  @brief Класс для управления коммуникациями.
 *  
 *  Этот класс предоставляет методы для установления соединений и генерации хешей.
 */
class Communicate {
public:
    /** @brief Метод для установки соединения.
     *  @param port Порт для соединения.
     *  @param database Карта с данными базы.
     *  @param l1 Указатель на объект Logger для логирования.
     *  @return Возвращает статус соединения (0 - успех, другой код - ошибка).
     */
    int connection(int port, std::map<std::string, std::string> database, Logger* l1);
    
    /** @brief Генерация SHA1 хеша из строки.
     *  @param input_str Входная строка для хеширования.
     *  @return Возвращает хеш в виде строки.
     */
    static std::string sha1(std::string input_str);
    
    /** @brief Генерация соли для хеширования.
     *  @return Возвращает сгенерированную соль в виде строки.
     */
    static std::string generate_salt();
};
