using lab07.ParkingLotManager.Entities;
using lab07.ParkingLotManager.Interfaces;
using System.Collections.Generic;
using System;
using System.Linq;

namespace lab07.ParkingLotManager
{
    class Blacklist
    {
        List<string> NoEntry = new List<string>();
        private static Random generator = new Random();

        protected void GetBlacklist()
        {
            for(int i=0;i<10;i++)
            {
                NoEntry.Add("DLX " + (generator.Next(89999) + 10000));
            }
        }

    }
}
