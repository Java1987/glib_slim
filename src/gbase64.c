
/* #include "glib.h" */


/* static const char base64_alphabet[] = */
/*         "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; */

/* /\** */
/*  * g_base64_encode: */
/*  * @data: (array length=len) (element-type guint8): the binary data to encode */
/*  * @len: the length of @data */
/*  * */
/*  * Encode a sequence of binary data into its Base-64 stringified */
/*  * representation. */
/*  * */
/*  * Returns: (transfer full): a newly allocated, zero-terminated Base-64 */
/*  *               encoded string representing @data. The returned string must */
/*  *               be freed with g_free(). */
/*  * */
/*  * Since: 2.12 */
/*  *\/ */
/* gchar * */
/* g_base64_encode (const guchar *data, */
/*                  gint         len) */
/* { */
/*   gchar *out; */
/*   gint state = 0, outlen; */
/*   gint save = 0; */

/*   g_return_val_if_fail (data != NULL || len == 0, NULL); */

/*   /\* We can use a smaller limit here, since we know the saved state is 0, */
/*      +1 is needed for trailing \0, also check for unlikely integer overflow *\/ */
/*   if (len >= ((G_MAXSIZE - 1) / 4 - 1) * 3) */
/*     g_error("%s: input too large for Base64 encoding (%"G_GINT_FORMAT" chars)", */
/*         G_STRLOC, len); */

/*   out = g_malloc ((len / 3 + 1) * 4 + 1); */

/*   outlen = g_base64_encode_step (data, len, FALSE, out, &state, &save); */
/*   outlen += g_base64_encode_close (FALSE, out + outlen, &state, &save); */
/*   out[outlen] = '\0'; */

/*   return (gchar *) out; */
/* } */

/* static const unsigned char mime_base64_rank[256] = { */
/*   255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, */
/*   255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, */
/*   255,255,255,255,255,255,255,255,255,255,255, 62,255,255,255, 63, */
/*    52, 53, 54, 55, 56, 57, 58, 59, 60, 61,255,255,255,  0,255,255, */
/*   255,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, */
/*    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,255,255,255,255,255, */
/*   255, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, */
/*    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,255,255,255,255,255, */
/*   255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, */
/*   255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, */
/*   255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, */
/*   255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, */
/*   255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, */
/*   255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, */
/*   255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, */
/*   255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, */
/* }; */

/* /\** */
/*  * g_base64_decode: */
/*  * @text: zero-terminated string with base64 text to decode */
/*  * @out_len: (out): The length of the decoded data is written here */
/*  * */
/*  * Decode a sequence of Base-64 encoded text into binary data.  Note */
/*  * that the returned binary data is not necessarily zero-terminated, */
/*  * so it should not be used as a character string. */
/*  * */
/*  * Returns: (transfer full) (array length=out_len) (element-type guint8): */
/*  *               newly allocated buffer containing the binary data */
/*  *               that @text represents. The returned buffer must */
/*  *               be freed with g_free(). */
/*  * */
/*  * Since: 2.12 */
/*  *\/ */
/* guchar * */
/* g_base64_decode (const gchar *text, */
/*                  gint       *out_len) */
/* { */
/*   guchar *ret; */
/*   gint input_length; */
/*   gint state = 0; */
/*   guint save = 0; */

/*   g_return_val_if_fail (text != NULL, NULL); */
/*   g_return_val_if_fail (out_len != NULL, NULL); */

/*   input_length = strlen (text); */

/*   /\* We can use a smaller limit here, since we know the saved state is 0, */
/*      +1 used to avoid calling g_malloc0(0), and hence returning NULL *\/ */
/*   ret = g_malloc0 ((input_length / 4) * 3 + 1); */

/*   *out_len = g_base64_decode_step (text, input_length, ret, &state, &save); */

/*   return ret; */
/* } */

/* /\** */
/*  * g_base64_decode_inplace: */
/*  * @text: (inout) (array length=out_len) (element-type guint8): zero-terminated */
/*  *        string with base64 text to decode */
/*  * @out_len: (inout): The length of the decoded data is written here */
/*  * */
/*  * Decode a sequence of Base-64 encoded text into binary data */
/*  * by overwriting the input data. */
/*  * */
/*  * Returns: (transfer none): The binary data that @text responds. This pointer */
/*  *               is the same as the input @text. */
/*  * */
/*  * Since: 2.20 */
/*  * */
/* guchar * */
/* g_base64_decode_inplace (gchar *text, */
/*                          gint *out_len) */
/* { */
/*   gint input_length, state = 0; */
/*   guint save = 0; */

/*   g_return_val_if_fail (text != NULL, NULL); */
/*   g_return_val_if_fail (out_len != NULL, NULL); */

/*   input_length = strlen (text); */

/*   g_return_val_if_fail (input_length > 1, NULL); */

/*   *out_len = g_base64_decode_step (text, input_length, (guchar *) text, &state, &save); */

/*   return (guchar *) text; */
/* } */
/* *\/ */
