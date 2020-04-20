#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "_text.h"
}
TEST(SHWB, num0)
{
    /* Создаем структуру описания текста */
    text txt;
    txt = (list *) malloc(sizeof(list)); // Выделяем память под нее
    /* Создаем первую строку */
    const char contents1[MAXLINE+1] = {"str1 ptr1"};
    node *nd1;
    nd1 = (node *) malloc(sizeof(node)); // Выделяем память под нее
    strncpy(nd1->contents, contents1, MAXLINE);


    /* Создаем вторую строку */
    const char contents2[MAXLINE+1] = {"str2 ptr2 dtr2"};
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

    /* Вызов функции */
    showwordbeginnings(txt);

    FILE* f = fopen("shwb", "r");
    char buf[MAXLINE + 1];
    fgets(buf, MAXLINE, f);
    EXPECT_EQ(strcmp(buf, "s    p   \n"),0);
    fgets(buf, MAXLINE, f);
    EXPECT_EQ(strcmp(buf, "s    p    d   \n"),0);
}

TEST (SHWB, negative0)
{
    /* Создаем структуру описания текста */
    text txt;
    txt = (list *) malloc(sizeof(list)); // Выделяем память под нее

    /* Только что созданный текст не содержит ни одной строки */
    txt->length = 0;

    /* Вызов функции */
    EXPECT_EQ(showwordbeginnings(txt), 1);
}

