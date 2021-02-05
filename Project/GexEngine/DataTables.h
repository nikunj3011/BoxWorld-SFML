
#include "ResourceIdentifiers.h"
#include "Actor.h"
#include "Animation.h"
#include "Frogger.h"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

#include <map>
#include <vector>
#include <functional>


struct ActorData
{
	TextureID							texture;
	std::map<Actor::State, Animation>	animations;
	std::vector<Actor::Direction>	    directions;
};

struct NPCSpawnData {
	sf::Vector2f						position;
	Actor::Direction					direction;
	Actor::Type							type;
	float								speed;
	sf::Time							interval;
	sf::Time							elapsedTime;
};

std::map<Actor::Type, ActorData> initializeActorData();

std::vector<NPCSpawnData> initializeNPCSpawnData();

std::vector<sf::FloatRect> getWinningSpotPositions();

