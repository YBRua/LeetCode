import random
from tqdm import trange


def exponentiation_by_squaring(base: int, power: int):
    res = 1
    running_pow = base
    while power > 0:
        if power % 2 == 1:
            res *= running_pow
        running_pow = running_pow ** 2
        power = power // 2

    return res


if __name__ == "__main__":
    for _ in trange(1000):
        base = random.randint(1, 2000)
        power = random.randint(1, 2000)
        pred = exponentiation_by_squaring(base, power)
        true = base ** power
        if pred != true:
            raise ValueError(
                f"Failed at base={base}, power={power}. "
                f"Expected {true}, got {pred}.")
    print("Yoo")
