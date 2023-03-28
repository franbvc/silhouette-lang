# silhouette-lang

"silhouette" is a French word used to describe the dark shape and outline of someone or 
something visible against a lighter background, especially in dim light.

When you think of something iconic, like the Porsche 911, you don't need to see the
whole car to know what it is. Simply by its silhouette you can tell it's a 911, because
of its sleek shape and aesthetic pleasing lines.

The silhouette language follows this same principles of simplicity and elegance. It's
syntax is designed to be easy to read and write, encourage clean code, and to be 
able to be understood at a
glance.

In my opinion, one of the best programming languages ever created is C. It's simple,
powerful, and elegant. It's also very easy to read and write. The silhouette language
takes inspiration from C, and adds a few twists and tweaks to make it more readable and
approachable.

## Example

```
:INT x = 10
:CHAR y = 'a'
:STRING z = "Hello, world!"
:BOOL flag = true

:print(x) // Output: 10
:print(y); // Output: 'a'
:print(z); // Output: "Hello, world!"
:print(flag); // Output: true

:for (INT i = 0; i < 5; i++) {
  :print(i);
}

:fn addWholeNumber(INT x, INT y): INT {
  :guard x < 0:
    :print("Invalid argument x");
    :result -1

  :result x + y;
}

:INT sum = call add(10, 20);
:print(sum); // Output: 30

```
