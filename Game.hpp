//
// Game.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:27:01 2012 Pierre WILMOT
// Last update Fri Aug  3 03:36:39 2012 Pierre WILMOT
//

#ifndef __GAME_HPP__
#define __GAME_HPP__

#include	<iostream>
#include	"GameData.hpp"
#include	"IView.hpp"
#include	"IControler.hpp"

#define	SPEED_UP_DELAY	250

class Game : public GameData
{
public:
  Game(IView &v, IControler &c, unsigned int heigt = DEFAULT_HEIGT, unsigned int width = DEFAULT_WIDTH);
  ~Game();

  int			play();
  bool			pieceCanFall() const;
  bool			pieceCanMove(IControler::e_action a) const;
  bool			pieceCanRotate() const;
  void			display() const;
  void			addNewPiece();
  void			applyFalling();
  void			fixPiece();
  void			movePiece(IControler::e_action a);
  void			cleanLines();

 private:
  Piece		m_piece;
  Piece		m_nextPiece;
  bool		m_running;
  bool		m_falling;
  IView		&m_view;
  IControler	&m_controler;
  int		m_speed;
  int		m_speedup;
  int		m_turn;
};

#endif
