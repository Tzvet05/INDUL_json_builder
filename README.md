# INDUL_program_builder

**Indu**strial **L**anguage Program Builder

Program that turns a compiled INDUL binary file (compiled using [INDULC](https://github.com/Tzvet05/INDULC)) into a Json file of a Factorio blueprint containing the machine code on constant combinators.

## SETUP

Go into the cloned INDUL\_json\_builder/ directory and compile the program using
```
make
```

## USAGE

Run the Json file builder using
`./indul_json_builder [binary infile] ([json outfile])`

`[binary infile]` is the input INDUL binary file containing the compiled program. You must have reading permissions for it.

`[json outfile]` is the output Json file to write the blueprint in. You must have writing permissions for it. This argument is optional and will be replaced by a default argument `out.json` if left empty.

### Makefile rules

`make (all)` compiles the program.

`make clean` removes the object files.

`make fclean` removes the executable and the object files.

`make re` removes the executable, the object files, and recompiles.

## WIP FEATURES

- Compiled program stored on 512 different signals on the same constant combinator (in the order they are treated by the simulation for correct indexing)
