/* This is a torture-test of struct tag scoping rules */


struct s1 {
	int a;
};


void f(){
	struct s1;	/* 0x23cec50 */
	struct s2 {
		struct s1 *p1;	/* Should report as ptr to (incomplete) */
	} s2;
	struct s3 {
		struct s2 *p2;	/* Should be complete */
		struct s1 {	/* 0x23cec50 */
			double d;
		} *p1;			/* p1 should be ptr->complete */
	} s3;
	{
		struct s1 {
			float f;
		} s1;
	}
		
	struct s1 s1;		/* Not a dup defn! */
}

