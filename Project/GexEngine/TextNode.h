
#pragma once

#include "SceneNode.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include <string>

class TextNode : public SceneNode
{
public:
					TextNode(const FontHolder_t& fonts, const std::string& text_);

	void			setString(const std::string& text_);

private:
	virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Text		text;
	sf::IntRect		position;
};

