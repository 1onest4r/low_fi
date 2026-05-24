#pragma once

class Texture2D {
public:
    Texture2D(const char* fileName);
    ~Texture2D();
    void bind();

private:
    unsigned int textureID;
};