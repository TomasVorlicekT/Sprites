#include "Font.h"

Font::Font(const std::string& filename, int glyphWidth, int glyphHeight)
	:
	fontSprite(filename),
	glyphWidth(glyphWidth),
	glyphHeight(glyphHeight)
{
}

void Font::Draw(Graphics& gfx, const std::string& text, const Vei2 pos, const Color textColor) const
{
	Vei2 posChar = pos;

	for (const char& c : text)
	{
		if (c >= beginChar + 1 && c <= endChar)
		{
			convertCharToSpriteSection(gfx, c, posChar, textColor);
		}
		posChar.x += glyphWidth;
	}
}

void Font::convertCharToSpriteSection(Graphics& gfx, const char c, const Vei2 pos, const Color textColor) const
{
	int charPosSprite = c - beginChar;
	int rowNum = charPosSprite / columns;
	int columnNum = charPosSprite % columns;

	RectI srcRect = RectI(Vei2(columnNum * glyphWidth, rowNum * glyphHeight), glyphWidth, glyphHeight);

	gfx.DrawSprite((int)pos.x, (int)pos.y, srcRect, fontSprite, chroma);
}
