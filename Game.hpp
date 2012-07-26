//
// Game.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:27:01 2012 Pierre WILMOT
// Last update Fri Jul 27 00:59:09 2012 Pierre WILMOT
//

#ifndef __GAME_HPP__
#define __GAME_HPP__

#include	<iostream>
#include	"GameData.hpp"

class Game : public GameData
{
public:
  Game(unsigned int heigt = DEFAULT_HEIGT, unsigned int width = DEFAULT_WIDTH);
  ~Game();

  int			play();
  bool			pieceCanFall(int x, int y, Piece const &p);

 private:
  bool	m_running;
  bool	m_falling;
};

#endif
