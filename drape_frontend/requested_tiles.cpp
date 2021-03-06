#include "drape_frontend/requested_tiles.hpp"

namespace df
{

void RequestedTiles::Set(ScreenBase const & screen, bool have3dBuildings, TTilesCollection && tiles)
{
  lock_guard<mutex> lock(m_mutex);
  m_tiles = move(tiles);
  m_screen = screen;
  m_have3dBuildings = have3dBuildings;
}

TTilesCollection RequestedTiles::GetTiles()
{
  TTilesCollection tiles;
  {
    lock_guard<mutex> lock(m_mutex);
    m_tiles.swap(tiles);
  }
  return tiles;
}

ScreenBase RequestedTiles::GetScreen()
{
  lock_guard<mutex> lock(m_mutex);
  return m_screen;
}

bool RequestedTiles::Have3dBuildings()
{
  lock_guard<mutex> lock(m_mutex);
  return m_have3dBuildings;
}

bool RequestedTiles::CheckTileKey(TileKey const & tileKey) const
{
  lock_guard<mutex> lock(m_mutex);
  if (m_tiles.empty())
    return true;

  return m_tiles.find(tileKey) != m_tiles.end();
}

} //namespace df
