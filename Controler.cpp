//
// Controler.cpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Sat Jul 28 13:40:30 2012 Pierre WILMOT
// Last update Wed Aug  1 20:46:02 2012 Pierre WILMOT
//

#include	<iostream>
#include	"Controler.hpp"

Controler::Controler(View &v)
  : m_action(None), m_view(v)
{
  threadIt();
}

Controler::~Controler()
{
}

IControler::e_action		Controler::getEvent()
{
  e_action	ret;

  ret = m_action;
  m_action = None;
  return (ret);
}

int		Controler::threadEntryPoint()
{
  sf::Event	e;

  while (!mustQuit())
    {
      m_view.getWin()->waitEvent(e);
      if (e.type == sf::Event::KeyPressed)
	{
	  switch (e.key.code)
	    {
	    case sf::Keyboard::Up :
	      m_action = Rotate;
	      break;
	    case sf::Keyboard::Down :
	      m_action = Fall;
	      break;
	    case sf::Keyboard::Right :
	      m_action = Right;
	      break;
	    case sf::Keyboard::Left :
	      m_action = Left;
	      break;
	    default:
	      break;
	    }
	}
    }
  return (0);
}
