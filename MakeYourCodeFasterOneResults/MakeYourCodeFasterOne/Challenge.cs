namespace MakeYourCodeFasterOne;

public class Challenge {

  private readonly string _input = "0 37551 469 63 1 791606 2065 9983586";

  public long Run(int cycles) {
    Dictionary<(string, int), long> cache = new();
    return _input.Split(" ").Sum(stone => Cycle(stone, cycles, cache));
  }


  private long Cycle(string stone, int times, Dictionary<(string, int), long> cache) {

    if (times == 0)
    {
      return 1;
    }

    (string, int) key = (stone, times--);
    long result;
    if (cache.TryGetValue(key, out long cached))
    {
      result = cached;
    }


    else if (stone == "0")
    {
      cache[key] = Cycle("1", times, cache);
      result = cache[key];
    }


    else if (StoneHasEvenDigits(stone))
    {
      (string left, string right) = SplitStone(stone);
      cache[key] = Cycle(left, times, cache) + Cycle(right, times, cache);
      result = cache[key];
    }
    else
    {
      cache[key] = Cycle(MultiplyStoneBy2024(stone), times, cache);
      result = cache[key];
    }

    return result;
  }

  private bool StoneHasEvenDigits(string stone) {
    return stone.Length % 2 == 0;
  }

  private (string leftStone, string rightStone) SplitStone(string stone) {
    int middle = stone.Length / 2;
    string leftStone = stone[..middle];
    string rightStone = stone[middle..].TrimStart('0');
    if (rightStone.Length == 0) rightStone = "0";

    return (leftStone, rightStone);
  }

  private string MultiplyStoneBy2024(string stone) {
    return $"{2024L * long.Parse(stone)}";
  }
}
