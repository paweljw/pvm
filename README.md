# PVM

paweljw's virtual machine.

## What?

This project includes:

* a runtime for a stack-based VM, sporting a whopping 21 opcodes,
* a compiler for a super-rudimentary (meaning, almost opcode-like) language to a binary format understood by runtime (but at least it has labels now),
* a couple of examples of using the language,
* absolutely no procedures (though they can be implemented after a fashion) or global memory except for sixteen registers.

## Usage

```
$ make
$ make examples
$ bin/runtime hello_world.pvm
$ bin/runtime fizzbuzz.pvm
```

Compiling a script:

```
$ bin/compiler script.pvs output.pvm
```

### Debugging

## TODO

* [x] Question my Friday evening pastimes.
* [ ] Implement a better language on top of the VM (it would be so nice if I didn't have to push strings backwards).
* [ ] A header in the binary file, specifying e.g. entrypoint (currently assumed to be instruction 0).
* [ ] Global memory (but aren't registers fun?)
* [ ] Procedure calls (yeah, right).
