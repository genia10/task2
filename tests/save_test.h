#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "_text.h"
}

TEST(SAVE, num0)
{
    /* Создаем структуру описания текста */
    text txt;
    txt = (list *) malloc(sizeof(list)); // Выделяем память под нее

    /* Создаем первую строку */
    const char contents1[MAXLINE+1] = {"str1"};
    node *nd1;
    nd1 = (node *) malloc(sizeof(node)); // Выделяем память под нее
    strncpy(nd1->contents, contents1, MAXLINE);

    /* Создаем вторую строку */
    const char contents2[MAXLINE+1] = {"str2"};
    node *nd2;
    nd2 = (node *) malloc(sizeof(node)); // Выделяем память под нее
    strncpy(nd2->contents, contents2, MAXLINE);

    /* Создаем третью строку */
    const char contents3[MAXLINE+1] = {"str3"};
    node *nd3;
    nd3 = (node *) malloc(sizeof(node)); // Выделяем память под нее
    strncpy(nd3->contents, contents3, MAXLINE);

    /* Редактирование связей */
    txt->begin=nd1;
    txt->end=nd3;
    nd1->previous = NULL;
    nd1->next = nd2;
    nd2->previous = nd1;
    nd2->next = nd3;
    nd3->previous = nd2;
    nd3->next = NULL;
    txt->length = 3;

    /* Создаем курсор */
    crsr *cursor;
    cursor = (crsr *) malloc(sizeof(crsr)); // Выделяем память под него

    /* Курсор в конец последней строки*/
    cursor->line = txt->end;
    cursor->position = strlen(txt->end->contents);
    txt->cursor = cursor;

    char line[4] = {"123"};

    /* Вызов функции */
    save(txt, line);

    FILE* f=fopen(line, "r");
    char buf[MAXLINE + 1];
    fgets(buf, MAXLINE, f);
    EXPECT_EQ(strcmp(buf, "str1\n"),0);
    fgets(buf, MAXLINE, f);
    EXPECT_EQ(strcmp(buf, "str2\n"),0);
    fgets(buf, MAXLINE, f);
    EXPECT_EQ(strcmp(buf, "str3\n"),0);
}

TEST (SAVE, negative0)
{
    /* Создаем структуру описания текста */
    text txt;
    txt = (list *) malloc(sizeof(list)); // Выделяем память под нее

    /* Только что созданный текст не содержит ни одной строки */
    txt->length = 0;

    char line[4] = {"123"};

    /* Вызов функции */
    EXPECT_EQ(save(txt, line), 1);
}



