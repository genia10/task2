/**
 * ce.c -- команда переноса текущей строки в конец текста
 *
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>

#include "_text.h"

int ce(text txt){
    if (txt->length == 0)
            return 1;
    /* Переносим строку в конец текста */
    line_to_end(txt);
    return 0;
    }
