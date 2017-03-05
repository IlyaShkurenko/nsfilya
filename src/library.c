#include "library.h"

#include <stdio.h>
#include <assert.h>
#include <printf.h>
#include <string.h>
#include <stdlib.h>

List *ArrayOfList_new(List ** list, int count) {

    for(int i = 0; i < count; i++){
        list[i] = (List *) malloc(10 * sizeof(List ));
        list[i]->head = NULL;
    }
    return list;
}
List Create_List(char *array, List list) {
    list = *addLast(&list, array);

    return list;
}
Student *List_new(char *value) {
    Student *node = (Student *) malloc(sizeof(Student));
    node->next = NULL;
    strcpy(node->sent, value);

    return node;
}
List *addLast(List *self, char value[]) {
    Student *node = List_new(value);
    if (self->head == NULL) {
        self->head = node;
        return self;
    }
    Student *cur = self->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = node;
    return self;
}

void List_print(List *self) {
    {
        Student *cur = self->head;
        while (cur != NULL) {
            printf("%s\n", cur->sent);
            cur = cur->next;
        }
    }
}

int List_count(List * self) {
    Student *cur = self->head;
    int i = 0;
    while (cur != NULL) {
        i++;
        cur = cur->next;
    }
    return i;
}

void ListNode_free(Student ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}
void List_free(List * self){
    Student * cur = self->head;
    while(cur!=NULL){
        cur = cur->next;
        ListNode_free(&cur);

    }
}

char **split(char *str, char ch, int n) {
    char **words, *p;
    int cnt, i;

    words = NULL;
    cnt = 0;
    for (p = strtok(str, ","); p != NULL; p = strtok(NULL, ",")) {
        if ((words = (char **) realloc(words, sizeof(char *) * (cnt + 1))) == NULL)
            exit(1);
        if ((words[cnt] = strdup(p)) == NULL)
            exit(1);
        ++cnt;
    }

    if (!words || !cnt) {
        printf("Shit happens!\n");
        exit(1);
    }

    return words;
}

List *createList(Teacher *tPtr, List **lists, int index, char *buffer, int stcount, char **name) {
    for (int i = 0; i < stcount; i++) {
        if (strstr(buffer, name[i]) != NULL) {
            lists[index] = addLast(lists[index], name[i]);
        }
    }
    return lists[index];
}
List *Teacher_toList(List **Teacher_toList, Teacher *tPtr, List *self, List **list, int index) {
    Teacher_toList[index]->head = NULL;
    int count = 0;
    Student *cur = self->head;
    Student *listcur = list[index]->head;
    if (listcur == NULL) {
        while (cur != NULL) {
            Teacher_toList[index] = addLast(Teacher_toList[index], cur->sent);
            cur = cur->next;
        }
        return Teacher_toList[index];
    }
    else{
        while(cur!=NULL){
            while (listcur!=NULL){
                if(strcmp(cur->sent,listcur->sent)){
                    count++;
                    if(count == List_count(list[index])) {
                        Teacher_toList[index] = addLast(Teacher_toList[index], cur->sent);
                    }
                }
                listcur = listcur->next;
            }
            count = 0;
            cur = cur->next;
            listcur = list[index]->head;
        }
        return Teacher_toList[index];
    }
}

char *return_StudenttoStr(List *self, int count, char * str) {
    Student *cur = self->head;
    int i = 0;
    for (int i = 0; i <= count; i++) {
        strcat(str, cur->sent);
        if (i != count) {
            strcat(str, ", ");
        }
        cur = cur->next;
    }
    return str;
}
