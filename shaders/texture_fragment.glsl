#version 330 core
out vec4 FragColor;

in vec2 textureCoords;

uniform sampler2D textureData;

void main() {
    FragColor = texture(textureData, textureCoords);
}

