/**
 * showwordbeginnings.c -- команда вывода 1 букв слов
 *
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "_text.h"

static void show_line(int index, char *contents, int cursor, void *data);

FILE* f;
/**
 * Выводит содержимое указанного файла на экран
 */
int showwordbeginnings(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return 1;
    }
    f = fopen("shwb", "w");
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
    fclose(f);
    return 0;
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    UNUSED(cursor);
    /* Выводим начала слов на экран */
    fprintf(f,"%c", contents[0]); // Первый символ в строке
    int i=1;
    while (contents[i] != '\0'){
        if(contents[i-1]==' ') // Затем, если предыдущий символ - пробел, выводим символ
            fprintf(f,"%c", contents[i]);
        else fprintf(f," ");
        i++;
    }
    fprintf(f,"\n");
}

