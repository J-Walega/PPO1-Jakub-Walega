using lab07.ParkingLotManager.Entities;
using lab07.ParkingLotManager.Interfaces;
using System.Collections.Generic;

namespace lab07.ParkingLotManager
{
    class ParkingLot : Blacklist
    {
        private List<IEntity> entitiesOnProperty = new List<IEntity>();
        private int carsOnProperty = 0;
        private int maxCarsOnProperty = 50;
        private int Money = 0;
        private int bicyclesOnProperty = 0;
        private int maxBicycles = 20;

        public bool CheckIfCanEnter(IEntity entity)
        {
            return entity.CanEnter();
        }

        public void LetIn(IEntity entity)
        {
            GetBlacklist();

                entitiesOnProperty.Add(entity);

                if (entity is Car || entity is TeacherCar)
                {
                    if (carsOnProperty == maxCarsOnProperty)
                    {
                        entitiesOnProperty.Add(entity);
                        Log.Info(entity.Identify() + " did not let in - maximum number of cars on property");
                    }
                    Log.Info(entity.Identify() + " let in.");
                    this.carsOnProperty++;
                }

                else if (entity is Bicycle)
                {
                    if(bicyclesOnProperty < maxBicycles)
                    {
                        Log.Info(entity.Identify() + " let in.");
                        this.bicyclesOnProperty++;
                    }
                    else
                    {
                        Log.Info(entity.Identify() + " did not let in maximum number of bicycles on property");
                    }
                }
                else if (entity is Pedestrian)
                {
                    Log.Info(entity.Identify() + " let in.");
                }
                else if (entity is PrivilagedVehicle)
                {
                    Log.Info(entity.Identify());
                }
                else
                {
                    Log.Info(entity.Identify() + " did not let in- unknown vehicle");
                }
                
            }


        public int CountCars()
        {
            return this.carsOnProperty;
        }

        public int CountBicycles()
        {
            return this.bicyclesOnProperty;
        }
    }
}
