#ifndef INCLUDED_DRAWABLE_
#define INCLUDED_DRAWABLE_

#include <glm/glm.hpp> // for glm::mat4
#include "shaderprogram.h"

class Drawable
{
	protected:
		ShaderProgram &d_shaderProgram;

	public:
		Drawable(ShaderProgram &shaderProgram);
		virtual ~Drawable();

		ShaderProgram &shaderProgram();

		void draw(glm::mat4 const &viewMat, glm::mat4 const &projMat);
		virtual bool needsLighting() const;

	private:
		virtual void drawImpl(glm::mat4 const &viewMat, glm::mat4 const &projMat) = 0;
};

inline bool Drawable::needsLighting() const
{
	return false;
}

inline ShaderProgram &Drawable::shaderProgram()
{
	return d_shaderProgram;
}

#endif
