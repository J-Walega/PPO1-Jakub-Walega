﻿namespace lab07.ParkingLotManager.Entities
{
    class TeacherCar : Car
    {
        public TeacherCar(string plate) : base(plate) { }

        public string GetCharge()
        {
            return "Entered for free - employee";
        }
    }
}
