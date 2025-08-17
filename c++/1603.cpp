// Link: https://leetcode.com/problems/design-parking-system/description/
// Runtime: 58 ms
// Memory: 33.1 MB

class ParkingSystem {
public:
  ParkingSystem(int big, int medium, int small) {
    parkingPlaces = {big, medium, small};
  }

  bool addCar(int carType) {
    return parkingPlaces[carType - 1] > 0 ? parkingPlaces[carType - 1]-- : 0;
  }

private:
  std::vector<int> parkingPlaces;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
