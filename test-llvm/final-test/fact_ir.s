define internal i64 @main() {
entry:
  %0 = call i64 @fact(i64 5)
  ret i64 %0
}

define internal i64 @fact(i64 %x1) {
entry:
  %x = alloca i64, align 8
  store i64 %x1, i64* %x, align 4
  %0 = load i64, i64* %x, align 4
  %1 = icmp sle i64 %0, 1
  %2 = icmp ne i1 %1, false
  br i1 %2, label %then, label %else

then:                                             ; preds = %entry
  ret i64 1
  br label %exitIf

else:                                             ; preds = %entry
  %3 = load i64, i64* %x, align 4
  %4 = sub i64 %3, 1
  %5 = call i64 @fact(i64 %4)
  %6 = load i64, i64* %x, align 4
  %7 = mul i64 %6, %5
  ret i64 %7
  br label %exitIf

exitIf:                                           ; preds = %else, %then
  phi void [ <badref>, %then ], [ <badref>, %else ]
  ret void <badref>
}