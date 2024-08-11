program test_decl_var

implicit none

real :: var_real
integer :: var_int
complex :: var_cplx
logical :: var_log
character :: var_char
character(len=80) :: mnsj

! Initialize variables as in the original program
var_real = 3.141517
var_int = 6
var_cplx = (2, -4)
var_log = .true.
var_char = 'a'
mnsj = "Bienvenidos al curso de Fortran de PROTECO!"

! Tests
print *, "Testing..."
call assert_equals_real(var_real, 3.141517)
call assert_equals_int(var_int, 6)
call assert_equals_cplx(var_cplx, cmplx(2,-4))
call assert_equals_log(var_log, .true.)
call assert_equals_char(var_char, 'a')
call assert_equals_string(trim(mnsj), "Bienvenidos al curso de Fortran de PROTECO!")

contains

subroutine assert_equals_real(a, b)
    real, intent(in) :: a, b
    if (a == b) then
        print *, "Real number test passed."
    else
        print *, "Real number test failed."
    end if
end subroutine assert_equals_real

subroutine assert_equals_int(a, b)
    integer, intent(in) :: a, b
    if (a == b) then
        print *, "Integer test passed."
    else
        print *, "Integer test failed."
    end if
end subroutine assert_equals_int

subroutine assert_equals_cplx(a, b)
    complex, intent(in) :: a, b
    if (a == b) then
        print *, "Complex number test passed."
    else
        print *, "Complex number test failed."
    end if
end subroutine assert_equals_cplx

subroutine assert_equals_log(a, b)
    logical, intent(in) :: a, b
    if (a .eqv. b) then  ! Modified to use .eqv. for logical comparison
        print *, "Logical test passed."
    else
        print *, "Logical test failed."
    end if
end subroutine assert_equals_log

subroutine assert_equals_char(a, b)
    character, intent(in) :: a, b
    if (a == b) then
        print *, "Character test passed."
    else
        print *, "Character test failed."
    end if
end subroutine assert_equals_char

subroutine assert_equals_string(a, b)
    character(len=*), intent(in) :: a, b
    if (a == b) then
        print *, "String test passed."
    else
        print *, "String test failed."
    end if
end subroutine assert_equals_string

end program test_decl_var