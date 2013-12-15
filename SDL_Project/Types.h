#include <SDL.h>
#include "vector2d.h"

namespace Geometry
{
	typedef SDL_Rect Rect;
	typedef Rect* RectPtr;
	typedef Vector2D<float> Size;
	typedef Vector2D<float> Position;
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
