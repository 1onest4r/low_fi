#include "texture.h"
#include "stb_image.h"
#include "config.h"

Texture2D::Texture2D(const char* fileName) {
    int width, height, channels;
    unsigned char* data = stbi_load(fileName, &width, &height, &channels, 0);

    if (!data) {
        std::cout << "Failed to load texture: " << fileName << std::endl;
        return;
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data); // delete from cpu
}

Texture2D::~Texture2D() {
    glDeleteTextures(1, &textureID);
}

void Texture2D::bind() {
    glBindTexture(GL_TEXTURE_2D, textureID);
}