using lab07.ParkingLotManager;
using lab07.ParkingLotManager.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab07
{
    class Program
    {
        static void Main(string[] args)
        {
            int HOUR = 7;
            int minutes = 0;
            Console.WriteLine("Set data, in sequence, for: AnonymousPedestrians, Pedestrians, Cars, TeacherCars, Bicycles:\n");
            List<IEntity> queue = QueueGenerator.Generate();
            ParkingLot parking = new ParkingLot();

            Log.Info("There's " + parking.CountCars() + " cars in the parking lot");
            Log.Info();

            foreach(IEntity entity in queue)
            {
                if (parking.CheckIfCanEnter(entity))
                {
                    parking.LetIn(entity);
                    if(minutes < 10)
                    {
                        Console.WriteLine(HOUR + ":0" + minutes);
                    }
                    if(minutes >= 10)
                    {
                        Console.WriteLine(HOUR + ":" + minutes);
                    }              
                    minutes++;
                    if(minutes==60)
                    {
                        minutes = 0;
                        HOUR++;
                    }
                }
            }

            Log.Info();
            Log.Info("There's " + parking.CountCars() + " cars in the parking lot");
            Log.Info(parking.EndOfTheDay());
            Console.ReadKey();
        }
    }
}
