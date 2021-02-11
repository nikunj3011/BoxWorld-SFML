/*
Alena Selezneva
*/

#pragma once

namespace Category
{
	enum Type
	{
		None = 0,			// 000000000
		BackgroundLayer = 1 << 0,		// 000000001
		BoxMan			= 1 << 1,

		Platform1		= 1 << 2,
		MovingPlatform  = 1 << 3,
		Platform2		= 1 << 4,
		Enemy			= 1 << 5,
		Spike			= 1 << 6,
		Fire			= 1 << 7,
		GroundFire		= 1 << 8,
		Gem				= 1 << 9,
		Exit			= 1 << 10,

		WinningSpot		= 1 << 11,

		Score			= 1 << 12,

		Platform = Platform1 | MovingPlatform | Platform2 | Exit,
		Enemies = Enemy | Spike | Fire | GroundFire,

		NPC = Platform | Enemies,
	};
}

