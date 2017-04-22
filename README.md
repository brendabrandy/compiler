# compiler

# To do

* support strings, ints, pointers and chars
* support arguments
* support arithmetic operatiosn
* support loading, storing etc

# Done to-dos

* support static, extern, global and local variables
* assign an offset to local variables as I go through the stack frame
* assign an offset to temporary variables as I go through the stack frame

# Quads

General expression of the quad looks like this:

`DST = QUAD ARG1, ARG2`

| QUAD | QUAD CODE  | ARG1               | ARG2     | DST  | NOTE                            | DONE? |
|------|------------|--------------------|----------|------|---------------------------------|-------|
|BRLT  |QUAD\_BRLT  | false arm          | true arm | NULL | branch if less than             |Y      |
|BREQ  |QUAD\_BREQ  | false arm          | true arm | NULL | branch if equal to              |Y      |
|BRGT  |QUAD\_BRGT  | false arm          | true arm | NULL | branch if greater than          |Y      |
|BRLE  |QUAD\_BRLE  | false arm          | true arm | NULL | branch if less or equal to      |Y      |
|BRGE  |QUAD\_BRGE  | false arm          | true arm | NULL | branch if greater or equal to   |Y      |
|BR    |QUAD\_BR    | branch destination | NULL     | NULL | unconditional branch            |Y      |
|ADD   |E\_ADD      | src1               | src2     | dst  | dst = src1 + src2               |Y      |
|MINUS |E\_MINUS    | src1               | src2     | dst  | dst = src1 - src2               |Y      |
|MUL   |E\_MUL      | src1               | src2     | dst  | dst = src1 * src2               |N      |
|DIV   |E\_DIV      | src1               | src2     | dst  | dst = src1 / src2               |N      |
|MOD   |E\_MOD      | src1               | src2     | dst  | dst = src1 % src2               |N      |
|SHL   |E\_SHL      | src1               | src2     | dst  | dst = src1 << src2              |Y      |
|SHR   |E\_SHR      | src1               | src2     | dst  | dst = src1 >> src2              |Y      |
|XOR   |E\_XOR      | src1               | src2     | dst  | dst = src1 ^ src2               |Y      |
|AND   |E\_AND      | src1               | src2     | dst  | dst = src1 & src2 (bitwise)     |Y      |
|OR    |E\_OR       | src1               | src2     | dst  | dst = src1 \| src2 (bitwise)    |Y      |
|BNOT  |E\_BITNOT   | src1               | NULL     | dst  | dst = ~src1       (bitwise)     |N      |
|UMINUS|E\_UMINUS   | src1               | NULL     | dst  | dst = -src1                     |N      |
|UPLUS |E\_UPLUS    | src1               | NULL     | dst  | dst = +src1                     |N      |
|LOAD  |QUAD\_LOAD  | addr               | NULL     | dst  | dst = * addr (LOAD [address])   |N      |
|STORE |QUAD\_STORE | src1               | addr     | NULL | * addr = src1 (STORE a, [addr]) |N      |
|LEA   |QUAD\_LEA   | src1               | NULL     | dst  | dst = &src1                     |N      |
|MOV   |QUAD\_MOV   | src1               | NULL     | dst  | dst = src1                      |N      |
|CMP   |QUAD\_CMP   | src1               | src2     | NULL | compare src1 and src2           |N      |
|RETURN|QUAD\_RETURN| opt                | NULL     | NULL | return opt (can be NULL)        |N      |
|CALL  |QUAD\_CALL  | function name      | num\_args| NULL | calls function                  |N      |
|ARG   |QUAD\_ARGS  | arg number         | arg      | NULL | specifies arguments             |N      |
|NOT   |QUAD\_NOT   | src1               | NULL     | dst  | dst = !src1                     |N      |
