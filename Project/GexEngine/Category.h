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
		Frogger			= 1 << 1,

		Car				= 1 << 2,
		Truck			= 1 << 3,
		Alligator		= 1 << 4,
		Turtle			= 1 << 5,
		Log				= 1 << 6,

		River			= 1 << 7,
		WinningSpot		= 1 << 8,

		Score			= 1 << 9,

		Vehicle = Car | Truck,
		SwimmingNPC = Alligator | Turtle | Log | WinningSpot,

		NPC = Vehicle | SwimmingNPC,
	};
}

