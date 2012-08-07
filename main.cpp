//
// main.cpp for de in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:05:36 2012 Pierre WILMOT
// Last update Tue Aug  7 06:11:39 2012 Pierre WILMOT
//

#include	<unistd.h>
#include	"Game.hpp"
#include	"View.hpp"
#include	"Controler.hpp"
#include	"Random.hpp"



int	main(int ac, char **av)
{
  (void)ac;
  (void)av;
  View		v;
  Controler	c(v);
  Game		a(v, c);

  Random::seed(getpid());
  a.play();

  std::cout << "Quiting" << std::endl;
  return (0);
}
