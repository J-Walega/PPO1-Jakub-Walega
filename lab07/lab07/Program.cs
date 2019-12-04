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
            List<IEntity> queue = QueueGenerator.Generate();
            ParkingLot parking = new ParkingLot();

            Log.Info("There's " + parking.CountCars() + " cars in the parking lot");
            Log.Info();

            foreach(IEntity entity in queue)
            {
                if (parking.CheckIfCanEnter(entity))
                {   
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
                    parking.LetIn(entity);
                }
            }

            Log.Info();
            Log.Info("There's " + parking.CountCars() + " cars in the parking lot");
            Log.Info("There's " + parking.CountBicycles() + " bicycles in the parking lot");
            Console.WriteLine(QueueGenerator.CountMoney() + " gathered");
            Console.ReadKey();
        }
    }
}
