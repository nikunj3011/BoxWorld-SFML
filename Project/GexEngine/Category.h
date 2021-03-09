
#pragma once

namespace Category
{
	enum Type
	{
		None = 0,			// 000000000
		BackgroundLayer = 1 << 0,		// 000000001
		BoxMan			= 1 << 1,

		Fire = 1 << 6,
		Platform1		= 1 << 3,
		MovingPlatform  = 1 << 3,
		Platform2		= 1 << 3,
		Platform3		= 1 << 3,
		Enemy			= 1 << 6,
		Spike			= 1 << 7,		
		SoundEffect = 1 << 8,
		
		GroundFire		= 1 << 9,
		Gem				= 1 << 10,
		Exit			= 1 << 11,
		WinningSpot		= 1 << 12,
		SpikeUp = 1 << 15,
		Score			= 1 << 13,
		Platforms = 1 << 3,
		Platform = Platform1 | Platform2 | Exit | Platforms | MovingPlatform | Platform3,
		Enemies = Enemy | Spike | SpikeUp | Fire | GroundFire,

		NPC = Platform | Enemies,
	};
}

