#ifndef SPRITE_H
#define SPRITE_H

namespace CastleKeep
{
	class Sprite
	{
	public:
		Sprite(int widht, int height, void* data);
		virtual ~Sprite();
		setPos(int x, int y);
		setPos(Pos pos);

	private:
		Pos _pos;
		int _width;
		int _height;
		void *_data;
	}
}

#endif
