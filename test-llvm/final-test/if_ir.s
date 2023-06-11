define internal i64 @main() {
entry:
  %x = alloca i64, align 8
  store i64 10, i64* %x, align 4
  %y = alloca i64, align 8
  store i64 20, i64* %y, align 4
  %z = alloca i64, align 8
  store i64 5, i64* %z, align 4
  %0 = load i64, i64* %y, align 4
  %1 = load i64, i64* %x, align 4
  %2 = icmp sle i64 %1, %0
  %3 = icmp ne i1 %2, false
  br i1 %3, label %then, label %else

then:                                             ; preds = %entry
  %4 = load i64, i64* %x, align 4
  store i64 %4, i64* %z, align 4
  br label %exitIf

else:                                             ; preds = %entry
  %5 = load i64, i64* %y, align 4
  store i64 %5, i64* %z, align 4
  br label %exitIf

exitIf:                                           ; preds = %else, %then
  phi void [ <badref>, %then ], [ <badref>, %else ]
  %e = alloca i64, align 8
  %6 = load i64, i64* %y, align 4
  %7 = load i64, i64* %z, align 4
  %8 = icmp ne i64 %7, %6
  %9 = load i64, i64* %x, align 4
  %10 = load i64, i64* %z, align 4
  %11 = icmp ne i64 %10, %9
  %12 = and i1 %11, %8
  %13 = icmp ne i1 %12, false
  br i1 %13, label %then1, label %else2

then1:                                            ; preds = %exitIf
  store i64 50, i64* %e, align 4
  br label %exitIf3

else2:                                            ; preds = %exitIf
  store i64 10, i64* %e, align 4
  br label %exitIf3

exitIf3:                                          ; preds = %else2, %then1
  phi void [ <badref>, %then1 ], [ <badref>, %else2 ]
  %14 = load i64, i64* %e, align 4
  %15 = load i64, i64* %z, align 4
  %16 = add i64 %15, %14
  ret i64 %16
}