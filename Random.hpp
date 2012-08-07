//
// Random.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Fri Jul 27 01:18:54 2012 Pierre WILMOT
// Last update Tue Aug  7 06:20:44 2012 Pierre WILMOT
//

#ifndef __RANDOM_HPP__
#define __RANDOM_HPP__

#include	<ctime>
#include	<cstdlib>

class Random
{
public:
  static void	seed(unsigned int seed = time(0));
  static int	rand(int min, int max);
};

#endif
