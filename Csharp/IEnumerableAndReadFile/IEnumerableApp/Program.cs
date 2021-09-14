using System;
using System.Collections.Generic;
using System.IO;

namespace IEnumerableApp
{

    class Program
    {
        static IEnumerable<string> ReadFrom(string filename)
        {
            var reader = File.OpenText(filename);
            /* Console.WriteLine($"Type of reader = {reader.GetType()}"); */
            string eachline;
            while ((eachline = reader.ReadLine()) != null)
            {
                yield return eachline;
            }
        }
        static void Main(string[] args)
        {
            var lines = ReadFrom("textFile.txt");
            var points = new List<Point>();
            foreach (var line in lines)
            {
                /* Console.WriteLine(line); */
                /* Cat line thanh mot mang luu vao numbers */
                var numbers = line.Split(new[] { ", " }, StringSplitOptions.None);
                var x = Convert.ToDouble(numbers[0]);
                var y = Convert.ToDouble(numbers[1]);
                var newPoint = new Point(x, y);
                points.Add(newPoint);
            }
            Console.WriteLine("List of points: ");
            foreach (var point in points)
            {
                point.ShowInfo();
            }
        }
    }
}
