//
// Threadable.hpp for plazza in /home/jowett_j//pj/plazza/svn
// 
// Made by james jowett
// Login   <jowett_j@epitech.net>
// 
// Started on  Tue Apr 10 05:27:59 2012 james jowett
// Last update Mon Jul 30 03:08:12 2012 Pierre WILMOT
//

#ifndef __THREADABLE_HPP_
#define __THREADABLE_HPP_

#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cerrno>
#include <pthread.h>
#include "Mutex.hpp"

class Threadable
{
public:
  Threadable();
  ~Threadable();

  void			threadIt();

protected:
  virtual int		threadEntryPoint() = 0;
  bool			mustQuit();

private:
  static void		*entryPoint(void *);

private:
  Mutex			m_mustQuitMutex;
  volatile bool		m_mustQuit;
  bool			m_launched;
  pthread_t		m_thread;

private:
  Threadable(Threadable const&);
  Threadable	&operator=(Threadable const&);
};

#endif
