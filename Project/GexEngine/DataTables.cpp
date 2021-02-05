#include "DataTables.h"
#include "JsonFrameParser.h"

std::map<Actor::Type, ActorData> initializeActorData()
{
    std::map<Actor::Type, ActorData> data;

    data[Actor::Type::Frogger].texture = TextureID::Frogger;
    //data[Actor::Type::Frogger].texture = TextureID::Box;

    JsonFrameParser frames = JsonFrameParser("Media/Textures/boxworld.json");
    //JsonFrameParser frames2 = JsonFrameParser("Media/Textures/spritesheet (1).json");

    data[Actor::Type::Frogger].animations[Actor::State::Respawn].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Frogger].animations[Actor::State::Respawn].setDuration(sf::seconds(1.f));
    data[Actor::Type::Frogger].animations[Actor::State::Respawn].setRepeating(true);

    data[Actor::Type::Frogger].animations[Actor::State::IdleLeft].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Frogger].animations[Actor::State::IdleLeft].setDuration(sf::seconds(1.f));
    data[Actor::Type::Frogger].animations[Actor::State::IdleLeft].setRepeating(true);

    data[Actor::Type::Frogger].animations[Actor::State::IdleRight].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Frogger].animations[Actor::State::IdleRight].setDuration(sf::seconds(1.f));
    data[Actor::Type::Frogger].animations[Actor::State::IdleRight].setRepeating(true);

    data[Actor::Type::Frogger].animations[Actor::State::IdleUp].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Frogger].animations[Actor::State::IdleUp].setDuration(sf::seconds(1.f));
    data[Actor::Type::Frogger].animations[Actor::State::IdleUp].setRepeating(true);

    data[Actor::Type::Frogger].animations[Actor::State::IdleDown].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Frogger].animations[Actor::State::IdleDown].setDuration(sf::seconds(1.f));
    data[Actor::Type::Frogger].animations[Actor::State::IdleDown].setRepeating(true);

    data[Actor::Type::Frogger].animations[Actor::State::JumpLeft].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Frogger].animations[Actor::State::JumpLeft].setDuration(sf::seconds(1.f));
    data[Actor::Type::Frogger].animations[Actor::State::JumpLeft].setRepeating(false);

    data[Actor::Type::Frogger].animations[Actor::State::JumpRight].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Frogger].animations[Actor::State::JumpRight].setDuration(sf::seconds(1.f));
    data[Actor::Type::Frogger].animations[Actor::State::JumpRight].setRepeating(false);

    data[Actor::Type::Frogger].animations[Actor::State::JumpUp].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Frogger].animations[Actor::State::JumpUp].setDuration(sf::seconds(1.f));
    data[Actor::Type::Frogger].animations[Actor::State::JumpUp].setRepeating(false);

    data[Actor::Type::Frogger].animations[Actor::State::JumpDown].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Frogger].animations[Actor::State::JumpDown].setDuration(sf::seconds(1.f));
    data[Actor::Type::Frogger].animations[Actor::State::JumpDown].setRepeating(true);

    data[Actor::Type::Frogger].animations[Actor::State::Death].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Frogger].animations[Actor::State::Death].setDuration(sf::seconds(1.f));
    data[Actor::Type::Frogger].animations[Actor::State::Death].setRepeating(false);


    data[Actor::Type::Alligator].texture = TextureID::Frogger;
    data[Actor::Type::Alligator].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Alligator].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Alligator].animations[Actor::State::Idle].setRepeating(true);



    data[Actor::Type::Car1].texture = TextureID::Frogger;

    data[Actor::Type::Car1].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("platform1"));
    data[Actor::Type::Car1].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Car1].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Car2].texture = TextureID::Frogger;

    data[Actor::Type::Car2].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("groundfire"));
    data[Actor::Type::Car2].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Car2].animations[Actor::State::Idle].setRepeating(true);


    data[Actor::Type::Car3].texture = TextureID::Frogger;

    data[Actor::Type::Car3].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Car3].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Car3].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Truck1].texture = TextureID::Frogger;

    data[Actor::Type::Truck1].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Truck1].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Truck1].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Truck2].texture = TextureID::Frogger;

    data[Actor::Type::Truck2].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Truck2].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Truck2].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Turtle2].texture = TextureID::Frogger;

    data[Actor::Type::Turtle2].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Turtle2].animations[Actor::State::Idle].setDuration(sf::seconds(3.f));
    data[Actor::Type::Turtle2].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Turtle3].texture = TextureID::Frogger;

    data[Actor::Type::Turtle3].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Turtle3].animations[Actor::State::Idle].setDuration(sf::seconds(5.f));
    data[Actor::Type::Turtle3].animations[Actor::State::Idle].setRepeating(true);


    data[Actor::Type::Log1].texture = TextureID::Frogger;

    data[Actor::Type::Log1].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Log1].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Log1].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Log2].texture = TextureID::Frogger;

    data[Actor::Type::Log2].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Log2].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Log2].animations[Actor::State::Idle].setRepeating(true);


    data[Actor::Type::FroggerWinner].texture = TextureID::Frogger;

    data[Actor::Type::FroggerWinner].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::FroggerWinner].animations[Actor::State::Idle].setDuration(sf::seconds(3.f));
    data[Actor::Type::FroggerWinner].animations[Actor::State::Idle].setRepeating(true);


    return data;
}

std::vector<NPCSpawnData> initializeNPCSpawnData()
{
    std::vector<NPCSpawnData> spawnData(12);

    sf::Time time;

    spawnData[0] = NPCSpawnData();
    spawnData[0].position = sf::Vector2f(87.f, 155.f);
    spawnData[0].direction = Actor::Direction::Left;
    spawnData[0].type = Actor::Type::Car1;
    spawnData[0].speed = 0.f;
    spawnData[0].interval = sf::seconds(200);
    spawnData[0].elapsedTime = spawnData[0].interval;

    spawnData[1].position = sf::Vector2f(-50.f, 490.f);
    spawnData[1].direction = Actor::Direction::Right;
    spawnData[1].type = Actor::Type::Truck1;
    spawnData[1].speed = 40.f;
    spawnData[1].interval = sf::seconds(3);
    spawnData[1].elapsedTime = spawnData[1].interval;

    spawnData[2] = NPCSpawnData();
    spawnData[2].position = sf::Vector2f(530.f, 450.f);
    spawnData[2].direction = Actor::Direction::Left;
    spawnData[2].type = Actor::Type::Car3;
    spawnData[2].speed = -150.f;
    spawnData[2].interval = sf::seconds(2);
    spawnData[2].elapsedTime = spawnData[2].interval;

    spawnData[3] = NPCSpawnData();
    spawnData[3].position = sf::Vector2f(640.f, 277.f);
    spawnData[3].direction = Actor::Direction::Right;
    spawnData[3].type = Actor::Type::Car2;
    spawnData[3].speed = 0.f;
    spawnData[3].interval = sf::seconds(100);
    spawnData[3].elapsedTime = spawnData[3].interval;

    spawnData[4] = NPCSpawnData();
    spawnData[4].position = sf::Vector2f(530.f, 370.f);
    spawnData[4].direction = Actor::Direction::Left;
    spawnData[4].type = Actor::Type::Truck2;
    spawnData[4].speed = -60.f;
    spawnData[4].interval = sf::seconds(3);
    spawnData[4].elapsedTime = spawnData[4].interval;


    spawnData[5] = NPCSpawnData();
    spawnData[5].position = sf::Vector2f(530.f, 300);
    spawnData[5].direction = Actor::Direction::Left;
    spawnData[5].type = Actor::Type::Log2;
    spawnData[5].speed = -70.f;
    spawnData[5].interval = sf::seconds(5);
    spawnData[5].elapsedTime = spawnData[5].interval;

    spawnData[6] = NPCSpawnData();
    spawnData[6].position = sf::Vector2f(-50.f, 260.f);
    spawnData[6].direction = Actor::Direction::Right;
    spawnData[6].type = Actor::Type::Alligator;
    spawnData[6].speed = 70.f;
    spawnData[6].interval = sf::seconds(6);
    spawnData[6].elapsedTime = sf::seconds(6);;


    spawnData[10] = NPCSpawnData();
    spawnData[10].position = sf::Vector2f(-50.f, 260.f);
    spawnData[10].direction = Actor::Direction::Right;
    spawnData[10].type = Actor::Type::Log1;
    spawnData[10].speed = 60.f;
    spawnData[10].interval = sf::seconds(6);
    spawnData[10].elapsedTime = sf::seconds(3);


    spawnData[7] = NPCSpawnData();
    spawnData[7].position = sf::Vector2f(530.f, 230.f);
    spawnData[7].direction = Actor::Direction::Left;
    spawnData[7].type = Actor::Type::Turtle2;
    spawnData[7].speed = -100.f;
    spawnData[7].interval = sf::seconds(2);
    spawnData[7].elapsedTime = spawnData[7].interval;

    spawnData[8] = NPCSpawnData();
    spawnData[8].position = sf::Vector2f(-50.f, 180.f);
    spawnData[8].direction = Actor::Direction::Right;
    spawnData[8].type = Actor::Type::Log1;
    spawnData[8].speed = 70.f;
    spawnData[8].interval = sf::seconds(5);
    spawnData[8].elapsedTime = sf::seconds(5);

    spawnData[11] = NPCSpawnData();
    spawnData[11].position = sf::Vector2f(-50.f, 180.f);
    spawnData[11].direction = Actor::Direction::Left;
    spawnData[11].type = Actor::Type::Alligator;
    spawnData[11].speed = 80.f;
    spawnData[11].interval = sf::seconds(5);
    spawnData[11].elapsedTime = sf::seconds(2.5);;
   

    spawnData[9] = NPCSpawnData();
    spawnData[9].position = sf::Vector2f(530.f, 140.f);
    spawnData[9].direction = Actor::Direction::Left;
    spawnData[9].type = Actor::Type::Turtle3;
    spawnData[9].speed = -50.f;
    spawnData[9].interval = sf::seconds(5);
    spawnData[9].elapsedTime = spawnData[9].interval;


    return spawnData;

}

std::vector<sf::FloatRect> getWinningSpotPositions()
{
    std::vector<sf::FloatRect> positions;

    float height = 26.f;
    float width = 42.f;
    float top = 78.f;
    float left = 15.f;
    float interval = 102.f;

    for (int i = 0; i < 5; ++i) {
        positions.push_back(sf::FloatRect(left, top, width, height));
        left += interval;
    }

    return positions;
}

