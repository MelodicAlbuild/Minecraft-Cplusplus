#ifndef MINECRAFT_SHADER_H
#define MINECRAFT_SHADER_H
#include "core.h"

namespace Minecraft {
	enum class ShaderType : uint8 {
		Vertex,
		Fragment
	};

	struct Shader {
		char* filepath;
		uint32 shaderId;
		ShaderType type;

		bool compile(ShaderType type, const char* shaderFilepath);
		void destroy();

		static GLenum toGlShaderType(ShaderType type);
	};
}

#endif