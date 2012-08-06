//
// main.cpp for de in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:05:36 2012 Pierre WILMOT
// Last update Sun Jul 29 03:49:37 2012 Pierre WILMOT
//

#include	"Game.hpp"
#include	"View.hpp"
#include	"Controler.hpp"

int	main(int ac, char **av)
{
  (void)ac;
  (void)av;
  View		v;
  Controler	c(v);
  Game		a(v, c);

  a.play();

  std::cout << "Quiting" << std::endl;
  return (0);
}
