/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

/**
 * @brief returns true when reach last line in prices file
 * @return True when is the last line of the file, False otherwise
 */
static bool is_last_line(unsigned int store)
{
  return store == NO_STORES - 1u;
}

void array_dump(PricesTable a)
{
  for (unsigned int store = 0u; store < NO_STORES; ++store)
  {
    Store sp = a[store][price];
    Store sd = a[store][amount];
    fprintf(stdout, "store %u %u: Syrah: %u (%u), Malbec: %u (%u), Cabernet Sauvignon: %u (%u), Merlot: %u (%u)",
            sp.id, sd.number,
            sp.syrah, sd.syrah,
            sp.malbec, sd.malbec,
            sp.cabernet_sauvignon, sd.cabernet_sauvignon,
            sp.merlot, sd.merlot);
    if (!is_last_line(store))
    {
      fprintf(stdout, "\n");
    }
  }
}

unsigned int max_total_sales(PricesTable a)
{
  unsigned int maximum_total_sales = 0;
  maximum_total_sales = ((a[0][price].syrah * a[0][amount].syrah) + (a[0][price].malbec * a[0][amount].malbec) + (a[0][price].cabernet_sauvignon * a[0][amount].cabernet_sauvignon) + (a[0][price].merlot * a[0][amount].merlot));

  /* COMPLETAR */
  for (int store = 0; store < NO_STORES; store++)
  {
    if (maximum_total_sales < ((a[store][price].syrah * a[store][amount].syrah) + (a[store][price].malbec * a[store][amount].malbec) + (a[store][price].cabernet_sauvignon * a[store][amount].cabernet_sauvignon) + (a[store][price].merlot * a[store][amount].merlot)))
    {
      maximum_total_sales = ((a[store][price].syrah * a[store][amount].syrah) + (a[store][price].malbec * a[store][amount].malbec) + (a[store][price].cabernet_sauvignon * a[store][amount].cabernet_sauvignon) + (a[store][price].merlot * a[store][amount].merlot));
    }
  }

  return maximum_total_sales;
}

void array_from_file(PricesTable array, const char *filepath)
{
  int filasPorTienda[NO_STORES][2];
  for (int i = 0; i < NO_STORES; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      filasPorTienda[i][j] = 0;
    }
  }

  FILE *file = NULL;

  file = fopen(filepath, "r");
  if (file == NULL)
  {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  unsigned int id;
  unsigned int number;

  int i = 0;
  while (!(feof(file)) && (i < (NO_STORES * TYPE)))
  {

    /* COMPLETAR: Leer ambos Store */
    Store store_prices = store_from_file(file, price);
    Store store_amounts = store_from_file(file, amount);

    /* COMPLETAR: lectura de store id y store number */
    int res = fscanf(file, " #%u-%u# ", &id, &number);
    if (res != 2)
    {
      fprintf(stderr, "Invalid file.\n");
      exit(EXIT_FAILURE);
    }
    if (((int)id) <= 0 || (number > NO_STORES) || (number < 1) || ((int)number) < 0)
    {
      fprintf(stderr, "Store numbers must be between 1 and 16 and id must be positive\n");
      exit(EXIT_FAILURE);
    }

    if ((filasPorTienda[number - 1][0] == 0))
    {
      filasPorTienda[number - 1][0] = 1;
    }
    else
    {
      fprintf(stderr, "For each store there should be only one row of prices\n");
      exit(EXIT_FAILURE);
    }

    if ((filasPorTienda[number - 1][1] == 0))
    {
      filasPorTienda[number - 1][1] = 1;
    }
    else
    {
      fprintf(stderr, "For each store there should be only one row of amounts\n");
      exit(EXIT_FAILURE);
    }

    /* COMPLETAR: Actualizar ambos Store con los datos de store id y store number */
    store_prices.id = id;
    store_prices.number = number;
    store_amounts.number = number;
    store_amounts.id = id;
    /* COMPLETAR: Guardar ambos Store en el arreglo multidimensional*/
    array[number - 1][price] = store_prices;
    array[number - 1][amount] = store_amounts;
    i++;
  }
  fclose(file);
}
