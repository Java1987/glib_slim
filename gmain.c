

#include "glib.h"

int main(int argc, char **argv) {
  g_log_debug("%s\n", "main entry");

  g_log_debug("%s\n", "strfuncs start");
  gchar *origin = "I have a pen, I have a apple, en!, pineple, PPAP";
  gchar *copy = g_strdup(origin);
  g_log_debug("%s\n", copy);
  g_free(copy);

  g_log_debug("%s\n", "garray start");
  GArray *array = g_array_new_with_type(int);
  int i = 11, j = 12, k = 13;
  g_array_append(array, &i, 1);
  g_array_append(array, &j, 1);
  g_array_prepend(array, &k, 1);
  g_log_debug("garray len = %d\n", array->len);
  g_array_free(array);
  
  g_log_debug("%s\n", "main exit");
  return 0;
} 
