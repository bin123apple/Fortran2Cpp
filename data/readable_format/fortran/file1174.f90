program test_type_anything
  implicit none

  ! Begin testing
  call test_times2scalar()
  call test_times2array()
  call test_times2boo()

  print *, "All tests passed successfully."

contains

  subroutine times2scalar(val)
    class(*), intent(inout) :: val

    select type(val)
    type is (integer)
       val = val*2
    type is (real)
       val = val*2.0
    end select
  end subroutine times2scalar

  subroutine times2array(val)
    class(*), intent(inout) :: val(:)

    select type(val)
    type is (integer)
       val = val*2
    type is (real)
       val = val*2.0
    end select
  end subroutine times2array

  subroutine times2boo(val, resi, resr)
    class(*), intent(in) :: val
    integer, intent(out) :: resi
    real, intent(out) :: resr

    select type(val)
    type is (integer)
       resi = val*2
    type is (real)
       resr = val*2.0
    end select
  end subroutine times2boo

  subroutine test_times2scalar()
    integer :: ix = 2
    real :: iy = 3.0

    call times2scalar(ix)
    if (ix /= 4) then
      print *, "test_times2scalar for integer failed."
    else
      print *, "test_times2scalar for integer passed."
    endif

    call times2scalar(iy)
    if (iy /= 6.0) then
      print *, "test_times2scalar for real failed."
    else
      print *, "test_times2scalar for real passed."
    endif
  end subroutine test_times2scalar

  subroutine test_times2array()
    integer, dimension(3) :: ai = [1, 2, 3]
    real, dimension(3) :: ar = [1.0, 2.0, 3.0]
    call times2array(ai)
    if (all(ai == [2, 4, 6])) then
      print *, "test_times2array for integer array passed."
    else
      print *, "test_times2array for integer array failed."
    endif

    call times2array(ar)
    if (all(ar == [2.0, 4.0, 6.0])) then
      print *, "test_times2array for real array passed."
    else
      print *, "test_times2array for real array failed."
    endif
  end subroutine test_times2array

  subroutine test_times2boo()
    integer :: ix = 2, rx
    real :: iy = 3.0, ry

    call times2boo(ix, rx, ry)
    if (rx == 4) then
      print *, "test_times2boo for integer passed."
    else
      print *, "test_times2boo for integer failed."
    endif

    call times2boo(iy, rx, ry)
    if (ry == 6.0) then
      print *, "test_times2boo for real passed."
    else
      print *, "test_times2boo for real failed."
    endif
  end subroutine test_times2boo

end program test_type_anything