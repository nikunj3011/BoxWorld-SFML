#include "DataTables.h"
#include "JsonFrameParser.h"

std::map<Actor::Type, ActorData> initializeActorData()
{
    std::map<Actor::Type, ActorData> data;

    data[Actor::Type::Boxman].texture = TextureID::BoxWorld;
    //data[Actor::Type::Boxman].texture = TextureID::Box;

    JsonFrameParser frames = JsonFrameParser("Media/Textures/boxworld.json");
    //JsonFrameParser frames2 = JsonFrameParser("Media/Textures/spritesheet (1).json");

    data[Actor::Type::Boxman].animations[Actor::State::Respawn].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::Respawn].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::Respawn].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleLeft].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleLeft].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleLeft].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleRight].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleRight].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleRight].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleUp].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleUp].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleUp].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleDown].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleDown].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleDown].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::JumpLeft].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpLeft].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpLeft].setRepeating(false);

    data[Actor::Type::Boxman].animations[Actor::State::JumpRight].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpRight].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpRight].setRepeating(false);

    data[Actor::Type::Boxman].animations[Actor::State::JumpUp].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpUp].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpUp].setRepeating(false);

    data[Actor::Type::Boxman].animations[Actor::State::JumpDown].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpDown].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpDown].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::Death].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::Death].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::Death].setRepeating(false);


    //data[Actor::Type::Alligator].texture = TextureID::BoxWorld;
    //data[Actor::Type::Alligator].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    //data[Actor::Type::Alligator].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    //data[Actor::Type::Alligator].animations[Actor::State::Idle].setRepeating(true);



    data[Actor::Type::Platform1].texture = TextureID::BoxWorld;

    data[Actor::Type::Platform1].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("platform1"));
    data[Actor::Type::Platform1].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Platform1].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::GroundFire].texture = TextureID::BoxWorld;

    data[Actor::Type::GroundFire].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("groundfire"));
    data[Actor::Type::GroundFire].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::GroundFire].animations[Actor::State::Idle].setRepeating(true);


    data[Actor::Type::Enemy].texture = TextureID::BoxWorld;

    data[Actor::Type::Enemy].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("enemy"));
    data[Actor::Type::Enemy].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Enemy].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Spike].texture = TextureID::BoxWorld;

    data[Actor::Type::Spike].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("spike"));
    data[Actor::Type::Spike].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Spike].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Fire].texture = TextureID::BoxWorld;

    data[Actor::Type::Fire].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("fire"));
    data[Actor::Type::Fire].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Fire].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::MovingPlatform].texture = TextureID::BoxWorld;

    data[Actor::Type::MovingPlatform].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("movingplatform"));
    data[Actor::Type::MovingPlatform].animations[Actor::State::Idle].setDuration(sf::seconds(3.f));
    data[Actor::Type::MovingPlatform].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Platform2].texture = TextureID::BoxWorld;

    data[Actor::Type::Platform2].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("platform2"));
    data[Actor::Type::Platform2].animations[Actor::State::Idle].setDuration(sf::seconds(5.f));
    data[Actor::Type::Platform2].animations[Actor::State::Idle].setRepeating(true);


    data[Actor::Type::Gem].texture = TextureID::BoxWorld;

    data[Actor::Type::Gem].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("correctgem"));
    data[Actor::Type::Gem].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Gem].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Exit].texture = TextureID::BoxWorld;

    data[Actor::Type::Exit].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("exitdoor"));
    data[Actor::Type::Exit].animations[Actor::State::Idle].setDuration(sf::seconds(0.1f));
    data[Actor::Type::Exit].animations[Actor::State::Idle].setRepeating(false);


    data[Actor::Type::BoxWinner].texture = TextureID::BoxWorld;

    data[Actor::Type::BoxWinner].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::BoxWinner].animations[Actor::State::Idle].setDuration(sf::seconds(3.f));
    data[Actor::Type::BoxWinner].animations[Actor::State::Idle].setRepeating(true);


    return data;
}

std::vector<NPCSpawnData> initializeNPCSpawnData()
{
    std::vector<NPCSpawnData> spawnData(12);

    sf::Time time;

    spawnData[0] = NPCSpawnData();
    spawnData[0].position = sf::Vector2f(87.f, 155.f);
    spawnData[0].direction = Actor::Direction::Left;
    spawnData[0].type = Actor::Type::Platform1;
    spawnData[0].speed = 0.f;
    spawnData[0].interval = sf::seconds(40000);
    spawnData[0].elapsedTime = spawnData[0].interval;

    spawnData[1] = NPCSpawnData();
    spawnData[1].position = sf::Vector2f(530.f, 250.f);
    spawnData[1].direction = Actor::Direction::Right;
    spawnData[1].type = Actor::Type::Platform1;
    spawnData[1].speed = 0.f;
    spawnData[1].interval = sf::seconds(400000);
    spawnData[1].elapsedTime = spawnData[1].interval;

    spawnData[2] = NPCSpawnData();
    spawnData[2].position = sf::Vector2f(540.f, 220.f);
    spawnData[2].direction = Actor::Direction::Right;
    spawnData[2].type = Actor::Type::Enemy;
    spawnData[2].speed = 0.f;
    spawnData[2].interval = sf::seconds(400000);
    spawnData[2].elapsedTime = spawnData[2].interval;

    spawnData[3] = NPCSpawnData();
    spawnData[3].position = sf::Vector2f(640.f, 277.f);
    spawnData[3].direction = Actor::Direction::Right;
    spawnData[3].type = Actor::Type::GroundFire;
    spawnData[3].speed = 0.f;
    spawnData[3].interval = sf::seconds(400000);
    spawnData[3].elapsedTime = spawnData[3].interval;

    spawnData[4] = NPCSpawnData();
    spawnData[4].position = sf::Vector2f(180.f, 90.f);
    spawnData[4].direction = Actor::Direction::Left;
    spawnData[4].type = Actor::Type::Spike;
    spawnData[4].speed = 0.f;
    spawnData[4].interval = sf::seconds(400000);
    spawnData[4].elapsedTime = spawnData[4].interval;


    spawnData[5] = NPCSpawnData();
    spawnData[5].position = sf::Vector2f(1270.f, 90.f);
    spawnData[5].direction = Actor::Direction::Left;
    spawnData[5].type = Actor::Type::Exit;
    spawnData[5].speed = 0.f;
    spawnData[5].interval = sf::seconds(400000);
    spawnData[5].elapsedTime = spawnData[5].interval;

    spawnData[6] = NPCSpawnData();
    spawnData[6].position = sf::Vector2f(1200.f, 150.f);
    spawnData[6].direction = Actor::Direction::Right;
    spawnData[6].type = Actor::Type::Platform1;
    spawnData[6].speed = 0.f;
    spawnData[6].interval = sf::seconds(400000);
    spawnData[6].elapsedTime = spawnData[6].interval;


    spawnData[10] = NPCSpawnData();
    spawnData[10].position = sf::Vector2f(855.f, 75.f);
    spawnData[10].direction = Actor::Direction::Right;
    spawnData[10].type = Actor::Type::Gem;
    spawnData[10].speed = 0.f;
    spawnData[10].interval = sf::seconds(400000);
    spawnData[10].elapsedTime = spawnData[6].interval;

    spawnData[7] = NPCSpawnData();
    spawnData[7].position = sf::Vector2f(100.f, 156.f);
    spawnData[7].direction = Actor::Direction::Right;
    spawnData[7].type = Actor::Type::MovingPlatform;
    spawnData[7].speed = 70.f;
    spawnData[7].interval = sf::seconds(2);
    spawnData[7].elapsedTime = spawnData[7].interval;

    spawnData[8] = NPCSpawnData();
    spawnData[8].position = sf::Vector2f(1590.f, 80.f);
    spawnData[8].direction = Actor::Direction::Right;
    spawnData[8].type = Actor::Type::Platform2;
    spawnData[8].speed = 0.f;
    spawnData[8].interval = sf::seconds(400000);
    spawnData[8].elapsedTime = spawnData[8].interval;

    spawnData[11] = NPCSpawnData();
    spawnData[11].position = sf::Vector2f(735.f, 230.f);    //(735.f, 200.f);
    spawnData[11].direction = Actor::Direction::Up;
    spawnData[11].type = Actor::Type::Fire;
    spawnData[11].speed = -50.f;
    spawnData[11].interval = sf::seconds(3);
    spawnData[11].elapsedTime = sf::seconds(2.5);;
   

    spawnData[9] = NPCSpawnData();
    spawnData[9].position = sf::Vector2f(180.f, 35.f);
    spawnData[9].direction = Actor::Direction::Left;
    spawnData[9].type = Actor::Type::Platform2;
    spawnData[9].speed = 0.f;
    spawnData[9].interval = sf::seconds(400000);
    spawnData[9].elapsedTime = spawnData[9].interval;


    return spawnData;

}



std::map<Actor::Type, ActorData> initializeActorData2()
{
    std::map<Actor::Type, ActorData> data;

    data[Actor::Type::Boxman].texture = TextureID::BoxWorld2;
    //data[Actor::Type::Boxman].texture = TextureID::Box;

    JsonFrameParser frames = JsonFrameParser("Media/Textures/level2.json");
    //JsonFrameParser frames2 = JsonFrameParser("Media/Textures/spritesheet (1).json");

    data[Actor::Type::Boxman].animations[Actor::State::Respawn].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::Respawn].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::Respawn].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleLeft].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleLeft].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleLeft].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleRight].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleRight].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleRight].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleUp].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleUp].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleUp].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleDown].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleDown].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleDown].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::JumpLeft].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpLeft].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpLeft].setRepeating(false);

    data[Actor::Type::Boxman].animations[Actor::State::JumpRight].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpRight].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpRight].setRepeating(false);

    data[Actor::Type::Boxman].animations[Actor::State::JumpUp].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpUp].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpUp].setRepeating(false);

    data[Actor::Type::Boxman].animations[Actor::State::JumpDown].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpDown].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpDown].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::Death].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::Death].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::Death].setRepeating(false);


    //data[Actor::Type::Alligator].texture = TextureID::BoxWorld;
    //data[Actor::Type::Alligator].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    //data[Actor::Type::Alligator].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    //data[Actor::Type::Alligator].animations[Actor::State::Idle].setRepeating(true);



    data[Actor::Type::Platform1].texture = TextureID::BoxWorld2;

    data[Actor::Type::Platform1].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("platform1"));
    data[Actor::Type::Platform1].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Platform1].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::GroundFire].texture = TextureID::BoxWorld2;

    data[Actor::Type::GroundFire].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("river"));
    data[Actor::Type::GroundFire].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::GroundFire].animations[Actor::State::Idle].setRepeating(true);


    data[Actor::Type::Enemy].texture = TextureID::BoxWorld2;

    data[Actor::Type::Enemy].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("enemy"));
    data[Actor::Type::Enemy].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Enemy].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Spike].texture = TextureID::BoxWorld2;

    data[Actor::Type::Spike].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("spike"));
    data[Actor::Type::Spike].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Spike].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::SpikeUp].texture = TextureID::BoxWorld2;

    data[Actor::Type::SpikeUp].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("spikup"));
    data[Actor::Type::SpikeUp].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::SpikeUp].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Fire].texture = TextureID::BoxWorld2;

    data[Actor::Type::Fire].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("enemfire"));
    data[Actor::Type::Fire].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Fire].animations[Actor::State::Idle].setRepeating(true);


    data[Actor::Type::Platforms].texture = TextureID::BoxWorld2;

    data[Actor::Type::Platforms].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("platforms"));
    data[Actor::Type::Platforms].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Platforms].animations[Actor::State::Idle].setRepeating(true);


    data[Actor::Type::Platform3].texture = TextureID::BoxWorld2;

    data[Actor::Type::Platform3].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("platform3"));
    data[Actor::Type::Platform3].animations[Actor::State::Idle].setDuration(sf::seconds(3.f));
    data[Actor::Type::Platform3].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Platform2].texture = TextureID::BoxWorld2;

    data[Actor::Type::Platform2].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("platform2"));
    data[Actor::Type::Platform2].animations[Actor::State::Idle].setDuration(sf::seconds(5.f));
    data[Actor::Type::Platform2].animations[Actor::State::Idle].setRepeating(true);


    data[Actor::Type::Gem].texture = TextureID::BoxWorld2;

    data[Actor::Type::Gem].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("gem"));
    data[Actor::Type::Gem].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Gem].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Exit].texture = TextureID::BoxWorld2;

    data[Actor::Type::Exit].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("win"));
    data[Actor::Type::Exit].animations[Actor::State::Idle].setDuration(sf::seconds(0.1f));
    data[Actor::Type::Exit].animations[Actor::State::Idle].setRepeating(false);


    data[Actor::Type::BoxWinner].texture = TextureID::BoxWorld2;

    data[Actor::Type::BoxWinner].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::BoxWinner].animations[Actor::State::Idle].setDuration(sf::seconds(3.f));
    data[Actor::Type::BoxWinner].animations[Actor::State::Idle].setRepeating(true);


    return data;
}

std::vector<NPCSpawnData> initializeNPCSpawnData2()
{
    std::vector<NPCSpawnData> spawnData(30);

    sf::Time time;

    //long platform
    spawnData[0] = NPCSpawnData();
    spawnData[0].position = sf::Vector2f(87.f, 216.f);
    spawnData[0].direction = Actor::Direction::Left;
    spawnData[0].type = Actor::Type::Platform1;
    spawnData[0].speed = 0.f;
    spawnData[0].interval = sf::seconds(40000);
    spawnData[0].elapsedTime = spawnData[0].interval;

    spawnData[1] = NPCSpawnData();
    spawnData[1].position = sf::Vector2f(280.f, 250.f);
    spawnData[1].direction = Actor::Direction::Right;
    spawnData[1].type = Actor::Type::Platform1;
    spawnData[1].speed = 0.f;
    spawnData[1].interval = sf::seconds(400000);
    spawnData[1].elapsedTime = spawnData[1].interval;

    spawnData[27] = NPCSpawnData();
    spawnData[27].position = sf::Vector2f(800.f, 80.f);
    spawnData[27].direction = Actor::Direction::Right;
    spawnData[27].type = Actor::Type::Platform1;
    spawnData[27].speed = 0.f;
    spawnData[27].interval = sf::seconds(400000);
    spawnData[27].elapsedTime = spawnData[27].interval;


    //forward platforms
    spawnData[6] = NPCSpawnData();
    spawnData[6].position = sf::Vector2f(600.f, 140.f);
    spawnData[6].direction = Actor::Direction::Right;
    spawnData[6].type = Actor::Type::Platforms;
    spawnData[6].speed = 0.f;
    spawnData[6].interval = sf::seconds(400000);
    spawnData[6].elapsedTime = spawnData[6].interval;



    //river
    spawnData[3] = NPCSpawnData();
    spawnData[3].position = sf::Vector2f(640.f, 283.f);
    spawnData[3].direction = Actor::Direction::Right;
    spawnData[3].type = Actor::Type::GroundFire;
    spawnData[3].speed = 0.f;
    spawnData[3].interval = sf::seconds(400000);
    spawnData[3].elapsedTime = spawnData[3].interval;

    //exit
    spawnData[5] = NPCSpawnData();
    spawnData[5].position = sf::Vector2f(1225.f, 160.f);
    spawnData[5].direction = Actor::Direction::Left;
    spawnData[5].type = Actor::Type::Exit;
    spawnData[5].speed = 0.f;
    spawnData[5].interval = sf::seconds(400000);
    spawnData[5].elapsedTime = spawnData[5].interval;




    //gem
    spawnData[10] = NPCSpawnData();
    spawnData[10].position = sf::Vector2f(145.f, 40.f);
    spawnData[10].direction = Actor::Direction::Right;
    spawnData[10].type = Actor::Type::Gem;
    spawnData[10].speed = 0.f;
    spawnData[10].interval = sf::seconds(400000);
    spawnData[10].elapsedTime = spawnData[6].interval;

    //moving fire

    spawnData[11] = NPCSpawnData();
    spawnData[11].position = sf::Vector2f(735.f, 250.f);    //(735.f, 200.f);
    spawnData[11].direction = Actor::Direction::Up;
    spawnData[11].type = Actor::Type::Fire;
    spawnData[11].speed = -50.f;
    spawnData[11].interval = sf::seconds(3);
    spawnData[11].elapsedTime = sf::seconds(2.5);

    spawnData[28] = NPCSpawnData();
    spawnData[28].position = sf::Vector2f(535.f, 20.f);    //(735.f, 200.f);
    spawnData[28].direction = Actor::Direction::Up;
    spawnData[28].type = Actor::Type::Fire;
    spawnData[28].speed = 50.f;
    spawnData[28].interval = sf::seconds(3);
    spawnData[28].elapsedTime = sf::seconds(2.5);

    spawnData[29] = NPCSpawnData();
    spawnData[29].position = sf::Vector2f(335.f, 250.f);    //(735.f, 200.f);
    spawnData[29].direction = Actor::Direction::Up;
    spawnData[29].type = Actor::Type::Fire;
    spawnData[29].speed = -50.f;
    spawnData[29].interval = sf::seconds(3);
    spawnData[29].elapsedTime = sf::seconds(2.5);

    //background platform
    spawnData[12] = NPCSpawnData();
    spawnData[12].position = sf::Vector2f(600.f, 140.f);    //(735.f, 200.f);
    spawnData[12].direction = Actor::Direction::Up;
    spawnData[12].type = Actor::Type::Platforms;
    spawnData[12].speed = 0.f;
    spawnData[12].interval = sf::seconds(400000);
    spawnData[12].elapsedTime = spawnData[8].interval;


    //spike pillar
    spawnData[4] = NPCSpawnData();
    spawnData[4].position = sf::Vector2f(270.f, 90.f);
    spawnData[4].direction = Actor::Direction::Left;
    spawnData[4].type = Actor::Type::SpikeUp;
    spawnData[4].speed = 0.f;
    spawnData[4].interval = sf::seconds(400000);
    spawnData[4].elapsedTime = spawnData[4].interval;

    spawnData[9] = NPCSpawnData();
    spawnData[9].position = sf::Vector2f(270.f, 35.f);
    spawnData[9].direction = Actor::Direction::Left;
    spawnData[9].type = Actor::Type::Platform2;
    spawnData[9].speed = 0.f;
    spawnData[9].interval = sf::seconds(400000);
    spawnData[9].elapsedTime = spawnData[9].interval;



    spawnData[13] = NPCSpawnData();
    spawnData[13].position = sf::Vector2f(570.f, 90.f);
    spawnData[13].direction = Actor::Direction::Left;
    spawnData[13].type = Actor::Type::SpikeUp;
    spawnData[13].speed = 0.f;
    spawnData[13].interval = sf::seconds(400000);
    spawnData[13].elapsedTime = spawnData[4].interval;

    spawnData[14] = NPCSpawnData();
    spawnData[14].position = sf::Vector2f(570.f, 35.f);
    spawnData[14].direction = Actor::Direction::Left;
    spawnData[14].type = Actor::Type::Platform2;
    spawnData[14].speed = 0.f;
    spawnData[14].interval = sf::seconds(400000);
    spawnData[14].elapsedTime = spawnData[9].interval;


    spawnData[15] = NPCSpawnData();
    spawnData[15].position = sf::Vector2f(450.f, 170.f);
    spawnData[15].direction = Actor::Direction::Left;
    spawnData[15].type = Actor::Type::Spike;
    spawnData[15].speed = 0.f;
    spawnData[15].interval = sf::seconds(400000);
    spawnData[15].elapsedTime = spawnData[4].interval;

    spawnData[16] = NPCSpawnData();
    spawnData[16].position = sf::Vector2f(450.f, 225.f);
    spawnData[16].direction = Actor::Direction::Left;
    spawnData[16].type = Actor::Type::Platform2;
    spawnData[16].speed = 0.f;
    spawnData[16].interval = sf::seconds(400000);
    spawnData[16].elapsedTime = spawnData[9].interval;


    spawnData[17] = NPCSpawnData();
    spawnData[17].position = sf::Vector2f(700.f, 170.f);
    spawnData[17].direction = Actor::Direction::Left;
    spawnData[17].type = Actor::Type::Spike;
    spawnData[17].speed = 0.f;
    spawnData[17].interval = sf::seconds(400000);
    spawnData[17].elapsedTime = spawnData[4].interval;

    spawnData[18] = NPCSpawnData();
    spawnData[18].position = sf::Vector2f(700.f, 225.f);
    spawnData[18].direction = Actor::Direction::Left;
    spawnData[18].type = Actor::Type::Platform2;
    spawnData[18].speed = 0.f;
    spawnData[18].interval = sf::seconds(400000);
    spawnData[18].elapsedTime = spawnData[9].interval;

    //enemy
    spawnData[2] = NPCSpawnData();
    spawnData[2].position = sf::Vector2f(270.f, 220.f);
    spawnData[2].direction = Actor::Direction::Right;
    spawnData[2].type = Actor::Type::Enemy;
    spawnData[2].speed = 0.f;
    spawnData[2].interval = sf::seconds(400000);
    spawnData[2].elapsedTime = spawnData[2].interval;

    //small platforms
    spawnData[8] = NPCSpawnData();
    spawnData[8].position = sf::Vector2f(110.f, 144.f);
    spawnData[8].direction = Actor::Direction::Right;
    spawnData[8].type = Actor::Type::Platform3;
    spawnData[8].speed = 0.f;
    spawnData[8].interval = sf::seconds(400000);
    spawnData[8].elapsedTime = spawnData[8].interval;
     
    spawnData[7] = NPCSpawnData();
    spawnData[7].position = sf::Vector2f(220.f, 168.f);
    spawnData[7].direction = Actor::Direction::Right;
    spawnData[7].type = Actor::Type::Platform3;
    spawnData[7].speed = 0.f;
    spawnData[7].interval = sf::seconds(400000);
    spawnData[7].elapsedTime = spawnData[7].interval;

    spawnData[19] = NPCSpawnData();
    spawnData[19].position = sf::Vector2f(330.f, 155.f);
    spawnData[19].direction = Actor::Direction::Left;
    spawnData[19].type = Actor::Type::Platform3;
    spawnData[19].speed = 0.f;
    spawnData[19].interval = sf::seconds(400000);
    spawnData[19].elapsedTime = spawnData[9].interval;

    spawnData[20] = NPCSpawnData();
    spawnData[20].position = sf::Vector2f(435.f, 117.f);
    spawnData[20].direction = Actor::Direction::Left;
    spawnData[20].type = Actor::Type::Platform3;
    spawnData[20].speed = 0.f;
    spawnData[20].interval = sf::seconds(400000);
    spawnData[20].elapsedTime = spawnData[9].interval;

    spawnData[21] = NPCSpawnData();
    spawnData[21].position = sf::Vector2f(558.f, 160.f);
    spawnData[21].direction = Actor::Direction::Left;
    spawnData[21].type = Actor::Type::Platform3;
    spawnData[21].speed = 0.f;
    spawnData[21].interval = sf::seconds(400000);
    spawnData[21].elapsedTime = spawnData[9].interval;

    spawnData[22] = NPCSpawnData();
    spawnData[22].position = sf::Vector2f(650.f, 135.f);
    spawnData[22].direction = Actor::Direction::Left;
    spawnData[22].type = Actor::Type::Platform3;
    spawnData[22].speed = 0.f;
    spawnData[22].interval = sf::seconds(400000);
    spawnData[22].elapsedTime = spawnData[9].interval;

    spawnData[23] = NPCSpawnData();
    spawnData[23].position = sf::Vector2f(750.f, 180.f);
    spawnData[23].direction = Actor::Direction::Left;
    spawnData[23].type = Actor::Type::Platform3;
    spawnData[23].speed = 0.f;
    spawnData[23].interval = sf::seconds(400000);
    spawnData[23].elapsedTime = spawnData[9].interval;

    spawnData[24] = NPCSpawnData();
    spawnData[24].position = sf::Vector2f(860.f, 250.f);
    spawnData[24].direction = Actor::Direction::Left;
    spawnData[24].type = Actor::Type::Platform3;
    spawnData[24].speed = 0.f;
    spawnData[24].interval = sf::seconds(400000);
    spawnData[24].elapsedTime = spawnData[9].interval;

    spawnData[25] = NPCSpawnData();
    spawnData[25].position = sf::Vector2f(960.f, 210.f);
    spawnData[25].direction = Actor::Direction::Left;
    spawnData[25].type = Actor::Type::Platform3;
    spawnData[25].speed = 0.f;
    spawnData[25].interval = sf::seconds(400000);
    spawnData[25].elapsedTime = spawnData[9].interval;

    spawnData[26] = NPCSpawnData();
    spawnData[26].position = sf::Vector2f(1059.f, 168.f);
    spawnData[26].direction = Actor::Direction::Left;
    spawnData[26].type = Actor::Type::Platform3;
    spawnData[26].speed = 0.f;
    spawnData[26].interval = sf::seconds(400000);
    spawnData[26].elapsedTime = spawnData[9].interval;



    return spawnData;

}



std::map<Actor::Type, ActorData> initializeActorData3()
{
    std::map<Actor::Type, ActorData> data;

    data[Actor::Type::Boxman].texture = TextureID::BoxWorld3;
    //data[Actor::Type::Boxman].texture = TextureID::Box;

    JsonFrameParser frames = JsonFrameParser("Media/Textures/level3.json");
    //JsonFrameParser frames2 = JsonFrameParser("Media/Textures/spritesheet (1).json");

    data[Actor::Type::Boxman].animations[Actor::State::Respawn].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::Respawn].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::Respawn].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleLeft].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleLeft].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleLeft].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleRight].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleRight].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleRight].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleUp].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleUp].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleUp].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::IdleDown].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::IdleDown].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::IdleDown].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::JumpLeft].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpLeft].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpLeft].setRepeating(false);

    data[Actor::Type::Boxman].animations[Actor::State::JumpRight].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpRight].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpRight].setRepeating(false);

    data[Actor::Type::Boxman].animations[Actor::State::JumpUp].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpUp].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpUp].setRepeating(false);

    data[Actor::Type::Boxman].animations[Actor::State::JumpDown].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::JumpDown].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::JumpDown].setRepeating(true);

    data[Actor::Type::Boxman].animations[Actor::State::Death].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::Boxman].animations[Actor::State::Death].setDuration(sf::seconds(1.f));
    data[Actor::Type::Boxman].animations[Actor::State::Death].setRepeating(false);


    //data[Actor::Type::Alligator].texture = TextureID::BoxWorld;
    //data[Actor::Type::Alligator].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    //data[Actor::Type::Alligator].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    //data[Actor::Type::Alligator].animations[Actor::State::Idle].setRepeating(true);



    data[Actor::Type::Platform1].texture = TextureID::BoxWorld3;

    data[Actor::Type::Platform1].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("platform1"));
    data[Actor::Type::Platform1].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::Platform1].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::GroundFire].texture = TextureID::BoxWorld3;

    data[Actor::Type::GroundFire].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("river"));
    data[Actor::Type::GroundFire].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
    data[Actor::Type::GroundFire].animations[Actor::State::Idle].setRepeating(true); 

    data[Actor::Type::Platform3].texture = TextureID::BoxWorld3;

    data[Actor::Type::Platform3].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("platform3"));
    data[Actor::Type::Platform3].animations[Actor::State::Idle].setDuration(sf::seconds(3.f));
    data[Actor::Type::Platform3].animations[Actor::State::Idle].setRepeating(true);

    data[Actor::Type::Platform2].texture = TextureID::BoxWorld3;

    data[Actor::Type::Platform2].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("platform2"));
    data[Actor::Type::Platform2].animations[Actor::State::Idle].setDuration(sf::seconds(5.f));
    data[Actor::Type::Platform2].animations[Actor::State::Idle].setRepeating(true); 
     

    data[Actor::Type::BoxWinner].texture = TextureID::BoxWorld3;

    data[Actor::Type::BoxWinner].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("player"));
    data[Actor::Type::BoxWinner].animations[Actor::State::Idle].setDuration(sf::seconds(3.f));
    data[Actor::Type::BoxWinner].animations[Actor::State::Idle].setRepeating(true);


    return data;
}

std::vector<NPCSpawnData> initializeNPCSpawnData3()
{
    std::vector<NPCSpawnData> spawnData(8);

    sf::Time time;

    spawnData[0] = NPCSpawnData();
    spawnData[0].position = sf::Vector2f(87.f, 155.f);
    spawnData[0].direction = Actor::Direction::Left;
    spawnData[0].type = Actor::Type::Platform1;
    spawnData[0].speed = 0.f;
    spawnData[0].interval = sf::seconds(40000);
    spawnData[0].elapsedTime = spawnData[0].interval;

    spawnData[1] = NPCSpawnData();
    spawnData[1].position = sf::Vector2f(250.f, 170.f);
    spawnData[1].direction = Actor::Direction::Right;
    spawnData[1].type = Actor::Type::Platform2;
    spawnData[1].speed = 0.f;
    spawnData[1].interval = sf::seconds(400000);
    spawnData[1].elapsedTime = spawnData[1].interval;

    spawnData[2] = NPCSpawnData();
    spawnData[2].position = sf::Vector2f(360.f, 130.f);
    spawnData[2].direction = Actor::Direction::Right;
    spawnData[2].type = Actor::Type::Platform3;
    spawnData[2].speed = 0.f;
    spawnData[2].interval = sf::seconds(400000);
    spawnData[2].elapsedTime = spawnData[1].interval;

    spawnData[3] = NPCSpawnData();
    spawnData[3].position = sf::Vector2f(500.f, 106.f);
    spawnData[3].direction = Actor::Direction::Right;
    spawnData[3].type = Actor::Type::Platform2;
    spawnData[3].speed = 0.f;
    spawnData[3].interval = sf::seconds(400000);
    spawnData[3].elapsedTime = spawnData[1].interval;

    spawnData[4] = NPCSpawnData();
    spawnData[4].position = sf::Vector2f(672.f, 180.f);
    spawnData[4].direction = Actor::Direction::Right;
    spawnData[4].type = Actor::Type::Platform3;
    spawnData[4].speed = 0.f;
    spawnData[4].interval = sf::seconds(400000);
    spawnData[4].elapsedTime = spawnData[1].interval;

    spawnData[5] = NPCSpawnData();
    spawnData[5].position = sf::Vector2f(780.f, 140.f);
    spawnData[5].direction = Actor::Direction::Left;
    spawnData[5].type = Actor::Type::Platform2;
    spawnData[5].speed = 0.f;
    spawnData[5].interval = sf::seconds(400000);
    spawnData[5].elapsedTime = spawnData[1].interval;


    spawnData[6] = NPCSpawnData();
    spawnData[6].position = sf::Vector2f(936.f, 157.f);
    spawnData[6].direction = Actor::Direction::Left;
    spawnData[6].type = Actor::Type::Platform3;
    spawnData[6].speed = 0.f;
    spawnData[6].interval = sf::seconds(400000);
    spawnData[6].elapsedTime = spawnData[1].interval;

    /*spawnData[6] = NPCSpawnData();
    spawnData[6].position = sf::Vector2f(640.f, 287.f);
    spawnData[6].direction = Actor::Direction::Left;
    spawnData[6].type = Actor::Type::Platform2;
    spawnData[6].speed = 0.f;
    spawnData[6].interval = sf::seconds(400000);
    spawnData[6].elapsedTime = spawnData[1].interval;*/

    spawnData[7] = NPCSpawnData();
    spawnData[7].position = sf::Vector2f(640.f, 287.f);
    spawnData[7].direction = Actor::Direction::Left;
    spawnData[7].type = Actor::Type::GroundFire;
    spawnData[7].speed = 0.f;
    spawnData[7].interval = sf::seconds(400000);
    spawnData[7].elapsedTime = spawnData[1].interval;


    return spawnData;

}


std::vector<sf::FloatRect> getWinningSpotPositions()
{
    std::vector<sf::FloatRect> positions;

    float height = 70.f;
    float width = 30.f;
    float top = 120.f;
    float left = 1155.f;
    //level 1 1255
    float interval = 102.f;
    for (int i = 0; i < 1; ++i) {
        positions.push_back(sf::FloatRect(left, top, width, height));
        left += interval;
    }


    return positions;
}

