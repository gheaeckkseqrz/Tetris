#ifndef __VIEW_HPP__
#define __VIEW_HPP__

#include	<iostream>
#include        <SFML/System.hpp>
#include        <SFML/Graphics.hpp>
#include	<SFML/Graphics/Text.hpp>
#include	"IView.hpp"
#include	"Piece.hpp"
#include	"Colors.hpp"

#define	BLOC_SIZE	15
#define	WIN_X_PX	150
#define	WIN_Y_PX	400

class View : public IView
{
public:
  View();
  ~View();

  void			clear();
  void			refresh();
  void			drawBloc(int x, int y, Colors::e_color, bool border = true);
  void			setScore(unsigned int score);
  sf::RenderWindow	*getWin() const;

private:
  sf::Color		m_colors[Colors::Max_Color];
  sf::RenderWindow      *m_win;
};

#endif
