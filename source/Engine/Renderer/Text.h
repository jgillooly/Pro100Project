#pragma once
#include "Font.h"
#include "Core/Color.h"
#include <string>
#include <memory>

struct SDL_Texture;
namespace antares {
	class Renderer;
	class Text
	{
	public:
		Text() = default;
		Text(std::shared_ptr<Font> font) : m_font{ font } {}
		~Text();
		void Create(Renderer& renderer, const std::string& text, const Color& color);
		void Draw(Renderer& renderer, int x, int y);
		void Draw(Renderer& renderer, const class Transform& transform);
		friend class SpaceGame;
	private:
		std::shared_ptr<Font> m_font;
		SDL_Texture* m_texture = nullptr;
	};
}