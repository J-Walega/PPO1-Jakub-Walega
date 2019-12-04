namespace lab07.ParkingLotManager.Entities
{
    class TeacherCar : Car
    {
        public TeacherCar(string plate) : base(plate) { }

        public int Pay()
        {
            return 0;
        }
    }
}
