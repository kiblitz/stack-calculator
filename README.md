# stack-calculator
## About
CLI evaluator for postfix expressions (reverse Polish notation)
## Use
Download the release and execute it in the following form
```
./stack-calc [--stack] [file.json...]
```
- ### --stack
  If enabled, displays the stack after every operation
- ### file.json...
  Expand command list with json files
  #### ex:
  ```
  {
  "abs":"dup 0 < if -1 * noop",
  "dup":"1 pick",
  "err":"2 pick - abs swap /"
  }
  ```
  
### Commands
- **quit**: quits the program
- **help**: displays commands list
- **stack**: displays the stack
- **noop**: pass
- **clear**: empties stack
- **pop**: removes top of stack
- **popn**: removes top `n` elements of the stack (*ex: `1 2 3 2 popn` => `1`*)
- **skip**: skips next `n` commands (*ex: `2 skip 1 2 3 4` => `3 4`*)
- **pick**: copies the `n`'th element of the stack (*ex: `2 3 4 2 pick` => `2 3 4 3`*)
- **swap**: swaps top `2` elements of the stack
- **if**: if the top element of the stack is `0`, skip the next `3` commands (*ex: `0 if 1 2 3 4` => `4`*)
- **>**, **=**, **<**: `1` if true, `0` otherwise (*ex: `2 < 3` => `1`*)
- **+**, **-**, **\***, **/**, **//**, **%**, **^**, **e**, **pi**, **ln**, **sin**, **arcsin**, **cos**, **arccos**, **tan**, **arctan**: standard functions

### Custom Commands
In the form `: command corresponding-commands... ;`
- **ex**: `: dup 1 pick ;`
