# C_mini_project
# Election System (C Console App)

A simple command-line voting system written in C. It supports officer authentication, candidate and voter registration, vote casting, and results tabulation — all with a boxed, colorized console UI.

## Features

- **Officer authentication** — a fixed officer ID gates access to the system
- **Candidate registration** — register candidates under one of five parties (Blue, Green, Red, Yellow, Pink) with Sri Lankan NIC validation (old 10-char and new 12-digit formats) and an auto-generated candidate number
- **Voter registration** — register voters with NIC validation, district check (Colombo only), age check (18+), and duplicate-registration protection
- **Vote casting** — voters vote once per NIC; votes are tracked and voters are flagged as "voted" to prevent double voting
- **Results tabulation** — officer-only view that tallies votes per candidate and declares a winner
- **Boxed console UI** — cyan unicode box-drawing borders (`╔ ═ ║ ╚ ╝`) wrap each menu, with color-coded success (green) and error (red) messages

## Requirements

- A C compiler (`gcc` or equivalent)
- A terminal that supports UTF-8 and ANSI escape codes (Linux/Mac terminal, or Windows Terminal — legacy `cmd.exe` will show raw escape codes instead of colors/borders)

## Build

```bash
gcc -o election_system election_system.c
```

## Run

```bash
./election_system
```

On startup, enter the officer ID to access the main menu:

```
1. Voters & Candidates Registration
2. For Voting
3. Show Election Results
0. Exit
```

## File Structure

The program creates and reads several data files in the working directory at runtime:

| File | Purpose |
|---|---|
| `Candidate.txt` | Registered candidates (party, NIC, number, name) |
| `Voter.txt` | Registered voters and their voted status |
| `Voter_Alldetails.txt` | Full voter details (address, age, district) |
| `votes.txt` | Recorded votes (currently not written — see Known Issues) |
| `updateVoter.txt` | Snapshot of voter list written during vote casting |
| `Results.txt` | Final tallied results, written after results are shown |

## Known Issues / Limitations

- **Vote recording is disabled**: the code that appends to `votes.txt` inside `castVote()` is commented out, so `showResults()` will typically report no votes have been cast. Uncomment/fix that block to make results work end-to-end.
- **Candidate array indexing**: `deatils()` increments its counter twice per registration, which can skip array slots.
- **Officer ID is hardcoded** (`1234`) in the source — not suitable for production use.
- No password/authentication beyond a numeric officer ID.

## License

No license specified — add one if you plan to share or distribute this project.
