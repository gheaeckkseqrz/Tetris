#include	<iostream>
#include	"View.hpp"

View::View()
{
  m_win = new  sf::RenderWindow(sf::VideoMode(768, 768), "Snake");
}

View::~View()
{
}
