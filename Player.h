#pragma once
#include <string.h>
#include <string>
class PLAYER
{
private:
	int nCenterX, nCenterY;
	int nMoveX, nMoveY;
	int nX, nY;
	std::string g_strPlayer;
public:
	explicit PLAYER();

	inline int player_str() 
	{ 
		return g_strPlayer.size();
	}

	/*inline int GetnCenterX() const
	{
		return nCenterX;
	}
	inline void SetnCenterX(int _nCenterX)
	{
		nCenterX = _nCenterX;
	}

	inline int GetnCenterY()
	{
		return nCenterY;
	}*/
	int PLAYER::Getplayer_str(int _strPlayer)
	{
	 return	g_strPlayer[_strPlayer];
	}
	int PLAYER::GetnCenterX()
	{
		return nCenterX;
	}
	int PLAYER::GetnCenterY()
	{
		return nCenterY;
	}
	int PLAYER::GetnMoveX()
	{
		return nMoveX;
	}
	int PLAYER::GetnMoveY()
	{
		return nMoveY;
	}
	int PLAYER::GetnX()
	{
		return nX;
	}
	int PLAYER::GetnY()
	{
		return nY;
	}
	int PLAYER::SetnMoveXmin(int _nMoveX )
	{
		nMoveX-= _nMoveX;
		return _nMoveX;
	}
	int PLAYER::SetnMoveXplus( int _nMoveX )
	{
		nMoveX += _nMoveX;
		return _nMoveX;
	}
	int PLAYER::SetnX(int _nMoveX, int _nCenterX)
	{
	  nX=_nMoveX-_nCenterX;
	  return _nMoveX-_nCenterX;
	}
	void Init();
};