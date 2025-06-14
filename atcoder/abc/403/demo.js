const car = {
    make: 'Toyota',
    model: 'Camry',
}

const camry = Object.create(car);

console.log(camry.make) // Toyota

car.make = "Not Toyota"

console.log(camry.make) // Not Toyota
console.log(car.make) // Not Toyota