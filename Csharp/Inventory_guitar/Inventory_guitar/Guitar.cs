using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Inventory_guitar
{
	public class Guitar
	{
		private double price;
		private string serialNumber;
		private string builder;
		private string model;
		private string type;
		private string backWood;
		private string topWood;

		public Guitar(string serialNumber,
									double price,
									string builder,
									string model,
									string type,
									string backWood,
									string topWood)
		{
			this.price = price;
			this.serialNumber = serialNumber;
			this.builder = builder;
			this.model = model;
			this.type = type;
			this.backWood = backWood;
			this.topWood = topWood;
		}

		public string getSerialNumber()
		{
			return serialNumber;
		}

		public double getPrice()
		{
			return price;
		}

		public void setPrice(double newPrice)
		{
			price = newPrice;
		}

		public string getBuilder()
		{
			return builder;
		}

		public string getModel()
		{
			return model;
		}

		public string getBackWood()
		{
			return backWood;
		}

		public string getTopWood()
		{
			return topWood;
		}

		public string getType()
		{
			return type;
		}
	}
}
