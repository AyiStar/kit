# Development Notes

## Design Decisions

- Similar to the scenario in https://stackoverflow.com/questions/37700365/if-youre-in-the-we-dont-use-exceptions-camp-then-how-do-you-use-the-standar

### No Exceptions and RTTI

- Efficiency
- Make it easy for C API

### No Tensor Slicing

- Keep it as simple as possible


### STL Usage

- Use: algorithm, numeric, type_traits/concept, iterator/range, atomic...
- Not Use: containers in core data structure

### [TODO] No Runtime Allocation

- Currently not supported
- Use different allocator


## TODO List

### Operator Register-Dispatch Mechanism

- Pytorch's dispatch: https://zhuanlan.zhihu.com/p/386876377
