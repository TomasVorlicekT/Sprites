#pragma once

#include <string>
#include "Surface.h"
#include "Vei2.h"
#include "Graphics.h"
#include "Colors.h"

class Font
{
public:
	Font(const std::string& filename, int glyphWidth, int glyphHeight);
	void Draw(Graphics& gfx, const std::string& text, const Vei2 pos, const Color textColor) const;
private:
	void convertCharToSpriteSection(Graphics& gfx, const char c, const Vei2 pos, const Color textColor) const;

private:
	static constexpr Color chroma = Colors::White;
	Surface fontSprite;
	int glyphWidth;
	int glyphHeight;
	const int rows{ 3 };
	const int columns{ 32 };
	const char beginChar = ' ';
	const char endChar = '~';
};