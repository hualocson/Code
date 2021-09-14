using System;
namespace DemoCSharp
{
	class Program
	{

		public static void Main()
		{
			int n = int.Parse(Console.ReadLine());
			int[] a = new int[n];
			ReadInfo(a);
			int m = int.Parse(Console.ReadLine());
			int[] b = new int[m];
			ReadInfo(b);
			int[] result = new int[m + n];
			result = MergeArr(a, b);
			ShowArr(a);
			Console.WriteLine();
			ShowArr(b);
			Console.WriteLine();
			ShowArr(result);
		}
		static void ShowArr(int[] arr)
		{
			int n = arr.Length;
			for (int i = 0; i < n; i++)
			{
				Console.Write($"{arr[i]} ");
			}
		}
		static int[] MergeArr(int[] a, int[] b)
		{
			int n, m, r, IndexA = 0, IndexB = 0;
			n = a.Length;
			m = b.Length;
			r = m + n;
			int[] result = new int[r];
			for (int i = 0; i < r; i++)
			{
				if (IndexA < n && IndexB < m)
				{
					if (a[IndexA] < b[IndexB])
					{
						result[i] = a[IndexA++];
					}
					else
					{
						result[i] = b[IndexB++];
					}
				}
				else
				{
					if (IndexA == n)
						result[i] = b[IndexB++];
					else if (IndexB == m)
						result[i] = a[IndexA++];
				}
			}
			return result;
		}
		static void ReadInfo(int[] arr)
		{
			int n = arr.Length;
			for (int i = 0; i < n; i++)
			{
				arr[i] = int.Parse(Console.ReadLine());
			}
		}
	}
}
