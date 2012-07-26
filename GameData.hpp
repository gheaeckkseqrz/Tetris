//
// GameData.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:36:39 2012 Pierre WILMOT
// Last update Fri Jul 27 00:14:10 2012 Pierre WILMOT
//

#ifndef __GAMEDATA_HPP__
#define __GAMEDATA_HPP__

#include	<iostream>
#include	<vector>
#include	"Piece.hpp"

#define	DEFAULT_HEIGT	20
#define	DEFAULT_WIDTH	10

class GameData
{
public:
  GameData(unsigned int heigt, unsigned int width);
  ~GameData();

protected:
  unsigned int		m_heigt;
  unsigned int		m_width;
  std::vector<Piece::e_color>	*m_map;
  unsigned int		score;
};

#endif
