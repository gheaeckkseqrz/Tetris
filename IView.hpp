//
// IView.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Fri Jul 27 01:53:52 2012 Pierre WILMOT
// Last update Mon Aug  6 19:30:40 2012 Pierre WILMOT
//

#ifndef __IVIEW_HPP__
#define __IVIEW_HPP__

#include	<iostream>
#include	"Colors.hpp"

class IView
{
public:
  virtual void		clear() = 0;
  virtual void		refresh() = 0;
  virtual void		drawBloc(int x, int y, Colors::e_color, bool border = true) = 0;
  virtual void		setScore(unsigned int score) = 0;
};

#endif
