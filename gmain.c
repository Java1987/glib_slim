

#include "glib.h"

int main(int argc, char **argv) {
  // g_log_debug("%s\n", "main entry");
  gchar *origin = "I have a pen, I have a apple, en!, pineple, PPAP";
  gchar *copy = g_strdup(origin);
  g_log_debug("%s\n", copy);
  g_free(copy);
  // g_log_debug("%s\n", "main exit");
  return 0;
} 
