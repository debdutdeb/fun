#include "strtok.h"

char *tokenize(const char *__src, int delim)
{
  static const char *src;
  static char *token;
  const char *start_pos_loc;

  if (__src)
    {
      src = __src;
      start_pos_loc = src;
    }
  else
    {
      if (!token)
        {
          start_pos_loc = src;
        }
      else
        {
          memcpy(&start_pos_loc, token - sizeof(char *), sizeof(char *));
          free((void *)token - sizeof(char *));
        }
    }

  size_t substring_length = 0;
  const char *ptr;

  for (ptr = start_pos_loc; *ptr != 0 && *ptr != delim; ptr++)
    {
      substring_length++;
    }

  if (!substring_length)
    {
      return NULL;
    }

  // Skipping the final delimiter.
  ptr++;

  token = malloc(substring_length + 1 + sizeof(char *));
  assert(token);

  memcpy(token, &ptr, sizeof(char *));
  token += sizeof(char *);
  memcpy(token, start_pos_loc, substring_length);

  token[substring_length] = 0;

  return token;
}