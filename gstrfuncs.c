
#include "glib.h"


gchar* g_strdelimit (gchar       *string,
              const gchar *delimiters,
              gchar        new_delim)
{
  gchar *c;
4
  g_return_val_if_fail (string != NULL, NULL);

  if (!delimiters)
    delimiters = G_STR_DELIMITERS;

  for (c = string; *c; c++)
    {
      if (strchr (delimiters, *c))
        *c = new_delim;
    }

  return string;
}

gchar* g_strdup (const gchar *str)
{
  gchar *new_str;
  gint length;

  if (str)
    {
      length = strlen (str) + 1;
      new_str = g_new (char, length);
      memcpy (new_str, str, length);
    }
  else
    new_str = NULL;

  return new_str;
}
