#include "Text.h"

Engine::Text::Text(const char* fontName, uint fontSize, Shader* shader)
{
	this->fontName = fontName;
	this->shader = shader;
	this->fontSize = fontSize;
	Init();
}

Engine::Text* Engine::Text::SetScale(float scale)
{
	this->scale = scale;
	return this;
}

Engine::Text* Engine::Text::SetColor(float r, float g, float b)
{
	color = vec3(r / 255, g / 255, b / 255);
	return this;
}

Engine::Text* Engine::Text::SetPosition(float x, float y)
{
	position = vec2(x, y);
	return this;
}

Engine::Text* Engine::Text::SetText(string text)
{
	this->text = text;
	return this;
}

// Tambahan
Engine::Text* Engine::Text::SetVisible(bool visible) {
	this->isVisible = visible;
	return this;
}

bool Engine::Text::IsVisible() const {
	return isVisible;
}
// Tambahan

void Engine::Text::Draw()
{
	// Tambahan
	if (!isVisible) return;
	// Tambahan

	float x = position.x;
	float y = position.y;

	// Activate corresponding render state
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	shader->Use();
	shader->setVec3(color, "ourColor");
	glActiveTexture(GL_TEXTURE0);
	shader->setInt(0, "ourTexture");
	mat4 model;
	shader->setMat4(model, "model");
	glBindVertexArray(vao);

	// Iterate through all characters
	string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		TextCharacter ch = TextCharacters[*c];
		GLfloat xpos = x + ch.Bearing.x * scale;
		GLfloat ypos = y - (this->TextCharacters['H'].Bearing.y - ch.Bearing.y) * scale;
		GLfloat w = ch.Size.x * scale;
		GLfloat h = ch.Size.y * scale;
		GLfloat H = TextCharacters['H'].Size.y * scale;
		ypos += (H - h);
		// Update VBO for each character
		GLfloat vertices[] = {
			// Positions			// Texture Coords
			xpos + w,  ypos + h,	1.0f, 0.0f, // Bottom Right
			xpos + w,  ypos,		1.0f, 1.0f, // Top Right
			xpos,	   ypos,		0.0f, 1.0f, // Top Left
			xpos,	   ypos + h,	0.0f, 0.0f  // Bottom Left 
		};
		// Render glyph texture over quad
		glBindTexture(GL_TEXTURE_2D, ch.TextureID);
		// Update content of VBO memory
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// Render quad
		glDrawArrays(GL_QUADS, 0, 4);
		// Now advance cursors for next glyph (note that advance is number of 1 / 64 pixels)
		x += (ch.Advance >> 6) * scale; // Bitshift by 6 to get value in pixels(2 ^ 6 = 64)
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_BLEND);

}

uint Engine::Text::GetFontSize()
{
	return fontSize;
}

float Engine::Text::GetScale()
{
	return scale;
}

void Engine::Text::Init()
{
	// Init Freetype
	FT_Library ft;
	if (FT_Init_FreeType(&ft)) {
		throw ("ERROR::FREETYPE: Could not init FreeType Library");
	}
	FT_Face face;
	if (FT_New_Face(ft, fontName, 0, &face)) {
		throw ("ERROR::FREETYPE: Failed to load font");
	}

	FT_Set_Pixel_Sizes(face, 0, fontSize);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction
	for (GLubyte c = 0; c < 128; c++)
	{
		// Load character glyph
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			throw "ERROR::FREETYTPE: Failed to load Glyph";
			continue;
		}
		// Generate texture
		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer
		);
		// Set texture options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// Now store character for later use
		TextCharacter character = {
			texture,
			ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			(GLuint)face->glyph->advance.x
		};
		TextCharacters.insert(pair<GLchar, TextCharacter>(c, character));
	}

	FT_Done_Face(face);
	FT_Done_FreeType(ft);

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 4 * 4, NULL,
		GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}