#include <Elementary.h>


EAPI_MAIN int
elm_main(int argc, char **argv)
{
   Evas_Object *win, *btn;

   elm_policy_set(ELM_POLICY_QUIT, ELM_POLICY_QUIT_LAST_WINDOW_CLOSED);

   win = elm_win_util_standard_add("Main", "App");
   elm_win_autodel_set(win, EINA_TRUE);

   evas_object_show(btn);
   Eo * layout1 = elm_layout_add(win);
   Eo * layout2 = elm_layout_add(win);
   elm_layout_file_set(layout1,"source.edj","my_group");
   elm_layout_file_set(layout2,"source.edj","my_group");
   evas_object_show(layout1);
   evas_object_show(layout2);


   edje_object_text_class_set(elm_layout_edje_get(layout1), "test_class", "Sans", 50);

   //Ali.m This will override layout1 textblock too
   edje_object_text_class_set(elm_layout_edje_get(layout2), "test_class", "Sans", 30);

   evas_object_move(layout1,0,0);
   evas_object_move(layout2,160,240);
   evas_object_resize(layout1,160,240);
   evas_object_resize(layout2,160,240);
   evas_object_resize(win,320,480);
   evas_object_show(win);
   elm_run();

   return 0;
}
ELM_MAIN()