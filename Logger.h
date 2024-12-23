/** @file
 *  @author Рыбаков Е.М.
 *  @version 1.0
 *  @date 23.12.2024
 *  @copyright ИБСТ ПГУ
 *  @brief Заголовочный файл для класса Logger
 *
 *  Этот класс отвечает за ведение логов событий в программе.
 */

#pragma once
#include <string>

/** @class Logger
 *  @brief Класс для ведения логов.
 *
 *  Этот класс управляет записью логов в файл и предоставляет методы для работы с ними.
 */
class Logger {
    static std::string getCurrentDateTime(std::string s);

    std::string path_to_logfile;

public:
    /** @brief Метод записи сообщения в лог-файл.
     *  @param s Сообщение, которое нужно записать в лог.
     *  @return Возвращает статус записи (0 - успех, другой код - ошибка).
     */
    int writelog(std::string s);
    
    /** @brief Метод установки пути к лог-файлу.
     *  @param path_file Путь к файлу лога.
     *  @return Возвращает статус установки пути (0 - успех, другой код - ошибка).
     */
    int set_path(std::string path_file);
    
    /** @brief Конструктор по умолчанию класса Logger.
     */
    Logger();
    
    /** @brief Конструктор класса Logger с указанием пути к файлу лога.
     *  @param s Путь к файлу лога.
     */
    Logger(std::string s);
};
