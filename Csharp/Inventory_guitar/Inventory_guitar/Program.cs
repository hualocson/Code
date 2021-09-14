using System;

namespace Inventory_guitar
{
	class Program
	{
		static void Main(string[] args)
		{
			Inventory inventory = new Inventory();
			initializeInventory(inventory);

			Guitar whatErinLikes = new Guitar("",
																				0,
																				"fender",
																				"Stratocastor",
																				"electric",
																				"Alder",
																				"Alder");

			Guitar guitar = inventory.search(whatErinLikes);
			if (guitar != null)
			{
				Console.WriteLine("Erin, you might like this " +
						guitar.getBuilder() + " " + guitar.getModel() + " " +
						guitar.getType() + " guitar:\n  " +
						guitar.getBackWood() + " back and sides, \n" +
						guitar.getTopWood() + " top.\nYou can have it for only $" +
						guitar.getPrice() + "!");
			}
			else
			{
				Console.WriteLine("Sorry, Erin, we have nothing for you.");
			}
		}
		static void initializeInventory(Inventory inventory)
		{
			inventory.addGuitar("001", 1500, "fender", "Stratocastor", "electric", "Alder", "Alder");
			inventory.addGuitar("V95693", 1499.95, "Fender", "Stratocastor", "electric", "Alder", "Alder");
		}
	}
}
