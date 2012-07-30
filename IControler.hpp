//
// IControler.hpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Sat Jul 28 04:12:48 2012 Pierre WILMOT
// Last update Mon Jul 30 03:56:16 2012 Pierre WILMOT
//

#ifndef	__ICONTROLER_HPP__
#define	__ICONTROLER_HPP__

class	IControler
{
public:
  enum	e_action
    {
      Right,
      Left,
      Rotate,
      Fall,
      None
    };

public:
  virtual e_action	getEvent() = 0;

};

#endif
