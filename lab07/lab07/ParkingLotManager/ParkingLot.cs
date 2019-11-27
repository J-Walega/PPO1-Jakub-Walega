using lab07.ParkingLotManager.Entities;
using lab07.ParkingLotManager.Interfaces;
using System.Collections.Generic;

namespace lab07.ParkingLotManager
{
    class ParkingLot
    {
        private List<IEntity> entitiesOnProperty = new List<IEntity>();
        private int carsOnProperty = 0;
        private int maxCarsOnProperty = 50;
        private int Money = 0;

        public bool CheckIfCanEnter(IEntity entity)
        {
            return entity.CanEnter();
        }

        public void LetIn(IEntity entity)
        {
            if(carsOnProperty < maxCarsOnProperty)
            {
                entitiesOnProperty.Add(entity);
                Log.Info(entity.Identify() + " let in.");
                Log.Info(entity.GetCharge());

                if (entity is Car)
                {
                    this.carsOnProperty++;
                    Money = Money + 5;
                }
                else if (entity is Pedestrian)
                {

                }
                else
                {
                    Log.Info(entity.Identify() + " did not let in- unknown vehicle");
                }
            }

            if(carsOnProperty == maxCarsOnProperty)
            {
                entitiesOnProperty.Add(entity);
                Log.Info(entity.Identify() + " did not let in - maximum number of cars on property");
            }
        }

        public int CountCars()
        {
            return this.carsOnProperty;
        }

        public string EndOfTheDay()
        {
            return "Money accumulated:" + Money + "PLN";
        }
    }
}
