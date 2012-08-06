//
// View.cpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Fri Jul 27 13:59:57 2012 Pierre WILMOT

//

#include	<iostream>
#include	<sstream>
#include	"View.hpp"

View::View()
{
  m_win = new  sf::RenderWindow(sf::VideoMode(WIN_X_PX, WIN_Y_PX), "Tetris");

  m_colors[Colors::Red] = sf::Color::Red;
  m_colors[Colors::Green] = sf::Color::Green;
  m_colors[Colors::Blue] = sf::Color::Blue;
  m_colors[Colors::Yellow] = sf::Color::Yellow;
  m_colors[Colors::Gray] = sf::Color(230, 230, 230);
  m_colors[Colors::Orange] = sf::Color(255, 174, 0);
  m_colors[Colors::Pink] = sf::Color(255, 127, 127);
  m_colors[Colors::Purple] = sf::Color(127, 0, 127);
}

View::~View()
{
}


void		View::clear()
{
  sf::RectangleShape bloc;

  m_win->clear();
  bloc.setSize(sf::Vector2f(WIN_X_PX, 100));
  bloc.setFillColor(sf::Color::White);
  bloc.setPosition(0, 0);
  m_win->draw(bloc);
}

void		View::refresh()
{
  m_win->display();
}

void		View::drawBloc(int x, int y, Colors::e_color c, bool border)
{
  sf::RectangleShape bloc;

  bloc.setSize(sf::Vector2f(BLOC_SIZE, BLOC_SIZE));
  bloc.setOutlineColor(sf::Color::Black);
  bloc.setOutlineThickness(0);
  if (border)
    bloc.setOutlineThickness(1);
  bloc.setFillColor(m_colors[c]);
  bloc.setPosition(x * BLOC_SIZE, WIN_Y_PX - (y * BLOC_SIZE) - BLOC_SIZE);
  m_win->draw(bloc);
}

void		View::setScore(unsigned int score)
{
  std::stringstream	ss;
  ss << score;

  sf::Text		text(ss.str());
  text.setCharacterSize(30);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Black);

  m_win->draw(text);
}

sf::RenderWindow	*View::getWin() const
{
  return (m_win);
}
