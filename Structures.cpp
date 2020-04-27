struct ResourceList
{
	//Money//
	unsigned int Ducats;
	//Base resources//
	unsigned int Lumber;
	unsigned int Clay;
	unsigned int Marble;
	unsigned int Horses;
	unsigned int Food;
	//Processed resources//
	unsigned int Planks;
	unsigned int Bricks;
	unsigned int MarbleBlocks;
	unsigned int Beer;
	//Capacities//
	unsigned int PopulationCap;// softcap = 0.75*Cap
	unsigned int HorseCap;
	//Others//
	unsigned int Population;
	//Previous Values//
	unsigned int Prev_Ducats;
	unsigned int Prev_Lumber;
	unsigned int Prev_Clay;
	unsigned int Prev_Marble;
	unsigned int Prev_Horses;
	unsigned int Prev_Food;
	unsigned int Prev_Planks;
	unsigned int Prev_Bricks;
	unsigned int Prev_MarbleBlocks;
	unsigned int Prev_Beer;
	unsigned int Prev_Population;
};