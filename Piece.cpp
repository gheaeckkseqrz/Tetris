//
// Piece.cpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:53:51 2012 Pierre WILMOT

//

#include	<iostream>
#include	"Piece.hpp"
#include	"Random.hpp"

Piece::Piece()
{
  int	size;
  int	x;
  int	y;

  m_shape = new bool*[MAX_WIDTH];
  for (int i(0) ; i < MAX_WIDTH ; ++i)
    m_shape[i] = new bool[MAX_HEIGT];

  for (int i(0) ; i < MAX_WIDTH ; ++i)
    for (int j(0) ; j < MAX_HEIGT ; ++j)
      m_shape[i][j] = false;

  size  = Random::rand(1, (MAX_WIDTH * MAX_HEIGT) / 2);
  for (int i(0) ; i < size ; ++i)
    {
      while (1)
	{
	  x = Random::rand(0, MAX_WIDTH - 1);
	  y = Random::rand(0, MAX_HEIGT - 1);
	  if (!m_shape[x][y])
	    {
	      m_shape[x][y] = true;
	      i++;
	      break;
	    }
	}
    }

  std::cout << "Final Piece : " << std::endl << std::endl;

  for (int i(0) ; i < MAX_WIDTH ; ++i)
    {
      std::cout << std::endl;
    for (int j(0) ; j < MAX_HEIGT ; ++j)
      std::cout << ((m_shape[i][j]) ? 'X' : ' ');
  std::cout << std::endl << std::endl;
    }

}

Piece::~Piece()
{
}
