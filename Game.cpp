//
// Game.cpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:26:15 2012 Pierre WILMOT
//

#include	<unistd.h>
#include	<iostream>
#include	"Game.hpp"

Game::Game(unsigned int heigt, unsigned int width)
  :GameData(heigt, width), m_running(true)
{
  std::cout << "Initilising Game, H : " << heigt << " W : " << width << std::endl;
}

Game::~Game()
{
}

int		       	Game::play()
{
  while (m_running)
    {
      std::cout << "Game is running" << std::endl;
      Piece	a;
      sleep(1);
    }
  return (0);
}

bool			Game::pieceCanFall(int x, int y, Piece const &p)
{
  (void)x;
  (void)y;
  (void)p;

  return (true);
}
