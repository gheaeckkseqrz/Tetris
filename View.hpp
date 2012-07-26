#ifndef __VIEW_HPP__
#define __VIEW_HPP__

#include	<iostream>
#include        <SFML/System.hpp>
#include        <SFML/Graphics.hpp>

class View
{
 public:
  View();
  ~View();

private:
  sf::RenderWindow      *m_win;
};

#endif
