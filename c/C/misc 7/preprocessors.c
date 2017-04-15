#include<stdio.h> 
/*
Demonstration of : Preprocessor and directives

Preprocessor is a system tool that acts
on the source code just before compilation.
# represents the preprocessor. 
 
Nature of the preprocessor action is decided 
by its directive (command). 
 
Important Preprocessor Directives 
------------------------------ 
#include : It has a header file associated. It include (brings in) the content of the header file into the current program.
#define : Defines a macro. (see definitions that follow the program) 
#undef  : Un-defines a macro.
#ifdef  : Conditional compilation of source code if the macro is defined.
#ifndef  : Conditional compilation of source code if the macro is not defined.
#else   :  Else to #ifdef or to #ifndef
#endif  : End if to #ifdef or to #ifndef
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 */

#define PI 3.14 
#define MAX(A,B) A>B?A:B
#define ADD(N1,N2) N1+N2

int main()
{
    float r, a;
    int q,w,e;
    printf("\n enter radius ");
    scanf("%f", &r);
    a = PI * r*r;
    printf("\n Area : %f", a);
 
#undef PI
#ifdef PI
    this piece of code is not compiled
    because PI is not defined
    
    use of token PI wont be substituted with its definition
    printf("\n PI : %f ", PI);
#else
    printf("\n Sorry PI got undefined");
#endif    
    
    printf("\n Enter 2 numbers ");
    scanf("%d%d", &q, &w);
    e = MAX(q,w);
    //compiles into e = q>w?q:w;
    printf("\n Max : %d ", e);
            
    
    return 0;
}//main


/*
 macro
------- 
 A macro provides a token replacement mechanism.
 Just before compilation its usage is replaced by 
 its definition.
 
 Macro may take parameters also.
 See examples above.
 For calls to a parameterized macro the
 preprocessor replaces the macro token 
 with the macro definition in which the
 macro parameters are also substituted
 with the actually used parameters.
 
 
 
 */
