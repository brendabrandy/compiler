# compiler

# QUADS

General expression of the quad looks like this:

`DST = QUAD ARG1, ARG2`

| QUAD | QUAD CODE | ARG1               | ARG2     | DST  | NOTE                          |
|------|-----------|--------------------|----------|------|-------------------------------|
|BRLT  |QUAD\_BRLT | false arm          | true arm | NULL | branch if less than           |
|BREQ  |QUAD\_BREQ | false arm          | true arm | NULL | branch if equal to            |
|BRGT  |QUAD\_BRGT | false arm          | true arm | NULL | branch if greater than        |
|BRLE  |QUAD\_BRLE | false arm          | true arm | NULL | branch if less or equal to    |
|BRGE  |QUAD\_BRGE | false arm          | true arm | NULL | branch if greater or equal to |
|BR    |QUAD\_BR   | branch destination | NULL     | NULL | unconditional branch          |
|ADD   |E\_ADD     | src1               | src2     | dst  | dst = src1 + src2             |
|MINUS |E\_MINUS   | src1               | src2     | dst  | dst = src1 - src2             |
|MUL   |E\_MUL     | src1               | src2     | dst  | dst = src1 * src2             |
|DIV   |E\_DIV     | src1               | src2     | dst  | dst = src1 / src2             |
|MOD   |E\_MOD     | src1               | src2     | dst  | dst = src1 % src2             |
|SHL   |E\_SHL     | src1               | src2     | dst  | dst = src1 << src2            |
|SHR   |E\_SHR     | src1               | src2     | dst  | dst = src1 >> src2            |
|LT    |E\_LT      | src1               | src2     | dst  | dst = src1 < src2             |
|GT    |E\_GT      | src1               | src2     | dst  | dst = src1 > src2             |
|LTEQ  |E\_LTEQ    | src1               | src2     | dst  | dst = src1 <= src2            |
|GTEQ  |E\_GTEQ    | src1               | src2     | dst  | dst = src1 >= src2            |
|EQEQ  |E\_EQEQ    | src1               | src2     | dst  | dst = src1 == src2            |
|NOTEQ |E\_NOTEQ   | src1               | src2     | dst  | dst = src1 != src2            |
|LOGOR |E\_LOGOR   | src1               | src2     | dst  | dst = src1 || src2            |
|LOGAND|E\_LOGAND  | src1               | src2     | dst  | dst = src1 && src2            |
