#include "strtok.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv, char *envp[])
{
  const char *string0 = "Hello World Hello Universe";
  const char *string0_tokened[] = {"Hello", "World", "Hello", "Universe"};
  const char *string1 = "A random string that does nothing exceptional";
  const char *string1_tokened[] = {"A",    "random",  "string",     "that",
                                   "does", "nothing", "exceptional"};

  char *token;

  token = tokenize(string0, ' ');
  for (int i = 0; token && i < 4; token = tokenize(NULL, ' '), i++)
    {
      printf("got_token='%s', saved_token='%s'\n", token, string0_tokened[i]);
      assert(strcmp(token, string0_tokened[i]) == 0);
    }

  token = tokenize(string1, ' ');
  for (int i = 0; token && i < 7; token = tokenize(NULL, ' '), i++)
    {
      printf("got_token='%s', saved_token='%s'\n", token, string1_tokened[i]);
      assert(strcmp(token, string1_tokened[i]) == 0);
    }

  return 0;
}