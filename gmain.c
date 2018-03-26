

#include "glib.h"


void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/** 
*   heap_sort start
*/
#define LEFT(i)  (((i) << 1) + 1)
#define RIGHT(i) (((i) << 1) + 2)

void max_heapify(int *array, int arr_len, int i) {
  if (i >= arr_len)
    return;

  int left = LEFT(i);
  int right = RIGHT(i);

  int max = i;
  if (left < arr_len && array[left] > array[max])
    max = left;
  if (right < arr_len && array[right] > array[max])
    max = right;

  if (max != i) {
    swap(&array[i], &array[max]);
    max_heapify(array, arr_len, max);
  }
}

void build_max_heap(int *array, int arr_len) {
  int last_parent = arr_len / 2;
  for (int i = last_parent; i >= 0; i--) {
    max_heapify(array, arr_len, i);
  }
}

void heap_sort(int *array, int arr_len) {

// 如果找前K大的数，使用该方法
//  for (int i = 0; i < arr_len; i++) {
//    build_max_heap(&array[i], arr_len - i);
//  }

  build_max_heap(array, arr_len);
  
  int length = arr_len;
  for (int i = arr_len - 1; i > 0; i--) {
    swap(&array[0], &array[i]);
    length--;
    max_heapify(array, length, 0);
  }
}
/** 
*   heap_sort end
*/


/** 
*   quick_sort start
*/
void quick_sort(int *array, int length) {
  if (length <= 1) 
    return;

  int pivot = length - 1;
  int k = 0;
  for (int j = 0; j < pivot; j++) {
    if (array[j] < array[pivot]) {
      swap(&array[j], &array[k]);
      k++;
    }
  }
  swap(&array[k], &array[pivot]);

  quick_sort(&array[0], k);
  
  quick_sort(&array[k + 1], length - k - 1);
}
/** 
*   quick_sort end
*/


int main(int argc, char **argv) {
  g_log_debug("%s\n", "main entry");

  /* g_log_debug("%s\n", "strfuncs start"); */
  /* gchar *origin = "I have a pen, I have a apple, en!, pineple, PPAP"; */
  /* gchar *copy = g_strdup(origin); */
  /* g_log_debug("%s\n", copy); */
  /* g_free(copy); */

  /* g_log_debug("%s\n", "garray start"); */
  /* GArray *array = g_array_new_with_type(int); */
  /* int i = 11, j = 12, k = 13; */
  /* g_array_append(array, &i, 1); */
  /* g_array_append(array, &j, 1); */
  /* g_array_prepend(array, &k, 1); */
  /* g_log_debug("garray len = %d\n", array->len); */
  /* g_array_free(array); */

  int array[10] = {10, 1, 2, 3, 4, 5, 7, 9, 8, 6};
  // heap_sort(array, 10);
  quick_sort(array, 10);
  for (int i = 0; i < 10; i++) {
      g_log_debug("a[%d] = %d ## ", i, array[i]);
    }
  g_log_debug("%s\n", "main exit");
  return 0;
} 
