# silhouette-lang

"silhouette" is a French word used to describe the dark shape and outline of someone or 
something visible against a lighter background, especially in dim light.
`
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
