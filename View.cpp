//
// View.cpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Fri Jul 27 13:59:57 2012 Pierre WILMOT
// Last update Mon Aug  6 16:47:35 2012 Pierre WILMOT
//

#include	<iostream>
#include	"View.hpp"

View::View()
{
  m_win = new  sf::RenderWindow(sf::VideoMode(WIN_X_PX, WIN_Y_PX), "Tetris");

  m_colors[Colors::Red] = sf::Color::Red;
  m_colors[Colors::Green] = sf::Color::Green;
  m_colors[Colors::Blue] = sf::Color::Blue;
  m_colors[Colors::Yellow] = sf::Color::Yellow;
  m_colors[Colors::Gray] = sf::Color(127, 127, 127);
}

View::~View()
{
}


void		View::clear()
{
  m_win->clear();
}

void		View::refresh()
{
  m_win->display();
}

void		View::drawBloc(int x, int y, Colors::e_color c)
{
  sf::RectangleShape bloc;

  bloc.setSize(sf::Vector2f(BLOC_SIZE, BLOC_SIZE));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(1);
  bloc.setFillColor(m_colors[c]);
  bloc.setPosition(x * BLOC_SIZE, WIN_Y_PX - (y * BLOC_SIZE) - BLOC_SIZE);
  m_win->draw(bloc);
}

void		View::setScore(unsigned int score)
{
  (void)score;
}

sf::RenderWindow	*View::getWin() const
{
  return (m_win);
}
