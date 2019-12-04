using lab07.ParkingLotManager.Interfaces;

namespace lab07.ParkingLotManager.Entities
{
    class PrivilagedVehicle : IEntity
    {
        public string Identify()
        {
            return "It's a privilaged vehicle";
        }
        public bool CanEnter()
        {
            return true;
        }
    }
}
