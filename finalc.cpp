#include "finalc.h"
int main()
{
    Whole x(10), y(2), add, mul, sub, div, num, comp, andd, orr;
    Decimal a(0.5), b(0.5), dadd, dmul, dsub, ddiv, dnum, dcomp, dandd, dorr;
	BOOL p;
	p=true;
	yoi::print(p);

    add = x + y;
    mul = x * y;
    sub = x - y;
    div = x / y;
    comp = x == y;
    andd = x && y;
    orr = x || y;

    dadd = a + b;
    dmul = a * b;
    dsub = a - b;
    ddiv = a / b;
    dcomp = a == b;
    dandd = a && b;
    dorr = a || b;

    yoi::printer("X:");
    yoi::print(x);

    yoi::printer("Y:");
    yoi::print(y);

    yoi::printer("a:");
    yoi::print(a);

    yoi::printer("b:");
    yoi::print(b);

    yoi::printer("DAddition:");
    yoi::print(dadd);

    yoi::printer("dSubtraction:");
    yoi::print(dsub);

    yoi::printer("dMultiplication:");
    yoi::print(dmul);

    yoi::printer("dDivision:");
    yoi::print(ddiv);

    yoi::printer("Please enter a number:");
    yoi::enter(dnum);

    yoi::printer("dec Number:");
    yoi::print(dnum);

    Whole heba(2006);
    yoi::printer("Your birthyear");
    yoi::print(heba);

    yoi::printer("x & y is ");
    yoi::print(andd);

    yoi::printer("x | y is ");
    yoi::print(orr);

    yoi::printer("Addition:");
    yoi::print(add);

    yoi::printer("Subtraction:");
    yoi::print(sub);

    yoi::printer("Multiplication:");
    yoi::print(mul);

    yoi::printer("Division:");
    yoi::print(div);

    yoi::printer("Please enter a number:");
    yoi::enter(num);

    yoi::printer("Number:");
    yoi::print(num);

    return 0;
}
