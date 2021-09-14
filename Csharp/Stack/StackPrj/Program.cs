using System;
using System.Collections;

namespace StackPrj
{
	class Program
	{
		static void Main(string[] args)
		{
			string str = Console.ReadLine();
			string result = encodeString(str);
			Console.WriteLine(result);
		}
		static string encodeString(string str)
		{
			Stack st = new Stack();
			str += "@";
			int len = str.Length;
			string result = "";
			for (int i = 0; i < len; i++)
			{
				if (st.Count == 0 || st.Peek().Equals(str[i]))
				{
					st.Push(str[i]);
				}
				else
				{
					int count = 1;
					result += st.Pop();
					while (st.Count != 0)
					{
						count++;
						st.Pop();
					}
					result += count.ToString();
					st.Push(str[i]);
				}
			}
			return result;
		}
		static Stack ConvertToBin(int n)
		{
			Stack st = new Stack();
			while (n > 0)
			{
				st.Push(n % 2);
				n /= 2;
			}
			return st;
		}
		static void ShowStack(Stack st)
		{
			int len = st.Count;
			for (int i = 0; i < len; i++)
			{
				Console.Write(st.Pop());
			}
		}
	}
}
