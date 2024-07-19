# Instruction_qer = """
# You play the role of a questioner, and you need to ask an answerer to give a C++ translation of the corresponding Fortran code through multiple rounds of dialogue. 
# The flow of the dialogue is as follows: 
# 1. In the first round of dialogue, you need to ask the answerer to give a C++ translation of the corresponding Fortran code. 
# 2. In the second round of dialogue, you need to ask the answerer to build Unit tests based on the original Fortran code and the translated C++ code respectively to verify whether the original Fortran code has been translated correctly. 

# You need to keep every conversation concise.
# Now you play the role of the questioner and ask the answerer about this question: {Fortran_Code}
# """

Instruction_qer = """
You play the role of a questioner, and you need to ask an answerer to give a C++ translation of the corresponding Fortran code through multiple rounds of dialogue. 
The flow of the dialogue is as follows: 
1. In the first round of dialogue: you need to ask the answerer to give a C++ translation of the corresponding Fortran code. 
2. In the second round of dialogue: In order to verify whether the original Fortran code has been translated correctly, you need to ask the answerer to build Unit tests based on the original Fortran code and the translated C++ code respectively. 

You need to keep every conversation concise.
"""

Instruction_ser_tran = """
I now need to ask you some questions about Fortran to C++ code translation, You need to keep every answer concise.
The first question is: {Fortran_Code}
"""

Instruction_ser_unit = """
{Unit_Test_Request}
I will execute part of the unit test code you gave. 
But please note that I cannot download external libraries, so please do not add any external libraries (such as google test) when writing unit testing code. 
"""

delete_comments = '''Help me to delete the comments of the following fortran code: 
Fortran Code:
{Fortran_Code}
Fortran Code without comments:
'''

if_contain_ext_prompt = """
Help me to determine if my fortran code containing undefined external within the code snippet itself
{Fortran_Code}
Just Answer "Yes" or "No".
"""

Init_solver_prompt = """
Fortran Unit test code:
```fortran
{fortran_code}
```
C++ Unit test code:
```cpp
{cpp_code}
```
"""
# futher_modification = """
# I now provide you with the output of fortran and cpp unit test execution. 
# If all unit tests pass, you can tell me the complete version of the correct C++ translation result by using "The correct C++ translation is:". 
# Otherwise, please help me modify the unit test code and tell me the complete modified version. 
# I will continue to help you execute the code.
# fortran code outputs: {fortran_compile_result} 
# C++ code result: {cpp_compile_result}
# """

ff_cf_further_modification = """
modify the unit test code based on the outputs and give me the complete modified unit test code to make sure I can compile and run it directly
fortran code outputs: {fortran_compile_result} 
C++ code result: {cpp_compile_result}
"""

missing_terminating = """
Here is the cpp compile errors:
{cpp_compile_result}
It looks that the String literal spans multiple lines. Help me to modify the cpp unit test code and make sure there is no \\n inside the string.
"""

ft_cf_further_modification = """
modify the cpp unit test code based on the outputs and give me the complete modified unit test code to make sure I can compile and run it directly
{cpp_compile_result}
"""

ff_ct_further_modification = """
modify the fortran unit test code based on the outputs and give me the complete modified unit test code to make sure I can compile and run it directly
{fortran_compile_result}
"""

ft_ct_further_check = """
fortran code outputs: {fortran_compile_result} 
C++ code result: {cpp_compile_result}
Based on the unit test results tell me if the translation has been done correctly?
Just Answer "Yes" or "No".
"""

q_ask_s_translation = """
Here is my fortran code: {fortran_code}. Now you need to provide a complete question (including code) to the answerer and ask him to translate this fortran code to C++. Don't translate this fortran code by yourself.
"""

q_ask_s_unit_test ="""
Here is the answer from the solver: {ser_answer}, you now need to ask the answerer to provide the executable Unit tests codes for both the original Fortran code and the translated C++ code. 
Please add the unit tests to the main function. 
In c++ code, you should use 'assert' for the unit test checking. One example: assert (has_close_elements((1.0, 2.0, 5.9, 4.0, 5.0), 0.95) == true);
In fortran code, you should use the following format for the unit test checking:     
if (has_close_elements(a, n, 0.8)) then
    write(*,*) "Test case 2 failed: assertion failed"
    call exit(1)
end if
"""

end_prompt_ = """
Give the the correct and complete fortran-c++ code pair based on your last unit test codes.
"""

combine_header_files_cpp = """
I need you to help me put all the functions I need into the same C++ file instead of adding additional header files.
{compile_result}
"""

combine_header_files_fortran = """
I need you to help me put all the functions I need into the same fortran file instead of adding additional header files.
{compile_result}
"""

further_modification_ = """
Help me continue to modify the C++ and fortran codes to ensure that they have the same functions and provide the complete unit test code to make sure I can compile and run it directly (Not only the main code).
"""

clear_prompt_ = """
Your answer was neither 'yes' nor 'no'. Please provide a clear answer.
"""

Prompts_Fortran_to_Cpp = '''Help me to translate the following Fortran code to C++ code, don't give any words: 
Fortran Code: 
program DRB093_doall2_collapse_orig_no\n use omp_lib\n use DRB093\n implicit none\n\n integer :: len, i, j\n len = 100\n\n allocate (a(len,len))\n\n !$omp parallel do collapse(2)\n do i = 1, len\n do j = 1, len\n a(i,j) = a(i,j)+1\n end do\n end do\n !$omp end parallel do\nend program
Translated C++ Code: #include <stdio.h>\nint a[100][100];\nint main()\n{{\n int i,j;\n#pragma omp parallel for collapse(2)\n for (i=0;i<100;i++)\n for (j=0;j<100;j++)\n a[i][j]=a[i][j]+1;\n return 0;\n}}\n\n

Help me to translate the following Fortran code to C++ code, don't give any words: 
Fortran Code: 
program DRB096_doall2_taskloop_collapse_orig_no\n use omp_lib\n use DRB096\n implicit none\n\n integer :: len, i, j\n len = 100\n\n allocate (a(len,len))\n\n !$omp parallel\n !$omp single\n !$omp taskloop collapse(2)\n do i = 1, len\n do j = 1, len\n a(i,j) = a(i,j)+1\n end do\n end do\n !$omp end taskloop\n !$omp end single\n !$omp end parallel\n\n print 100, a(50,50)\n 100 format ('a(50,50) =',i3)\n\nend program. 
Translated C++ Code: #include <stdio.h>\n#if (_OPENMP<201511)\n#error "An OpenMP 4.5 compiler is needed to compile this test."\n#endif\n\n#include <stdio.h>\nint a[100][100];\nint main()\n{{\n int i, j;\n#pragma omp parallel\n {{\n#pragma omp single\n {{\n#pragma omp taskloop collapse(2)\n for (i = 0; i < 100; i++)\n for (j = 0; j < 100; j++)\n a[i][j]+=1; \n }}\n }}\n printf ("a[50][50]=%d\n", a[50][50]);\n return 0;\n}}\n 

Help me to translate the following Fortran code to C++ code, don't give any words: 
Fortran Code:
{Fortran_Code}
Translated C++ Code:
'''

prompts_f2c_func_expl = '''Help me to translate the following Fortran code to C++ code by using the following format:
The function of the source Fortran Code is: ...
Translated c++ code is: ...
Explanation: ...

Example:
Fortran Code needs to be translated:
program DRB093_doall2_collapse_orig_no\n use omp_lib\n use DRB093\n implicit none\n\n integer :: len, i, j\n len = 100\n\n allocate (a(len,len))\n\n !$omp parallel do collapse(2)\n do i = 1, len\n do j = 1, len\n a(i,j) = a(i,j)+1\n end do\n end do\n !$omp end parallel do\nend program
Translated C++ Code: #include <stdio.h>\nint a[100][100];\nint main()\n{{\n int i,j;\n#pragma omp parallel for collapse(2)\n for (i=0;i<100;i++)\n for (j=0;j<100;j++)\n a[i][j]=a[i][j]+1;\n return 0;\n}}\n\n

The function of the source Fortran Code is: 
The original Fortran code is designed to initialize a two-dimensional array and then increment each element in the array by 1. It does this in parallel using OpenMP, a standard for parallel programming. The collapse(2) directive is used to flatten the nested loop structure into a single iteration space, allowing for more efficient parallel execution.

Translated c++ code is: 
#include <omp.h>
#include <iostream>

int main() {
    const int len = 100;
    int a[len][len];

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            a[i][j] = a[i][j] + 1;
        }
    }

    return 0;
}

Explanation: 
1. Header Files: The C++ code includes <omp.h> for OpenMP support and <iostream> for input/output operations, although the latter is not used in this snippet. In contrast, the Fortran code uses omp_lib module for OpenMP and a custom module DRB093, which is not used in the snippet provided.
2. Array Initialization: The C++ code statically declares a 2D array a[100][100]. In the Fortran code, the array a is dynamically allocated with dimensions [len][len], where len = 100. C++ code assumes the array is globally initialized to zeroes, similar to what would happen by default in Fortran.
3. Parallel Region: The C++ code uses #pragma omp parallel for collapse(2) to parallelize the nested loop. This is directly analogous to the Fortran version's !$omp parallel do collapse(2), indicating that both loops are collapsed into a single parallel loop.
4. Loop Indices: Fortran arrays are 1-indexed, while C++ arrays are 0-indexed. Therefore, the loop in C++ starts from 0 up to len-1, whereas in Fortran, it goes from 1 to len. This difference is accounted for in the translation.
5. Increment Operation: The core operation inside the loops, a[i][j] = a[i][j] + 1, remains the same in both languages, incrementing each element of the array by 1.
This translation maintains the original code's intent and structure, adjusting for the syntactic and indexing differences between Fortran and C++.

Real Code:
Fortran Code needs to be translated:
{Fortran_Code}
'''

Asserter_Y_N = '''
I will provide you a paragraph of Fortran code and a paragraph of translated C++ code, you need to help me to assess if they perform the same function. You only need to tell me whether this Fortran code has been correctly translated into C++ code. If it is, just answer: "Yes". If not, answer: "No", and provide the reason.
Fortran code:
program DRB093_doall2_collapse_orig_no\n use omp_lib\n use DRB093\n implicit none\n\n integer :: len, i, j\n len = 100\n\n allocate (a(len,len))\n\n !$omp parallel do collapse(2)\n do i = 1, len\n do j = 1, len\n a(i,j) = a(i,j)+1\n end do\n end do\n !$omp end parallel do\nend program
Translated C++ Code: 
#include <stdio.h>\nint a[100][100];\nint main()\n{{\n int i,j;\n#pragma omp parallel for collapse(2)\n for (i=0;i<100;i++)\n for (j=0;j<100;j++)\n a[i][j]=a[i][j]+1;\n return 0;\n}}\n\n
Answer: Yes

Fortran code:
program DRB096_doall2_taskloop_collapse_orig_no\n use omp_lib\n use DRB096\n implicit none\n\n integer :: len, i, j\n len = 100\n\n allocate (a(len,len))\n\n !$omp parallel\n !$omp single\n !$omp taskloop collapse(2)\n do i = 1, len\n do j = 1, len\n a(i,j) = a(i,j)+1\n end do\n end do\n !$omp end taskloop\n !$omp end single\n !$omp end parallel\n\n print 100, a(50,50)\n 100 format ('a(50,50) =',i3)\n\nend program. 
Translated C++ Code: 
#include <stdio.h>\n#if (_OPENMP<201511)\n#error "An OpenMP 4.5 compiler is needed to compile this test."\n#endif\n\n#include <stdio.h>\nint a[100][100];\n\n {{\n#pragma omp single\n {{\n#pragma omp taskloop collapse(2)\n for (i = 0; i < 100; i++)\n for (j = 0; j < 100; j++)\n a[i][j]+=1; \n }}\n }}\n printf ("a[50][50]=%d\n", a[50][50]);\n return 0;\n}}\n 
Answer: No
1.The C++ code is missing the declaration and initialization of the loop variables i and j.
2.The C++ code has unnecessary double curly braces ({{ and }}).
3.The C++ code is missing the #pragma omp parallel directive before the #pragma omp single.

Fortran code:
{Fortran_Code}
Translated C++ Code:
{Cpp_Code}
Answer:
'''

Own_model_Modify_code = '''
The following code translation is not perfect, you need to modify the translated C++ Code based on the reasons.
Original Fortran code:
{Fortran_Code}
Translated C++ Code:
{Cpp_Code}
Reasons:
{Reasons}
Modified C++ Code:
'''

# Own_model_Y_N =  '''I will provide you a paragraph of Fortran code and a paragraph of translated C++ code, 
#                   you need to help me to assess if they perform the same function. 
#                   You only need to tell me whether this Fortran code has been correctly translated into C++ code. 
#                   If it is, just answer: "Yes". 
#                   If not, answer: "No", and provide the reason.Fortran code:{Fortran_code}Translated C++ Code:{Cpp_code}'''


Own_model_Y_N =  '''Help me to assess if the translated C++ is correct. 
                  Source fortran code: {Fortran_code}
                  Translated C++ Code: {Cpp_code}
                  Answer:'''


Prompts_Fortran_to_Cpp_modify = '''Help me to modify the translated C++ code based on the reason above, just provide the modified C++ code, don't give any words: 
C++ Code: #include <stdio.h>\nint a[100][100];\nint main()\n{{\n int i,j;\n#pragma omp parallel for collapse(2)\n for (i=0;i<100;i++)\n for (j=0;j<100;j++)\n a[i][j]=a[i][j]+1;\n return 0;\n}}\n\n

Help me to modify the translated C++ code based on the reason above, just provide the modified C++ code, don't give any words: 
C++ Code: #include <stdio.h>\n#if (_OPENMP<201511)\n#error "An OpenMP 4.5 compiler is needed to compile this test."\n#endif\n\n#include <stdio.h>\nint a[100][100];\nint main()\n{{\n int i, j;\n#pragma omp parallel\n {{\n#pragma omp single\n {{\n#pragma omp taskloop collapse(2)\n for (i = 0; i < 100; i++)\n for (j = 0; j < 100; j++)\n a[i][j]+=1; \n }}\n }}\n printf ("a[50][50]=%d\n", a[50][50]);\n return 0;\n}}\n 

Help me to modify the translated C++ code based on the reason above, just provide the modified C++ code, don't give any words: 
C++ Code:
'''

Compiler_inital_prompt_ = '''I am trying to translate a phagragraph of fortran code to C++ code, but the translated C++ code can not pass the compiler. Help me to modify the translated C++ to Make it possible to pass the compiler. All you need to do is provide me with the modified C++ code without any explanations.
Source fortran Code: 
program DRB096_doall2_taskloop_collapse_orig_no\n use omp_lib\n use DRB096\n implicit none\n\n integer :: len, i, j\n len = 100\n\n allocate (a(len,len))\n\n !$omp parallel\n !$omp single\n !$omp taskloop collapse(2)\n do i = 1, len\n do j = 1, len\n a(i,j) = a(i,j)+1\n end do\n end do\n !$omp end taskloop\n !$omp end single\n !$omp end parallel\n\n print 100, a(50,50)\n 100 format ('a(50,50) =',i3)\n\nend program. 
Translated C++ Code: 
#include <stdio.h>\n#if (_OPENMP<201511)\n#error "An OpenMP 4.5 compiler is needed to compile this test."\n#endif\n\n#include <stdio.h>\nint a[100][100];\n\n {{\n#pragma omp single\n {{\n#pragma omp taskloop collapse(2)\n for (i = 0; i < 100; i++)\n for (j = 0; j < 100; j++)\n a[i][j]+=1; \n }}\n }}\n printf ("a[50][50]=%d\n", a[50][50]);\n return 0;\n}}\n 
Modified C++ Code:
#include <stdio.h>\n#if (_OPENMP<201511)\n#error "An OpenMP 4.5 compiler is needed to compile this test."\n#endif\n\n#include <stdio.h>\nint a[100][100];\nint main()\n{{\n int i, j;\n#pragma omp parallel\n {{\n#pragma omp single\n {{\n#pragma omp taskloop collapse(2)\n for (i = 0; i < 100; i++)\n for (j = 0; j < 100; j++)\n a[i][j]+=1; \n }}\n }}\n printf ("a[50][50]=%d\n", a[50][50]);\n return 0;\n}}\n 

Source fortran Code:
{Fortran_Code}
Translated C++ Code:
{Cpp_Code}
Modified C++ Code:
'''

Compiler_inital_prompt = '''I am trying to translate a phagragraph of fortran code to C++ code, but the translated C++ code can not pass the compiler. Help me to modify the translated C++ to Make it possible to pass the compiler. All you need to do is provide me with the modified C++ code without any explanations.
Source fortran Code: 
program DRB096_doall2_taskloop_collapse_orig_no\n use omp_lib\n use DRB096\n implicit none\n\n integer :: len, i, j\n len = 100\n\n allocate (a(len,len))\n\n !$omp parallel\n !$omp single\n !$omp taskloop collapse(2)\n do i = 1, len\n do j = 1, len\n a(i,j) = a(i,j)+1\n end do\n end do\n !$omp end taskloop\n !$omp end single\n !$omp end parallel\n\n print 100, a(50,50)\n 100 format ('a(50,50) =',i3)\n\nend program. 
Translated C++ Code: 
#include <stdio.h>\n#if (_OPENMP<201511)\n#error "An OpenMP 4.5 compiler is needed to compile this test."\n#endif\n\n#include <stdio.h>\nint a[100][100];\n\n {{\n#pragma omp single\n {{\n#pragma omp taskloop collapse(2)\n for (i = 0; i < 100; i++)\n for (j = 0; j < 100; j++)\n a[i][j]+=1; \n }}\n }}\n printf ("a[50][50]=%d\n", a[50][50]);\n return 0;\n}}\n 

Source fortran Code:
{Fortran_Code}
Translated C++ Code:
{Cpp_Code}
'''

Compiler_check_prompt = '''
The compiler is throwing errors. The error report is: {reason}. Please help me to continue modifying the C++ code. Just write out the modified C++ code based on the error report, DO NOT write other words! New C++ Code:
'''

Unit_Test_prompt = '''
I want you to help me to select the suitable code for the unit test, I will provide you two kinds of code, fortran and cpp. 
You need to:
1. Determine if the Input and output parameters of these two kinds of code are values. 
2. If they are not values, just tell me "False". If they are values, find the module and function name and orgnize them by using the following format:
TEST(myLib, mySub_test) {{
   int cpp_input_parameter = 1;
   int fortran_input_parameter = 1;
   int cpp_output_parameter;
   int fortran_output_parameter;
   cpp_function_name(&a1, &b1);
   __fortran-module-name_MOD_fortran-function-name(&a2, &b2); # for the fortran function with module case, and you need to change the fortran names to lower cases
   _fortran-function-name(&a2, &b2); # for the fortran function without module case, and you need to change the fortran names to lower cases
   EXPECT_EQ(cpp_input_parameter, fortran_input_parameter);
   EXPECT_EQ(cpp_output_parameter, fortran_output_parameter);
}}

Example 1:
fortran code:
! {{ dg-do compile }}
! PR fortran/50524
!
program foo
   print *, 'abc'(2.e0:3)   ! {{ dg-error "must be of type INTEGER" }}
   print *,'qwe'(1:1e0)     ! {{ dg-error "must be of type INTEGER" }}
end program foo

cpp code:
#include <iostream>
#include <string>
int main() {{
    std::string abc = "abc";
    std::string qwe = "qwe";
    // In C++, string indexing must be an integer. Floats are not allowed.
    // So, the following lines would cause a compile error in C++ if uncommented.
    // std::cout << abc[2.0:3] << std::endl;
    // std::cout << qwe[1:1.0] << std::endl;
    return 0;
}}

Answer:
False

Example 2:
fortran code: 
SUBROUTINE CROTG(CA,CB,C,S)

      COMPLEX CA,CB,S
      REAL C

      COMPLEX ALPHA
      REAL NORM,SCALE

      INTRINSIC CABS,CONJG,SQRT

      IF (CABS(CA).EQ.0.) THEN
         C = 0.
         S = (1.,0.)
         CA = CB
      ELSE
         SCALE = CABS(CA) + CABS(CB)
         NORM = SCALE*SQRT((CABS(CA/SCALE))**2+ (CABS(CB/SCALE))**2)
         ALPHA = CA/CABS(CA)
         C = CABS(CA)/NORM
         S = ALPHA*CONJG(CB)/NORM
         CA = ALPHA*NORM
      END IF

      RETURN
END

cpp code:
#include <complex>
#include <cmath>

void crotg(std::complex<double>& ca, const std::complex<double>& cb, double& c, std::complex<double>& s) {{
    std::complex<double> alpha;
    double scale, norm;

    if (abs(ca) == 0.0) {{
        c = 0.0;
        s = std::complex<double>(1.0, 0.0);
        ca = cb;
    }} 
    else {{
        scale = abs(ca) + abs(cb);
        norm = scale * sqrt(pow(abs(ca/scale), 2) + pow(abs(cb/scale), 2));
        alpha = ca / abs(ca);
        c = abs(ca) / norm;
        s = alpha * std::conj(cb) / norm;
        ca = alpha * norm;
    }}
}}

Answer:
TEST(CrotgLib, Crotg_test) {{
   std::complex<double> cpp_input_parameter = {{1.0, 0.0}};
   std::complex<double> fortran_input_parameter = {{1.0, 0.0}};
   double cpp_output_parameter_c;
   double fortran_output_parameter_c;
   std::complex<double> cpp_output_parameter_s;
   std::complex<double> fortran_output_parameter_s;

   // C++ function call
   crotg(cpp_input_parameter, std::complex<double>(1.0, 0.0), cpp_output_parameter_c, cpp_output_parameter_s);

   // Fortran function call (no module case)
   _CROTG(&fortran_input_parameter, &std::complex<double>(1.0, 0.0), &fortran_output_parameter_c, &fortran_output_parameter_s);

   EXPECT_EQ(cpp_input_parameter, fortran_input_parameter);
   EXPECT_EQ(cpp_output_parameter_c, fortran_output_parameter_c);
   EXPECT_EQ(cpp_output_parameter_s, fortran_output_parameter_s);
}}

Example 3:
fortran code: 

cpp code:

Answer:


Real code:
fortran code:
{fortran_code}

cpp code:
{cpp_code}

Answer:
'''
modify_code = """Please modify the code and give the modified complete code, make sure all the functions are within a file and I will re-run the code. 
1. You can add debugging statements if needed.
2. If there is a need for external library installations, please let me know the appropriate pip command by enclosing them in ```sh ```"""

check_correctness = "Please judge whether the test code you just gave is correct based on the output of the code execution. Just Answer: 'Yes' or 'No'. "

end_dialogue = """
Give me the correct modified function code (without the test code) based on your last unit test code.
"""

further_modification = """
Please go ahead and modify the code to make sure it can run correctly. 
You should make sure all the functions are within a file and I will re-run the code.
"""

start_prompt = """
Could you help verify whether your code can run correctly? 
1. If needed, You could create some mock data or files to assist with this. But note that whether you create new data or create a new file and write the data to it, these operations need to be done in same python file.
2. I will help you to install the related packages, you just need to tell me how install the package you need by using ```sh ... ```.
3. Our goal is to verify that the function works correctly. So you need to make sure you provide me with a complete python code rather than providing some simplified version of it.
"""

run_code_prompt = """
To confirm the code functions properly, we should execute it and check its performance.
Let's test the code to make sure it operates as expected.
To verify that the code is functioning correctly, let's run a test.
Let's execute the code to validate its proper functioning.
To make certain our code is running right, we should perform a test.
Let's initiate a run to confirm that the code works as intended.
To ascertain the code's effectiveness, we must test it.
We need to run the code to ensure it meets our standards.
Let's check the code's functionality by running it.
To guarantee the code's accuracy, testing it is essential.
We should execute the code to verify its accuracy.
Let's run the code to make sure everything is functioning properly.
To ensure flawless operation, we need to test the code.
Let's operate the code to check its effectiveness.
We should validate the code's performance by running it.
Let's put the code through a run-test to ensure it works correctly.
To be certain of the code's operation, we need to run it.
Running the code will help us verify its proper function.
Let's test run the code to check for any issues.
To confirm code reliability, let's execute it now.
We should run a trial to test the code's functionality.
Let's activate the code to ensure it's working as it should.
Running the code will confirm its efficiency and correctness.
We need to execute the code to confirm that it performs correctly.
To make sure the code is error-free, let's run a verification test.
Let's run the code to determine if it functions correctly.
We should check the code by running it to ensure its efficacy.
Let's perform a test run to validate the code's functionality.
To ascertain code performance, executing it is necessary.
We must run the code to ensure it operates efficiently.
To verify the code's success, let's give it a run.
Running the code will allow us to confirm its functionality.
We need to execute the code to see if it's working properly.
Let's initiate a test run to ensure the code is effective.
To confirm the code's operational success, testing it is crucial.
Let's deploy the code to check its working condition.
Running the code is essential to verify its proper execution.
We should operate the code to confirm its capabilities.
Let's activate a test run to ensure the code functions well.
To make sure the code performs its intended functions, we need to run it.
Running the code will help us ensure it meets functional requirements.
We should test the code to confirm that it executes properly.
Let's perform a functional test to ensure the code is running correctly.
To check the code's precision, let's run it.
We must initiate a test to verify the code's functionality.
To determine if the code is error-free, we should run it now.
Running the code is the best way to ensure its accuracy.
Let's conduct a run to verify that the code operates as it should.
We need to run the code to check its functionality and reliability.
Let's execute the code to test its overall performance.
"""


verify_code_prompt = """
Can you check if your code runs as expected?
Could you test your code to see if it functions properly?
Would you mind confirming that your code operates correctly?
Can you please verify the functionality of your code?
Could you ensure that your code is executing correctly?
Would you verify whether your code is functioning properly?
Can you determine if your code performs well?
Could you assist in checking if your code runs smoothly?
Can you help confirm your code's correctness?
Would you be able to test if your code is working right?
Can you examine your code to ensure it operates as intended?
Could you validate that your code works properly?
Would you mind running a test on your code to verify its performance?
Can you see if there are any issues with how your code runs?
Could you take a look to confirm your code functions correctly?
Would you mind ensuring your code's accuracy?
Can you help determine if your code is error-free?
Could you check for any flaws in your code's operation?
Would you be able to confirm the operational functionality of your code?
Can you make sure that your code is free of errors?
Could you perform a quick check to see if your code runs correctly?
Would you test your code to ensure it's executing properly?
Can you verify that your code meets the expected standards?
Could you assist by verifying your code's performance?
Would you mind checking if your code executes without issues?
Can you confirm the reliability of your code?
Could you please ensure that your code works as it should?
Would you assess whether your code runs effectively?
Can you help verify your code's operational correctness?
Could you double-check the functioning of your code?
Would you mind verifying that your code operates without problems?
Can you look into whether your code functions as planned?
Could you help confirm that your code performs as needed?
Would you be willing to check your code for proper operation?
Can you ensure that your code executes as expected?
Could you run a diagnostic to see if your code is working correctly?
Would you mind testing your code for functionality?
Can you verify the accuracy of your code's execution?
Could you provide assurance that your code is running properly?
Would you verify if your code is up to performance standards?
Can you check your code for any operational errors?
Could you run a trial on your code to confirm it functions correctly?
Would you conduct a check to ensure your code is accurate?
Can you help make sure your code is functioning correctly?
Could you assess if your code is performing as expected?
Would you mind giving your code a run-through to check its correctness?
Can you verify if your code is functioning up to standards?
Could you please test your code for correct operation?
Would you be willing to help ensure that your code is running smoothly?
Can you confirm if your code meets all functional requirements?
Make sure the code runs as intended.
Ensure that the code functions properly.
Verify the correct operation of the code.
Confirm that the code performs as expected.
Double-check the execution of the code.
Test the code to see that it works correctly.
Ascertain that the code behaves as it should.
Check that the code operates correctly.
Ensure the code executes without errors.
Validate the functionality of the code.
Review the code's performance to ensure accuracy.
Monitor the execution to confirm it's functioning properly.
Examine the code to make sure it runs smoothly.
Assess whether the code meets the expected outcomes.
Certify that the code is executing as planned.
Scrutinize the code for proper execution.
Check off that the code works as designed.
Inspect the code for correct operation.
Reconfirm that the code operates as intended.
Authenticate the correct running of the code.
Proof the code to ensure it's working correctly.
Cross-verify the execution of the code.
Make certain the code is functioning correctly.
Confirm the proper execution of your code.
Ensure your code executes as planned.
Verify that your code runs correctly.
Double-check that your code is functioning properly.
Make sure your code performs as expected.
Check that your code operates smoothly.
Validate that your code meets the operational criteria.
Ensure the code does what it's supposed to do.
Test to ensure the code's functionality.
Confirm that the code is error-free upon execution.
Ensure that the code delivers the expected results.
Double-check the code's results for accuracy.
Confirm that the code's output is as anticipated.
Make sure the code completes without issues.
Ensure that the code's performance is up to standard.
Confirm the reliability of the code during execution.
Make sure the code's logic performs correctly.
Verify the outcome of the code's execution.
Check for any discrepancies in the code's operation.
Ensure the code executes as it is supposed to.
Confirm the stability of the code upon execution.
Test the code thoroughly before finalizing.
Make certain the code executes without any hiccups.
Validate the precision of the code's operation.
Check that the code complies with the requirements.
Recheck the code's functionality for assurance.
Ensure that the code achieves the intended functionality.
Monitor the code to ensure it executes flawlessly.
Evaluate the code's execution to confirm correctness.
Ascertain that the code meets performance standards.
Review the code to ensure it fulfills its purpose.
Confirm that the code executes according to the plan.
Make sure the code is free from execution errors.
Ensure that the code's execution aligns with expectations.
Cross-check to confirm the code's proper functionality.
Validate that the code operates as it should.
Confirm that the code's process is correct.
Make certain the code's results are accurate.
Ensure that the code runs efficiently.
Verify that the code's performance is satisfactory.
Check that the code is functioning as it should.
Test the code's execution for any potential issues.
Make sure the code functions as intended under all conditions.
Confirm the integrity of the code's operations.
Ensure that the code performs effectively.
Review the code execution for any anomalies.
Validate the effectiveness of the code's execution.
Double-check the code for flawless performance.
Ensure that the code meets all operational expectations.
Confirm that the code handles all scenarios correctly.
Verify the code's effectiveness in real conditions.
Check the code's consistency in execution.
Make certain that the code adheres to the expected behavior.
Ensure the code's compliance with the specifications.
Confirm the code's capability to perform as necessary.
Monitor the code's performance for stability.
Ascertain that the code is ready for deployment.
Make sure the code satisfies all functional requirements.
Ensure that the code executes without deviations.
Confirm the code's readiness for operational use.
Test the code for dependability during execution.
Verify the code's robustness in various environments.
Check that the code performs efficiently.
Confirm that the code is up to professional standards.
Ensure the code's operations are in full effect.
Reaffirm the code's readiness for live environments.
Make sure the code is optimized for performance.
Confirm the code's suitability for the intended tasks.
Double-check the code for operational accuracy.
Ensure the code meets the quality standards.
Verify the code's readiness for full-scale use.
Confirm that the code maintains consistency.
Make certain the code delivers on its promises.
Ensure the code's functionality before release.
Confirm that the code functions optimally.
Double-check to ensure the code's successful execution.
Make sure the code's behavior matches the documentation.
"""

final_code_prompt = """
Our code has passed all the tests successfully, here's the code:
The code has successfully cleared all the tests, here it is:
We've successfully passed all tests with our code, here's the code:
All tests have been successfully passed by our code, here is what we wrote:
Our program succeeded in all the tests, here's the code:
Our code has cleared all its tests successfully, here's the code:
We've completed all tests successfully, here's our code:
Our coding tests were all passed successfully, here's our code:
Every test has been successfully passed by our code, see it here:
Our code achieved success in all the tests, here it is:
Successfully, our code has passed all tests, here's what we developed:
Our code met all the test criteria successfully, here is the code:
Our code excelled in all the tests, here's the code:
All the tests have been cleared by our code, here it is:
Our software has successfully passed all the testing, here's the code:
Every test was a success for our code, here's the code:
We've passed all the required tests with our code, here it is:
Our code was successful in all the tests, here is our work:
The tests were all successfully passed by our code, here it is:
Our code sailed through all the tests, here's the code:
Our code has surpassed all testing successfully, here it is:
We've successfully navigated all tests with our code, here's the result:
All required tests were successfully passed by our code, see it here:
Our code has triumphed in all the tests, here's our code:
Every test has been successfully conquered by our code, here it is:
Our application passed all tests successfully, here is the code:
The code has proven successful in all tests, here it is:
Our code has come through all the tests with success, here's the code:
Our programming successfully passed all examinations, here's our code:
We've mastered all the tests with our code, here it is:
Our system has successfully passed all tests, here is the code:
The code has been successful in all tests, here is our work:
Every testing hurdle was successfully cleared by our code, here it is:
We've cleared all tests with our code successfully, here's the code:
Our code has been vetted and succeeded in all tests, here it is:
All tests have been met with success by our code, here's the code:
Our project successfully passed all the test phases, here is our code:
Successfully, our code has conquered all the tests, here's the output:
Our code managed to pass all tests successfully, here's the code:
The code has fulfilled all test conditions successfully, here it is:
Our code was tested and passed all assessments successfully, here's the code:
Every test was smoothly passed by our code, here's what we coded:
Our code nailed all the tests successfully, here's our work:
We have successfully completed all tests with our code, here it is:
Every test criteria was met successfully by our code, here's the code:
Our script passed all tests without fail, here is the code:
Our code stood up to all tests and passed, here's the code:
All testing barriers were successfully broken by our code, here it is:
Our code has flawlessly passed all the tests, here's our script:
Our code has been validated through all tests successfully, here's the code:
"""