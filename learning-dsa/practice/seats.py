seat_prices = [
    [-1, 42, 13, 17, 23],
    [11, 13, -1, 10, 10],
    [14, 12, 15, -1, -1],
    [16, 17, 10, 11, 19],
    [-1, -1, -1, -1, -1],
    [-1, 14, 17, -1, 14],
]

required_seats = 3
rows = 6
columns = 5


def getMinPrice(requiredSeats, seatPrices):
    min_price = 10000000
    for row in seatPrices:
        current_price = 0
        used = 0
        for idx, s in enumerate(row):
            used += 1
            if s == -1:
                current_price = 0
                used = 0
            elif used == requiredSeats:
                current_price += s
                if current_price < min_price:
                    min_price = current_price
                current_price = current_price - row[idx - requiredSeats + 1]
                used -= 1
            else:
                current_price += s
    return min_price


print getMinPrice(required_seats, seat_prices)

