
#include "glib.h"

void g_mem_record_to(gstring path, G_MEM_CALLBACK callback) {}

void g_mem_record_begin() {}

void g_mem_record_end() {}

gpointer g_mem_record_malloc(gulong size, const char* _file, const int _line, const char* _func)
{
  // g_log_debug("file %s: line %d (%s): malloc %d", _file, _line, _func, size);
  return malloc(size);
}

gpointer g_mem_record_malloc0(gulong size, const char* _file, const int _line, const char* _func)
{
  // g_log_debug("file %s: line %d (%s): malloc %d", _file, _line, _func, size);
  gpointer ptr = malloc(size);
  if (ptr)
    memset(ptr, 0, size);
  return ptr;
}

gpointer g_mem_record_realloc(gpointer mem, gulong size, const char* _file, const int _line, const char* _func)
{
  // g_log_debug("file %s: line %d (%s): realloc %d", _file, _line, _func, size);
  return realloc(mem, size);
}

void g_mem_record_free(gpointer mem, const char* _file, const int _line, const char* _func)
{
  // g_log_debug("file %s: line %d (%s): free %d", _file, _line, _func, size);
  free(mem);
}
