/**
 * text.h -- внешний интерфейс библиотеки для работы с текстом
 *
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255
#include <stdio.h>
#include <string.h>

/**
 * Абстрактный тип текстовых объектов
 */
typedef struct _list *text;

/**
 * Абстрактный тип курсора
 */
typedef struct _crsr *cursor;

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, const char *contents);

/**
 * Добавляет строку за курсором
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
int y_line(text txt, const char *contents);

/**
 * Перемещает текущую строку в конец текста
 * @param txt текст
 * @returns none
 */
int line_to_end(text txt);

/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, char *contents, int cursor_position, void *data),
    void *data
);

/**
 * Передвигает курсор в заданную позицию
 * @param txt текст
 * @param line строка в которой должен быть курсор
 * @param pos позиция в которой должен быть курсор
 * @returns none
 */
int moving(
    text txt,
    char *line,
    char *pos
);

#define UNUSED(x) (void)(x)

/**
 * Переносит строку в конец текста
 */
int ce(text txt);
/**
 * Выводит только первые буквы слов из содержимого файла на экран
 */
int showwordbeginnings(text txt);
/**
 * Сдвиг курсора (m номерстроки позиция)
 */
int m(text txt, char *line, char *pos);
/**
 * Замена строки после курсора (y строка)
 */
int y(text txt,const char *line);
/**
 * Сохранение файла
 */
int save(text txt, char *filename);

#endif
