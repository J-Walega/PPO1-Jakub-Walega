﻿using lab07.ParkingLotManager.Interfaces;

namespace lab07.ParkingLotManager.Entities
{
    class Bicycle : IEntity
    {
        public bool CanEnter()
        {
            return true;
        }

        public string Identify()
        {
            return "Unknown bicycle";
        }
    }
}
