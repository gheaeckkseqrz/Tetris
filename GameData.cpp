//
// GameData.cpp for Tetris in /home/wilmot_p/PROJETS/Tetris
// 
// Made by Pierre WILMOT
// Login   <pierre.wilmot@gmail.com>
// 
// Started on  Thu Jul 26 23:39:34 2012 Pierre WILMOT

//

#include	<iostream>
#include	"GameData.hpp"

GameData::  GameData(unsigned int heigt, unsigned int width)
  : m_heigt(heigt), m_width(width)
{
  m_map = new std::vector<Colors::e_color>[width];

  for (unsigned int i(0) ; i < m_width ; ++i)
    m_map[i].insert(m_map[i].begin(), m_heigt + MAX_HEIGT, Colors::None);
}

GameData::~GameData()
{
  delete[] m_map;
}
