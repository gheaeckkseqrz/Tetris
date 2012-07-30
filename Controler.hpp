//
// Controler.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Sat Jul 28 03:46:30 2012 Pierre WILMOT
// Last update Mon Jul 30 03:56:11 2012 Pierre WILMOT
//

#ifndef __CONTROLER_HPP__
#define __CONTROLER_HPP__

#include	<iostream>
#include	<SFML/Window/Event.hpp>
#include	<SFML/Window/Keyboard.hpp>
#include	"IControler.hpp"
#include	"View.hpp"
#include	"Threadable.hpp"

class Controler : public IControler, public Threadable
{
public:
  Controler(View &v);
  ~Controler();

  e_action	getEvent();

private:
  int		threadEntryPoint();

private:
  e_action		m_action;
  View			&m_view;
};

#endif
