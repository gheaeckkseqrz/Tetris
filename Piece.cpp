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
  m_shape = new bool*[MAX_WIDTH];
  for (int i(0) ; i < MAX_WIDTH ; ++i)
    m_shape[i] = new bool[MAX_HEIGT];

  m_pieces[0] = ("11000110000000000000");
  m_pieces[1] = ("10000110001000000000");
  m_pieces[2] = ("10000110000100000000");
  m_pieces[3] = ("01000110001000000000");
  m_pieces[4] = ("11000100001000000000");
  m_pieces[5] = ("10000100001100000000");
  m_pieces[6] = ("11111000000000000000");

  reset();
}

Piece::~Piece()
{
}

unsigned int	Piece::getX() const
{
  return (m_x);
}

unsigned int	Piece::getY() const
{
  return (m_y);
}

unsigned int	Piece::getMaxX() const
{
  return (m_maxX);
}

unsigned int	Piece::getMaxY() const
{
  return (m_maxY);
}

void		Piece::setX(unsigned int x)
{
  m_x = x;
}

void		Piece::setY(unsigned int y)
{
  m_y = y;
}

void		Piece::reset()
{
  int	r;

  m_x = 0;
  m_y = 0;

  for (int i(0) ; i < MAX_WIDTH ; ++i)
    for (int j(0) ; j < MAX_HEIGT ; ++j)
      m_shape[i][j] = false;

  r = Random::rand(0, 6);

  for (int i(0) ; i < MAX_WIDTH ; ++i)
    for (int j(0) ; j < MAX_HEIGT ; ++j)
      {
	if (m_pieces[r][i * MAX_HEIGT + j] == '1')
	  m_shape[i][j] = true;
      }
  calcMaximuns();
  m_color = Colors::Red;
}

void		Piece::display(IView &v, unsigned int yLimit) const
{
  for (int i(0) ; i < MAX_WIDTH ; ++i)
    {
      for (int j(0) ; j < MAX_HEIGT ; ++j)
	{
	  if (m_shape[i][j] && (j + m_y) < yLimit)
	    v.drawBloc(i + m_x, j + m_y, m_color);
	}
    }
}

bool		Piece::getBloc(int x, int y) const
{
  if (x < 0 || x > MAX_WIDTH || y < 0 || y > MAX_HEIGT)
    return (false);
  return (m_shape[x][y]);
}

Colors::e_color	Piece::getColor() const
{
  return (m_color);
}

Piece		&Piece::operator=(const Piece &m)
{
  std::cout << "Piece = operator " << std::endl;

  for (int i(0) ; i < MAX_WIDTH ; ++i)
    for (int j(0) ; j < MAX_WIDTH ; ++j)
      m_shape[i][j] = m.getBloc(i, j);

  m_maxX = m.m_maxX;
  m_maxY = m.m_maxY;
  m_color = m.getColor();
  return (*this);
}

void		Piece::rotate()
{
  unsigned int		max;
  bool			*m[5];
  bool			bak;

  max = (m_maxY > m_maxX) ? m_maxY : m_maxX;
  m[0] = &bak;
  for (unsigned int i(0) ; i < max / 2 ; ++i)
    for (unsigned int j(0) ; j < (max + 1) / 2 ; ++j)
      {
	m[1] = &(m_shape[j][i]);
	m[2] = &(m_shape[i][max-1-j]);
	m[3] = &(m_shape[max-1-j][max-1-i]);
	m[4] = &(m_shape[max-1-i][j]);
	for (int k(0) ; k < 5 ; ++k)
	  *m[k] = *m[(k+1)%5];
      }
  calcMaximuns();
}

void		Piece::calcMaximuns()
{
  m_maxY = 0;

  for (unsigned int i(0) ; i < MAX_WIDTH ; ++i)
    for (unsigned int j(0) ; j < MAX_HEIGT ; ++j)
      {
	if (m_shape[i][j])
	  {
	    std::cout << "There is a bloc in " << i << " | " << j << std::endl;
	    m_maxX = i;
	    if (j > m_maxY)
	      m_maxY = j;
	  }
      }
  m_maxX++;
  m_maxY++;
  std::cout << "MaxX : " << m_maxX << std::endl;
  std::cout << "MaxY : " << m_maxY << std::endl;
}
