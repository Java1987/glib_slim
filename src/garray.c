
#include "glib.h"

#define MIN_ARRAY_SIZE  16

typedef struct _GRealArray  GRealArray;

struct _GRealArray
{
  guint8 *data;
  guint   len;
  guint   alloc;
  guint   elt_size;
  guint   zero_terminated : 1;
  guint   clear : 1;
  //  gint    ref_count;
  // GDestroyNotify clear_func;
};

#define g_array_elt_len(array,i) ((array)->elt_size * (i))

#define g_array_elt_pos(array,i) ((array)->data + g_array_elt_len((array),(i)))

#define g_array_elt_zero(array, pos, len)                               \
  (memset (g_array_elt_pos ((array), pos), 0,  g_array_elt_len ((array), len)))

#define g_array_zero_terminate(array) G_STMT_START{                     \
  if ((array)->zero_terminated)                                         \
    g_array_elt_zero ((array), (array)->len, 1);                        \
}G_STMT_END

static guint g_nearest_pow (gint num)
{
  guint n = 1;

  while (n < num && n > 0)
    n <<= 1;

  return n ? n : num;
}

static void g_array_maybe_expand (GRealArray *array,
                      gint        len)
{
  guint want_alloc = g_array_elt_len (array, array->len + len + 
                                      array->zero_terminated);

  if (want_alloc > array->alloc)
    {
      want_alloc = g_nearest_pow (want_alloc);
      want_alloc = MAX (want_alloc, MIN_ARRAY_SIZE);

      array->data = g_realloc (array->data, want_alloc);

	  //      if (G_UNLIKELY (g_mem_gc_friendly))
      memset (array->data + array->alloc, 0, want_alloc - array->alloc);

      array->alloc = want_alloc;
    }
}

GArray* g_array_new(gint elt_size)
{
  GRealArray *array = g_new0(GRealArray, 1);

  array->data            = NULL;
  array->len             = 0;
  array->alloc           = 0;
  array->zero_terminated = 1;
  array->clear           = 1;
  array->elt_size        = elt_size;
  //  array->ref_count       = 1;
  //  array->clear_func      = NULL;
  
  if (array->zero_terminated)
  {
	g_array_maybe_expand (array, 0);
    g_array_zero_terminate(array);
  }

  return (GArray*) array;
}

void g_array_free(GArray *farray)
{
  GRealArray *array = (GRealArray*) farray;
   
  g_return_if_fail(array);

  if (array->data)
  {
	g_free(array->data);
	array->data = NULL;
	array->len = 0;
  }
  
  g_free(array);
}

GArray* g_array_append	  (GArray   *farray,
			   gpointer  data,
			   gint	     len)
{
  GRealArray *array = (GRealArray*) farray;
   
  g_return_val_if_fail (array, NULL);

  if (len == 0)
    return farray;

  g_array_maybe_expand (array, len);

  memcpy (g_array_elt_pos (array, array->len), data, 
          g_array_elt_len (array, len));

  array->len += len;

  g_array_zero_terminate (array);

  return farray;
}

GArray* g_array_prepend  (GArray   *farray,
			   gpointer  data,
			   gint	     len)
{
  GRealArray *array = (GRealArray*) farray;

  g_return_val_if_fail (array, NULL);

  if (len == 0)
    return farray;

  g_array_maybe_expand (array, len);

  memmove (g_array_elt_pos (array, len), g_array_elt_pos (array, 0),
           g_array_elt_len (array, array->len));

  memcpy (g_array_elt_pos (array, 0), data, g_array_elt_len (array, len));

  array->len += len;

  g_array_zero_terminate (array);

  return farray;
}

GArray* g_array_remove_range (GArray *farray,
                      guint   index_,
                      guint   length)
{
  GRealArray *array = (GRealArray*) farray;

  g_return_val_if_fail (array, NULL);
  g_return_val_if_fail (index_ <= array->len, NULL);
  g_return_val_if_fail (index_ + length <= array->len, NULL);

  //  if (array->clear_func != NULL)
  //  {
  //    guint i;
  //
  //    for (i = 0; i < length; i++)
  //    array->clear_func (g_array_elt_pos (array, index_ + i));
  //  }

  if (index_ + length != array->len)
    memmove (g_array_elt_pos (array, index_),
             g_array_elt_pos (array, index_ + length),
             (array->len - (index_ + length)) * array->elt_size);

  array->len -= length;
  //  if (G_UNLIKELY (g_mem_gc_friendly))
  //    g_array_elt_zero (array, array->len, length);
  //  else

  g_array_zero_terminate (array);

  return farray;
}

GArray* g_array_set_length (GArray   *farray,
			   gint	     length)
{
  GRealArray *array = (GRealArray*) farray;

  g_return_val_if_fail (array, NULL);

  if (length > array->len)
  {
    g_array_maybe_expand (array, length - array->len);
	if (array->clear)
      g_array_elt_zero (array, array->len, length - array->len);
  }
  else if (length < array->len) {
	g_array_remove_range (farray, length, array->len - length);
  }
   
  array->len = length;
  
  g_array_zero_terminate (array);
  
  return farray;
}

GArray* g_array_remove_index (GArray   *farray,
			   gint		 index_)
{
  GRealArray* array = (GRealArray*) farray;

  g_return_val_if_fail (array, NULL);

  g_return_val_if_fail (index_ < array->len, NULL);

  //  if (array->clear_func != NULL)
  //    array->clear_func (g_array_elt_pos (array, index_));

  if (index_ != array->len - 1)
    memmove (g_array_elt_pos (array, index_),
             g_array_elt_pos (array, index_ + 1),
             g_array_elt_len (array, array->len - index_ - 1));

  array->len -= 1;
  
  g_array_zero_terminate (array);

  return farray;
}

GArray* g_array_insert_val (GArray   *farray,
			   gint index_,
			   gpointer  data,
			   gint len)
{
  GRealArray *array = (GRealArray*) farray;

  g_return_val_if_fail (array, NULL);

  if (len == 0)
    return farray;

  g_array_maybe_expand (array, len);

  memmove (g_array_elt_pos (array, len + index_),
           g_array_elt_pos (array, index_),
           g_array_elt_len (array, array->len - index_));

  memcpy (g_array_elt_pos (array, index_), data, g_array_elt_len (array, len));

  array->len += len;

  g_array_zero_terminate (array);

  return farray;
}


