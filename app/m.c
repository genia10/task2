/**
 * m.c -- функция перемещения курсора
 * 
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "_text.h"

int m(text txt, char *line, char *pos) {
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return 1;
    }
    /* Двигаем курсор */ 
    int d = moving(txt, line, pos);
    if (d==2)
        return 2;
    return 0;
    }


