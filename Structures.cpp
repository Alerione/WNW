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
};