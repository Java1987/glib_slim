
#include "glib.h"

GList* g_list_alloc		(void);
void   g_list_free		(GList		*list);
void   g_list_free_1		(GList		*list);
GList* g_list_append		(GList		*list,
				 gpointer	 data);
GList* g_list_prepend		(GList		*list,
				 gpointer	 data);
GList* g_list_insert		(GList		*list,
				 gpointer	 data,
				 gint		 position);
GList* g_list_insert_sorted	(GList		*list,
				 gpointer	 data,
				 GCompareFunc	 func);			    
GList* g_list_concat		(GList		*list1, 
				 GList		*list2);
GList* g_list_remove		(GList		*list,
				 gpointer	 data);
GList* g_list_remove_link	(GList		*list,
				 GList		*link);
GList* g_list_reverse		(GList		*list);
GList* g_list_nth		(GList		*list,
				 guint		 n);
GList* g_list_find		(GList		*list,
				 gpointer	 data);
GList* g_list_find_custom	(GList		*list,
				 gpointer	 data,
				 GCompareFunc	 func);
gint   g_list_position		(GList		*list,
				 GList		*link);
gint   g_list_index		(GList		*list,
				 gpointer	 data);
GList* g_list_last		(GList		*list);
GList* g_list_first		(GList		*list);
guint  g_list_length		(GList		*list);
void   g_list_foreach		(GList		*list,
				 GFunc		 func,
				 gpointer	 user_data);
gpointer g_list_nth_data	(GList		*list,
				 guint		 n);

#define g_list_previous(list)	((list) ? (((GList *)(list))->prev) : NULL)
#define g_list_next(list)	((list) ? (((GList *)(list))->next) : NULL)

/* Singly linked lists
 */
GSList* g_slist_alloc		(void);
void	g_slist_free		(GSList		*list);
void	g_slist_free_1		(GSList		*list);
GSList* g_slist_append		(GSList		*list,
				 gpointer	 data);
GSList* g_slist_prepend		(GSList		*list,
				 gpointer	 data);
GSList* g_slist_insert		(GSList		*list,
				 gpointer	 data,
				 gint		 position);
GSList* g_slist_insert_sorted	(GSList		*list,
				 gpointer	 data,
				 GCompareFunc	 func);			    
GSList* g_slist_concat		(GSList		*list1, 
				 GSList		*list2);
GSList* g_slist_remove		(GSList		*list,
				 gpointer	 data);
GSList* g_slist_remove_link	(GSList		*list,
				 GSList		*link);
GSList* g_slist_reverse		(GSList		*list);
GSList* g_slist_nth		(GSList		*list,
				 guint		 n);
GSList* g_slist_find		(GSList		*list,
				 gpointer	 data);
GSList* g_slist_find_custom	(GSList		*list,
				 gpointer	 data,
				 GCompareFunc	 func);
gint	g_slist_position	(GSList		*list,
				 GSList		*link);
gint	g_slist_index		(GSList		*list,
				 gpointer	 data);
GSList* g_slist_last		(GSList		*list);
guint	g_slist_length		(GSList		*list);
void	g_slist_foreach		(GSList		*list,
				 GFunc		 func,
				 gpointer	 user_data);
gpointer g_slist_nth_data	(GSList		*list,
				 guint		 n);

#define g_slist_next(slist)	((slist) ? (((GSList *)(slist))->next) : NULL)
