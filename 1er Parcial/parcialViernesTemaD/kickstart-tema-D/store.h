/*
  @file store.h
  @brief Defines store prices and amounts information
*/

#ifndef _STORE_H
#define _STORE_H
#define EXPECTED_PRICES_FILE_FORMAT "%u %u %u %u "

typedef enum
{
  price,
  amount
} type_t;

#include <stdio.h>

/** @brief Type used to represent store data.*/
typedef struct _store
{
  unsigned int id;     // store id
  unsigned int number; // store number
  type_t type;
  unsigned int syrah;
  unsigned int malbec;
  unsigned int cabernet_sauvignon;
  unsigned int merlot;
} Store;

/**
 * @brief reads store data from file line
 * @details
 * Store file line must contain:
 * <unsigned int> <unsigned int> <unsigned int> <unsigned int>
 *
 * @param[in] file Opened file stream
 * @param[in] type The type of information
 * @return Store structure which contains read information from file
 */
Store store_from_file(FILE *file, type_t type);

#endif //_STORE_H
