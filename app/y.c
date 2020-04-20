/**
 * y.c -- функция вставки строки после курсора с заменой
 * 
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "_text.h"
#include <assert.h>

int y(text txt, const char *line)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return 2;
    }
   /* Вставляем строку */
   int m = y_line(txt,line);
   if(m == 1)
       return 1;

   return 0;
}
