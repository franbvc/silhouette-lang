define internal i64 @main() {
entry:
  %0 = mul i64 4, 5
  %1 = add i64 5, 10
  %2 = sdiv i64 %1, 3
  %3 = add i64 %2, %0
  ret i64 %3
}