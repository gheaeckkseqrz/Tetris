//
// main.cpp for de in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:05:36 2012 Pierre WILMOT
// Last update Fri Jul 27 01:40:40 2012 Pierre WILMOT
//

#include	"Game.hpp"
#include	"View.hpp"

int	main(int ac, char **av)
{
  (void)ac;
  (void)av;
  View		v;
  Game		a;

  a.play();

  std::cout << "Quiting" << std::endl;
  return (0);
}
