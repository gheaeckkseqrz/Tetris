//
// Piece.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:54:08 2012 Pierre WILMOT
// Last update Mon Aug  6 19:18:55 2012 Pierre WILMOT
//

#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include	<iostream>
#include	"IView.hpp"
#include	"Colors.hpp"

#define	MAX_HEIGT	5
#define	MAX_WIDTH	5

class Piece
{
public:
  Piece();
  ~Piece();

  int			getX() const;
  unsigned int		getY() const;

  unsigned int		getMaxX() const;
  unsigned int		getMaxY() const;
  unsigned int		getMinX() const;
  unsigned int		getMinY() const;

  void			setX(unsigned int x);
  void			setY(unsigned int y);

  bool			getBloc(int x, int y) const;
  void			setBloc(int x, int y, bool v);
  Colors::e_color	getColor() const;
  void			setColor(Colors::e_color);
  void			reset();
  void			display(IView &v, unsigned int yLimit) const;
  void			rotate();
  void			calcMaximuns();

  Piece			&operator=(const Piece &m);

private:
  int			m_x;
  unsigned int		m_y;
  unsigned int		m_minX;
  unsigned int		m_minY;
  unsigned int		m_maxX;
  unsigned int		m_maxY;
  bool			**m_shape;
  Colors::e_color	m_color;
  std::string		m_pieces[7];
  Colors::e_color	m_colordList[7];
};

#endif
