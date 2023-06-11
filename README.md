# silhouette-lang

"silhouette" is a French word used to describe the dark shape and outline of someone or 
something visible against a lighter background, especially in dim light.

When you think of something iconic, like the Porsche 911, you don't need to see the
whole car to know what it is. Simply by its silhouette you can tell it's a 911, because
of its sleek shape and aesthetic pleasing lines.

The silhouette language follows this same principles of simplicity and elegance. It's
syntax is designed to be easy to read and write, encourage clean code, and to be 
able to be understood at a glance, while also allowing for flexibility in syntax choices.

Silhouette builds upon the strengths of languages like C, known for its simplicity, 
power, and readability. However, it introduces a few twists and tweaks from languages
with a more modern syntax, such as Rust and Haskell, to further enhance readability and 
make it more approachable to new programmers.


## Example

```
fn fact x: Int = {
    if x <= 1 { -> 1;} 
    else {
        result -> x * fact(x-1);
    }
}

let ans: Int = call fact(3);

ans = ans + fact(4);

ans * 2;
```

## Requirements

* Flex 2.6.4
* Bison 3.8.2
* Clang++ 14.0.0
* CMake 3.22.1 (optional)

## How to compile
### Note: All commands should be run from the `/compiler` directory located at the root of the project.


1. Using CMake:

```
cmake --build ./build
```

2. Using Flex, Bison, and Clang++:

  * Flex: `flex -o ./tokenizer-flex/tokens.cpp ./tokenizer-flex/tokens.l`
  * Bison: `bison -o ./parser-bison/parser.cpp ./parser-bison/parser.y`
  * Clang++: `clang++ ./parser-bison/parser.cpp codegen.cpp main.cpp ./tokenizer-flex/tokens.cpp -o parser -lLLVM -L/usr/lib/llvm-14/lib`

## How to run

1. Compiled using CMake:

```
./build/parser < {input file}
```

2. Compiled using Flex, Bison, and Clang++:

```
./parser < {input file}
```