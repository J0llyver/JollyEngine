#include "Texture.h"

#include "stb_image/stb_image.h"
#include <GL/glew.h>

Texture::Texture(const std::string &path) {
  stbi_set_flip_vertically_on_load(1);  // OpenGL expects texture pixels to start at the bottom left

  int width, height, bpp;
  unsigned char* localBuffer = stbi_load(path.c_str(), &width, &height, &bpp, 4);

  glGenTextures(1, &rendererId);
  glBindTexture(GL_TEXTURE_2D, rendererId);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
  glBindTexture(GL_TEXTURE_2D, 0);

  if (localBuffer) {
    stbi_image_free(localBuffer);
  }
}

Texture::~Texture() { glDeleteTextures(1, &rendererId); }

void Texture::Bind(unsigned int slot) const {
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, rendererId);
}

void Texture::Unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }
