import 'dart:io';

int fibo(int n) {
  if (n == 1) {
    return 1;
  }
  if (n == 0) {
    return 0;
  }
  return fibo(n - 1) + fibo(n - 2);
}

void main() {
  int? n = int.parse(stdin.readLineSync()!);
  int k = fibo(n);

  print("fibo cua so $n la $k");
}
