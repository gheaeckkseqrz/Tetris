//
// GameData.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:36:39 2012 Pierre WILMOT
// Last update Sat Jul 28 02:48:01 2012 Pierre WILMOT
//

#ifndef __GAMEDATA_HPP__
#define __GAMEDATA_HPP__

#include	<iostream>
#include	<vector>
#include	"Piece.hpp"
#include	"Colors.hpp"

#define	DEFAULT_HEIGT	20
#define	DEFAULT_WIDTH	10

class GameData
{
public:
  GameData(unsigned int heigt, unsigned int width);
  ~GameData();

protected:
  unsigned int			m_heigt;
  unsigned int			m_width;
  std::vector<Colors::e_color>	*m_map;
  unsigned int			m_score;
};

#endif
