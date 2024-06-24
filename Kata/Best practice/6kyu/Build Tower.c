void build_tower(unsigned n, char **tower)// the size of tower is n * 2n - 1
{
  for (unsigned int i = 0; i < n; i++)
    for (unsigned int j = 0; j < 2 * n - 1; j++)
      if (j >= (n - 1) - i && j <= (n - 1) + i)
        tower[i][j] = '*';
      else
        tower[i][j] = ' ';
}