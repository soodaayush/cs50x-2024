import cs50

while True:
    cash = cs50.get_float("Change owed: ")
    if cash > 0:
        coin = round(cash * 100)
        coinAmount = 0
        quarters = 0
        dimes = 0
        nickels = 0
        pennies = 0

        quarters = int(coin / 25)
        dimes = int((coin % 25) / 10)
        nickels = int(((coin % 25) % 10) / 5)
        pennies = int(((coin % 25) % 10) % 5)

        coinAmount += quarters + dimes + nickels + pennies

        print(coinAmount)
        break
