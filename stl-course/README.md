# The STL Adventure 🚀

A hands-on introduction to the C++ **Standard Template Library (STL)** — the giant
toolbox of ready-made containers and algorithms that comes free with C++.

This course is 13 lessons. Each lesson is **one file you can compile and run**.
Every file has two parts:

1. **LEARN** — working example code. Read it, run it, see what it prints.
2. **YOUR TURN** — small exercises with `TODO` blanks for *you* to fill in.

When you run a lesson, each exercise prints either:

```
  [PASS] exercise 1.1   <- you got it right! ✅
  [ ?? ] exercise 1.2   <- not done yet, keep going 🔧
```

Your goal: turn every `[ ?? ]` into a `[PASS]`.

If you get stuck, fully-worked answers for **every** lesson (1–13) live in the
`solutions/` folder — but try hard first. Struggling a little is how the
learning sticks.

---

## The lessons (do them in order)

| # | File | What you'll learn |
|---|------|-------------------|
| 1 | `exercises/01_vector.cpp`     | `std::vector` — the resizable array you'll use everywhere |
| 2 | `exercises/02_string.cpp`     | `std::string` — text as a first-class object |
| 3 | `exercises/03_iterators.cpp`  | Iterators — how the STL "points" into a container |
| 4 | `exercises/04_algorithms.cpp` | `sort`, `find`, `count`, `max_element`, `accumulate` … |
| 5 | `exercises/05_map.cpp`        | `std::pair` and `std::map` — key → value lookups |
| 6 | `exercises/06_set.cpp`        | `std::set` — a bag of *unique*, sorted things |
| 7 | `exercises/07_containers.cpp` | `std::array`, `std::stack`, `std::queue` |
| 8 | `exercises/08_lambdas.cpp`    | Lambdas — little functions you write inline |
| 9 | `exercises/09_challenges.cpp` | Challenges — combine everything so far 🔥 |
| 10 | `exercises/10_advanced.cpp`  | Advanced — the deep end (interview classics) 🌊 |
| 11 | `exercises/11_closures.cpp`  | Closures — lambdas that remember state 🧠 |
| 12 | `exercises/12_stl_limits.cpp`| STL to the limits — let the library do the work ⚙️ |
| 13 | `exercises/13_big_boss.cpp`  | **Big Boss** — approximate string lookup / autocorrect 👑🐉 |

Every lesson now also ends with a **`GOING FURTHER 🔥`** section — extra, tougher
exercises for when the main ones feel too easy.

---

## How to build and run

You need a C++ compiler (`g++` or `clang++`). On this Mac, `c++` works.

**Compile and run one lesson:**

```bash
c++ -std=c++17 -Wall exercises/01_vector.cpp -o build/01_vector
./build/01_vector
```

**Or use the Makefile shortcut** (builds into a `build/` folder for you):

```bash
make            # build every lesson
make 01_vector  # build & run just lesson 1
make clean      # delete the build folder
```

To run a lesson's *solution* instead, point the compiler at the `solutions/` file.

---

## A note on `using namespace std;`

These lessons write `using namespace std;` at the top so you can type `vector`
instead of `std::vector`. That keeps the code short and friendly while you're
learning. In big real-world projects people usually *don't* do this and write the
`std::` prefix everywhere — you'll see both styles out there. Don't worry about it
for now.

Have fun! 🎉
