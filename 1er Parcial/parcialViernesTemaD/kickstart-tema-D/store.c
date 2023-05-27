/*
  @file store.c
  @brief Implements store structure and methods
*/
#include <stdlib.h>
#include "store.h"

static const int NUMBER_OF_STORE_VARS = 4;

Store store_from_file(FILE *file, type_t type)
{
  Store store;
  int res;
  if (type == price)
  {
    res = fscanf(file, EXPECTED_PRICES_FILE_FORMAT, &store.syrah, &store.malbec, &store.cabernet_sauvignon, &store.merlot);
  }
  else
  {
    res = fscanf(file, "%u %u %u %u ", &store.syrah, &store.malbec, &store.cabernet_sauvignon, &store.merlot);
  }
  if (res != NUMBER_OF_STORE_VARS)
  {
    fprintf(stderr, "Invalid array format readed from input file");
    exit(EXIT_FAILURE);
  }

  if ((int)store.syrah < 0 || (int)store.malbec < 0 || (int)store.cabernet_sauvignon < 0 || (int)store.merlot < 0)
  {
    fprintf(stderr, "Prices or amounts must be 0 or positive\n");
    exit(EXIT_FAILURE);
  }

  return store;
}
