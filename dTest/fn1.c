int f();

double j;	/* compiler shouldn't notice this error */
{
 int j;
}

int h(int x, char c)
{ int h; }		/* gcc does NOT complain about this */

