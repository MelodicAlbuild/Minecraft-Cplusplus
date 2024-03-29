#ifndef SQUARE_PLAYER_H
#define SQUARE_PLAYER_H

namespace Minecraft {
	struct Window;

	namespace Cubes {
		void init(const Window& window);
		void destroy();

		void update(float dt);
	}
}

#endif