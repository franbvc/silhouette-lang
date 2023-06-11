define internal i64 @main() {
entry:
  %0 = call i64 @fib(i64 12)
  ret i64 %0
}

define internal i64 @fib(i64 %x1) {
entry:
  %x = alloca i64, align 8
  store i64 %x1, i64* %x, align 4
  %0 = load i64, i64* %x, align 4
  %1 = icmp eq i64 %0, 1
  %2 = load i64, i64* %x, align 4
  %3 = icmp eq i64 %2, 0
  %4 = or i1 %3, %1
  %5 = icmp ne i1 %4, false
  br i1 %5, label %then, label %else

then:                                             ; preds = %entry
  %6 = load i64, i64* %x, align 4
  ret i64 %6
  br label %exitIf

else:                                             ; preds = %entry
  %7 = load i64, i64* %x, align 4
  %8 = sub i64 %7, 2
  %9 = call i64 @fib(i64 %8)
  %10 = load i64, i64* %x, align 4
  %11 = sub i64 %10, 1
  %12 = call i64 @fib(i64 %11)
  %13 = add i64 %12, %9
  ret i64 %13
  br label %exitIf

exitIf:                                           ; preds = %else, %then
  phi void [ <badref>, %then ], [ <badref>, %else ]
  ret void <badref>
}