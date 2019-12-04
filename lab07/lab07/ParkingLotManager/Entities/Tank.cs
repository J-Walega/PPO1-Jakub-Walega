using lab07.ParkingLotManager.Interfaces;

namespace lab07.ParkingLotManager.Entities
{
    class Tank : IEntity
    {
        public string Identify()
        {
            return "Tank";
        }

        public bool CanEnter()
        {
            return false;
        }
    }
}
