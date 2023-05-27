# imbroglio

the best silly language ever

a language thats basically just extended brainfuck lol

file extension: `.ism`


## INSTRUCTION SET:
The full instruction set, alongside a brainfuck equivalent

```
ADD ; adds one (+)
ADT ; adds three (+++)
SUB ; subtracts one (-)
SBT ; subtracts three (---)
MVR ; moves right one (>)
MRT ; moves right three (>>>)
MVL ; moves left one (<)
MLT ; moves left three (<<<)
SLP ; starts loop ([)
ELP ; ends loop (])
PUT ; prints (.)
GET ; gets input (,)
```

## synatax y conventions
tabs dont matter but they make ur code look swag as hell

rather than this:
```
; unreadable and stupid
ADD
SLP
MVR
ADD
MVR
SUB
ELP
```

try this:
```
; readable and swag
ADD
SLP
  MVR
  ADD
  MVR
  SUB
ELP
```

## what is an imbroglio
i dont know but it means clusterfuck

## commands

``imbroglio <file_name>`` runs a `.ism` file.

``imbroglio -[t/transpile] <file_name>`` converts a `.ism` to a `.bf` file.
