//
// Random.cpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Fri Jul 27 01:30:31 2012 Pierre WILMOT
// Last update Fri Jul 27 01:30:32 2012 Pierre WILMOT
//

#include "Random.hpp"

void	Random::seed(unsigned int seed)
{
  srand(seed);
}

int	Random::rand(int min, int max)
{
  return (::rand() % (max + 1 - min) + min);
}
