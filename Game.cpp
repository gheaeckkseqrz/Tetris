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

Game::Game(IView &v, IControler &c, unsigned int heigt, unsigned int width)
  :GameData(heigt, width), m_running(true), m_view(v), m_controler(c), m_speed(5), m_speedup(1), m_turn(0)
{
  std::cout << "Initilising Game, H : " << heigt << " W : " << width << std::endl;
  m_piece.setX((width - (MAX_WIDTH)) / 2);
  m_piece.setY(heigt);
}

Game::~Game()
{
}

int		       	Game::play()
{
  while (m_running)
    {
      if (m_falling == false)
	addNewPiece();
      if (pieceCanFall())
	applyFalling();
      else
	{
	  fixPiece();
	  cleanLines();
	}
      display();
      movePiece(m_controler.getEvent());
      display();
      usleep((1000000 / 10) * (m_speed / m_speedup));
      m_turn++;
      if (m_turn % SPEED_UP_DELAY == 0 && m_speed > 1)
	m_speed--;
    }
  return (0);
}

bool			Game::pieceCanFall() const
{
  for (unsigned int i(m_piece.getMinX()) ; i < m_piece.getMaxX() ; ++i)
    for (unsigned int j(m_piece.getMinY()) ; j < m_piece.getMaxY() ; ++j)
      {
	if (m_piece.getBloc(i, j) && (j + m_piece.getY()) <= 0)
	  return (false);
	if (m_piece.getBloc(i, j) && m_map[i + m_piece.getX()][j + m_piece.getY() - 1] != Colors::None)
	  return (false);
      }
  return (true);
}

void			Game::display() const
{
  m_view.clear();
  for (unsigned int x(0) ; x < m_width ; ++x)
    for (unsigned int y(0) ; y < m_heigt ; ++y)
      {
	if (m_map[x][y] != Colors::None)
	  m_view.drawBloc(x, y, m_map[x][y]);
      }
  if (m_falling)
    m_piece.display(m_view, m_heigt);
  m_view.setScore(m_score);
  m_view.refresh();
}

void			Game::addNewPiece()
{
  m_piece = m_nextPiece;
  m_nextPiece.reset();
  m_piece.setX((m_width - (MAX_WIDTH)) / 2);
  m_piece.setY(DEFAULT_HEIGT);
  m_falling = true;
}

void			Game::applyFalling()
{
  m_piece.setY(m_piece.getY() - 1);
}

void			Game::fixPiece()
{
  for (unsigned int i(0) ; i < m_piece.getMaxX() ; ++i)
    for (unsigned int j(0) ; j < m_piece.getMaxY() ; ++j)
      if (m_piece.getBloc(i, j))
	{
	  m_map[i + m_piece.getX()][j + m_piece.getY()] = m_piece.getColor();
	  if (j + m_piece.getY() > m_heigt)
	    {
	      sleep(2);
	      m_running = false;
	    }
	}
  m_falling = false;
  m_speedup = 1;
}

void			Game::movePiece(IControler::e_action a)
{
  if (!pieceCanMove(a))
    return;
  switch (a)
    {
    case IControler::None :
      return;
      break;
    case IControler::Rotate :
      if (pieceCanRotate())
	m_piece.rotate();
      break;
    case IControler::Fall :
      m_speedup *= 2;
      break;
    case IControler::Right :
      m_piece.setX(m_piece.getX() + 1);
      break;
    case IControler::Left :
      m_piece.setX(m_piece.getX() - 1);
      break;
    }
}

void			Game::cleanLines()
{
  for (unsigned int j(0) ; j < m_heigt ; ++j)
    {
      for (unsigned int i(0) ; i < m_width ; ++i)
	{
	  if (m_map[i][j] == Colors::None)
	    break;
	  if (i == m_width - 1)
	    {
	      std::cout << "Have to del L" << j << std::endl;
	      for(unsigned int a(0) ; a < m_width ; ++a)
		m_map[a].erase(m_map[a].begin() + j);
	      j--;
	      m_score++;
	    }
	}
    }
}

bool		Game::pieceCanMove(IControler::e_action a) const
{
  int	d(0);

  if (a == IControler::Right)
    {
      d = 1;
      if (m_piece.getMaxX() + m_piece.getX() + 1 > m_width )
	return (false);
    }
  else if (a == IControler::Left)
    {
      if (m_piece.getX() + m_piece.getMinX() <= 0)
	return (false);
      d = -1;
    }
  for (unsigned int i(m_piece.getMinX()) ; i < m_piece.getMaxX() ; ++i)
    for (unsigned int j(m_piece.getMaxX()) ; j < m_piece.getMaxY() ; ++j)
      {
	if (m_piece.getBloc(i, j) && m_map[i + m_piece.getX() + d][j + m_piece.getY()] != Colors::None)
	  return (false);
      }
  return (true);
}

bool		Game::pieceCanRotate() const
{
  Piece		test;

  test = m_piece;
  test.rotate();
  if (m_piece.getX() + test.getMaxX() >= m_width
      || m_piece.getX() + (int)test.getMinX() < 0)
    return (false);
  for (unsigned int i(test.getMinX()) ; i < test.getMaxX() ; ++i)
    for (unsigned int j(test.getMinY()) ; j < test.getMaxY() ; ++j)
      {
	if (test.getBloc(i, j) && m_map[i + m_piece.getX()][j + m_piece.getY()] != Colors::None)
	  return (false);
      }
  return (true);
}
