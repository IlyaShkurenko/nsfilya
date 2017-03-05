#ifndef EXTRAMODULE_LIBRARY_H
#define EXTRAMODULE_LIBRARY_H
typedef struct {
    char sent[1000];
    struct Student *next;
} Student;
typedef struct {
    Student *head;
} List;
typedef struct {
    Student *student;
    struct Student *next;
    char name[100];
    List *list;
} Teacher;


char *return_StudenttoStr(List *self, int count, char * str);
char **split(char *str, char ch, int n);

List *ArrayOfList_new(List ** list, int count);

List *addLast(List *self, char value[]);

List Create_List(char *array, List list);

void List_print(List *self);

int List_count(List * self);

void ListNode_free(Student ** self);

void List_free(List * self);

List *createList(Teacher *tPtr, List **lists, int index, char *buffer, int stcount, char **name);

List *Teacher_toList(List **Teacher_toList, Teacher *tPtr, List *self, List **list, int index);

#endif