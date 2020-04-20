#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "_text.h"
}

TEST(M, num0)
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

    /* Редактирование связей */
    txt->begin=nd1;
    txt->end=nd2;
    txt->begin->next=nd2;
    txt->begin->previous=NULL;
    txt->end->next=NULL;
    txt->end->previous = nd1;
    txt->length = 2;

    /* Создаем курсор */
    crsr *cursor;
    cursor = (crsr *) malloc(sizeof(crsr)); // Выделяем память под него

    /* Курсор в конец последней строки*/
    cursor->line = txt->end;
    cursor->position = strlen(txt->end->contents);
    txt->cursor = cursor;

    char line[2] = "1";
    char pos[2] = "2";

    /* Вызов функции */
    m(txt, line, pos);

    EXPECT_EQ(strcmp(txt->cursor->line->contents, "str2"), 0);
    EXPECT_EQ(txt->cursor->position, 3);
}

TEST(M, negative0)
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

    /* Редактирование связей */
    txt->begin=nd1;
    txt->end=nd2;
    txt->begin->next=nd2;
    txt->begin->previous=NULL;
    txt->end->next=NULL;
    txt->end->previous = nd1;
    txt->length = 2;

    /* Создаем курсор */
    crsr *cursor;
    cursor = (crsr *) malloc(sizeof(crsr)); // Выделяем память под него

    /* Курсор в конец последней строки*/
    cursor->line = txt->end;
    cursor->position = strlen(txt->end->contents);
    txt->cursor = cursor;

    char line[2] = "2";
    char pos[2] = "1";

    /* Вызов функции */
    EXPECT_EQ(m(txt, line, pos), 2);

    char line1[2] = "1";
    char pos1[2] = "6";

      /* Вызов функции */
    EXPECT_EQ(m(txt, line1, pos1), 2);
}

TEST (M, negative1)
{
    /* Создаем структуру описания текста */
    text txt;
    txt = (list *) malloc(sizeof(list)); // Выделяем память под нее

    /* Только что созданный текст не содержит ни одной строки */
    txt->length = 0;

    char line[2] = "1";
    char pos[2] = "2";

    /* Вызов функции */
    EXPECT_EQ(m(txt, line, pos), 1);
}


