#include <stdlib.h>
#include <check.h>
#include "library.h"

START_TEST (check_equals_List_from_CVS_string)
    {
        int i = 0;
        List list = {
                .head = NULL,
        };
        char str[] = "ilya,dima,vlad,igor";
        char **array;
        array = split(str, ',', 3);
        for (int i = 0; i <= 3; i++) {
            list = Create_List(array[i], list);
        }
        Student * cur = list.head;
        while(cur!=NULL){
            ck_assert_str_eq(cur->sent,array[i]);
            cur = cur->next;
            i++;
        }

    } END_TEST
START_TEST (check_equals_CVS_StringFromList)
    {
        List list = {
                .head = NULL,
        };
        char str[] = "ilya, dima, vlad, igor";
        list = *addLast(&list,"ilya");
        list = *addLast(&list,"dima");
        list = *addLast(&list,"vlad");
        list = *addLast(&list,"igor");
        char * buf = (char *) malloc(4 * sizeof(str));
        return_StudenttoStr(&list, 3,buf);
        ck_assert_str_eq(str,buf);

    }
END_TEST

START_TEST (List_to_Teacher)
    {
        //testing attachment of students to the teacher list
        int i = 0;
        List list = {
                .head = NULL,
        };
        List **lists = (List **) malloc(2 * sizeof(List *));
        List **List_toTeacher = (List **) malloc(3 * sizeof(List *));
        Teacher *tPtr = (Teacher *) malloc(3 * sizeof(Teacher));
        char **namesForTest1 = (char**)malloc(2* sizeof(char*));
        namesForTest1[0] = "ilya";
        namesForTest1[1] = "vlad";
        char **namesForTest2 = (char**)malloc(3 * sizeof(char*));
        namesForTest2[0] = "ilya";
        namesForTest2[1] = "dima";
        namesForTest2[2] = "igor";
        char **namesForTest3 = (char**)malloc(4 * sizeof(char*));
        namesForTest3[0] = "ilya";
        namesForTest3[1] = "dima";
        namesForTest3[2] = "vlad";
        namesForTest3[3] = "igor";
        char **namesForTest4 = (char**)malloc(2* sizeof(char*));
        namesForTest4[0] = "dima";
        namesForTest4[1] = "igor";
        char **namesForTest5 = (char**)malloc(1* sizeof(char*));
        namesForTest5[0] = "vlad";
        char str[] = "ilya, dima, vlad, igor";
        ArrayOfList_new(lists,3);
        ArrayOfList_new(List_toTeacher,3);
        strcpy(tPtr[0].name,"Ruslan");
        strcpy(tPtr[1].name,"Olena");
        strcpy(tPtr[2].name,"Ivan");
        lists[0] = createList(tPtr, lists, 0, str, 2,namesForTest1);
        lists[1] = createList(tPtr, lists, 1, str, 3,namesForTest2);
        Student * cur = lists[0]->head;
        while(cur!=NULL){
            ck_assert_str_eq(cur->sent,namesForTest1[i]);
            cur = cur->next;
            i++;
        }
        i = 0;
        Student * cur2 = lists[1]->head;
        while(cur2!=NULL){
            ck_assert_str_eq(cur2->sent,namesForTest2[i]);
            cur2 = cur2->next;
            i++;
        }
        /*testing function that takes a list of students and a teacher and as a
         result creates a new list in which students are entered from t
         he input list that are not tied to this teacher.*/
        list = *addLast(&list,"ilya");
        list = *addLast(&list,"dima");
        list = *addLast(&list,"vlad");
        list = *addLast(&list,"igor");
        List_toTeacher[2] = Teacher_toList(List_toTeacher, tPtr, &list, lists, 2);
        Student * cur3 = List_toTeacher[2]->head;
        i = 0;
        while(cur3!=NULL){
            ck_assert_str_eq(cur3->sent,namesForTest3[i]);
            cur3 = cur3->next;
            i++;
        }
        List_toTeacher[0] = Teacher_toList(List_toTeacher, tPtr, &list, lists, 0);
        Student * cur4 = List_toTeacher[0]->head;
        i = 0;
        while(cur4!=NULL){
            ck_assert_str_eq(cur4->sent,namesForTest4[i]);
            cur4 = cur4->next;
            i++;
        }
        List_toTeacher[1] = Teacher_toList(List_toTeacher, tPtr, &list, lists, 1);
        Student * cur5 = List_toTeacher[1]->head;
        i = 0;
        while(cur5!=NULL){
            ck_assert_str_eq(cur5->sent,namesForTest5[i]);
            cur5 = cur5->next;
            i++;
        }
        free(namesForTest1);
        free(namesForTest2);
        free(namesForTest3);
        free(namesForTest4);
        free(namesForTest5);
        for(int j = 0; j < 2; j++){
            List_free(lists[j]);
        }
        for(int j = 0; j < 3; j++){
            List_free(List_toTeacher[j]);
        }


    }
END_TEST
Suite *test_suite() {
    Suite *s = suite_create("Module");
    TCase *tc_sample;

    tc_sample = tcase_create("TestCase");
    tcase_add_test(tc_sample, check_equals_List_from_CVS_string);
    tcase_add_test(tc_sample, check_equals_CVS_StringFromList);
    tcase_add_test(tc_sample, List_to_Teacher);

    suite_add_tcase(s, tc_sample);

    return s;
}
int main() {
    Suite *s = test_suite();
    SRunner *sr = srunner_create(s);
    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_VERBOSE);

    int num_tests_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return num_tests_failed;
    return EXIT_SUCCESS;
}