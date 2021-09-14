using System;

namespace Array2DApp
{
	class Program
	{
		static void Main(string[] args)
		{
			int m, n;
			m = int.Parse(Console.ReadLine());
			n = int.Parse(Console.ReadLine());
			int[,] arr = new int[m, n];
			ReadInfor(arr);
			int sum = Sum(arr);
			Console.WriteLine($"{sum}");
		}
		static int Sum(int[,] Arr)
		{
			int m, n;
			int sum = 0;
			n = Arr.GetLength(0);
			m = Arr.GetLength(1);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					sum += Arr[i, j];
				}
			}
			return sum;
		}
		static void ReadInfor(int[,] Arr)
		{
			int m, n;
			n = Arr.GetLength(0);
			m = Arr.GetLength(1);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					Arr[i, j] = int.Parse(Console.ReadLine());
				}
			}
		}
		static void ShowInfor(int[,] Arr)
		{
			int m, n;
			n = Arr.GetLength(0);
			m = Arr.GetLength(1);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					Console.Write($"{Arr[i, j]} ");
				}
				Console.WriteLine();
			}
		}
	}
}
