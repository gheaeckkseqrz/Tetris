//
// Mutex.hpp for plazza in /home/jowett_j//pj/plazza/svn
// 
// Made by james jowett
// Login   <jowett_j@epitech.net>
// 
// Started on  Wed Apr 11 02:14:01 2012 james jowett
// Last update Mon Jul 30 03:05:32 2012 Pierre WILMOT
//

#ifndef	__MUTEX_HPP__
#define __MUTEX_HPP__

#include	<cerrno>
#include	<cstring>
#include	<stdexcept>
#include	<iostream>
#include	<pthread.h>

class Mutex
{
public:
  enum e_type
    {
      Normal,
      Recursive
    };

public:
  Mutex(e_type = Normal);
  ~Mutex();
  bool			lock();
  bool			trylock(bool&);
  bool			unlock();
  e_type		getType();

  private:
  e_type		m_t;
  pthread_mutex_t	m_mutex;

private:
  Mutex(Mutex const&);
  Mutex& operator=(Mutex const&);
};

#endif
