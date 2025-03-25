using System.Diagnostics;
using MakeYourCodeFasterOne;

Challenge challenge = new();


Stopwatch watch = Stopwatch.StartNew();
long result = challenge.Run(25);
long millisecondsElapsed = watch.ElapsedMilliseconds;

Console.WriteLine($"Your solution was: {result}");
Console.WriteLine(result == 204022 ? "Great Success!" : "Not quite there yet, keep going!");
Console.WriteLine($"Your solution ran in: {millisecondsElapsed} ms");
Console.WriteLine($"That is about: {millisecondsElapsed / 1000f} s");
Console.WriteLine(millisecondsElapsed < 1000
  ? "Another satisfied customer!"
  : "The customer couldn't wait that long and walked away....");
Console.WriteLine();