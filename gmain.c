

#include "glib.h"

int main(int argc, char *argv) {
  g_log_debug("%s\n", "main entry");
  
  g_log_debug("%s\n", "main exit");
  return 0;
} 
