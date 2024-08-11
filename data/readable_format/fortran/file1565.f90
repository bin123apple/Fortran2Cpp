module proc_component_example

  type t
    real :: a
    procedure(print_int), pointer, &
                          nopass :: proc
  end type t

  abstract interface
    subroutine print_int (arg, lun)
      import
      type(t), intent(in) :: arg
      integer, intent(in) :: lun
    end subroutine print_int
  end interface

  integer :: calls = 0

contains

  subroutine print_me (arg, lun)
    type(t), intent(in) :: arg
    integer, intent(in) :: lun
    write (lun,*) arg%a
    calls = calls + 1
  end subroutine print_me

  subroutine print_my_square (arg, lun)
    type(t), intent(in) :: arg
    integer, intent(in) :: lun
    write (lun,*) arg%a**2
    calls = calls + 1
  end subroutine print_my_square

end module proc_component_example

program main
    use proc_component_example
    use iso_fortran_env, only : output_unit

    type(t) :: x

    x%a = 2.71828

    x%proc => print_me
    call x%proc(x, output_unit)
    x%proc => print_my_square
    call x%proc(x, output_unit)

    if (calls/=2) STOP 1

    ! Test
    if (calls == 2) then
        write(*,*) 'Test passed.'
    else
        write(*,*) 'Test failed.'
        stop 2
    endif

end program main