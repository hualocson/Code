using System;
using System.Collections;

namespace QueueApp
{
	class Program
	{
		static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			Queue qe = new Queue();
			for (int i = 0; i < n; i++)
			{
				int temp = int.Parse(Console.ReadLine());
				qe.Enqueue(temp);
			}
			int k = int.Parse(Console.ReadLine());
			Queue result = new Queue();

			while (qe.Count != 0)
			{
				if (!result.Contains(qe.Peek()))
				{
					if (result.Count == k)
					{
						result.Dequeue();
					}
					result.Enqueue(qe.Peek());
				}
				qe.Dequeue();
			}
			ShowQueue(result);
		}
		static void ShowQueue(Queue qe)
		{
			while (qe.Count != 0)
			{
				Console.Write($"{qe.Dequeue()} ");
			}
		}
	}
}
