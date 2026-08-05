# Task 1 — Shell Main Loop Control Flow

```text
              ┌──────────────────┐
              │  Start program   │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │ Display prompt   │
              │   my_shell>      │
              └────────┬─────────┘
                       │
                       ▼
              ┌──────────────────┐
              │ Read user input  │
              │ using fgets()    │
              └────────┬─────────┘
                       │
              ┌────────▼─────────┐
              │ Did fgets return │
              │      NULL?       │
              └──────┬─────┬─────┘
                   Yes     No
                    │       │
                    ▼       ▼
              ┌────────┐  ┌────────────────┐
              │  Exit  │  │ Remove newline │
              └────────┘  └───────┬────────┘
                                  │
                           ┌──────▼───────┐
                           │ Empty input? │
                           └─────┬───┬────┘
                               Yes  No
                                │    │
                                │    ▼
                                │ ┌──────────────┐
                                │ │ Input exit?  │
                                │ └────┬────┬────┘
                                │    Yes    No
                                │     │      │
                                │     ▼      ▼
                                │   Exit   Display
                                │          command
                                │             │
                                └─────────────┘
                                      │
                                      ▼
                              Display prompt again
