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
};