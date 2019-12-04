using lab07.ParkingLotManager.Entities;
using lab07.ParkingLotManager.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;

namespace lab07.ParkingLotManager
{
    class QueueGenerator
    {
        private static Random generator = new Random();
        private static int ANONYMOUS_PEDESTRIANS_COUNT = 30;
        private static int PEDESTRIANS_COUNT = 10;
        private static int CARS_COUNT = 50;
        private static int TEACHER_CARS_COUNT = 10;
        private static int BICYCLES_COUNT = 5;
        private static int Money = 0;

        private static void GetData()
        {
            Console.WriteLine("Set number of Anonymous Pedestrians:");
            ANONYMOUS_PEDESTRIANS_COUNT = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Set number of Pedestrians:");
            PEDESTRIANS_COUNT = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Set number of Cars:");
            CARS_COUNT = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Set number of Teacher Cars:");
            TEACHER_CARS_COUNT = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Set number of Bicycles:");
            BICYCLES_COUNT = Convert.ToInt32(Console.ReadLine());
        }

        public static List<IEntity> Generate()
        {
            GetData();
            List<IEntity> queue = new List<IEntity>();

            for (int i = 0; i < ANONYMOUS_PEDESTRIANS_COUNT; i++)
            {
                queue.Add(new Pedestrian());
            }

            for (int i = 0; i < PEDESTRIANS_COUNT; i++)
            {
                queue.Add(new Pedestrian(GetRandomName()));
            }

            for (int i = 0; i < CARS_COUNT; i++)
            {
                queue.Add(new Car(GetRandomPlateNumber()));
                Money += 5;
            }

            for (int i = 0; i < TEACHER_CARS_COUNT; i++)
            {
                queue.Add(new TeacherCar(GetRandomPlateNumber()));
            }

            for (int i = 0; i < BICYCLES_COUNT; i++)
            {
                queue.Add(new Bicycle());
            }

            return queue.OrderBy(a => Guid.NewGuid()).ToList(); ;
        }

        private static string GetRandomPlateNumber()
        {
            return "DLX " + (generator.Next(89999) + 10000);
        }

        private static string GetRandomName()
        {
            List<string> names = new List<string>() { "John", "Jack", "James", "George", "Joe", "Jim" };
            return names[generator.Next(names.Count)];
        }
        public static string CountMoney()
        {
            return Money +" PLN";
        }
    }
}
