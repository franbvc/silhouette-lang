define internal i64 @main() {
entry:
  %0 = call i64 @runCode()
  ret i64 %0
}

define internal i64 @addTwo(i64 %x1, i64 %y2) {
entry:
  %x = alloca i64, align 8
  store i64 %x1, i64* %x, align 4
  %y = alloca i64, align 8
  store i64 %y2, i64* %y, align 4
  %0 = load i64, i64* %y, align 4
  %1 = load i64, i64* %x, align 4
  %2 = add i64 %1, %0
  ret i64 %2
}

define internal i64 @square(i64 %x1) {
entry:
  %x = alloca i64, align 8
  store i64 %x1, i64* %x, align 4
  %0 = load i64, i64* %x, align 4
  %1 = load i64, i64* %x, align 4
  %2 = mul i64 %1, %0
  ret i64 %2
  ret void <badref>
}

define internal i64 @max(i64 %x1, i64 %y2) {
entry:
  %x = alloca i64, align 8
  store i64 %x1, i64* %x, align 4
  %y = alloca i64, align 8
  store i64 %y2, i64* %y, align 4
  %0 = load i64, i64* %y, align 4
  %1 = load i64, i64* %x, align 4
  %2 = icmp sgt i64 %1, %0
  %3 = icmp ne i1 %2, false
  br i1 %3, label %then, label %else

then:                                             ; preds = %entry
  %4 = load i64, i64* %x, align 4
  ret i64 %4
  br label %exitIf

else:                                             ; preds = %entry
  %5 = load i64, i64* %y, align 4
  ret i64 %5
  br label %exitIf

exitIf:                                           ; preds = %else, %then
  phi void [ <badref>, %then ], [ <badref>, %else ]
  ret void <badref>
}

define internal i64 @min(i64 %x1, i64 %y2) {
entry:
  %x = alloca i64, align 8
  store i64 %x1, i64* %x, align 4
  %y = alloca i64, align 8
  store i64 %y2, i64* %y, align 4
  %0 = load i64, i64* %y, align 4
  %1 = load i64, i64* %x, align 4
  %2 = icmp slt i64 %1, %0
  %3 = icmp ne i1 %2, false
  br i1 %3, label %then, label %else

then:                                             ; preds = %entry
  %4 = load i64, i64* %x, align 4
  ret i64 %4
  br label %exitIf

else:                                             ; preds = %entry
  %5 = load i64, i64* %y, align 4
  ret i64 %5
  br label %exitIf

exitIf:                                           ; preds = %else, %then
  phi void [ <badref>, %then ], [ <badref>, %else ]
  ret void <badref>
}

define internal i64 @runCode() {
entry:
  %foo = alloca i64, align 8
  store i64 2, i64* %foo, align 4
  %bar = alloca i64, align 8
  store i64 3, i64* %bar, align 4
  %fooBar = alloca i64, align 8
  %0 = load i64, i64* %foo, align 4
  %1 = load i64, i64* %bar, align 4
  %2 = call i64 @addTwo(i64 %0, i64 %1)
  store i64 %2, i64* %fooBar, align 4
  %3 = load i64, i64* %fooBar, align 4
  %4 = call i64 @square(i64 %3)
  store i64 %4, i64* %fooBar, align 4
  %ret = alloca i64, align 8
  %5 = load i64, i64* %fooBar, align 4
  %6 = call i64 @max(i64 %5, i64 15)
  store i64 %6, i64* %ret, align 4
  %7 = load i64, i64* %fooBar, align 4
  %8 = call i64 @min(i64 %7, i64 100)
  ret i64 %8
  ret void <badref>
}