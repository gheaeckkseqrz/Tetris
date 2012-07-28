//
// IView.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Fri Jul 27 01:53:52 2012 Pierre WILMOT
// Last update Sat Jul 28 00:58:15 2012 Pierre WILMOT
//

#ifndef __IVIEW_HPP__
#define __IVIEW_HPP__

#include	<iostream>
#include	"Colors.hpp"

#define	WIN_X_PX	500
#define	WIN_Y_PX	500

class IView
{
public:
  virtual void		clear() = 0;
  virtual void		refresh() = 0;
  virtual void		drawBloc(int x, int y, Colors::e_color) = 0;
  virtual void		setScore(unsigned int score) = 0;
};

#endif
