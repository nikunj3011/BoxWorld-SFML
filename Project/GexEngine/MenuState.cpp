#include "MenuState.h"
#include "Utility.h"
#include "ResourceHolder.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


MenuState::MenuState(StateStack& stack, Context context)
    : State(stack, context)
    , options()
    , optionIndex(0)
{
    sf::Texture& texture = context.textures->get(TextureID::TitleScreen);
    sf::Font& font = context.fonts->get(FontID::Main);

    backgroundSprite.setTexture(texture);

    sf::Text playOption;
    playOption.setFont(font);
    playOption.setString("Play");
    centerOrigin(playOption);
    playOption.setPosition(context.window->getView().getSize() / 2.f);
    options.push_back(playOption);

    sf::Text exitOption;
    exitOption.setFont(font);
    exitOption.setString("Exit");
    centerOrigin(exitOption);
    exitOption.setPosition(playOption.getPosition() + sf::Vector2f(0.f, 30.f));
    options.push_back(exitOption);

    updateOptionText();
    //context.music->play(MusicID::MenuTheme);

}

void MenuState::draw()
{
    auto& window = *getContext().window;

    window.setView(window.getDefaultView());
    window.draw(backgroundSprite);

    for (const auto& text : options) {
        window.draw(text);
    }
}

bool MenuState::update(sf::Time dt)
{
    return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed)
        return false;

    if (event.key.code == sf::Keyboard::Return)
    {
        if (optionIndex == Play) {
            requestStackPop();
            requestStackPush(StateID::Game);
        }
        else if (optionIndex == Exit)
        {
            requestStackPop();
        }
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
        if (optionIndex > 0)
            optionIndex--;
        else
            optionIndex = options.size() - 1;

        updateOptionText();
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
        if (optionIndex < options.size() - 1)
            optionIndex++;
        else
            optionIndex = 0;

        updateOptionText();
    }

    return true;
}

void MenuState::updateOptionText() {
    if (options.empty())
        return;

    for (auto& text : options)
        text.setFillColor(sf::Color::White);

    options[optionIndex].setFillColor(sf::Color::Red);
}
