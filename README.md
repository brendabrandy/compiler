# compiler

# QUADS

General expression of the quad looks like this:

`DST = QUAD ARG1, ARG2`

| QUAD | QUAD CODE  | ARG1               | ARG2     | DST  | NOTE                            |
|------|------------|--------------------|----------|------|---------------------------------|
|BRLT  |QUAD\_BRLT  | false arm          | true arm | NULL | branch if less than             |
|BREQ  |QUAD\_BREQ  | false arm          | true arm | NULL | branch if equal to              |
|BRGT  |QUAD\_BRGT  | false arm          | true arm | NULL | branch if greater than          |
|BRLE  |QUAD\_BRLE  | false arm          | true arm | NULL | branch if less or equal to      |
|BRGE  |QUAD\_BRGE  | false arm          | true arm | NULL | branch if greater or equal to   |
|BR    |QUAD\_BR    | branch destination | NULL     | NULL | unconditional branch            |
|ADD   |E\_ADD      | src1               | src2     | dst  | dst = src1 + src2               |
|MINUS |E\_MINUS    | src1               | src2     | dst  | dst = src1 - src2               |
|MUL   |E\_MUL      | src1               | src2     | dst  | dst = src1 * src2               |
|DIV   |E\_DIV      | src1               | src2     | dst  | dst = src1 / src2               |
|MOD   |E\_MOD      | src1               | src2     | dst  | dst = src1 % src2               |
|SHL   |E\_SHL      | src1               | src2     | dst  | dst = src1 << src2              |
|SHR   |E\_SHR      | src1               | src2     | dst  | dst = src1 >> src2              |
|LT    |E\_LT       | src1               | src2     | dst  | dst = src1 < src2               |
|GT    |E\_GT       | src1               | src2     | dst  | dst = src1 > src2               |
|LTEQ  |E\_LTEQ     | src1               | src2     | dst  | dst = src1 <= src2              |
|GTEQ  |E\_GTEQ     | src1               | src2     | dst  | dst = src1 >= src2              |
|EQEQ  |E\_EQEQ     | src1               | src2     | dst  | dst = src1 == src2              |
|NOTEQ |E\_NOTEQ    | src1               | src2     | dst  | dst = src1 != src2              |
|LOGOR |E\_LOGOR    | src1               | src2     | dst  | dst = src1 || src2 (logical)    |
|LOGAND|E\_LOGAND   | src1               | src2     | dst  | dst = src1 && src2 (logical)    |
|XOR   |E\_XOR      | src1               | src2     | dst  | dst = src1 ^ src2               |
|AND   |E\_AND      | src1               | src2     | dst  | dst = src1 & src2 (bitwise)     |
|OR    |E\_OR       | src1               | src2     | dst  | dst = src1 | src2 (bitwise)     |
|BNOT  |E\_BITNOT   | src1               | NULL     | dst  | dst = ~src1       (bitwise)     |
|UMINUS|E\_UMINUS   | src1               | NULL     | dst  | dst = -src1                     |
|UPLUS |E\_UPLUS    | src1               | NULL     | dst  | dst = +src1                     |
|LOAD  |QUAD\_LOAD  | addr               | NULL     | dst  | dst = * addr (LOAD [address])   |
|STORE |QUAD\_STORE | src1               | addr     | NULL | * addr = src1 (STORE a, [addr]) |
|LEA   |QUAD\_LEA   | src1               | NULL     | dst  | dst = &src1                     |
|MOV   |QUAD\_MOV   | src1               | NULL     | dst  | dst = src1                      |
|CMP   |QUAD\_CMP   | src1               | src2     | NULL | compare src1 and src2           |
|RETURN|QUAD\_RETURN| opt                | NULL     | NULL | return opt (can be NULL)        |
|CALL  |QUAD\_CALL  | function name      | num\_args| NULL | calls function                  |
|ARG   |QUAD\_ARGS  | arg number         | arg      | NULL | specifies arguments             |
|NOT   |QUAD\_NOT   | src1               | NULL     | dst  | dst = !src1                     |
