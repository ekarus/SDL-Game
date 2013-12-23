#include <SDL.h>
#include "vector2d.h"
#include "Rectangle.h"

namespace Geometry
{
	typedef SDL_Rect Rect;
	typedef Rect* RectPtr;
	typedef Vector2D<float> Size;
	typedef Vector2D<float> Position;
//	typedef Rectangle<float> Rectangle;
}

namespace Physics
{
	typedef Vector2D<float> Velocity;
	typedef Vector2D<float> Acceleration;
}

namespace Game
{
	typedef float FrameTime;
}

/*
struct Color
{
	enum Enum
	{
		green,
		blue,
		gray,
		orange,
		red,
		dark_gray,
		white,
		black
	};
};

typedef SDL_Texture RawTexture;
typedef RawTexture* RawTexturePtr;*/
