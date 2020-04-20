/**
 * moving.c -- Команда передвигает курсор в заданную позицию
 *
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include <stdlib.h>
#include <string.h>
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
)
{
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    unsigned int index = 0;
    unsigned int l, p;
    l=atoi(line);
    p=atoi(pos);
    if (l>=txt->length)
        return 2;
    /* Ищем строку в которой курсор */
    while (index!=l){
    current=current->next;
    index++;
   }
   if (p>=strlen(current->contents))
        return 2;
   txt->cursor->line=current;
   txt->cursor->position=p+1;
   return 0;
}
