# Link: https://leetcode.com/problems/design-parking-system/description/
# Runtime: 146 ms
# Memory: 16.8 MB

class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.parkingPlaces = [big, medium, small]
        

    def addCar(self, carType: int) -> bool:
        if self.parkingPlaces[carType - 1] > 0:
            self.parkingPlaces[carType - 1] -= 1
            return True
        else:
            return False



# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
