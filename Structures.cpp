struct ResourceList
{
	//Money//
	int Ducats;
	//Base resources//
	int Lumber;
	int Clay;
	int Marble;
	int Horses;
	int Food;
	//Processed resources//
	int Planks;
	int Bricks;
	int MarbleBlocks;
	int Beer;
	//Capacities//
	int PopulationCap;// softcap = 0.75*Cap
	int HorseCap;
	//Others//
	int Population;
	int PopReq;
	int GuildsCount;
	int EducationSlots;
	double HorseOverflow;
	double PopMod;
	double FoodPenalty;
	double EducationFactor;
	//Previous Values//
	int Prev_Ducats;
	int Prev_Lumber;
	int Prev_Clay;
	int Prev_Marble;
	int Prev_Horses;
	int Prev_Food;
	int Prev_Planks;
	int Prev_Bricks;
	int Prev_MarbleBlocks;
	int Prev_Beer;
	int Prev_Population;

	void AddDucats(int a, bool prev)
	{
		Ducats += a;
		if (prev)Prev_Ducats += a;
	}


	void AddLumber(int a, bool prev)
	{
		Lumber += a;
		if(prev)Prev_Lumber += a;
	}

	void AddClay(int a, bool prev)
	{
		Clay += a;
		if (prev)Prev_Clay += a;
	}

	void AddMarble(int a, bool prev)
	{
		Marble += a;
		if (prev)Prev_Marble += a;
	}

	void AddHorses(int a, bool prev)
	{
		Horses += a;
		if (prev)Prev_Horses += a;
	}

	void AddFood(int a, bool prev)
	{
		Food += a;
		if (prev)Prev_Food += a;
	}

	void AddPlanks(int a, bool prev)
	{
		Planks += a;
		if (prev)Prev_Planks += a;
	}

	void AddBricks(int a, bool prev)
	{
		Bricks += a;
		if (prev)Prev_Bricks += a;
	}

	void AddMarbleBlocks(int a, bool prev)
	{
		MarbleBlocks += a;
		if (prev)Prev_MarbleBlocks += a;
	}

	void AddBeer(int a, bool prev)
	{
		Beer += a;
		if (prev)Prev_Beer += a;
	}
};