# push_swap

> A 42 School algorithm project — sorting a stack of integers using a limited set of operations.

---

## 📋 Overview

**push_swap** requires sorting a stack of integers using two stacks (`a` and `b`) and a restricted set of operations, with the goal of using as few operations as possible.

### Available operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements of stack a |
| `sb` | Swap the first 2 elements of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top of stack b onto stack a |
| `pb` | Push the top of stack a onto stack b |
| `ra` | Rotate stack a upward |
| `rb` | Rotate stack b upward |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack a |
| `rrb` | Reverse rotate stack b |
| `rrr` | `rra` and `rrb` at the same time |

---

## 📁 File Structure

```
push_swap/
├── push_swap.h
└── srcs/
    ├── algorithm/
    │   ├── algorithm_structure_1.c
    │   ├── algorithm_structure_2.c
    │   ├── algorithm_structure_3.c
    │   ├── algorithm_structure_4.c
    │   ├── init_node_a_1.c
    │   ├── init_node_a_2.c
    │   └── init_node_b.c
    ├── commands/
    │   ├── push.c
    │   ├── reverse_rotate.c
    │   ├── rotate.c
    │   └── swap.c
    ├── input/
    │   ├── ft_split_new.c
    │   ├── ft_split_new_2.c
    │   ├── handle_errors.c
    │   ├── init_stack_a.c
    │   └── main.c
    └── stack_utils/
        └── stack_find_len.c
```

### Directory breakdown

| Directory | Role |
|-----------|------|
| `algorithm/` | Core sorting logic and node initialization |
| `commands/` | Implementation of all stack operations |
| `input/` | Argument parsing, input validation, stack initialization |
| `stack_utils/` | Stack utility functions |

---

*42 Paris — push_swap*
