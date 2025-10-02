
# Philosophers

An implementation of the classic **Dining Philosophers** concurrency problem in C for the 42 curriculum  
> Focus: thread creation/management, mutex-based synchronization, timing with millisecond precision, and avoiding deadlocks.


## ✨ Features
- One thread per philosopher + shared table state
- **Forks protected by `pthread_mutex_t`** (no data races)
- Accurate timing with millisecond timestamps
- Death detection (`time_to_die`) with prompt termination
- Status logging in the canonical format:
```

is thinking|has taken a fork|is eating|is sleeping|died

````
- Meal limit to stop when everyone has eaten enough


## 🧪 Arguments

```text
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
````

- All times are in **milliseconds**.
- The last argument is optional. If provided, the simulation ends when each philosopher has eaten that many times.

Examples:

```bash
./philo 5 800 200 200
./philo 5 800 200 200 7
```

## 🛠️ Build

Prereqs: POSIX threads.

```bash
make          # builds the binary (see Makefile for name)
make clean    # remove objects
make fclean   # remove objects + binary
make re       # rebuild
```



## 🚀 Run & Observe

```bash
./philo 4 410 200 200
# 0 1 has taken a fork
# 0 1 has taken a fork
# 0 1 is eating
# ...
```

- A philosopher **dies** when the time since their last meal exceeds `time_to_die`.
- When death is detected, the program prints the `died` line and terminates.


## 📂 Project Structure

- `main.c` – entry point / setup & teardown
- `init_and_parse.c` – CLI parsing and initialization
- `threads.c` – philosopher threads & routine
- `check_death.c` – monitoring / death detection
- `table_activity.c` – actions (eat/sleep/think) and timing helpers
- `philo_utils.c`, `libft_utils.c` – utilities (atoi, time, printing, etc.)
- `philo.h` – shared structs & prototypes
- `Makefile` – build rules


## 📖 What I Practiced

- `pthread_create`, `pthread_join`, `pthread_mutex_*`
- Designing a shared state without data races
- Avoiding deadlocks (fork-picking strategy)
- Fairness / starvation considerations
- Precise sleeps and timestamping

