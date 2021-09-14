using System;

namespace myApp
{
	public class Vehicle
	{
		public string Color;
		protected int Miles;
		protected int Year;

		public virtual void Greet()
		{
			Console.WriteLine("Hello, this is a Vehicle");
		}

		public Vehicle(string color, int miles, int year)
		{
			Color = color;
			Miles = miles;
			Year = year;
			Console.WriteLine("Instance Constructor of Vehicle, "
												+ $"color={this.Color}, "
												+ $"miles={this.Miles}, "
												+ $"year={this.Year}");
		}
		public static long productionDate;
		static Vehicle()
		{
			Console.WriteLine("This is a Static Constructor. It is called before Instance Constructor");
			/* this.Miles = 100; Cannot access instance property from static constructor */
			productionDate = DateTime.Now.Ticks;
		}
	}
	public class Bus : Vehicle
	{
		protected int BusNumber;

		public Bus(string color, int miles, int year, int busNumber) : base(color, miles, year)
		{
			this.BusNumber = busNumber;
			Console.WriteLine("Instance Constructor of Bus, "
												+ $"busNumber={this.BusNumber}");
		}

		public override void Greet()
		{
			base.Greet();
			Console.WriteLine("Hello, this is a Bus");
		}

	}
	public class MiniBus : Bus
	{
		public MiniBus(string color, int miles, int year, int busNumber) : base(color, miles, year, busNumber)
		{
			Console.WriteLine("Initialize MiniBus object");
		}
		public override void Greet() { base.Greet(); }
	}
	class Program
	{
		static void Main(string[] args)
		{
			/* var vehicle = new Vehicle("red", 120, 1993); */
			/* vehicle.Greet(); */
			var bus = new Bus("green", 1300, 2018, 20);
			/* Console.WriteLine($"Vehicle.productionDate = {Vehicle.productionDate}"); */
			Console.WriteLine($"Bus.productionDate = {Bus.productionDate}");
			/* bus.Greet(); */
		}
	}
}
