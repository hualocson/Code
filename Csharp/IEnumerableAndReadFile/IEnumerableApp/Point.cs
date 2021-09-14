using System;

namespace IEnumerableApp
{
    class Point
    {
        public Point(double x, double y)
        {
            X = x;
            Y = y;
        }

        public Double X { get; set; }
        public Double Y { get; set; }

        public void ShowInfo()
        {
            Console.WriteLine($"x = {X} | y = {Y}");
        }
    }
}
