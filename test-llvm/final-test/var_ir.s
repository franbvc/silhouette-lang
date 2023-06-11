define internal i64 @main() {
entry:
  %a = alloca i64, align 8
  store i64 15, i64* %a, align 4
  %b = alloca i64, align 8
  store i64 5, i64* %b, align 4
  %c = alloca i64, align 8
  %0 = load i64, i64* %b, align 4
  %1 = load i64, i64* %a, align 4
  %2 = add i64 5, %1
  %3 = sdiv i64 %2, %0
  store i64 %3, i64* %c, align 4
  %4 = load i64, i64* %c, align 4
  ret i64 %4
}