/*Copyright (C) 2013 Real Numbers

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef RENDERER_H
#define RENDERER_H

#include "types.h"
#include "window.h"

namespace CastleKeep
{
	class Sprite;

	enum class RenderBackend
	{
		SDL2,
		OPENGL,
		OPENGLES	
	};

	struct RenderInfo
	{
	/**/
	};

	class Renderer
	{
	public:
		Renderer(Window *window, Color background);
		virtual ~Renderer();
		virtual void render(const RenderInfo &info)=0;
		virtual void renderSprite(const Sprite &sprite)=0;
		virtual void renderSpriteArray(Sprite sprites[], int length)=0;
		virtual void clearScreen()=0;
		virtual Sprite* createSpriteFromPixelBuffer(uint8_t buffer);
	private:
		Window *_window;
		Color _background;
	};

}

#endif
