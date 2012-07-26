//
// Piece.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:54:08 2012 Pierre WILMOT
// Last update Fri Jul 27 01:00:32 2012 Pierre WILMOT
//

#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include	<iostream>

#define	MAX_HEIGT	5
#define	MAX_WIDTH	5

class Piece
{
public:
  enum	e_color
    {
      None,
      Red,
      Green,
      Blue,
      Max_Color
    };

public:
  Piece();
  ~Piece();

private:
  bool		**m_shape;
};

#endif
