
#include "glib.h"

void g_mem_record_to(gstring path, G_MEM_CALLBACK callback) {}

void g_mem_record_begin() {}

void g_mem_record_end() {}

gpointer g_mem_record_malloc(gulong size, const char* __file__, const int __line__, const char* __func__)
{
  // g_log_debug("file %s: line %d (%s): malloc %d", __file__, __line__, __func__, size);
  return malloc(size);
}

gpointer g_mem_record_malloc0(gulong size, const char* __file__, const int __line__, const char* __func__)
{
  // g_log_debug("file %s: line %d (%s): malloc %d", __file__, __line__, __func__, size);
  gpointer ptr = malloc(size);
  if (ptr)
    memset(ptr, 0, size);
  return ptr;
}

gpointer g_mem_record_realloc(gpointer mem, gulong size, const char* __file__, const int __line__, const char* __func__)
{
  // g_log_debug("file %s: line %d (%s): realloc %d", __file__, __line__, __func__, size);
  return realloc(mem, size);
}

void g_mem_record_free(gpointer mem, const char* __file__, const int __line__, const char* __func__)
{
  // g_log_debug("file %s: line %d (%s): free %d", __file__, __line__, __func__, size);
  free(mem);
}
